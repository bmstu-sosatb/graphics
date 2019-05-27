#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "algs.h"

#include <QMessageBox>
#include <QColor>
#include <QColorDialog>

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
    ui->draw_label->setPixmap(*scene);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete painter;
    delete scene;
}


void MainWindow::change_colour()
{
    switch (ui->BackgroundColourcomboBox->currentIndex()){
    case 0:
        ui->draw_label->setStyleSheet("QLabel { background-color : white; }");
        break;
    case 1:
        ui->draw_label->setStyleSheet("QLabel { background-color : black; }");
        break;
    case 2:
        ui->draw_label->setStyleSheet("QLabel { background-color : yellow; }");
        break;
    case 3:
        ui->draw_label->setStyleSheet("QLabel { background-color : red; }");
        break;
    case 4:
        ui->draw_label->setStyleSheet("QLabel { background-color : blue; }");
        break;
    case 5:
        ui->draw_label->setStyleSheet("QLabel { background-color : green; }");
        break;
    default:
        break;
    }

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
        painter->setPen(QColor(Qt::blue));
        break;
    case 5:
        painter->setPen(QColor(Qt::green));
        break;
    default: break;
    }
}

void MainWindow::on_pushButton_drawonecir_clicked()
{
    bool q1, q2, q3;
    QString strxc = ui->lineEdit_xc1cir->text();
    QString stryc = ui->lineEdit_yc1cir->text();
    QString strr = ui->lineEdit_r->text();

    int xc = strxc.toInt(&q1);
    int yc = stryc.toInt(&q2);
    int r = strr.toInt(&q3);

    if (q1 && q2 && q3)
    {
        if (r >= 0)
        {
            change_colour();
            if (ui->radioButton_kan->isChecked())
            {
                draw_circle_kan(xc, yc, r, *painter);
            }
            if (ui->radioButton_par->isChecked())
            {
                draw_circle_par(xc, yc, r, *painter);
            }
            if (ui->radioButton_br->isChecked())
            {
                draw_circle_br(xc, yc, r, *painter);
            }
            if (ui->radioButton_srt->isChecked())
            {
                draw_circle_srt(xc, yc, r, *painter);
            }
            if (ui->radioButton_dll->isChecked())
            {
                draw_circle_dll(xc, yc, r, *painter);
            }
            ui->draw_label->setPixmap(*scene);
        }
        else
            QMessageBox::warning(this, "Ошибка!", "Радиус не может быть отрицательным!");
    }
    else
        QMessageBox::warning(this, "Ошибка!", "Введены неверные параметры, данные должны быть целыми!");
}

void MainWindow::on_pushButton_drawmanycir_clicked()
{
    bool q1, q2, q3, q4, q5;
    QString strxc = ui->lineEdit_xc2cir->text();
    QString stryc = ui->lineEdit_yc2cir->text();
    QString strrbeg = ui->lineEdit_rbeg->text();
    QString strrend = ui->lineEdit_rend->text();
    QString strstep = ui->lineEdit_stepcir->text();

    int xc = strxc.toInt(&q1);
    int yc = stryc.toInt(&q2);
    int rbeg = strrbeg.toInt(&q3);
    int rend = strrend.toInt(&q4);
    int step = strstep.toInt(&q5);

    if (q1 && q2 && q3 && q4 && q5)
    {
        if (rbeg >= 0 && rbeg <= rend && step > 0)
        {
            change_colour();
            if (ui->radioButton_kan->isChecked())
            {
                draw_many_circle(xc, yc, rbeg, rend, step, *painter, draw_circle_kan);
            }
            if (ui->radioButton_par->isChecked())
            {
                draw_many_circle(xc, yc, rbeg, rend, step, *painter, draw_circle_par);
            }
            if (ui->radioButton_br->isChecked())
            {
                draw_many_circle(xc, yc, rbeg, rend, step, *painter, draw_circle_br);
            }
            if (ui->radioButton_srt->isChecked())
            {
                draw_many_circle(xc, yc, rbeg, rend, step, *painter, draw_circle_srt);
            }
            if (ui->radioButton_dll->isChecked())
            {
                draw_many_circle(xc, yc, rbeg, rend, step, *painter, draw_circle_dll);
            }
            ui->draw_label->setPixmap(*scene);
        }
        else
            if (rbeg <= 0 || rend <=0)
                QMessageBox::warning(this, "Ошибка!", "Радиус не может быть отрицательным!");
            else if (rbeg > rend)
                    QMessageBox::warning(this, "Ошибка!", "R_нач не может быть больше, чем R_конеч!");
                else
                    QMessageBox::warning(this, "Ошибка!", "Шаг должен быть натуральным числом!");

    }
    else
        QMessageBox::warning(this, "Ошибка!", "Введены неверные параметры, данные должны быть целыми!");
}

