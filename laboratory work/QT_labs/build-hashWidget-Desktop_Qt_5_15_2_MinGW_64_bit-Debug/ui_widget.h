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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLineEdit *lineEditValue;
    QPushButton *pushButtonRemove;
    QSpinBox *spinBoxKey;
    QPushButton *pushButtonInsert;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(823, 600);
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(-1, -4, 801, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        graphicsView = new QGraphicsView(verticalLayoutWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout->addWidget(graphicsView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        lineEditValue = new QLineEdit(verticalLayoutWidget);
        lineEditValue->setObjectName(QString::fromUtf8("lineEditValue"));

        horizontalLayout->addWidget(lineEditValue);

        pushButtonRemove = new QPushButton(verticalLayoutWidget);
        pushButtonRemove->setObjectName(QString::fromUtf8("pushButtonRemove"));

        horizontalLayout->addWidget(pushButtonRemove);

        spinBoxKey = new QSpinBox(verticalLayoutWidget);
        spinBoxKey->setObjectName(QString::fromUtf8("spinBoxKey"));

        horizontalLayout->addWidget(spinBoxKey);

        pushButtonInsert = new QPushButton(verticalLayoutWidget);
        pushButtonInsert->setObjectName(QString::fromUtf8("pushButtonInsert"));

        horizontalLayout->addWidget(pushButtonInsert);


        verticalLayout->addLayout(horizontalLayout);

        verticalScrollBar = new QScrollBar(Widget);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(800, 0, 20, 591));
        verticalScrollBar->setOrientation(Qt::Vertical);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButtonRemove->setText(QCoreApplication::translate("Widget", "Delete", nullptr));
        pushButtonInsert->setText(QCoreApplication::translate("Widget", "Insert", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
