#ifndef RESOURCEALLOCATOR_H
#define RESOURCEALLOCATOR_H

#include <QWidget>
#include <QLineEdit>
namespace Ui {
class ResourceAllocator;
}

class ResourceAllocator : public QWidget
{
    Q_OBJECT

public:
    explicit ResourceAllocator(QWidget *parent = nullptr);
    ~ResourceAllocator();

public slots:
    void handleCalculateButtonClicked();

private:
    Ui::ResourceAllocator *ui;
    QLineEdit* maxInputs[5];
    QLineEdit* allocationInputs[5];

    void calculateSafeSequence();
    void updateTable(int k,const QVector<QVector<int>> &allocation, const QVector<QVector<int>> &max, const QVector<QVector<int>> &need, const QVector<int> &available);
};

#endif
