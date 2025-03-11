#include <stdlib.h>

#include <QApplication>
#include <QDebug>

#include "TreeWidget.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    TreeWidget widget;
    widget.show();

    return app.exec();
}
