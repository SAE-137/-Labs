#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class treeWidget; }
QT_END_NAMESPACE

class treeWidget : public QMainWindow
{
    Q_OBJECT

public:
    treeWidget(QWidget *parent = nullptr);
    ~treeWidget();

private:
    Ui::treeWidget *ui;
};
#endif // TREEWIDGET_H
