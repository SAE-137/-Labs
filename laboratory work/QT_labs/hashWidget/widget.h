
#pragma once

#include <QWidget>
#include"C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\Hash\hashTable.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class QGraphicsScene;


class Widget : public QWidget {
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr, int size = 1);
    ~Widget();

    void show();
    void insert(int key, const QString &value);
    void removeKey(int key);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::Widget *ui;
    hashTable *m_table;
    QGraphicsScene *m_scene;
    int m_fontSize = 14;

    void _redrawHashTable();
    void _updateSceneRect();
    QPointF _drawHashTable();
};


