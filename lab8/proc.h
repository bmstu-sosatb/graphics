#ifndef PROC_H
#define PROC_H

#include <QPainter>
#include <QColor>
#include <QPixmap>

typedef struct point point_t;
typedef struct contur contur_t;
typedef struct line line_t;

struct point
{
    int x;
    int y;
    double nx;
    double ny;
    double k;
    double b;
    int f;
    point_t *next;
};

struct contur
{
    point_t *head;
    point_t *tail;
    int zamknut;
};

struct lines_t
{
    int xbeg;
    int xend;
    int ybeg;
    int yend;
    int full;
    lines_t *next;
};

int is_vypukl(contur_t fig);
point_t* add_point(int x, int y, point_t *tail);
void free_points(point_t *head);
void swap(int *a, int  *b);
lines_t* add_line(int xbeg, int ybeg, int xend, int yend, lines_t *tail);
void free_lines(lines_t *head);

#endif // PROC_H
