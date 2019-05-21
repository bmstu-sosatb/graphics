#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->radioButton_kan->setChecked(true);
    scene = new QPixmap(710, 710);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
    painter->setPen(Qt::black);
    ui->graphicsView->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
    delete scene;
}

void MainWindow::clean_clicked()
{

}

void MainWindow::change_colour()
{
    switch (ui->BackgroundColourcomboBox->currentIndex()){
    case 0: ui->graphicsView->setStyleSheet("QGraphicsView {backgroung : white; }");
            break;
    case 1: ui->graphicsView->setStyleSheet("QGraphicsView {backgroung : black; }");
            break;
    case 2: ui->graphicsView->setStyleSheet("QGraphicsView {backgroung : yellow; }");
            break;
    case 3: ui->graphicsView->setStyleSheet("QGraphicsView {backgroung : red; }");
            break;
    case 4: ui->graphicsView->setStyleSheet("QGraphicsView {backgroung : blue; }");
            break;
    case 5: ui->graphicsView->setStyleSheet("QGraphicsView {backgroung : green; }");
            break;
    default: break;
    }
    switch (ui->LinesColourcomboBox->currentIndex()){
    case 0: painter->setPen(QColor(Qt::black));
            break;
    case 1: painter->setPen(QColor(Qt::white));
            break;
    case 2: painter->setPen(QColor(Qt::yellow));
            break;
    case 3: painter->setPen(QColor(Qt::red));
            break;
    case 4: painter->setPen(QColor(Qt::blue));
            break;
    case 5: painter->setPen(QColor(Qt::green));
            break;
    default: break;
    }
}
