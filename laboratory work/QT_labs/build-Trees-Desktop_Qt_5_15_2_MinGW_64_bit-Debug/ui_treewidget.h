/********************************************************************************
** Form generated from reading UI file 'treewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEWIDGET_H
#define UI_TREEWIDGET_H

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

    void setupUi(QMainWindow *treeWidget)
    {
        if (treeWidget->objectName().isEmpty())
            treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->resize(800, 600);
        centralwidget = new QWidget(treeWidget);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeWidget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(treeWidget);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        treeWidget->setMenuBar(menubar);
        statusbar = new QStatusBar(treeWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        treeWidget->setStatusBar(statusbar);

        retranslateUi(treeWidget);

        QMetaObject::connectSlotsByName(treeWidget);
    } // setupUi

    void retranslateUi(QMainWindow *treeWidget)
    {
        treeWidget->setWindowTitle(QCoreApplication::translate("treeWidget", "treeWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class treeWidget: public Ui_treeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWIDGET_H