void MainWindow::on_pushButton_drawoneel_clicked()
{
    bool q1, q2, q3, q4;
    QString strxc = ui->lineEdit_xcel->text();
    QString stryc = ui->lineEdit_ycel->text();
    QString stra = ui->lineEdit_a->text();
    QString strb = ui->lineEdit_b->text();

    int xc = strxc.toInt(&q1);
    int yc = stryc.toInt(&q2);
    int a = stra.toInt(&q3);
    int b = strb.toInt(&q4);

    if (q1 && q2 && q3 && q4)
    {
        if (a >= 0 && b >= 0)
        {
            change_colour();
            if (ui->radioButton_kan->isChecked())
            {
                draw_ellipse_kan(xc, yc, a, b, *painter);
            }
            if (ui->radioButton_par->isChecked())
            {
                draw_ellipse_par(xc, yc, a, b, *painter);
            }
            if (ui->radioButton_br->isChecked())
            {
                draw_ellipse_br(xc, yc, a, b, *painter);
            }
            if (ui->radioButton_srt->isChecked())
            {
                draw_ellipse_srt(xc, yc, a, b, *painter);
            }
            if (ui->radioButton_dll->isChecked())
            {
                draw_ellipse_dll(xc, yc, a, b, *painter);
            }
            ui->draw_label->setPixmap(*scene);
        }
        else
            QMessageBox::warning(this, "Ошибка!", "Значения полуосей a и b не могут быть отрицательными!");
    }
    else
        QMessageBox::warning(this, "Ошибка!", "Введены неверные параметры, данные должны быть целыми!");
}

void MainWindow::on_pushButton_drawmanyel_clicked()
{
    bool q1, q2, q3, q4, q5, q6;
    QString strxc = ui->lineEdit_xc2el->text();
    QString stryc = ui->lineEdit_yc2el->text();
    QString strabeg = ui->lineEdit_abeg->text();
    QString strbbeg = ui->lineEdit_bbeg->text();
    QString strstep = ui->lineEdit_stepel->text();
    QString strn = ui->lineEdit_nel->text();

    int xc = strxc.toInt(&q1);
    int yc = stryc.toInt(&q2);
    int abeg = strabeg.toInt(&q3);
    int bbeg = strbbeg.toInt(&q4);
    int step = strstep.toInt(&q5);
    int n = strn.toInt(&q6);

    if (q1 && q2 && q3 && q4 && q5 && q6)
    {
        if (abeg >= 0 && bbeg >=0 && step > 0 && n >= 0)
        {
            change_colour();
            if (ui->radioButton_kan->isChecked())
            {
                draw_many_ellipse(xc, yc, abeg, bbeg, step, n, *painter, draw_ellipse_kan);
            }
            if (ui->radioButton_par->isChecked())
            {
                draw_many_ellipse(xc, yc, abeg, bbeg, step, n, *painter, draw_ellipse_par);
            }
            if (ui->radioButton_br->isChecked())
            {
                draw_many_ellipse(xc, yc, abeg, bbeg, step, n, *painter, draw_ellipse_br);
            }
            if (ui->radioButton_srt->isChecked())
            {
                draw_many_ellipse(xc, yc, abeg, bbeg, step, n, *painter, draw_ellipse_srt);
            }
            if (ui->radioButton_dll->isChecked())
            {
                draw_many_ellipse(xc, yc, abeg, bbeg, step, n, *painter, draw_ellipse_dll);
            }
            ui->draw_label->setPixmap(*scene);
        }
        else if (abeg < 0 || bbeg < 0)
            QMessageBox::warning(this, "Ошибка!", "Значения полуосей a_нач и b_нач не могут быть отрицательными!");
            else if (step <= 0)
                QMessageBox::warning(this, "Ошибка!", "Шаг должен быть натуральным числом!");
                else QMessageBox::warning(this, "Ошибка!", "Колчество эллипсов не может быть отрицательным!");
    }
    else
        QMessageBox::warning(this, "Ошибка!", "Введены неверные параметры, данные должны быть целыми!");
}

void MainWindow::on_pushButton_clean_clicked()
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
