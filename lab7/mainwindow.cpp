#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <QImage>
#include <QColor>
#include <QColorDialog>
#include <QMessageBox>
#include <QString>

#define DIST 40
#define XOFFSET 350
#define YOFFSET 10
#define SIZE 900

otcekatel_t *otcek = nullptr;
lines_t *head = nullptr;
lines_t *tail = head;
double eps = 1;


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
    ui->lines_color->setAutoFillBackground(true);
    ui->lines_color->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::green);
    ui->result_color->setAutoFillBackground(true);
    ui->result_color->setPalette(Pal);

    color_border = QColor(Qt::black);
    color_lines = QColor(Qt::red);
    color_result = QColor(Qt::green);

    ui->lineEdit_eps->setText(QString("%1").arg(eps));
}

MainWindow::~MainWindow()
{
    delete painter;
    delete scene;
    delete ui;
}

void MainWindow::on_pushButton_clean_clicked()
{
    free_lines(head);
    head = nullptr;
    tail = head;
    free_otcekatel(otcek);
    otcek = nullptr;
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
    if (otcek)
    {
        painter->setPen(color_border);
        painter->drawLine(otcek->xleft, otcek->ylow, otcek->xleft, otcek->yhigh);
        painter->drawLine(otcek->xleft, otcek->ylow, otcek->xright, otcek->ylow);
        painter->drawLine(otcek->xleft, otcek->yhigh, otcek->xright, otcek->yhigh);
        painter->drawLine(otcek->xright, otcek->ylow, otcek->xright, otcek->yhigh);
        ui->draw_label->setPixmap(*scene);
    }
}

void MainWindow::on_pushButton_lines_clicked()
{
    color_lines = QColorDialog::getColor(Qt::red, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_lines);
    ui->lines_color->setAutoFillBackground(true);
    ui->lines_color->setPalette(Pal);
    ui->lines_color->show();
    for (lines_t *line = head; line; line = line->next)
    {
        painter->setPen(color_lines);
        painter->drawLine(line->xbeg, line->ybeg, line->xend, line->yend);
        ui->draw_label->setPixmap(*scene);
    }
}

void MainWindow::on_pushButton_result_clicked()
{
    color_result = QColorDialog::getColor(Qt::green, this);
    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, color_result);
    ui->result_color->setAutoFillBackground(true);
    ui->result_color->setPalette(Pal);
    ui->result_color->show();
}

void MainWindow::on_pushButton_otcekatel_clicked()
{
    bool q1, q2, q3, q4;
    QString strxleft = ui->lineEdit_xleft->text();
    QString strxright = ui->lineEdit_xright->text();
    QString strylow = ui->lineEdit_ylow->text();
    QString stryhigh = ui->lineEdit_yhigh->text();

    int xleft = strxleft.toInt(&q1);
    int xright = strxright.toInt(&q2);
    int ylow = strylow.toInt(&q3);
    int yhigh = stryhigh.toInt(&q4);

    if (q1 && q2 && q3 && q4)
    {
        if (xleft > xright)
        {
            swap(&xleft, &xright);
            ui->lineEdit_xleft->setText(strxright);
            ui->lineEdit_xright->setText(strxleft);
        }
        if (ylow > yhigh)
        {
            swap(&ylow, &yhigh);
            ui->lineEdit_yhigh->setText(strylow);
            ui->lineEdit_ylow->setText(stryhigh);
        }
        if (!otcek)
            otcek = create_otcekatel(xleft, xright, ylow, yhigh);
        else
        {
            otcek->xleft = xleft;
            otcek->xright = xright;
            otcek->ylow = ylow;
            otcek->yhigh = yhigh;
        }
        painter->setPen(color_border);
        painter->drawLine(xleft, ylow, xleft, yhigh);
        painter->drawLine(xleft, ylow, xright, ylow);
        painter->drawLine(xleft, yhigh, xright, yhigh);
        painter->drawLine(xright, ylow, xright, yhigh);
        ui->draw_label->setPixmap(*scene);
    }
    else
        QMessageBox::warning(this, "Ошибка ввода", "Координаты должны быть целочисленными!");
}

void MainWindow::on_pushButton_eps_clicked()
{
    bool q;
    QString streps = ui->lineEdit_eps->text();

    double deps = streps.toDouble(&q);
    if (q)
        eps = deps;
    else
        QMessageBox::warning(this, "Ошибка ввода", "Точность должна быть задана действитедьным значением!");
}

