#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPainter>
#include <qpainter.h>
#include <QColor>
#include <QColorDialog>
#include <QGraphicsScene>
#define _USE_MATH_DEFINES
#include <math.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->radioButton_dll->setChecked(true);
    scene->setBackgroundBrush(Qt::white);
    pen = new QPen;
    pen->setColor(Qt::black);

    connect(ui->pushButton_drawone, SIGNAL(clicked()), this, SLOT(drawone_clicked()));
    connect(ui->pushButton_clean, SIGNAL(clicked()), this, SLOT(clean_clicked()));
    connect(ui->pushButton_drawmany, SIGNAL(clicked()), this, SLOT(drawmany_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clean_clicked()
{
    scene->clear();
}

void MainWindow::change_colour()
{
    switch (ui->BackgroundColourcomboBox->currentIndex()){
    case 0: scene->setBackgroundBrush(Qt::white);
            break;
    case 1: scene->setBackgroundBrush(Qt::black);
            break;
    case 2: scene->setBackgroundBrush(Qt::yellow);
            break;
    case 3: scene->setBackgroundBrush(Qt::red);
            break;
    case 4: scene->setBackgroundBrush(Qt::blue);
            break;
    case 5: scene->setBackgroundBrush(Qt::green);
            break;
    default: break;
    }
    switch (ui->LinesColourcomboBox->currentIndex()){
    case 0: pen->setColor(Qt::black);
            break;
    case 1: pen->setColor(Qt::white);
            break;
    case 2: pen->setColor(Qt::yellow);
            break;
    case 3: pen->setColor(Qt::red);
            break;
    case 4: pen->setColor(Qt::green);
            break;
    case 5: pen->setColor(Qt::blue);
            break;
    default: break;
    }
}

void MainWindow::drawone_clicked()
{
    bool q1, q2, q3, q4;
    QString xbegstr =  ui->lineEdit_xbeg->text();
    QString ybegstr = ui->lineEdit_ybeg->text();
    QString xendstr = ui->lineEdit_xend->text();
    QString yendstr = ui->lineEdit_yend->text();

    int xbeg = xbegstr.toInt(&q1);
    int ybeg = ybegstr.toInt(&q2);
    int xend = xendstr.toInt(&q3);
    int yend = yendstr.toInt(&q4);

    if (q1 && q2 && q3 && q4)
    {
        change_colour();
        if (ui->radioButton_cda->isChecked())
        {
            printf("cda\n");
            draw_cda(xbeg, ybeg, xend, yend);
        }
        if (ui->radioButton_brint->isChecked())
        {
            printf("brint\n");
            draw_brint(xbeg, ybeg, xend, yend);
        }
        if (ui->radioButton_brfloat->isChecked())
        {
            printf("brfloat\n");
            draw_brfloat(xbeg, ybeg, xend, yend);
        }
        if (ui->radioButton_brstep->isChecked())
        {
            printf("brstep\n");
            draw_brstep(xbeg, ybeg, xend, yend);
        }
        if (ui->radioButton_vu->isChecked())
        {
            printf("vu\n");
            draw_vu(xbeg, ybeg, xend, yend);
        }
        if (ui->radioButton_dll->isChecked())
        {
            printf("dll\n");
            draw_dll(xbeg, ybeg, xend, yend);
        }
    }
    else
    {
        QMessageBox msg;
        msg.setInformativeText("Введены неверные параметры, значения должны быть целыми!");
        msg.setText("Ошибка ввода!");
        msg.setIcon(QMessageBox::Information);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
        if (!q1)
            ui->lineEdit_xbeg->clear();
        if (!q2)
            ui->lineEdit_ybeg->clear();
        if (!q3)
            ui->lineEdit_xend->clear();
        if (!q4)
            ui->lineEdit_yend->clear();
    }
}

void MainWindow::drawmany_clicked()
{
    bool q1, q2, q3, q4;
    QString xcstr =  ui->lineEdit_xc->text();
    QString ycstr = ui->lineEdit_yc->text();
    QString anglestr = ui->lineEdit_angle->text();
    QString lenstr = ui->lineEdit_len->text();

    int xc = xcstr.toInt(&q1);
    int yc = ycstr.toInt(&q2);
    int angle = anglestr.toInt(&q3);
    int len = lenstr.toInt(&q4);

    if (q1 && q2 && q3 && q4)
    {
        change_colour();
        if (ui->radioButton_cda->isChecked())
        {
            printf("cda\n");
            drawmany(xc, yc, angle, len, draw_cda);
        }
        if (ui->radioButton_brint->isChecked())
        {
            printf("brint\n");
            drawmany(xc, yc, angle, len, draw_brint);
        }
        if (ui->radioButton_brfloat->isChecked())
        {
            printf("brfloat\n");
            drawmany(xc, yc, angle, len, draw_brfloat);
        }
        if (ui->radioButton_brstep->isChecked())
        {
            printf("brstep\n");
            drawmany(xc, yc, angle, len, draw_brstep);
        }
        if (ui->radioButton_vu->isChecked())
        {
            printf("vu\n");
            drawmany(xc, yc, angle, len, draw_vu);
        }
        if (ui->radioButton_dll->isChecked())
        {
            printf("dll\n");
            drawmany(xc, yc, angle, len, draw_dll);
        }
    }
    else
    {
        QMessageBox msg;
        msg.setInformativeText("Введены неверные параметры, значения должны быть целыми!");
        msg.setText("Ошибка ввода!");
        msg.setIcon(QMessageBox::Information);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
        if (!q1)
            ui->lineEdit_xc->clear();
        if (!q2)
            ui->lineEdit_yc->clear();
        if (!q3)
            ui->lineEdit_angle->clear();
        if (!q4)
            ui->lineEdit_len->clear();
    }
}

void MainWindow::draw_cda(int xbeg, int ybeg, int xend, int yend)
{
    int dx = xend - xbeg;
    int dy = yend - ybeg;
    if (dx == 0 && dy == 0)
        scene->addEllipse(xbeg, ybeg, 0.1, 0.1, *pen, QBrush());
    else
    {
        int dltx = abs(dx);
        int dlty = abs(dy);
        int l;
        double sx, sy;
        if (dltx > dlty)
            l = dltx;
        else l = dlty;
        sx = (double) dx / (double) l;
        sy = (double) dy / (double) l;
        double x = xbeg, y = ybeg;
        for (int i = 0; i < l + 1; i++)
        {
            scene->addEllipse(round(x), round(y), 0.1, 0.1, *pen, QBrush());
            x += sx;
            y += sy;
        }

    }
}

int get_sign(int a)
{
    if (a > 0)
        return 1;
    if (a == 0)
        return 0;
    return -1;
}

void MainWindow::draw_brint(int xbeg, int ybeg, int xend, int yend)
{
    int dx = xend - xbeg;
    int dy = yend - ybeg;
    if (dx == 0 && dy == 0)
        scene->addEllipse(xbeg, ybeg, 0.1, 0.1, *pen, QBrush());
    else
    {
        int x = xbeg, y = ybeg;
        int sx = get_sign(dx), sy = get_sign(dy);
        dx = abs(dx);
        dy = abs(dy);
        int obmen;
        if (dx > dy)
            obmen = 0;
        else
        {
            obmen = 1;
            int t = dx;
            dx = dy;
            dy = t;
        }

        int e = 2 * dy - dx;
        for (int i = 0; i < dx + 1; i++)
        {
            scene->addEllipse(x, y, 0.1, 0.1, *pen, QBrush());
            if (e >= 0)
            {
                if (obmen == 0)
                    y += sy;
                else x += sx;
                e -= 2 * dx;
            }
            if (obmen == 0)
                x += sx;
            else y += sy;
            e += 2 * dy;
        }
    }
}

void MainWindow::draw_brfloat(int xbeg, int ybeg, int xend, int yend)
{
    int dx = xend - xbeg;
    int dy = yend - ybeg;
    if (dx == 0 && dy == 0)
        scene->addEllipse(xbeg, ybeg, 0.1, 0.1, *pen, QBrush());
    else
    {
        int x = xbeg, y = ybeg;
        int sx = get_sign(dx), sy = get_sign(dy);
        dx = abs(dx);
        dy = abs(dy);
        int obmen;
        if (dx > dy)
            obmen = 0;
        else
        {
            obmen = 1;
            int t = dx;
            dx = dy;
            dy = t;
        }

        double m = (double) dy / (double) dx;
        double e = m - 0.5;
        for (int i = 0; i < dx + 1; i++)
        {
            scene->addEllipse(x, y, 0.1, 0.1, *pen, QBrush());
            if (e >= 0)
            {
                if (obmen == 0)
                    y += sy;
                else x += sx;
                e -= 1;
            }
            if (obmen == 0)
                x += sx;
            else y += sy;
            e += m;
        }
    }
}

void MainWindow::draw_brstep(int xbeg, int ybeg, int xend, int yend)
{
    int imax = 255;
    QColor color(pen->color());
    int dx = xend - xbeg;
    int dy = yend - ybeg;
    if (dx == 0 && dy == 0)
        scene->addEllipse(xbeg, ybeg, 0.1, 0.1, *pen, QBrush());
    else
    {
        int x = xbeg, y = ybeg;
        int sx = get_sign(dx), sy = get_sign(dy);
        dx = abs(dx);
        dy = abs(dy);
        int obmen;
        if (dx > dy)
            obmen = 0;
        else
        {
            obmen = 1;
            int t = dx;
            dx = dy;
            dy = t;
        }

        double m = (double) dy / (double) dx;
        double e = imax * 0.5;
        m = m * imax;
        double w = imax - m;
        color.setAlphaF(imax/2);
        pen->setColor(color);
        scene->addEllipse(x, y, 0.1, 0.1, *pen, QBrush());
        for (int i = 0; i < dx; i++)
        {
            if (e < w)
            {
                if (!obmen)
                    x += sx;
                else
                    y += sy;
                e += m;
            }
            else
            {
                x += sx;
                y += sy;
                e -= w;
            }
            color.setAlphaF(e / imax);
            pen->setColor(color);
            scene->addEllipse(x, y, 0.1, 0.1, *pen, QBrush());
        }
    }
}

void MainWindow::draw_vu(int xbeg, int ybeg, int xend, int yend)
{
    int imax = 255;
    QColor color(pen->color());

    int dx = abs(xend - xbeg);
    int dy = abs(yend - ybeg);
    if (dx == 0 && dy == 0)
        scene->addEllipse(xbeg, ybeg, 0.1, 0.1, *pen, QBrush());
    else
    {
        double m;
        double y_iter = 0;
        double x_iter = 0;
        if (dy < dx)
        {
            if (xend < xbeg)
            {
                int t = xbeg;
                xbeg = xend;
                xend = t;
                t = ybeg;
                ybeg = yend;
                yend = t;
            }
            m = (double)dy / (double)dx;
            if (yend < ybeg)
                m = -m;
            y_iter = ybeg + m;
            scene->addEllipse(xbeg, ybeg, 0.1, 0.1, *pen, QBrush());
            scene->addEllipse(xend, yend, 0.1, 0.1, *pen, QBrush());
            for (int x = xbeg+ 1; x < xend; x++)
            {
                color.setAlphaF((imax - fabs(y_iter - (int)y_iter) * imax) / imax);
                pen->setColor(color);
                scene->addEllipse(x, (int)y_iter, 0.1, 0.1, *pen, QBrush());
                color.setAlphaF((fabs(y_iter - (int)y_iter) * imax) / imax);
                pen->setColor(color);
                scene->addEllipse(x, (int)y_iter + 1, 0.1, 0.1, *pen, QBrush());
                y_iter += m;
            }
        }
        else
        {
            if (yend < ybeg)
            {
                int t = xbeg;
                xbeg = xend;
                xend = t;
                t = ybeg;
                ybeg = yend;
                yend = t;
            }
            m = (double)dx / (double)dy;
            if (xend < xbeg)
                m = -m;
            x_iter = xbeg + m;
            scene->addEllipse(xbeg, ybeg, 0.1, 0.1, *pen, QBrush());
            scene->addEllipse(xend, yend, 0.1, 0.1, *pen, QBrush());
            for (int y = ybeg + 1; y < yend; y++)
            {
                color.setAlphaF((imax - fabs(x_iter - (int)x_iter) * imax) / imax);
                pen->setColor(color);
                scene->addEllipse((int)x_iter, y, 0.1, 0.1, *pen, QBrush());
                color.setAlphaF((fabs(x_iter - (int)x_iter) * imax) / imax);
                pen->setColor(color);
                scene->addEllipse((int)x_iter + 1, y, 0.1, 0.1, *pen, QBrush());
                x_iter += m;
            }
        }
    }
}

void MainWindow::draw_dll(int xbeg, int ybeg, int xend, int yend)
{
    scene->addLine(xbeg, ybeg, xend, yend, *pen);
}


void MainWindow::drawmany(int xc, int yc, int angle, int len, void (MainWindow::*draw)(int, int, int, int))
{
    int x = xc + len;
    int y = yc;
    double angl = 0;
    double step = (double) angle / 180 * M_PI;
    while (angl <= 2 * M_PI)
    {
        (this->*draw)(xc, yc, x, y);
        x = round(xc + len * cos(angl));
        y = round(yc + len * sin(angl));
        angl += step;
    }
}
