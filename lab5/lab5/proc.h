#ifndef PROC_H
#define PROC_H

#include <QPainter>
#include <QColor>
#include <QPixmap>

typedef struct point point_t;
typedef struct contur contur_t;

struct point
{
    int x;
    int y;
    point_t *next;
};

struct contur
{
    point_t *head;
    point_t *tail;
    int zamknut;
    contur_t *next;
};

point_t* add_point(int x, int y, point_t *tail);
void free_points(point_t *head);
contur_t* add_contur(contur_t *tail);
void free_conturs(contur_t *head);
void paint(QPixmap &scene, QPainter &painter, QColor color_fill, QColor color_background);

#endif // PROC_H