void MainWindow::on_pushButton_addline_clicked()
{
    bool q1, q2, q3, q4;
    QString strxbeg = ui->lineEdit_xbeg->text();
    QString strxend = ui->lineEdit_xend->text();
    QString strybeg = ui->lineEdit_ybeg->text();
    QString stryend = ui->lineEdit_yend->text();

    int xbeg = strxbeg.toInt(&q1);
    int xend = strxend.toInt(&q2);
    int ybeg = strybeg.toInt(&q3);
    int yend = stryend.toInt(&q4);

    if (q1 && q2 && q3 && q4)
    {
        if (ybeg > yend)
        {
            swap(&ybeg, &yend);
            swap(&xbeg, &ybeg);
        }
        tail = add_line(xbeg, ybeg, xend, yend, tail);
        if (!head)
            head = tail;
        painter->setPen(color_lines);
        painter->drawLine(xbeg, ybeg, xend, yend);
        ui->draw_label->setPixmap(*scene);
    }
    else
        QMessageBox::warning(this, "Ошибка ввода", "Координаты должны быть целочисленными!");
}


void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->x();
    int y = event->y();

    if (x >= XOFFSET && x <= XOFFSET + SIZE && y >= YOFFSET && y <= YOFFSET + SIZE)
    {
        x -= XOFFSET;
        y -= YOFFSET;
        if (!otcek)
        {
            otcek = create_otcekatel(x, -1, y, -1);
            painter->setPen(Qt::gray);
            painter->drawLine(x, 0, x, SIZE);
            painter->drawLine(0, y, SIZE, y);
            ui->draw_label->setPixmap(*scene);
            return;
        }

        if (!otcek->full)
        {
            otcek->xright = x;
            otcek->yhigh = y;
            otcek->full = 1;
            if (otcek->xleft > otcek->xright)
                swap(&(otcek->xleft), &(otcek->xright));
            if (otcek->yhigh < otcek->ylow)
                swap(&(otcek->yhigh), &(otcek->ylow));
            scene->fill(QColor(Qt::white));
            painter->setPen(color_border);
            painter->drawLine(otcek->xleft, otcek->ylow, otcek->xleft, otcek->yhigh);
            painter->drawLine(otcek->xleft, otcek->ylow, otcek->xright, otcek->ylow);
            painter->drawLine(otcek->xleft, otcek->yhigh, otcek->xright, otcek->yhigh);
            painter->drawLine(otcek->xright, otcek->ylow, otcek->xright, otcek->yhigh);
            ui->draw_label->setPixmap(*scene);
            return;
        }

        if (!tail || tail->full)
        {
            tail = add_line(x, y, -1, -1, tail);
            if (!head)
                head = tail;
            painter->setPen(color_lines);
            painter->drawPoint(x, y);
            ui->draw_label->setPixmap(*scene);
            return;
        }

        if (event->modifiers() == Qt::ShiftModifier)
        {
            tail->xend = x;
            tail->yend = tail->ybeg;
        }
        else if (event->modifiers() == Qt::ControlModifier)
        {
            tail->yend = y;
            tail->xend = tail->xbeg;
        }
        else
        {
            tail->xend = x;
            tail->yend = y;
        }
        if (tail->ybeg > tail->yend)
        {
            swap(&(tail->xbeg), &(tail->xend));
            swap(&(tail->ybeg), &(tail->yend));
        }
        tail->full = 1;

        painter->setPen(color_lines);
        painter->drawLine(tail->xbeg, tail->ybeg, tail->xend, tail->yend);
        ui->draw_label->setPixmap(*scene);
        }
}

void MainWindow::on_pushButton_cut_clicked()
{
    painter->setPen(color_result);
    for (lines_t *line = head; line; line = line->next)
    {
        lines_t res = cut_line(*line, otcek, eps);
        int x = res.xbeg, x1 = res.xend, y = res.ybeg, y1 = res.yend;
        (void)x;
        (void)x1;
        (void)y;
        (void)y1;
        if (res.full == 1)
        {

            painter->drawLine(res.xbeg, res.ybeg, res.xend, res.yend);
        }
        ui->draw_label->setPixmap(*scene);

    }
}
