#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPainter>
#include <qpainter.h>
#include <QColor>
#include <QColorDialog>
#include <QLabel>
#define _USE_MATH_DEFINES
#include <math.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QPixmap(710, 710);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
    painter->setPen(Qt::black);
    ui->radioButton_dll->setChecked(true);
    ui->draw_label->setAutoFillBackground(true);

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
    ui->draw_label->setStyleSheet("QLabel { background-color : white; }");
    delete painter;
    delete scene;
    scene = new QPixmap(710, 710);
    scene->fill(QColor("transparent"));
    painter = new QPainter(scene);
    painter->setPen(Qt::black);
    ui->draw_label->setPixmap(*scene);
}


void MainWindow::change_colour()
{
    switch (ui->BackgroundColourcomboBox->currentIndex()){
    case 1:
        ui->draw_label->setStyleSheet("QLabel { background-color : black; }");
        break;
    case 0:
        ui->draw_label->setStyleSheet("QLabel { background-color : white; }");
        break;
    case 3:
        ui->draw_label->setStyleSheet("QLabel { background-color : red; }");
        break;
    case 5:
        ui->draw_label->setStyleSheet("QLabel { background-color : green; }");
        break;
    case 2:
        ui->draw_label->setStyleSheet("QLabel { background-color : yellow; }");
        break;
    case 4:
        ui->draw_label->setStyleSheet("QLabel { background-color : blue; }");
        break;
    default:
        break;
    }
//    ui->draw_label->show();
    switch (ui->LinesColourcomboBox->currentIndex()){
    case 0:
        painter->setPen(QColor(Qt::black));
        break;
    case 1:
        painter->setPen(QColor(Qt::white));
        break;
    case 2:
        painter->setPen(QColor(Qt::yellow));
        break;
    case 3:
        painter->setPen(QColor(Qt::red));
        break;
    case 4:
        painter->setPen(QColor(Qt::green));
        break;
    case 5:
        painter->setPen(QColor(Qt::blue));
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
        ui->draw_label->setPixmap(*scene);
    }
    else
    {
        QMessageBox msg;
        msg.setInformativeText("Введены неверные параметры, значения должны быть целыми!");
        msg.setText("Ошибка ввода!");
        msg.setIcon(QMessageBox::Information);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
//        if (!q1)
//            ui->lineEdit_xbeg->clear();
//        if (!q2)
//            ui->lineEdit_ybeg->clear();
//        if (!q3)
//            ui->lineEdit_xend->clear();
//        if (!q4)
//            ui->lineEdit_yend->clear();
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
        ui->draw_label->setPixmap(*scene);
    }
    else
    {
        QMessageBox msg;
        msg.setInformativeText("Введены неверные параметры, значения должны быть целыми!");
        msg.setText("Ошибка ввода!");
        msg.setIcon(QMessageBox::Information);
        msg.setDefaultButton(QMessageBox::Ok);
        msg.exec();
//        if (!q1)
//            ui->lineEdit_xc->clear();
//        if (!q2)
//            ui->lineEdit_yc->clear();
//        if (!q3)
//            ui->lineEdit_angle->clear();
//        if (!q4)
//            ui->lineEdit_len->clear();
    }
}

void MainWindow::draw_cda(int xbeg, int ybeg, int xend, int yend)
{
    int dx = xend - xbeg;
    int dy = yend - ybeg;
    if (dx == 0 && dy == 0)
        painter->drawPoint(xbeg, ybeg);
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
            painter->drawPoint(round(x), round(y));
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
        painter->drawPoint(xbeg, ybeg);
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
            painter->drawPoint(x, y);
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
        painter->drawPoint(xbeg, ybeg);
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
            painter->drawPoint(x, y);
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
    int I = 255;
    QColor color(painter->pen().color());
    int dx = xend - xbeg;
    int dy = yend - ybeg;
    if (dx == 0 && dy == 0)
        painter->drawPoint(xbeg, ybeg);
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
        double e = I * 0.5;
        m = m * I;
        double w = I - m;
        color.setAlphaF(I/2);
        painter->setPen(color);
        painter->drawPoint(x, y);
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
            color.setAlphaF(e / I);
            painter->setPen(color);
            painter->drawPoint(x, y);
        }
    }
}

void MainWindow::draw_vu(int xbeg, int ybeg, int xend, int yend)
{
    int I = 255;
    QColor color(painter->pen().color());

    int dx = abs(xend - xbeg);
    int dy = abs(yend - ybeg);
    if (dx == 0 && dy == 0)
        painter->drawPoint(xbeg, ybeg);
    else
    {
        double m;
        double yi = 0;
        double xi = 0;
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
            yi = ybeg + m;
            painter->drawPoint(xbeg, ybeg);
            painter->drawPoint(xend, yend);
            for (int x = xbeg+ 1; x < xend; x++)
            {
                color.setAlphaF((I - fabs(yi - (int)yi) * I) / I);
                painter->setPen(color);
                painter->drawPoint(x, (int)yi);
                color.setAlphaF((fabs(yi - (int)yi) * I) / I);
                painter->setPen(color);
                painter->drawPoint(x, (int)yi + 1);
                yi += m;
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
            xi = xbeg + m;
            painter->drawPoint(xbeg, ybeg);
            painter->drawPoint(xend, yend);
            for (int y = ybeg + 1; y < yend; y++)
            {
                color.setAlphaF((I - fabs(xi - (int)xi) * I) / I);
                painter->setPen(color);
                painter->drawPoint((int)xi, y);
                color.setAlphaF((fabs(xi - (int)xi) * I) / I);
                painter->setPen(color);
                painter->drawPoint((int)xi + 1, y);
                xi += m;
            }
        }
    }
}

void MainWindow::draw_dll(int xbeg, int ybeg, int xend, int yend)
{
    painter->drawLine(xbeg, ybeg, xend, yend);
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
