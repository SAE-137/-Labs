#include "widget.h"
#include "ui_widget.h"



#include "graphicsitem.h"

#include"C:\Users\admin\Desktop\Algorithms\-Labs\laboratory work\Hash\hashTable.h"
#include<QDebug>

#include "widget.h"
#include "ui_widget.h"
#include <QScrollBar>
#include <QGraphicsScene>
#include <QGraphicsLineItem>
#include<QMessageBox>


Widget::Widget(QWidget *parent, int size)
    : QWidget(parent),
    ui(new Ui::Widget),
    m_table(new hashTable(size)), ///
    m_scene(new QGraphicsScene(this)),
    m_size(size)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(m_scene);
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->graphicsView->setTransform(QTransform());

    connect(ui->pushButtonInsert, &QPushButton::clicked, this, [this]() {
        QString values = ui->lineEditValue->text();
        QString keys = ui->lineEditKeys->text();

        QStringList valueList = values.split(' ', Qt::SkipEmptyParts);
        QStringList keyList = keys.split(' ', Qt::SkipEmptyParts);


        if (valueList.size() != keyList.size()) {
            QMessageBox::warning(this, "Ошибка", "Количество ключей и значений не совпадает.");
            return;
        }


        for (int i = 0; i < valueList.size(); ++i) {
            int key = keyList[i].toInt();
            QString value = valueList[i];
            insert(key, value);
        }
    });

    connect(ui->pushButtonRemove, &QPushButton::clicked, this, [this]() {
        removeKey(ui->spinBoxKey->value());
        m_size--;
    });

    connect(ui->pushButtonCreate, &QPushButton::clicked, this, [this](){
        int size = ui->spinBoxSize->value();
        if(size > 0){
        m_table->resizeTable(size);
            m_size = size;
        _updateSceneRect();
        }
    });

    connect(ui->pushButtonRand, &QPushButton::clicked, this, [this]() {
        QString stringWords;
        QString stringKeys;
        QSet<int> usedKeys;
        int min = ui->spinBoxMin->value();
        int max = ui->spinBoxMax->value();
        m_size += ui->spinBoxAmount->value();
        for (int i = 0; i < ui->spinBoxAmount->value(); ++i) {

            int key;
            do {
                key = min + rand() % (max - min + 1);
            } while (usedKeys.contains(key));
            usedKeys.insert(key);
            int wordLength = 4 + rand() % 9;
            QString word;
            for (int j = 0; j < wordLength; ++j) {
                char randomChar = 'a' + rand() % 26;
                word += randomChar;
            }
            stringWords += word + ' ';
            stringKeys += QString::number(key) + ' ';
        }
        ui->lineEditValue->setText(stringWords.trimmed());
        ui->lineEditKeys->setText(stringKeys.trimmed());
    });
    ui->comboBox->addItem("Hi(k) = (Hi-1(k) + c * i + d * i * i) % n");


    connect(ui->comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, [this](int index) {
                m_table->setHashFunction(index + 1);
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
    const int bucketWidth = 100;
    const int bucketHeight = 57; // вот так вот
    const int spacing = 20;
    const int startX = 0;
    const int startY = 0;

    for (int i = 0; i < m_table->getSize(); ++i) {
        int xPos = startX;
        int yPos = startY + i * (bucketHeight + spacing);


        QGraphicsRectItem *bucketRect = m_scene->addRect(xPos, yPos, bucketWidth, bucketHeight, QPen(Qt::black));
        QGraphicsTextItem *bucketText = m_scene->addText(QString("Bucket %1").arg(i));

        qreal textWidth = bucketText->boundingRect().width();
        qreal textHeight = bucketText->boundingRect().height();

        qreal textX = xPos + (bucketWidth - textWidth) / 2;
        qreal textY = yPos + (bucketHeight - textHeight) / 2;

        bucketText->setPos(textX, textY);


        node *current = m_table->getBucket(i);
        xPos += bucketWidth + spacing;

        while (current != nullptr) {

            graphicsItem *item = new graphicsItem(
                QString("Key: %1\nValue: %2").arg(current->getKey()).arg(QString::fromStdString(current->getValue())));
            item->setFontSize(m_fontSize);
            m_scene->addItem(item);
            item->setPos(xPos, yPos);
            xPos += item->boundingRect().width() + spacing;

            current = current->getNext();
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
    // Устанавливаем размер сцены
    int sceneWidth = qMax(int(m_scene->width()), ui->graphicsView->viewport()->width());
    int sceneHeight = qMax(int(m_scene->height()), ui->graphicsView->viewport()->height());

    // Добавляем дополнительный отступ (например, 20 пикселей)
    int padding = 72 * m_size;
    m_scene->setSceneRect(0, 0, sceneWidth + padding, sceneHeight + padding);

    // Перерисовываем хэш-таблицу (если это необходимо)
    _redrawHashTable();
}




