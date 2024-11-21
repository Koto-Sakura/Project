#include "resourceallocator.h"
#include "ui_resourceallocator.h"
#include <QTableWidgetItem>
#include <QMessageBox>

ResourceAllocator::ResourceAllocator(QWidget *parent)
    : QWidget(parent), ui(new Ui::ResourceAllocator)
{
    ui->setupUi(this);
    // 初始化 maxInputs 数组
    maxInputs[0] = ui->maxInputs_0;
    maxInputs[1] = ui->maxInputs_1;
    maxInputs[2] = ui->maxInputs_2;
    maxInputs[3] = ui->maxInputs_3;
    maxInputs[4] = ui->maxInputs_4;
    // 初始化 allocationInputs 数组
    allocationInputs[0] = ui->allocationInputs_0;
    allocationInputs[1] = ui->allocationInputs_1;
    allocationInputs[2] = ui->allocationInputs_2;
    allocationInputs[3] = ui->allocationInputs_3;
    allocationInputs[4] = ui->allocationInputs_4;
    connect(ui->calculateButton, &QPushButton::clicked, this, &ResourceAllocator::handleCalculateButtonClicked);
}

ResourceAllocator::~ResourceAllocator()
{
    delete ui;
}

void ResourceAllocator::handleCalculateButtonClicked()
{
    calculateSafeSequence();
}

void ResourceAllocator::calculateSafeSequence()
{
    // 获取用户输入
    QString availableStr = ui->availableInput->text();
    QStringList availableList = availableStr.split(' ');

    int n = 5; // 进程数
    int m = 3; // 资源种类

    int Available[3];
    QVector<QVector<int>> Allocation(5, QVector<int>(3));
    QVector<QVector<int>> Max(5, QVector<int>(3));
    QVector<QVector<int>> Need(5, QVector<int>(3));

    for (int i = 0; i < m; ++i)
    {
        Available[i] = availableList[i].toInt();
    }

    for (int i = 0; i < n; ++i)
    {
        QString maxStr = maxInputs[i]->text();
        QString allocationStr = allocationInputs[i]->text();
        QStringList maxList = maxStr.split(' ');
        QStringList allocationList = allocationStr.split(' ');

        for (int j = 0; j < m; ++j)
        {
            Max[i][j] = maxList[j].toInt();
            Allocation[i][j] = allocationList[j].toInt();
        }
    }

    // 计算 Need 矩阵
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            Need[i][j] = Max[i][j] - Allocation[i][j];
        }
    }

    // 计算初始可用资源
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            Available[j] -= Allocation[i][j];
        }
    }

    // 安全序列
    std::vector<int> safeSeq;
    bool isFinished[5] = {false};
    int safeCount = 0;


    ui->resourceTable->setRowCount(0);
    while (safeCount < n)
    {
        bool found = false;
        for (int i = 0; i < n; ++i)
        {
            if (!isFinished[i])
            {
                int j = 0;
                for (; j < m; ++j)
                {
                    if (Need[i][j] > Available[j])
                    {
                        break;
                    }
                }
                if (j == m)
                {
                    safeSeq.push_back(i);
                    safeCount++;

                    for (int k = 0; k < m; ++k)
                    {
                        Available[k] += Allocation[i][k];
                    }

                    isFinished[i] = true;
                    found = true;
                    updateTable(i, Allocation, Max, Need, QVector<int>{Available[0], Available[1], Available[2]});
                }
            }
        }
        if (!found)
        {
            ui->resultLabel->setText("系统不安全");
            return;
        }
    }
    QString safeSequenceStr = "系统安全，安全序列为: ";
    for (size_t i = 0; i < safeSeq.size(); ++i)
    {
        safeSequenceStr += "P" + QString::number(safeSeq[i]);
        if (i < safeSeq.size() - 1) // 如果不是最后一个元素，添加逗号和空格
        {
            safeSequenceStr += ", ";
        }
    }

    ui->resultLabel->setText(safeSequenceStr);
}

void ResourceAllocator::updateTable(int k, const QVector<QVector<int>> &allocation, const QVector<QVector<int>> &max, const QVector<QVector<int>> &need, const QVector<int> &available)
{
    int row = ui->resourceTable->rowCount();
    ui->resourceTable->insertRow(row);
    // 设置进程编号
    ui->resourceTable->setItem(row, 0, new QTableWidgetItem(QString("P%1").arg(k)));

    // 设置已分配资源
    for (int j = 0; j < 3; ++j)
    {
        ui->resourceTable->setItem(row, 1 + j, new QTableWidgetItem(QString::number(allocation[k][j])));
    }

    // 设置最大需求
    for (int j = 0; j < 3; ++j)
    {
        ui->resourceTable->setItem(row, 4 + j, new QTableWidgetItem(QString::number(max[k][j])));
    }

    // 设置需求资源数
    for (int j = 0; j < 3; ++j)
    {
        ui->resourceTable->setItem(row, 7 + j, new QTableWidgetItem(QString::number(need[k][j])));
    }

    // 设置更新后的 Available 数组
    for (int j = 0; j < 3; ++j)
    {
        ui->resourceTable->setItem(row, 10 + j, new QTableWidgetItem(QString::number(available[j])));
    }
}
