#include "proc.h"
#include <windows.h>


contur_t *head = add_contur(nullptr);
contur_t *tail = head;

point_t* add_point(int x, int y, point_t *tail)
{
    point_t* p = new point_t;
    p->x = x;
    p->y = y;
    p->next = nullptr;
    if (tail != nullptr)
        tail->next = p;
    return p;
}

void free_points(point_t *head)
{
    point_t *next;
    for (point_t *ptr = head; ptr != nullptr; ptr = next)
    {
        next = ptr->next;
        delete ptr;
    }
}

contur_t* add_contur(contur_t *tail)
{
    contur_t* c = new contur_t;
    c->head = nullptr;
    c->tail = nullptr;
    c->zamknut = 0;
    c->next = nullptr;
    if (tail != nullptr)
        tail->next = c;
    return c;
}

void free_conturs(contur_t *head)
{
    contur_t *next;
    for (contur_t *ptr = head; next != nullptr; ptr = next)
    {
        next = ptr->next;
        free_points(ptr->head);
        delete ptr;
    }
}

void paint(QPixmap &scene, QPainter &painter, QColor color_fill, QColor color_background)
{
    int xmin = head->head->x;
    int xmax = head->head->x;
    int ymin = head->head->y;
    int ymax = head->head->y;
    QImage img = scene.toImage();

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

    painter.setPen(Qt::green);
    painter.drawLine(xsep, ymin - 10, xsep, ymax + 10);
    painter.setPen(color_fill);

    for (contur_t *cntr = head; cntr != nullptr; cntr = cntr->next)
    {
        for (point_t *start = cntr->head; start != nullptr; start = start->next)
        {
            point_t *end = start->next ? start->next : cntr->head;
            double k = (double) (end->y - start->y) / (end->x - start->x);
            double b = start->y - k * start->x;
            if (start->y < end->y)
            {
                for (int ycur = start->y; ycur <= end->y; ycur++)
                {
                    int xcur = (ycur - b) /  k;
                    if (xcur < xsep)
                        for (int xx = xcur + 1; xx < xsep; xx++)
                        {
                            QColor color = img.pixelColor(xx, ycur);
                            if (color == color_background)
                                painter.setPen(color_fill);
                            else
                                painter.setPen(color_background);
                            painter.drawPoint(xx, ycur);

                        }
                    if (xcur > xsep)
                    {
                        for (int xx = xsep + 1; xx < xcur; xx++)
                        {
                            QColor color = img.pixelColor(xx, ycur);
                            if (color == color_background)
                                painter.setPen(color_fill);
                            else
                                painter.setPen(color_background);
                            painter.drawPoint(xx, ycur);
                        }
                    }

                    Sleep(50);
                }
            }
        }
    }
}

