#include <QtMath>
#include <QPainter>

#include "graphicsitem.h"


graphicsItem::graphicsItem(const QString &text, QGraphicsItem *next)
    : QGraphicsSimpleTextItem(text, next)
{}

int graphicsItem::fontSize() const
{
    return font().pointSize();
}

QColor graphicsItem::textColor() const
{
    return m_textColor;
}

QColor graphicsItem::borderColor() const
{
    return m_borderColor;
}

QColor graphicsItem::fillColor() const
{
    return m_fillColor;
}

void graphicsItem::setFontSize(int size)
{
    QFont font = this->font();
    font.setPointSize(size);
    this->setFont(font);
}

void graphicsItem::setTextColor(const QColor &color)
{
    m_textColor = color;
    update();
}

void graphicsItem::setBorderColor(const QColor &color)
{
    m_borderColor = color;
    update();
}

void graphicsItem::setFillColor(const QColor &color)
{
    m_fillColor = color;
    update();
}

QRectF graphicsItem::boundingRect() const
{
    QRectF rect = QGraphicsSimpleTextItem::boundingRect();

    return rect;
}

void graphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);


    painter->setBrush(QBrush(m_fillColor));
    painter->setPen(QPen(Qt::black));


    painter->drawRect(boundingRect());


    QFont font = this->font();
    font.setPointSize(8);
    font.setWeight(QFont::Normal);
    painter->setFont(font);


    painter->setPen(QPen(m_textColor));


    QRectF textRect = boundingRect();
    textRect.adjust(3, 3, -3, -3);


    painter->drawText(textRect, Qt::AlignCenter, text());
}
