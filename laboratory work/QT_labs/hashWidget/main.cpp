#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget ht;
    ht.insert(15, "apple");
    ht.insert(25, "banana");
    ht.insert(35, "cherry");
    ht.insert(12, "apple");
    ht.insert(23, "banana");
    ht.insert(37, "cherry");

    ht.show();
    return a.exec();
}
