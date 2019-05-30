#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "proc.h"
#include <windows.h>
#include <QImage>
#include <QColor>
#include <QColorDialog>
#include <QMessageBox>
#include <QString>

#define DIST 20
#define XOFFSET 350
#define YOFFSET 10
#define SIZE 900

extern contur_t *head;
extern contur_t *tail;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->draw_label->setMouseTracking(true);
    this->setMouseTracking(true);
    scene = new QPixmap(SIZE, SIZE);
    scene->fill(QColor("transparent"));
    scene->fill(QColor(Qt::white));
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

    color_border = QColor(Qt::black);
    color_fill = QColor(Qt::red);
    color_background = QColor(Qt::white);
    ui->radioButton_slow->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete painter;
    delete scene;
    delete ui;
}

void MainWindow::on_pushButton_clean_clicked()
{
    ui->textEdit->clear();
    free_conturs(head);
    head = add_contur(nullptr);
    tail = head;
    delete painter;
    delete scene;
    scene = new QPixmap(SIZE, SIZE);
    scene->fill(QColor("transparent"));
    scene->fill(QColor(Qt::white));
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
        if (tail->zamknut)
            tail = add_contur(tail);
        painter->setPen(color_border);
        if (tail->head != nullptr)
        {
            int xprev = tail->tail->x;
            int yprev = tail->tail->y;
            tail->tail = add_point(x, y, tail->tail);
            ui->textEdit->append(QString("(%1;%2)").arg(x).arg(y));
            painter->drawLine(xprev, yprev, x, y);
            if (tail->head->x == x && tail->head->y == y)
            {
                tail->zamknut = 1;
                ui->textEdit->append(QString("--------"));
            }
        }
        else
        {
            tail->tail = add_point(x, y, tail->tail);
            ui->textEdit->append(QString("(%1;%2)").arg(x).arg(y));
            tail->head = tail->tail;
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
        if (tail->zamknut)
            tail = add_contur(tail);
        if (event->button() == Qt::LeftButton)
        {
            if (event->modifiers() == Qt::ShiftModifier)
            {
                if (tail->tail != nullptr)
                {
                    int xprev = tail->tail->x;
                    tail->tail = add_point(x, tail->tail->y, tail->tail);
                    ui->textEdit->append(QString("(%1;%2)").arg(x).arg(y));
                    painter->drawLine(xprev, tail->tail->y, x, tail->tail->y);
                }
                else flag = 1;
            }
            else if (event->modifiers() == Qt::ControlModifier)
            {
                if (tail->tail != nullptr)
                {
                    int yprev = tail->tail->y;
                    tail->tail = add_point(tail->tail->x, y, tail->tail);
                    ui->textEdit->append(QString("(%1;%2)").arg(x).arg(y));
                    painter->drawLine(tail->tail->x, yprev, tail->tail->x, y);
                }
                else flag = 1;
            }
            else
            {
                if (tail->tail != nullptr)
                {
                    int xprev = tail->tail->x;
                    int yprev = tail->tail->y;
                    tail->tail = add_point(x, y, tail->tail);
                    ui->textEdit->append(QString("(%1;%2)").arg(x).arg(y));
                    painter->drawLine(xprev, yprev, x, y);
                }
                else flag = 1;
            }

            if (flag)
            {
                tail->tail = add_point(x, y, tail->tail);
                ui->textEdit->append(QString("(%1;%2)").arg(x).arg(y));
                tail->head = tail->tail;
                painter->drawPoint(x, y);
            }
        }

        if (event->button() == Qt::RightButton)
        {
            if (tail->head != nullptr && abs(x - tail->head->x) <= DIST && abs(y - tail->head->y) <= DIST)
            {
                painter->drawLine(tail->head->x, tail->head->y, tail->tail->x, tail->tail->y);
                tail->tail = add_point(tail->head->x, tail->head->y, tail->tail);
                ui->textEdit->append(QString("(%1;%2)").arg(tail->head->x).arg(tail->head->y));
            }
            tail->zamknut = 1;
            ui->textEdit->append(QString("--------"));
        }
        ui->draw_label->setPixmap(*scene);
    }
}

void MainWindow::on_pushButton_clicked()
{
    int xmin = head->head->x;
    int xmax = head->head->x;
    int ymin = head->head->y;
    int ymax = head->head->y;
    bool flag = ui->radioButton_slow->isChecked();

    for (point_t *ptr = head->head->next; ptr != nullptr; ptr = ptr->next)
    {
        if (ptr->x > xmax)
            xmax = ptr->x;
        if (ptr->x < xmin)
            xmin = ptr->x;
        if (ptr->y > ymax)
            ymax = ptr->y;
        if (ptr->y < ymin)
            ymin = ptr->y;
    }

    int xsep = (xmin + xmax) / 2;

    painter->setPen(Qt::green);
    painter->drawLine(xsep, ymin - 10, xsep, ymax + 10);
    ui->draw_label->setPixmap(*scene);

    for (contur_t *cntr = head; cntr != nullptr; cntr = cntr->next)
    {
        for (point_t *start = cntr->head; start != nullptr; start = start->next)
        {
            point_t *end = start->next ? start->next : cntr->head;
            double k;
            if (end->x - start->x != 0)
                k = (double) (end->y - start->y) / (end->x - start->x);
            else k = 0;
            double b = start->y - k * start->x;
            int ystart = 0, yend = 0;
            if (start->y < end->y)
            {
                ystart = start->y;
                yend = end->y;
            }
            if (start->y > end->y)
            {
                ystart = end->y;
                yend = start->y;
            }
            for (int ycur = ystart; ycur < yend; ycur++)
            {
                QImage img = scene->toImage();
                int xcur;
                if (k != 0)
                    xcur = (ycur - b) /  k;
                else xcur = start->x;
                if (xcur < xsep)
                    for (int xx = xcur; xx < xsep; xx++)
                    {

                        QColor color = img.pixelColor(xx, ycur);
                        if (color == color_background)
                            painter->setPen(color_fill);
                        else
                        {
                            if (color == color_border)
                                painter->setPen(color_border);
                            else
                            {
                                if (color == color_fill)
                                    painter->setPen(color_background);
                                else painter->setPen(color_fill);
                            }
                        }
                        painter->drawPoint(xx, ycur);
                    }

                if (xcur > xsep)
                {
                    for (int xx = xsep + 1; xx <= xcur; xx++)
                    {
                        QColor color = img.pixelColor(xx, ycur);
                        if (color == color_background)
                            painter->setPen(color_fill);
                        else
                        {
                            if (color == color_border)
                                painter->setPen(color_border);
                            else
                            {
                                if (color == color_fill)
                                    painter->setPen(color_background);
                                else painter->setPen(color_fill);
                            }
                        }
                        painter->drawPoint(xx, ycur);
                    }
                }
                ui->draw_label->setPixmap(*scene);
                if (flag)
                    repaint();
            }
        }
    }
}
