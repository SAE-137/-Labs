#include "treewidget.h"
#include "ui_treewidget.h"

treeWidget::treeWidget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::treeWidget)
{
    ui->setupUi(this);
}

treeWidget::~treeWidget()
{
    delete ui;
}

