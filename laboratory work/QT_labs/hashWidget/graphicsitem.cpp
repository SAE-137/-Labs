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
    int padding = 3;
    rect.adjust(-padding, -padding, padding, padding);
    return rect;
}

void graphicsItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF textRect = QGraphicsSimpleTextItem::boundingRect();
    textRect.moveTo((boundingRect().width() - textRect.width()) / 5,
                    (boundingRect().height() - textRect.height()) / 5);
    painter->setBrush(QBrush(m_fillColor));
    painter->drawRect(boundingRect());
    painter->translate(textRect.x(), textRect.y());
    QGraphicsSimpleTextItem::paint(painter, option, widget);
}
