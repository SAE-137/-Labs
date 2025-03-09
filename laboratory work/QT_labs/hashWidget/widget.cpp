#include "widget.h"
#include "ui_widget.h"

#include <QGraphicsScene>

#include "graphicsitem.h"

#include"C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\Hash\hashTable.h"


#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsScene>
#include <QGraphicsLineItem>


Widget::Widget(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::Widget),
    m_table(new hashTable(10)),
    m_scene(new QGraphicsScene(this))
{
    ui->setupUi(this);
    ui->graphicsView->setScene(m_scene);

    connect(ui->pushButtonInsert, &QPushButton::clicked, this, [this]() {
        int key = ui->spinBoxKey->value();
        QString value = ui->lineEditValue->text();
        insert(key, value);
    });

    connect(ui->pushButtonRemove, &QPushButton::clicked, this, [this]() {
        removeKey(ui->spinBoxKey->value());
    });
}

Widget::~Widget()
{
    delete ui;
    delete m_table;
}

void Widget::show()
{
    QWidget::show();
    _updateSceneRect();
}

void Widget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    _updateSceneRect();
}

void Widget::insert(int key, const QString &value)
{
    m_table->insert(key, value.toStdString());
    _redrawHashTable();
}

void Widget::removeKey(int key)
{
    m_table->remove(key);
    _redrawHashTable();
}

QPointF Widget::_drawHashTable()
{
    const int bucketWidth = 100;  // Ширина корзины
    const int bucketHeight = 50;  // Высота корзины
    const int spacing = 20;       // Отступ между корзинами и элементами
    const int startX = 50;        // Начальная позиция по X
    const int startY = 50;        // Начальная позиция по Y

    for (int i = 0; i < m_table->getSize(); ++i) {
        int xPos = startX; // Корзины располагаются вертикально, поэтому xPos не меняется
        int yPos = startY + i * (bucketHeight + spacing); // Сдвигаем корзины вниз

        // Отрисовка корзины
        QGraphicsRectItem *bucketRect = m_scene->addRect(xPos, yPos, bucketWidth, bucketHeight, QPen(Qt::black));
        QGraphicsTextItem *bucketText = m_scene->addText(QString("Bucket %1").arg(i));
        bucketText->setPos(xPos + 10, yPos + 10);

        // Отрисовка элементов корзины (горизонтально)
        node *current = m_table->getBucket(i);
        xPos += bucketWidth + spacing; // Сдвигаемся вправо для отрисовки элементов

        while (current != nullptr) {
            // Создаем элемент для отрисовки узла
            graphicsItem *item = new graphicsItem(
                QString("Key: %1\nValue: %2").arg(current->getKey()).arg(QString::fromStdString(current->getValue())));
            item->setFontSize(m_fontSize);
            m_scene->addItem(item);
            item->setPos(xPos, yPos); // Элементы располагаются горизонтально
            xPos += item->boundingRect().width() + spacing; // Сдвигаемся вправо для следующего элемента

            current = current->getNext(); // Переходим к следующему узлу
        }
    }

    return QPointF();
}

void Widget::_redrawHashTable()
{
    m_scene->clear();
    _drawHashTable();
}

void Widget::_updateSceneRect()
{
    m_scene->setSceneRect(0, 0,
                          qMax(int(m_scene->width()), ui->graphicsView->viewport()->width()),
                          qMax(int(m_scene->height()), ui->graphicsView->viewport()->height()));
    _redrawHashTable();
}
