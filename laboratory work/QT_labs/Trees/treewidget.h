#pragma once

#include <QWidget>

#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\binaryTree.h"
#include"C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binarySearchTree\binarySearchTree.h"

class QGraphicsScene;

namespace Ui {
class TreeWidget;
}


class TreeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TreeWidget(QWidget *parent = nullptr);
    ~TreeWidget();

    void show();

public slots:
    void addKey(int key);
    void removeKey(int key);
    void changeTreeType(int id);
    void onTabChanged(int index);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QPointF _drawTree(node *root, int leftBorderPos, int rightBorderPos, int yPos);
    void _redrawTree();
    void _updateSceneRect();

    Ui::TreeWidget *ui;
    QGraphicsScene *m_scene = nullptr;
    int m_fontSize = 22;

    enum TreeType { STANDARD_TREE, SEARCH_TREE };
    TreeType m_currentTreeType;

    binaryTree *m_binaryTree = nullptr;
    binarySearchTree *m_binarySearchTree = nullptr;
};
