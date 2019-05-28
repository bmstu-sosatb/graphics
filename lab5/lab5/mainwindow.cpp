#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proc.h"

#include <QColor>
#include <QColorDialog>
#include <QMessageBox>

#define DIST 20
#define XOFFSET 230
#define YOFFSET 10
#define SIZE 710

extern point_t *head;
extern point_t *tail;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setPalette(color_background);
    ui->draw_label->setMouseTracking(true);
    this->setMouseTracking(true);
    scene = new QPixmap(SIZE, SIZE);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
    painter->setPen(Qt::black);
    ui->draw_label->setPixmap(*scene);
    painter->setPen(Qt::black);

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);

    ui->border_color->setAutoFillBackground(true);
    ui->border_color->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::red);
    ui->fill_color->setAutoFillBackground(true);
    ui->fill_color->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::white);
    ui->background_color->setAutoFillBackground(true);
    ui->background_color->setPalette(Pal);

    color_background = QColor(Qt::white);
    color_border = QColor(Qt::black);
    color_fill = QColor(Qt::red);
}

MainWindow::~MainWindow()
{
    delete painter;
    delete scene;
    delete ui;
}

void MainWindow::on_pushButton_clean_clicked()
{
    ui->draw_label->setPalette(color_background);
    delete painter;
    delete scene;
    scene = new QPixmap(SIZE, SIZE);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
    painter->setPen(Qt::black);
    ui->draw_label->setPixmap(*scene);
}

void MainWindow::on_pushButton_border_clicked()
{
    color_border = QColorDialog::getColor(Qt::black, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_border);
    ui->border_color->setAutoFillBackground(true);
    ui->border_color->setPalette(Pal);
    ui->border_color->show();
}

void MainWindow::on_pushButton_background_clicked()
{
    color_background = QColorDialog::getColor(Qt::white, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_background);
    ui->background_color->setAutoFillBackground(true);
    ui->background_color->setPalette(Pal);
    ui->background_color->show();
    ui->draw_label->setAutoFillBackground(true);
    ui->draw_label->setPalette(Pal);
    ui->draw_label->show();
}

void MainWindow::on_pushButton_fill_clicked()
{
    color_fill = QColorDialog::getColor(Qt::red, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_fill);
    ui->fill_color->setAutoFillBackground(true);
    ui->fill_color->setPalette(Pal);
    ui->fill_color->show();
}

void MainWindow::on_pushButton_add_clicked()
{
    bool q1, q2;
    QString strx = ui->lineEdit_x->text();
    QString stry = ui->lineEdit_y->text();

    int x = strx.toInt(&q1);
    int y = stry.toInt(&q2);

    if (q1 && q2)
    {
        painter->setPen(color_border);
        if (head != nullptr)
        {
            int xprev = tail->x;
            int yprev = tail->y;
            tail = add_point(x, y, tail);
            painter->drawLine(xprev, yprev, x, y);
        }
        else
        {
            tail = add_point(x, y, tail);
            head = tail;
            painter->drawPoint(x,y);
        }
        ui->draw_label->setPixmap(*scene);
    }
    else
        QMessageBox::warning(this, "Ошибка ввода", "Координаты должны быть целочисленными!");

}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    painter->setPen(color_border);
    int x = event->x();
    int y = event->y();
    int flag = 0;
    if (x >= XOFFSET && x <= XOFFSET + SIZE && y >= YOFFSET && y <= YOFFSET + SIZE)
    {
        x -= XOFFSET;
        y -= YOFFSET;
        if (event->button() == Qt::LeftButton)
        {
            if (event->modifiers() == Qt::ShiftModifier)
            {
                if (tail != nullptr)
                {
                    int xprev = tail->x;
                    tail = add_point(x, tail->y, tail);
                    painter->drawLine(xprev, tail->y, x, tail->y);
                }
                else flag = 1;
            }
            else if (event->modifiers() == Qt::ControlModifier)
            {
                if (tail != nullptr)
                {
                    int yprev = tail->y;
                    tail = add_point(tail->x, y, tail);
                    painter->drawLine(tail->x, yprev, tail->x, y);
                }
                else flag = 1;
            }
            else
            {
                if (tail != nullptr)
                {
                    int xprev = tail->x;
                    int yprev = tail->y;
                    tail = add_point(x, y, tail);
                    painter->drawLine(xprev, yprev, x, y);
                }
                else flag = 1;
            }

            if (flag)
            {
                tail = add_point(x, y, tail);
                head = tail;
                painter->drawPoint(x, y);
            }
        }

        if (event->button() == Qt::RightButton)
        {
            if (head != nullptr && abs(x - head->x) <= DIST && abs(y - head->y) <= DIST)
            {
                painter->drawLine(head->x, head->y, tail->x, tail->y);
                tail = add_point(head->x, head->y, tail);
            }
        }
        ui->draw_label->setPixmap(*scene);
    }
}
