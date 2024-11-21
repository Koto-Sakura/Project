/********************************************************************************
** Form generated from reading UI file 'resourceallocator.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESOURCEALLOCATOR_H
#define UI_RESOURCEALLOCATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ResourceAllocator
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelAvailable;
    QLineEdit *availableInput;
    QLabel *labelMax;
    QFormLayout *formLayoutMax;
    QLabel *labelMax0;
    QLineEdit *maxInputs_0;
    QLabel *labelMax1;
    QLineEdit *maxInputs_1;
    QLabel *labelMax2;
    QLineEdit *maxInputs_2;
    QLabel *labelMax3;
    QLineEdit *maxInputs_3;
    QLabel *labelMax4;
    QLineEdit *maxInputs_4;
    QLabel *labelAllocation;
    QFormLayout *formLayoutAllocation;
    QLabel *labelAllocation0;
    QLineEdit *allocationInputs_0;
    QLabel *labelAllocation1;
    QLineEdit *allocationInputs_1;
    QLabel *labelAllocation2;
    QLineEdit *allocationInputs_2;
    QLabel *labelAllocation3;
    QLineEdit *allocationInputs_3;
    QLabel *labelAllocation4;
    QLineEdit *allocationInputs_4;
    QPushButton *calculateButton;
    QTableWidget *resourceTable;
    QLabel *resultLabel;

    void setupUi(QWidget *ResourceAllocator)
    {
        if (ResourceAllocator->objectName().isEmpty())
            ResourceAllocator->setObjectName("ResourceAllocator");
        ResourceAllocator->resize(1036, 752);
        verticalLayout = new QVBoxLayout(ResourceAllocator);
        verticalLayout->setObjectName("verticalLayout");
        labelAvailable = new QLabel(ResourceAllocator);
        labelAvailable->setObjectName("labelAvailable");

        verticalLayout->addWidget(labelAvailable);

        availableInput = new QLineEdit(ResourceAllocator);
        availableInput->setObjectName("availableInput");

        verticalLayout->addWidget(availableInput);

        labelMax = new QLabel(ResourceAllocator);
        labelMax->setObjectName("labelMax");

        verticalLayout->addWidget(labelMax);

        formLayoutMax = new QFormLayout();
        formLayoutMax->setObjectName("formLayoutMax");
        labelMax0 = new QLabel(ResourceAllocator);
        labelMax0->setObjectName("labelMax0");

        formLayoutMax->setWidget(0, QFormLayout::LabelRole, labelMax0);

        maxInputs_0 = new QLineEdit(ResourceAllocator);
        maxInputs_0->setObjectName("maxInputs_0");

        formLayoutMax->setWidget(0, QFormLayout::FieldRole, maxInputs_0);

        labelMax1 = new QLabel(ResourceAllocator);
        labelMax1->setObjectName("labelMax1");

        formLayoutMax->setWidget(1, QFormLayout::LabelRole, labelMax1);

        maxInputs_1 = new QLineEdit(ResourceAllocator);
        maxInputs_1->setObjectName("maxInputs_1");

        formLayoutMax->setWidget(1, QFormLayout::FieldRole, maxInputs_1);

        labelMax2 = new QLabel(ResourceAllocator);
        labelMax2->setObjectName("labelMax2");

        formLayoutMax->setWidget(2, QFormLayout::LabelRole, labelMax2);

        maxInputs_2 = new QLineEdit(ResourceAllocator);
        maxInputs_2->setObjectName("maxInputs_2");

        formLayoutMax->setWidget(2, QFormLayout::FieldRole, maxInputs_2);

        labelMax3 = new QLabel(ResourceAllocator);
        labelMax3->setObjectName("labelMax3");

        formLayoutMax->setWidget(3, QFormLayout::LabelRole, labelMax3);

        maxInputs_3 = new QLineEdit(ResourceAllocator);
        maxInputs_3->setObjectName("maxInputs_3");

        formLayoutMax->setWidget(3, QFormLayout::FieldRole, maxInputs_3);

        labelMax4 = new QLabel(ResourceAllocator);
        labelMax4->setObjectName("labelMax4");

        formLayoutMax->setWidget(4, QFormLayout::LabelRole, labelMax4);

        maxInputs_4 = new QLineEdit(ResourceAllocator);
        maxInputs_4->setObjectName("maxInputs_4");

        formLayoutMax->setWidget(4, QFormLayout::FieldRole, maxInputs_4);


        verticalLayout->addLayout(formLayoutMax);

        labelAllocation = new QLabel(ResourceAllocator);
        labelAllocation->setObjectName("labelAllocation");

        verticalLayout->addWidget(labelAllocation);

        formLayoutAllocation = new QFormLayout();
        formLayoutAllocation->setObjectName("formLayoutAllocation");
        labelAllocation0 = new QLabel(ResourceAllocator);
        labelAllocation0->setObjectName("labelAllocation0");

        formLayoutAllocation->setWidget(0, QFormLayout::LabelRole, labelAllocation0);

        allocationInputs_0 = new QLineEdit(ResourceAllocator);
        allocationInputs_0->setObjectName("allocationInputs_0");

        formLayoutAllocation->setWidget(0, QFormLayout::FieldRole, allocationInputs_0);

        labelAllocation1 = new QLabel(ResourceAllocator);
        labelAllocation1->setObjectName("labelAllocation1");

        formLayoutAllocation->setWidget(2, QFormLayout::LabelRole, labelAllocation1);

        allocationInputs_1 = new QLineEdit(ResourceAllocator);
        allocationInputs_1->setObjectName("allocationInputs_1");

        formLayoutAllocation->setWidget(2, QFormLayout::FieldRole, allocationInputs_1);

        labelAllocation2 = new QLabel(ResourceAllocator);
        labelAllocation2->setObjectName("labelAllocation2");

        formLayoutAllocation->setWidget(3, QFormLayout::LabelRole, labelAllocation2);

        allocationInputs_2 = new QLineEdit(ResourceAllocator);
        allocationInputs_2->setObjectName("allocationInputs_2");

        formLayoutAllocation->setWidget(3, QFormLayout::FieldRole, allocationInputs_2);

        labelAllocation3 = new QLabel(ResourceAllocator);
        labelAllocation3->setObjectName("labelAllocation3");

        formLayoutAllocation->setWidget(5, QFormLayout::LabelRole, labelAllocation3);

        allocationInputs_3 = new QLineEdit(ResourceAllocator);
        allocationInputs_3->setObjectName("allocationInputs_3");

        formLayoutAllocation->setWidget(5, QFormLayout::FieldRole, allocationInputs_3);

        labelAllocation4 = new QLabel(ResourceAllocator);
        labelAllocation4->setObjectName("labelAllocation4");

        formLayoutAllocation->setWidget(6, QFormLayout::LabelRole, labelAllocation4);

        allocationInputs_4 = new QLineEdit(ResourceAllocator);
        allocationInputs_4->setObjectName("allocationInputs_4");

        formLayoutAllocation->setWidget(6, QFormLayout::FieldRole, allocationInputs_4);


        verticalLayout->addLayout(formLayoutAllocation);

        calculateButton = new QPushButton(ResourceAllocator);
        calculateButton->setObjectName("calculateButton");

        verticalLayout->addWidget(calculateButton);

        resourceTable = new QTableWidget(ResourceAllocator);
        if (resourceTable->columnCount() < 13)
            resourceTable->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        resourceTable->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        if (resourceTable->rowCount() < 5)
            resourceTable->setRowCount(5);
        resourceTable->setObjectName("resourceTable");
        resourceTable->setRowCount(5);
        resourceTable->setColumnCount(13);

        verticalLayout->addWidget(resourceTable);

        resultLabel = new QLabel(ResourceAllocator);
        resultLabel->setObjectName("resultLabel");

        verticalLayout->addWidget(resultLabel);


        retranslateUi(ResourceAllocator);
        QObject::connect(calculateButton, SIGNAL(clicked()), ResourceAllocator, SLOT(handleCalculateButtonClicked()));

        QMetaObject::connectSlotsByName(ResourceAllocator);
    } // setupUi

    void retranslateUi(QWidget *ResourceAllocator)
    {
        ResourceAllocator->setWindowTitle(QCoreApplication::translate("ResourceAllocator", "Resource Allocator", nullptr));
        labelAvailable->setText(QCoreApplication::translate("ResourceAllocator", "\345\217\257\347\224\250\350\265\204\346\272\220:", nullptr));
        labelMax->setText(QCoreApplication::translate("ResourceAllocator", "\346\234\200\345\244\247\351\234\200\346\261\202:", nullptr));
        labelMax0->setText(QCoreApplication::translate("ResourceAllocator", "P0:", nullptr));
        labelMax1->setText(QCoreApplication::translate("ResourceAllocator", "P1:", nullptr));
        labelMax2->setText(QCoreApplication::translate("ResourceAllocator", "P2:", nullptr));
        labelMax3->setText(QCoreApplication::translate("ResourceAllocator", "P3:", nullptr));
        labelMax4->setText(QCoreApplication::translate("ResourceAllocator", "P4:", nullptr));
        labelAllocation->setText(QCoreApplication::translate("ResourceAllocator", "\345\275\223\345\211\215\345\210\206\351\205\215:", nullptr));
        labelAllocation0->setText(QCoreApplication::translate("ResourceAllocator", "P0:", nullptr));
        labelAllocation1->setText(QCoreApplication::translate("ResourceAllocator", "P1:", nullptr));
        labelAllocation2->setText(QCoreApplication::translate("ResourceAllocator", "P2:", nullptr));
        labelAllocation3->setText(QCoreApplication::translate("ResourceAllocator", "P3:", nullptr));
        labelAllocation4->setText(QCoreApplication::translate("ResourceAllocator", "P4:", nullptr));
        calculateButton->setText(QCoreApplication::translate("ResourceAllocator", "\350\256\241\347\256\227", nullptr));
        QTableWidgetItem *___qtablewidgetitem = resourceTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ResourceAllocator", "\350\277\233\347\250\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = resourceTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ResourceAllocator", "\345\275\223\345\211\215\345\210\206\351\205\215A", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = resourceTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ResourceAllocator", "\345\275\223\345\211\215\345\210\206\351\205\215B", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = resourceTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ResourceAllocator", "\345\275\223\345\211\215\345\210\206\351\205\215C", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = resourceTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ResourceAllocator", "\346\234\200\345\244\247\351\234\200\346\261\202A", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = resourceTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ResourceAllocator", "\346\234\200\345\244\247\351\234\200\346\261\202B", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = resourceTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("ResourceAllocator", "\346\234\200\345\244\247\351\234\200\346\261\202C", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = resourceTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("ResourceAllocator", "\345\275\223\345\211\215\351\234\200\346\261\202A", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = resourceTable->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("ResourceAllocator", "\345\275\223\345\211\215\351\234\200\346\261\202B", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = resourceTable->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("ResourceAllocator", "\345\275\223\345\211\215\351\234\200\346\261\202C", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = resourceTable->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("ResourceAllocator", "\345\217\257\347\224\250\350\265\204\346\272\220A", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = resourceTable->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("ResourceAllocator", "\345\217\257\347\224\250\350\265\204\346\272\220B", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = resourceTable->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("ResourceAllocator", "\345\217\257\347\224\250\350\265\204\346\272\220C", nullptr));
        resultLabel->setText(QCoreApplication::translate("ResourceAllocator", "\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResourceAllocator: public Ui_ResourceAllocator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESOURCEALLOCATOR_H
