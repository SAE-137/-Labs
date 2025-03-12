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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TreeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *BinaryTreeTab;
    QGraphicsView *graphicsView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBoxKey;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonRemove;
    QWidget *SearchTreeTab;
    QGraphicsView *graphicsView_2;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinBoxKey_2;
    QPushButton *pushButtonAdd_2;
    QPushButton *pushButtonRemove_2;
    QWidget *tab_2;
    QGraphicsView *graphicsView_3;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBoxKey_3;
    QPushButton *pushButtonAdd_3;
    QPushButton *pushButtonRemove_3;

    void setupUi(QWidget *TreeWidget)
    {
        if (TreeWidget->objectName().isEmpty())
            TreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        TreeWidget->resize(1162, 642);
        verticalLayout = new QVBoxLayout(TreeWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(TreeWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        BinaryTreeTab = new QWidget();
        BinaryTreeTab->setObjectName(QString::fromUtf8("BinaryTreeTab"));
        graphicsView = new QGraphicsView(BinaryTreeTab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-10, -10, 1141, 571));
        graphicsView->setMouseTracking(true);
        graphicsView->setTabletTracking(true);
        horizontalLayoutWidget = new QWidget(BinaryTreeTab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 291, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        spinBoxKey = new QSpinBox(horizontalLayoutWidget);
        spinBoxKey->setObjectName(QString::fromUtf8("spinBoxKey"));

        horizontalLayout->addWidget(spinBoxKey);

        pushButtonAdd = new QPushButton(horizontalLayoutWidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));

        horizontalLayout->addWidget(pushButtonAdd);

        pushButtonRemove = new QPushButton(horizontalLayoutWidget);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);

        tabWidget->addTab(BinaryTreeTab, QString());
        SearchTreeTab = new QWidget();
        SearchTreeTab->setObjectName(QString::fromUtf8("SearchTreeTab"));
        graphicsView_2 = new QGraphicsView(SearchTreeTab);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(0, 0, 1131, 561));
        horizontalLayoutWidget_2 = new QWidget(SearchTreeTab);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(0, 0, 291, 61));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        spinBoxKey_2 = new QSpinBox(horizontalLayoutWidget_2);
        spinBoxKey_2->setObjectName(QString::fromUtf8("spinBoxKey_2"));

        horizontalLayout_2->addWidget(spinBoxKey_2);

        pushButtonAdd_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButtonAdd_2->setObjectName(QString::fromUtf8("pushButtonAdd_2"));

        horizontalLayout_2->addWidget(pushButtonAdd_2);

        pushButtonRemove_2 = new QPushButton(horizontalLayoutWidget_2);
        pushButtonRemove_2->setObjectName(QString::fromUtf8("pushButtonRemove_2"));

        horizontalLayout_2->addWidget(pushButtonRemove_2);

        tabWidget->addTab(SearchTreeTab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        graphicsView_3 = new QGraphicsView(tab_2);
        graphicsView_3->setObjectName(QString::fromUtf8("graphicsView_3"));
        graphicsView_3->setGeometry(QRect(0, 0, 1131, 561));
        horizontalLayoutWidget_3 = new QWidget(tab_2);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(0, 0, 291, 61));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        spinBoxKey_3 = new QSpinBox(horizontalLayoutWidget_3);
        spinBoxKey_3->setObjectName(QString::fromUtf8("spinBoxKey_3"));

        horizontalLayout_3->addWidget(spinBoxKey_3);

        pushButtonAdd_3 = new QPushButton(horizontalLayoutWidget_3);
        pushButtonAdd_3->setObjectName(QString::fromUtf8("pushButtonAdd_3"));

        horizontalLayout_3->addWidget(pushButtonAdd_3);

        pushButtonRemove_3 = new QPushButton(horizontalLayoutWidget_3);
        pushButtonRemove_3->setObjectName(QString::fromUtf8("pushButtonRemove_3"));

        horizontalLayout_3->addWidget(pushButtonRemove_3);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(TreeWidget);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(TreeWidget);
    } // setupUi

    void retranslateUi(QWidget *TreeWidget)
    {
        TreeWidget->setWindowTitle(QCoreApplication::translate("TreeWidget", "Form", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("TreeWidget", "Insert", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("TreeWidget", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(BinaryTreeTab), QCoreApplication::translate("TreeWidget", "Tab 1", nullptr));
        pushButtonAdd_2->setText(QCoreApplication::translate("TreeWidget", "Insert", nullptr));
        pushButtonRemove_2->setText(QCoreApplication::translate("TreeWidget", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SearchTreeTab), QCoreApplication::translate("TreeWidget", "\320\241\321\202\321\200\320\260\320\275\320\270\321\206\320\260", nullptr));
        pushButtonAdd_3->setText(QCoreApplication::translate("TreeWidget", "Insert", nullptr));
        pushButtonRemove_3->setText(QCoreApplication::translate("TreeWidget", "Delete", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("TreeWidget", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWidget: public Ui_TreeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
