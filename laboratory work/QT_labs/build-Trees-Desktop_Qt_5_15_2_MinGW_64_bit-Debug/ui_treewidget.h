#ifndef UI_TREEWIDGET_H
#define UI_TREEWIDGET_H

#include "qapplication.h"
#include <QtCore/QVariant>
#include <QtWidgets/QGraphicsView>
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
    QPushButton *pushButtonRemove;
    QPushButton *pushButtonAdd;
    QSpinBox *spinBoxKey;
    QGraphicsView *graphicsView;
    QWidget *SearchTreeTab;
    QGraphicsView *graphicsView_2;
    QWidget *tab_2;

    void setupUi(QWidget *TreeWidget)
    {
        if (TreeWidget->objectName().isEmpty())
            TreeWidget->setObjectName(QString::fromUtf8("TreeWidget"));
        TreeWidget->resize(543, 470);
        verticalLayout = new QVBoxLayout(TreeWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(TreeWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));


        BinaryTreeTab = new QWidget();
        BinaryTreeTab->setObjectName(QString::fromUtf8("BinaryTreeTab"));
        pushButtonRemove = new QPushButton(BinaryTreeTab);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));
        pushButtonRemove->setGeometry(QRect(440, 370, 81, 41));
        pushButtonAdd = new QPushButton(BinaryTreeTab);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(360, 370, 83, 41));
        spinBoxKey = new QSpinBox(BinaryTreeTab);
        spinBoxKey->setObjectName(QString::fromUtf8("spinBoxKey"));
        spinBoxKey->setGeometry(QRect(240, 370, 121, 41));
        graphicsView = new QGraphicsView(BinaryTreeTab);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-5, -9, 531, 381));
        tabWidget->addTab(BinaryTreeTab, QString("Standard Tree"));


        SearchTreeTab = new QWidget();
        SearchTreeTab->setObjectName(QString::fromUtf8("SearchTreeTab"));
        graphicsView_2 = new QGraphicsView(SearchTreeTab);
        graphicsView_2->setObjectName(QString::fromUtf8("graphicsView_2"));
        graphicsView_2->setGeometry(QRect(-10, -10, 531, 421));
        tabWidget->addTab(SearchTreeTab, QString("Binary Search Tree"));

        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString("Tab 2"));

        verticalLayout->addWidget(tabWidget);

        retranslateUi(TreeWidget);
        tabWidget->setCurrentIndex(1);

        QMetaObject::connectSlotsByName(TreeWidget);
    }

    void retranslateUi(QWidget *TreeWidget)
    {
        TreeWidget->setWindowTitle(QCoreApplication::translate("TreeWidget", "Tree Widget", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("TreeWidget", "Delete", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("TreeWidget", "Insert", nullptr));
    }

};

namespace Ui {
class TreeWidget: public Ui_TreeWidget {};
}

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
