#include <QGraphicsScene>

#include <iostream>

#include "qdebug.h"
#include "treeNodeGraphicsItem.h"

#include "treewidget.h"
#include "ui_treewidget.h"


TreeWidget::TreeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TreeWidget),
    m_scene(new QGraphicsScene(this)),
    m_currentTreeType(STANDARD_TREE)
{
    m_trees.append(new binaryTree);
    m_trees.append(new binarySearchTree);
    m_trees.append(new AVLTree);

    ui->setupUi(this);
    ui->graphicsView->setScene(m_scene);
    for (int i = 1; i < TreeType::COUNT; ++i)
    {

    }

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &TreeWidget::onTabChanged);

    // удаление
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, [this]() {
        QString stringKeys = ui->lineEdit_randomKeys->text();
        if (stringKeys.isEmpty())
        {
            addKey(ui->spinBoxKey->value());
        }
        else
        {
            for (QString key : stringKeys.split(' ', Qt::SkipEmptyParts))
            {
                addKey(key.toInt());
            }
        }
    });

    //Добавлене
    connect(ui->pushButtonRemove, &QPushButton::clicked, this, [this]() {
        QString stringKeys = ui->lineEdit_randomKeys->text();
        if (stringKeys.isEmpty())
        {
            removeKey(ui->spinBoxKey->value());
        }
        else
        {
            for (const QString &key : stringKeys.split(' ', Qt::SkipEmptyParts))
            {
                removeKey(key.toInt());
            }
        }
    });

    connect(ui->pushButton_randomize, &QPushButton::clicked, this, [this]() {
        QString stringKeys;
        QVector<int> keys(ui->spinBox_max->value() - ui->spinBox_min->value() + 1);
        for (int i = 0; i < keys.size(); ++i)
        {
            keys[i] = ui->spinBox_min->value() + i;
        }
        for (int i = 0; !keys.isEmpty() && i < ui->spinBox_count->value(); ++i)
        {
            int keyIndex = rand() % keys.size();
            stringKeys += QString::number(keys[keyIndex]) + ' ';
            keys.removeAt(keyIndex);
        }
        ui->lineEdit_randomKeys->setText(stringKeys);
    });

    _setTreeType(ui->tabWidget->currentIndex());
}

TreeWidget::~TreeWidget()
{
    delete ui;
    delete m_scene;
    qDeleteAll(m_trees);
}

void TreeWidget::onTabChanged(int index)
{
    _setTreeType(index);
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

static void debug(node* root, int space = 0, int indent = 4) {
    if (root == nullptr) return;

    space += indent;
    debug(root->getRight(), space);
    QString spaces(space - indent, ' ');
    qDebug().noquote() << spaces << root->getKey();
    debug(root->getLeft(), space);
}

void TreeWidget::addKey(int key)
{
    _currentTree()->insert(key);
    switch (m_currentTreeType)
    {
        case STANDARD_TREE:
            qDebug() << "Inserting key into BT:" << key;
            break;
        case SEARCH_TREE:
            qDebug() << "Inserting key into BST:" << key;
            break;
        case AVL_TREE:
            qDebug() << "Inserting key into AVL:" << key;
            break;
        default:
            break;

    }
//    debug(_currentTree()->getRoot());
    _redrawTree();
}


void TreeWidget::removeKey(int key)
{
    _currentTree()->deleteNode(key);
    _redrawTree();
}

void TreeWidget::_setTreeType(int index)
{
    m_currentTreeType = static_cast<TreeType>(index);
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
    _drawTree(_currentTree()->getRoot(), 0, m_scene->width(), 0);
}


void TreeWidget::_updateSceneRect()
{

    m_scene->setSceneRect(0, 0,
                          qMax(int(m_scene->width()), ui->graphicsView->viewport()->width()),
                          qMax(int(m_scene->height()), ui->graphicsView->viewport()->height())
                          );
    _redrawTree();
}


binaryTree* TreeWidget::_currentTree()
{
    return m_trees[m_currentTreeType];
}
