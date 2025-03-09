/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButtonInsert;
    QSpinBox *spinBoxKey;
    QGraphicsView *graphicsView;
    QLineEdit *lineEditValue;
    QPushButton *pushButtonRemove;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        pushButtonInsert = new QPushButton(Widget);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));
        pushButtonInsert->setGeometry(QRect(640, 540, 161, 61));
        spinBoxKey = new QSpinBox(Widget);
        spinBoxKey->setObjectName(QString::fromUtf8("spinBoxKey"));
        spinBoxKey->setGeometry(QRect(480, 538, 161, 61));
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 801, 531));
        lineEditValue = new QLineEdit(Widget);
        lineEditValue->setObjectName(QString::fromUtf8("lineEditValue"));
        lineEditValue->setGeometry(QRect(10, 540, 251, 51));
        pushButtonRemove = new QPushButton(Widget);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));
        pushButtonRemove->setGeometry(QRect(310, 550, 83, 29));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButtonInsert->setText(QCoreApplication::translate("Widget", "Insert", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
