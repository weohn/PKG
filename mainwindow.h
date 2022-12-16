#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "area.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_segments_clicked();
    void on_polygon_clicked();

private:
    Ui::MainWindow *ui;
    Area *area;
    QString segmentsPath = "s.txt";
    QString polygonPath = "p.txt";
    void CohenSutherland();
    void Polygon();
    void ClipAfterLine(std::vector<QPointF>& polygon, int cord, int bit);
    int getCode(qreal x, qreal y) const;
    int getCode(const QPointF& p) const;
};
#endif // MAINWINDOW_H
