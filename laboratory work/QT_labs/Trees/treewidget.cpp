#include <QGraphicsScene>

#include "treeNodeGraphicsItem.h"

#include "C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\binaryTree\binaryTree.h"

#include "treewidget.h"
#include "ui_TreeWidget.h"


TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget),
    m_scene(new QGraphicsScene(this)),
    m_binaryTree(new binaryTree),
    m_binarySearchTree(new binarySearchTree),
    m_currentTreeType(STANDARD_TREE)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(m_scene);

    // Подключаем переключение вкладок
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &TreeWidget::onTabChanged);

    // Кнопки для работы с деревьями
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, [this]() {
        addKey(ui->spinBoxKey->value());
    });

    connect(ui->pushButtonRemove, &QPushButton::clicked, this, [this]() {
        removeKey(ui->spinBoxKey->value());
    });
}

TreeWidget::~TreeWidget()
{
    delete ui;
    delete m_scene;
    delete m_binaryTree;
    delete m_binarySearchTree;
}

void TreeWidget::onTabChanged(int index)
{
    if (index == 0) {
        m_currentTreeType = STANDARD_TREE;
    } else {
        m_currentTreeType = SEARCH_TREE;
    }
    _redrawTree();
}

void TreeWidget::show()
{
    QWidget::show();
    _updateSceneRect();
}

void TreeWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    _updateSceneRect();
}

void TreeWidget::addKey(int key)
{
    if (m_currentTreeType == STANDARD_TREE) {
        m_binaryTree->insert(key);
    } else {
        m_binarySearchTree->insert(key);
    }
    _redrawTree();
}

void TreeWidget::removeKey(int key)
{
    if (m_currentTreeType == STANDARD_TREE) {
        m_binaryTree->deleteNode(key);
    } else {
        m_binarySearchTree->deleteNode(key);
    }
    _redrawTree();
}

void TreeWidget::changeTreeType(int id)
{
    if (id == 0) {
        m_currentTreeType = STANDARD_TREE;
    } else {
        m_currentTreeType = SEARCH_TREE;
    }
    _redrawTree();
}

QPointF TreeWidget::_drawTree(node *root, int leftBorderPos, int rightBorderPos, int yPos)
{
    if (root == nullptr) {
        return QPointF();
    }

    int xPos = (leftBorderPos + rightBorderPos) / 2;
    TreeNodeGraphicsItem *item = new TreeNodeGraphicsItem(QString::number(root->getKey()));
    item->setFontSize(m_fontSize);
    m_scene->addItem(item);
    item->setPos(xPos - item->boundingRect().width() / 2, yPos);
    QPointF center = item->pos() + QPointF(item->boundingRect().center());
    QPointF leftCenter = _drawTree(root->getLeft(), leftBorderPos, xPos, yPos + 75);
    QPointF rightCenter = _drawTree(root->getRight(), xPos, rightBorderPos, yPos + 75);

    if (!leftCenter.isNull()) {
        auto *line = m_scene->addLine(QLineF(center, leftCenter), QPen(Qt::red));
        line->setZValue(-1);
    }

    if (!rightCenter.isNull()) {
        auto *line = m_scene->addLine(QLineF(center, rightCenter), QPen(Qt::red));
        line->setZValue(-1);
    }

    return center;
}

void TreeWidget::_redrawTree()
{
    m_scene->clear();
    if (m_currentTreeType == STANDARD_TREE) {
        _drawTree(m_binaryTree->getRoot(), 0, m_scene->width(), 0);
    } else {
        _drawTree(m_binarySearchTree->getRoot(), 0, m_scene->width(), 0);
    }
}

void TreeWidget::_updateSceneRect()
{
    m_scene->setSceneRect(0, 0,
                          qMax(int(m_scene->width()), ui->graphicsView->viewport()->width()),
                          qMax(int(m_scene->height()), ui->graphicsView->viewport()->height())
                          );
    _redrawTree();
}
