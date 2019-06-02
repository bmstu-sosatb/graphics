#ifndef PROC_H
#define PROC_H

#include <QPainter>
#include <QColor>
#include <QPixmap>

typedef struct point point_t;
typedef struct contur contur_t;
typedef struct stack stack_t;

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

struct stack
{
    int x;
    int y;
    stack_t *prev;
};

point_t* add_point(int x, int y, point_t *tail);
void free_points(point_t *head);
contur_t* add_contur(contur_t *tail);
void free_conturs(contur_t *head);
bool stack_is_empty(stack_t *top);
stack_t* push(stack_t *top, int x, int y);
stack_t* pop(stack_t *top, int *x, int *y);

#endif // PROC_H
