#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QImage>
#include <QColor>
#include <QColorDialog>
#include <QMessageBox>
#include <QString>

#define DIST 40
#define XOFFSET 350
#define YOFFSET 10
#define SIZE 900

contur_t otcek = {nullptr, nullptr, 0};
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
    ui->draw_label->setPixmap(*scene);
    painter->setPen(QPen(Qt::black, 2));

    QPalette Pal(palette());
    Pal.setColor(QPalette::Background, Qt::black);
    ui->border_color->setAutoFillBackground(true);
    ui->border_color->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::blue);
    ui->lines_color->setAutoFillBackground(true);
    ui->lines_color->setPalette(Pal);

    Pal.setColor(QPalette::Background, Qt::red);
    ui->result_color->setAutoFillBackground(true);
    ui->result_color->setPalette(Pal);

    color_border = QColor(Qt::black);
    color_lines = QColor(Qt::blue);
    color_result = QColor(Qt::red);

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
    free_points(otcek.head);
    otcek = {nullptr, nullptr, 0};
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
    if (otcek.head && otcek.head->next)
    {
        painter->setPen(QPen(color_border, 2));
        for (point_t *ptr = otcek.head; ptr->next;ptr = ptr->next)
            painter->drawLine(ptr->x, ptr->y, ptr->next->x, ptr->next->y);
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
        painter->setPen(QPen(color_lines, 2));
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
    bool q1, q2;
    QString strx = ui->lineEdit_x->text();
    QString stry = ui->lineEdit_y->text();

    int x = strx.toInt(&q1);
    int y = stry.toInt(&q2);

    if (q1 && q2)
    {
        if (!otcek.zamknut)
        {
            painter->setPen(QPen(color_border, 2));
            if (otcek.tail)
            {
                painter->drawLine(otcek.tail->x, otcek.tail->y, x, y);
                otcek.tail = add_point(x, y, otcek.tail);
            }
            else
            {
                painter->drawPoint(x, y);
                otcek.tail = add_point(x, y, otcek.tail);
                otcek.head = otcek.tail;
            }
            ui->draw_label->setPixmap(*scene);
        }
    }
    else
        QMessageBox::warning(this, "Ошибка ввода", "Координаты должны быть целочисленными!");
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
        painter->setPen(QPen(color_lines, 2));
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

        if (!otcek.zamknut)
        {
            if (event->button() == Qt::LeftButton)
            {
                if (event->modifiers() == Qt::ShiftModifier)
                {
                    if (otcek.tail)
                    {
                        y = otcek.tail->y;
                    }
                }
                else if (event->modifiers() == Qt::ControlModifier)
                {
                    if (otcek.tail)
                    {
                        x = otcek.tail->x;
                    }
                }
            }
            else
            {
                if (otcek.head && event->button() == Qt::RightButton)
                {
                    x = otcek.head->x;
                    y = otcek.head->y;
                    otcek.zamknut = 1;
                }
            }
            painter->setPen(QPen(color_border, 2));
            if (otcek.tail)
            {
                painter->drawLine(otcek.tail->x, otcek.tail->y, x, y);
                otcek.tail = add_point(x, y, otcek.tail);
            }
            else
            {
                painter->drawPoint(x, y);
                otcek.tail = add_point(x, y, otcek.tail);
                otcek.head = otcek.tail;
            }
        }
        else
        {
            if (!tail || tail->full)
            {
                tail = add_line(x, y, -1, -1, tail);
                if (!head)
                    head = tail;
                painter->setPen(QPen(color_lines, 2));
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

            painter->setPen(QPen(color_lines, 2));
            painter->drawLine(tail->xbeg, tail->ybeg, tail->xend, tail->yend);
        }
        ui->draw_label->setPixmap(*scene);
    }
}

void MainWindow::on_pushButton_cut_clicked()
{
    if (!(otcek.head && otcek.head->next && otcek.head->next->next && otcek.head->next->next->next))
    {
        QMessageBox::warning(this, "Ошибкa", "Вы ввели менее трех точек! Отсекатель нужно задать выпуклым многоугольником!");
        return;
    }
    if (is_vypukl(otcek))
    {
        for (lines_t *line = head; line; line = line->next)
            cut_line(line);
        ui->draw_label->setPixmap(*scene);
    }
    else
        QMessageBox::warning(this, "Ошибкa", "Вы задали невыпуклый многоугольник! Отсекатель должен быть выпуклым многоугольником!");
}

void MainWindow::cut_line(lines_t *line)
{
    double tlow = 0, thigh = 1;
    int Dx = line->xend - line->xbeg;
    int Dy = line->yend - line->ybeg;
    for (point_t *C1 = otcek.head, *C2 = C1->next; C2; C1 = C2, C2 = C2->next)
    {
        int Wx = line->xbeg - C1->x;  // за f берем Ci
        int Wy = line->ybeg - C1->y;
        double Dsk = C2->nx * Dx + C2->ny * Dy;
        double Wsk = Wx * C2->nx + Wy * C2->ny;
        if (Dsk == 0)
        {
            if (Wsk >= 0)
                continue;
            else return;
        }
        double t = -Wsk / Dsk;
        if (Dsk > 0)
        {
            if (t > 1)
                return;
            else tlow = (tlow > t) ? tlow : t;
        }
        else
        {
            if (t < 0)
                return;
            else thigh = (thigh < t) ? thigh : t;
        }
    }
    if (tlow <= thigh)
    {
        int x1 = line->xbeg + (line->xend - line->xbeg) * tlow;
        int x2 = line->xbeg + (line->xend - line->xbeg) * thigh;
        int y1 = line->ybeg + (line->yend - line->ybeg) * tlow;
        int y2 = line->ybeg + (line->yend - line->ybeg) * thigh;
        painter->setPen(QPen(color_result, 2));
        painter->drawLine(x1, y1, x2, y2);
    }
}
