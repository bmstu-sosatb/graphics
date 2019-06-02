#include "mainwindow.h"
#include "ui_mainwindow.h"
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
int xzatr = -1;
int yzatr = -1;

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
                if (event->modifiers() == Qt::AltModifier)
                {
                    xzatr = x;
                    yzatr = y;
                    ui->lineEdit_xzatr->setText(QString("%1").arg(x));
                    ui->lineEdit_yzatr->setText(QString("%1").arg(y));
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
            painter->drawLine(tail->head->x, tail->head->y, tail->tail->x, tail->tail->y);
            tail->tail = add_point(tail->head->x, tail->head->y, tail->tail);
            ui->textEdit->append(QString("(%1;%2)").arg(tail->head->x).arg(tail->head->y));
            tail->zamknut = 1;
            ui->textEdit->append(QString("--------"));
        }
        ui->draw_label->setPixmap(*scene);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if (xzatr < 0 || yzatr < 0)
        QMessageBox::warning(this, "Ошибка", "Вы не ввели затравочный пиксель!");
    else
    {
        stack_t *top = push(nullptr, xzatr, yzatr);
        bool speed_flag = ui->radioButton_slow->isChecked();
        while (!(stack_is_empty(top)))
        {
            int xz, yz;
            top = pop(top, &xz, &yz);
            int xleft = xz, xright = xz;
            QImage img = scene->toImage();
            QColor color = img.pixelColor(xleft - 1, yz);
            painter->setPen(color_fill);
            painter->drawPoint(xz, yz);
            while (color != color_border)
            {
                xleft--;
                painter->drawPoint(xleft, yz);
                color = img.pixelColor(xleft - 1, yz);
            }
            color = img.pixelColor(xright + 1, yz);
            while (color != color_border)
            {
                xright++;
                painter->drawPoint(xright, yz);
                color = img.pixelColor(xright + 1, yz);
            }

            int y = yz + 1;
            int x = xleft;
            int flag;
            M0:
            if (x <= xright)
            {
                flag = 0;
                M1:
                color = img.pixelColor(x, y);
                if (color != color_border)
                {
                    if (color != color_fill)
                    {
                        if (x <= xright)
                        {
                            flag = 1;
                            x++;
                            goto M1;
                         }
                        else goto M2;
                    }
                    else goto M2;
                }
                else
                {
                    M2:
                    if (flag == 1)
                    {
                        if (x == xright)
                        {
                            color = img.pixelColor(x, y);
                            if (color != color_border)
                            {
                                if (color != color_fill)
                                {
                                    top = push(top, x, y);
                                    goto M4;
                                }
                                else goto M3;
                            }
                            else goto M3;
                        }
                        else
                        {
                            M3:
                            top = push(top, x - 1, y);
                            goto M4;
                        }
                        M4:
                        flag = 0;
                        int xt = x;
                        M5:
                        color = img.pixelColor(x, y);
                        if (color == color_border)
                        {
                            M6:
                            if (x < xright)
                            {
                                x++;
                                goto M5;
                            }
                        }
                        else
                        {
                            if (color == color_fill)
                                goto M6;
                            else
                            {
                                if (x == xt)
                                    x++;
                                else goto M0;
                            }
                        }
                    }
                    else goto M4;
                }
            }
            if (y == yz + 1)
            {
                x = xleft;
                y = yz - 1;
                goto M0;
            }
            ui->draw_label->setPixmap(*scene);
            if (speed_flag)
                repaint();
        }
    }
}

void MainWindow::on_pushButton_addzatr_clicked()
{
    bool q1, q2;
    QString strx = ui->lineEdit_xzatr->text();
    QString stry = ui->lineEdit_yzatr->text();

    int x = strx.toInt(&q1);
    int y = stry.toInt(&q2);

    if (q1 && q2)
    {
        xzatr = x;
        yzatr = y;
    }
    else QMessageBox::warning(this, "Ошибка ввода", "Координаты должны быть целочисленными!");
}
