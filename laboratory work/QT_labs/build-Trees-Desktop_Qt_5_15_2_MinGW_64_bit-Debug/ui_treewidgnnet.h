/********************************************************************************
** Form generated from reading UI file 'treewidgnnet.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEWIDGNNET_H
#define UI_TREEWIDGNNET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_treeWidget
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TreeWidget)
    {
        if (TreeWidget->objectName().isEmpty())
            TreeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        TreeWidget->resize(800, 600);
        centralwidget = new QWidget(TreeWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        TreeWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TreeWidget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        TreeWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(TreeWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        TreeWidget->setStatusBar(statusbar);

        retranslateUi(TreeWidget);

        QMetaObject::connectSlotsByName(TreeWidget);
    } // setupUi

    void retranslateUi(QMainWindow *treeWidget)
    {
        treeWidget->setWindowTitle(QCoreApplication::translate("treeWidget", "treeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TreeWidget: public Ui_treeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGNNET_H
