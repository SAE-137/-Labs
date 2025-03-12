QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../../AVLTree/AVLTree.cpp \
    ../../binarySearchTree/binarySearchTree.cpp \
    ../../binaryTree/binaryTree.cpp \
    ../../binaryTree/node.cpp \
    main.cpp \
    treenodegraphicsitem.cpp \
    treewidget.cpp

HEADERS += \
    ../../AVLTree/AVLTree.h \
    ../../binarySearchTree/binarySearchTree.h \
    ../../binaryTree/binaryTree.h \
    ../../binaryTree/node.h \
    treenodegraphicsitem.h \
    treewidget.h

FORMS += \
    ../../../../../../Downloads/TreeWidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
