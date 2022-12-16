#ifndef AREA_H
#define AREA_H
#include <QPainter>
#include <QWidget>
#include <vector>

class Line
{
public:
    explicit Line(const QPointF& p1, const QPointF& p2, const QColor& color);
    qreal x1() const;
    qreal x2() const;
    qreal y1() const;
    qreal y2() const;
    QPointF p1() const;
    QPointF p2() const;
    QColor color() const;
private:
    QPointF _p1, _p2;
    QColor _color;
};

class PolygonData
{
public:
    explicit PolygonData(const std::vector<QPointF>& points, const QColor& fillingColor);
    std::vector<QPointF> getPoints() const;
    QColor getColor() const;
private:
    std::vector<QPointF> _points;
    QColor _color;
};

enum class Mode
{
    None,
    Segments,
    Polygons,
};

class Area : public QWidget
{
    Q_OBJECT
public:
    explicit Area(QWidget *parent = nullptr, Mode mode = Mode::None);
    void AddLineSegment(const Line& data);
    QPointF Adjust(const QPointF& p);
    void AddPolygon(const std::vector<QPointF>& points, const QColor& fillingColor);
    void SetPolygonBorderColor(const QColor& color);
    void SetClippingWindow(const QPoint& p1, const QPoint& p2);
    void ChangeMode(Mode newMode);
    void Clear();
    void setUnit(int nu);
    int getUnit() const;
    QPoint getClippingWindowP1() const;
    QPoint getClippingWindowP2() const;
private:
    int u;
    int tick_length = 4;
    int grid_line_width = 1;
    int axis_width = 2;
    int box_offset = 1;
    int box_width = 1;
    int pixel_width = 1;
    int line_width = 3;
    int zx = 0;
    int zy = 0;
    Mode mode = Mode::None;
    std::vector<Line> segments;
    std::vector<PolygonData> polygons;
    QColor polygonBorderColor = Qt::black;
    QColor clippingWindowColor = Qt::magenta;
    QColor axisColor = Qt::black;
    QColor gridColor = Qt::gray;
    QColor boxColor = Qt::gray;
    QPoint clippingWindowp1;
    QPoint clippingWindowp2;
    void inline drawBox(QPainter(&p));
    void inline drawGrid(QPainter& p);
    void inline drawAxis(QPainter& p);
    void inline drawTicks(QPainter& p);
    void inline drawArrows(QPainter& p);
    void inline drawLineSegments(QPainter& p);
    void inline drawPolygons(QPainter& p);
    void inline drawClippingWindow(QPainter& p);
    void paintEvent(QPaintEvent* event) override;
};

#endif
