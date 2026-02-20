#pragma once

#include <QWidget>

#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\AVLTree\AVLTree.h"

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
    void onTabChanged(int index);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    void _setTreeType(int index);
    QPointF _drawTree(node *root, int leftBorderPos, int rightBorderPos, int yPos);
    void _redrawTree();
    void _updateSceneRect();
    binaryTree* _currentTree();

    Ui::TreeWidget *ui;
    QGraphicsScene *m_scene = nullptr;
    int m_fontSize = 22;

    enum TreeType
    {
        STANDARD_TREE,
        SEARCH_TREE,
        AVL_TREE,

        COUNT
    };

    TreeType m_currentTreeType;
    QVector<binaryTree*> m_trees;
};
