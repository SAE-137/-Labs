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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEditValue;
    QSpinBox *spinBoxKey;
    QPushButton *pushButtonInsert;
    QPushButton *pushButtonRemove;
    QComboBox *comboBox;
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(823, 656);
        horizontalLayoutWidget = new QWidget(Widget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(390, 570, 431, 87));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEditValue = new QLineEdit(horizontalLayoutWidget);
        lineEditValue->setObjectName(QString::fromUtf8("lineEditValue"));

        horizontalLayout->addWidget(lineEditValue);

        spinBoxKey = new QSpinBox(horizontalLayoutWidget);
        spinBoxKey->setObjectName(QString::fromUtf8("spinBoxKey"));

        horizontalLayout->addWidget(spinBoxKey);

        pushButtonInsert = new QPushButton(horizontalLayoutWidget);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));

        horizontalLayout->addWidget(pushButtonInsert);

        pushButtonRemove = new QPushButton(horizontalLayoutWidget);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);

        comboBox = new QComboBox(Widget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(620, 0, 201, 28));
        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(-3, -6, 831, 661));
        graphicsView->raise();
        horizontalLayoutWidget->raise();
        comboBox->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButtonInsert->setText(QCoreApplication::translate("Widget", "Insert", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("Widget", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
