/********************************************************************************
** Form generated from reading UI file 'TreeWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEWIDGET_H
#define UI_TREEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QSpinBox *spinBoxKey;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonRemove;

    void setupUi(QWidget *TreeWidget)
    {
        if (TreeWidget->objectName().isEmpty())
            TreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        TreeWidget->resize(543, 470);
        verticalLayout = new QVBoxLayout(TreeWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(TreeWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spinBoxKey = new QSpinBox(TreeWidget);
        spinBoxKey->setObjectName(QString::fromUtf8("spinBoxKey"));
        spinBoxKey->setMinimumSize(QSize(50, 0));

        horizontalLayout->addWidget(spinBoxKey);

        pushButtonAdd = new QPushButton(TreeWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonRemove = new QPushButton(TreeWidget);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TreeWidget);

        QMetaObject::connectSlotsByName(TreeWidget);
    } // setupUi

    void retranslateUi(QWidget *TreeWidget)
    {
        TreeWidget->setWindowTitle(QCoreApplication::translate("TreeWidget", "Form", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("TreeWidget", "Add", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("TreeWidget", "Remove", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWidget: public Ui_TreeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
