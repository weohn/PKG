#include <QApplication>
#include <QPushButton>
#include <QTableWidget>
#include <QTableView>
#include <QDebug>
#include <QFileDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <cmath>
#include <QMenuBar>
#include <QAction>
#include <QHeaderView>

QTableWidget *_TableWidget;

void info(QStringList fileNames)
{
    int size = _TableWidget->rowCount();
    _TableWidget->setRowCount(size + fileNames.size());

    for (int i=size; i<_TableWidget->rowCount(); i++)
    {
        int index = i - size;
        QImage img;
        img.load(fileNames[index]);
        QTableWidgetItem *item1 = new QTableWidgetItem(QFileInfo(fileNames[index].trimmed()).fileName());
        _TableWidget->setItem(i, 0, item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(QString::number(img.height()));
        _TableWidget->setItem(i, 1, item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(QString::number(img.width()));
        _TableWidget->setItem(i, 2, item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(QString::number(img.bitPlaneCount()));
        _TableWidget->setItem(i, 3, item4);

        QTableWidgetItem *item5 = new QTableWidgetItem(QString::number(std::round(img.dotsPerMeterX()/39.3701)));
        _TableWidget->setItem(i, 4, item5);

        QFile file(fileNames[index]);
        file.open(QIODevice::ReadOnly);
        QTableWidgetItem *item6;

        if (fileNames[index].toLower().endsWith("pcx") || fileNames[index].toLower().endsWith("bmp")) {
            item6 = new QTableWidgetItem("N/A");
        } else {
            double pureSize = img.height()*img.width()*img.bitPlaneCount()/8;
            int fileSize = file.size();
            float ratio = (float) ((int)(pureSize / fileSize * 100 + 0.5));
            item6 = new QTableWidgetItem(QString::number(ratio/100));
        }
        _TableWidget->setItem(i, 5, item6);

        QByteArray data = file.readAll();
        file.close();
    }

    _TableWidget->resizeColumnsToContents();
    _TableWidget->resizeRowsToContents();
}

void files()
{
    QStringList fileNames;
    fileNames = QFileDialog::getOpenFileNames(NULL, "Images", ".", "Images (*.jpg *.gif *.tif *.bmp *.png *.pcx);;All files (*.*)");
    info(fileNames);
}

int main(int argc, char **argv)
{
    QApplication app (argc, argv);

    QWidget window;
    window.setMinimumSize(1000, 800);

    QAction *load = new QAction("Load files");
    QAction *exit = new QAction("Exit");
    QMenuBar *_menu = new QMenuBar(&window);
    QMenu* fileMenu = _menu->addMenu("&File");
    fileMenu->addAction(load);
    fileMenu->addAction(exit);

    _TableWidget = new QTableWidget(&window);
    _TableWidget->setRowCount(argc-1);
    _TableWidget->setColumnCount(6);
    QStringList _TableHeader;
    _TableHeader<<"File name"<<"Height"<<"Width"<<"Bits"<<"DPI"<<"Compression";
    _TableWidget->setHorizontalHeaderLabels(_TableHeader);

    QPushButton *_btn = new QPushButton("Upload files", &window);
    QVBoxLayout *_layout = new QVBoxLayout(&window);
    _layout->addWidget(_menu);
    _layout->addWidget(_btn);
    _layout->addWidget(_TableWidget);

    if (argc > 1) {
        QStringList fileNames;
        for (int i=0; i<=argc; i++) {
            fileNames.append(argv[i]);
        }
        info(fileNames);
    }

    _TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    _TableWidget->setShowGrid(true);
    _TableWidget->setGeometry(10, 70, 550, 500);

    QObject::connect(exit, &QAction::triggered, qApp, &QApplication::quit);
    QObject::connect(load, &QAction::triggered, qApp, files);
    QObject::connect(_btn, &QPushButton::clicked, qApp, files);

    window.show();
    return app.exec();
}
