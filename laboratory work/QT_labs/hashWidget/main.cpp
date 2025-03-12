#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget ht(nullptr, 20);


    ht.show();
    return a.exec();
}
