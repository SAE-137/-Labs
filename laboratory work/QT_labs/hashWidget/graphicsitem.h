

#include <QGraphicsSimpleTextItem>

class graphicsItem : public QGraphicsSimpleTextItem
{
public:
    explicit graphicsItem(const QString &text = "", QGraphicsItem *next = nullptr);

    int fontSize() const;
    QColor textColor() const;
    QColor borderColor() const;
    QColor fillColor() const;

    void setFontSize(int size);
    void setTextColor(const QColor &color);
    void setBorderColor(const QColor &color);
    void setFillColor(const QColor &color);

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
    QColor m_textColor = Qt::black;
    QColor m_borderColor = Qt::black;
    QColor m_fillColor = Qt::white;
};


