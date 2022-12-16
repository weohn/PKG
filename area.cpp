#include "area.h"
#include <QPainter>
#include <QPainterPath>
#include <QMessageBox>

Line::Line(const QPointF& p1, const QPointF& p2, const QColor& color){
    _p1 = p1;
    _p2 = p2;
    _color = color;
}

qreal Line::x1() const{
    return _p1.x();
}

qreal Line::x2() const{
    return _p2.x();
}

qreal Line::y1() const{
    return _p1.y();
}

qreal Line::y2() const{
    return _p2.y();
}
QPointF Line::p1() const{
    return _p1;
}
QPointF Line::p2() const{
    return _p2;
}
QColor Line::color() const{
    return _color;
}

PolygonData::PolygonData(const std::vector<QPointF>& points, const QColor& color){
    _points = points;
    _color = color;
}
QColor PolygonData::getColor() const{
    return _color;
}
std::vector<QPointF> PolygonData::getPoints() const{
    return _points;
}
Area::Area(QWidget *parent, Mode _mode):QWidget(parent){
    u = std::min(width(), height()) / 20;
    mode = _mode;
}
QPointF Area::Adjust(const QPointF& p){
    return QPointF(zx + p.x() * u, zy - p.y() * u);
}
void Area::drawBox(QPainter& p){
    int h = height() - 2 * box_offset;
    int w = width() - 2 * box_offset;
    QPen boxPen(boxColor);
    boxPen.setWidth(box_width);
    p.setPen(boxPen);
    p.drawRect(box_offset, box_offset, w, h);
}
void Area::drawGrid(QPainter& p){
    QPen gridPen(gridColor);
    gridPen.setWidth(grid_line_width);
    p.setPen(gridPen);
    int i = 0;
    while(zx + i * u <= width() - box_offset)
    {
        i++;
        p.drawLine(zx + i * u, box_offset, zx + i * u, height() - box_offset);
        p.drawLine(zx - i * u, box_offset, zx - i * u, height() - box_offset);
    }
    i = 0;
    while(zy + i * u < height())
    {
        i++;
        p.drawLine(box_offset, zy + i * u, width() - box_offset, zy + i * u);
        p.drawLine(box_offset, zy - i * u, width() - box_offset, zy - i * u);
    }
}
void Area::drawAxis(QPainter& p){
    QPen axisPen(axisColor);
    axisPen.setWidth(axis_width);
    p.setPen(axisPen);
    p.drawLine(box_offset, zy, width() - box_offset, zy);
    p.drawLine(zx, box_offset, zx, height() - box_offset);
}
void Area::drawTicks(QPainter& p){
    QPen ticksPen(axisColor);
    ticksPen.setWidth(axis_width);
    p.setPen(ticksPen);
    QFont font = p.font();
    font.setPixelSize(12);
    p.setFont(font);
    int i = 0;
    int alignFlags = Qt::AlignRight | Qt::AlignTop;
    p.drawText(QRect{zx  - u + pixel_width, zy + pixel_width, u - pixel_width, u - pixel_width}, alignFlags, QString::number(0));
    while(zx + (i + 2) * u < width())
    {
        i++;
        p.drawLine(zx + i * u, zy + tick_length, zx + i * u, zy - tick_length);
        p.drawLine(zx - i * u, zy + tick_length, zx - i * u, zy - tick_length);
        if (zx + (i + 1) * u < width())
            p.drawText(QRect{zx + (i - 1) * u + pixel_width, zy + pixel_width, u - pixel_width, u - pixel_width}, alignFlags, QString::number(i));
        p.drawText(QRect{zx - (i + 1) * u + pixel_width, zy + pixel_width, u - pixel_width, u - pixel_width}, alignFlags, QString::number(-i));
    }
    i = 0;
    while(zy + (i + 2) * u < height())
    {
        i++;
        p.drawLine(zx - tick_length, zy + i * u, zx + tick_length, zy + i * u);
        p.drawLine(zx - tick_length, zy - i * u, zx + tick_length, zy - i * u);
        if (zy - (i + 1) * u > 0)
            p.drawText(QRect{zx  - u + pixel_width, zy - (i) * u +  pixel_width, u - pixel_width, u - pixel_width}, alignFlags, QString::number(i));
        p.drawText(QRect{zx - u + pixel_width, zy + (i) * u + pixel_width, u - pixel_width, u - pixel_width}, alignFlags, QString::number(-i));
    }
}
void Area::drawArrows(QPainter& p){
    QPen arrowsPen(axisColor);
    arrowsPen.setWidth((axis_width));
    p.setBrush(QBrush(axisColor));
    p.setRenderHint(QPainter::RenderHint::Antialiasing);
    QPainterPath px;
    px.moveTo(width() - u - 1, zy + 2 * tick_length);
    px.lineTo(width() - u - 1, zy - 2 * tick_length);
    px.lineTo(width() - 1, zy);
    px.lineTo(width() - u - 1, zy + 2 * tick_length);
    p.drawPath(px);
    p.drawText(QRect{width() - u / 2 - 1, zy + u / 2, u, u}, "X");
    QPainterPath py;
    py.moveTo(zx + 2 * tick_length, u + 1);
    py.lineTo(zx - 2 * tick_length, u + 1);
    py.lineTo(zx, 1);
    py.lineTo(zx + 2 * tick_length, u + 1);
    p.drawPath(py);
    p.drawText(QRect{zx + u / 2, u / 2, u, u}, "Y");
}
void Area::drawClippingWindow(QPainter& p){
    p.setPen(QPen(clippingWindowColor, line_width));
    p.setBrush(Qt::NoBrush);
    p.drawRect(QRectF{Adjust(clippingWindowp1), Adjust(clippingWindowp2)});
}
void Area::drawLineSegments(QPainter& p){
    if (segments.empty())
    {
        QMessageBox::warning(nullptr, "Ошибка", "Нет ни одного отрезка");
        return;
    }
    for (const auto& segmentData : segments)
    {
        p.setPen(QPen(segmentData.color(), line_width));
        p.drawLine(Adjust(segmentData.p1()), Adjust(segmentData.p2()));
    }
}
void Area::drawPolygons(QPainter& p){
    if (polygons.empty())
    {
        QMessageBox::warning(nullptr, "Ошибка", "Нет многоугольников");
        return;
    }
    p.setPen(QPen(polygonBorderColor, line_width));
    for (const auto& polygon : polygons)
    {
        std::vector<QPointF> polygonData = polygon.getPoints();
        p.setBrush(polygon.getColor());
        if (polygonData.empty())
        {
            QMessageBox::warning(nullptr, "Ошибка", "Нет многоугольников");
            return;
        }
        QPainterPath path;
        path.moveTo(Adjust(polygonData[0]));
        for (size_t i = 1; i < polygonData.size(); ++i)
        {
            path.lineTo(Adjust(polygonData[i]));
        }
        path.lineTo(Adjust(polygonData[0]));
        p.drawPath(path);
    }
}
void Area::AddLineSegment(const Line& data){
    segments.push_back(data);
}
void Area::AddPolygon(const std::vector<QPointF>& points, const QColor& fillingColor){
    polygons.push_back(PolygonData(points, fillingColor));
}
void Area::SetPolygonBorderColor(const QColor& color){
    polygonBorderColor = color;
}
void Area::SetClippingWindow(const QPoint& p1, const QPoint& p2){
    clippingWindowp1 = QPoint(std::min(p1.x(), p2.x()), std::max(p1.y(), p2.y()));
    clippingWindowp2 = QPoint(std::max(p1.x(), p2.x()), std::min(p1.y(), p2.y()));
}
QPoint Area::getClippingWindowP1() const{
    return clippingWindowp1;
}
QPoint Area::getClippingWindowP2() const{
    return clippingWindowp2;
}
void Area::ChangeMode(Mode newMode){
    mode = newMode;
}
void Area::Clear(){
    segments.clear();
    polygons.clear();
}
void Area::paintEvent(QPaintEvent*){
    zx = width() / 2;
    zy = height() / 2;
    QPainter pt(this);
    drawBox(pt);
    drawAxis(pt);
    drawTicks(pt);
    drawArrows(pt);
    drawGrid(pt);
    switch(mode)
    {
        case Mode::Segments:
            drawClippingWindow(pt);
            drawLineSegments(pt);
            break;
        case Mode::Polygons:
            drawPolygons(pt);
            drawClippingWindow(pt);
            break;
        case Mode::None:
            break;
    }
}
int Area::getUnit() const{
    return u;
}
void Area::setUnit(int nu){
      u = nu;
}
