#include "proc.h"

int is_vypukl(contur_t fig)
{
    double vp;
    point_t *prev;
    for (point_t *p1 = fig.head, *p2 = p1->next, *p3 = p2->next; p3; p1 = p2, p2 = p3, p3 = p3->next)
    {
        if(p3->next == fig.tail)
            prev = p3;
        int ax = p2->x - p1->x, ay = p2->y - p1->y;
        int bx = p3->x - p2->x, by = p3->y - p2->y;
        vp = ax * by - ay * bx;
        if (vp < 0)     // по норимальному должно быть <0, но экранные координаты
            return 0;
    }
    point_t *p1 = prev, *p2 = fig.tail, *p3 = fig.head->next;
    int ax = p2->x - p1->x, ay = p2->y - p1->y;
    int bx = p3->x - p2->x, by = p3->y - p2->y;
    vp = ax * by - ay * bx;
    if (vp < 0)    // по норимальному должно быть <0, но экранные координаты
        return 0;
    return 1;
}


void swap(int *a, int  *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

point_t* add_point(int x, int y, point_t *tail)
{
    point_t* p = new point_t;
    p->x = x;
    p->y = y;
    p->next = nullptr;
    p->nx = 0;
    p->ny = 0;
    p->f = 1;
    if (tail != nullptr)
    {
        tail->next = p;
        double ax = x - tail->x, ay = y - tail->y;
        if (ax == 0)
        {
            p->nx = 1;
            p->ny = 0;
        }
        else
        {
            p->ny = 1;
            p->nx = -ay * p->ny / ax;
        }
        if (p->nx * ay - p->ny * ax > 0)  // по норимальному должно быть <0, но экранные координаты
        {
            p->nx = -p->nx;
            p->ny = -p->ny;
        }
        if (ax == 0)
        {
            p->k = p->x;
            p->b = p->x;
            p->f = 0;

        }
        else
        {
            p->k = ay / ax;
            p->b = p->y - p->k * p->x;
        }
    }
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

lines_t* add_line(int xbeg, int ybeg, int xend, int yend, lines_t *tail)
{
    lines_t* l = new lines_t;
    l->xbeg = xbeg;
    l->ybeg = ybeg;
    l->xend = xend;
    l->yend = yend;
    if (xbeg < 0 || ybeg < 0|| xend < 0 || yend < 0)
        l->full = 0;
    else l->full = 1;
    l->next = nullptr;
    if (tail != nullptr)
        tail->next = l;
    return l;
}

void free_lines(lines_t *head)
{
    lines_t *next;
    for (lines_t *ptr = head; ptr != nullptr; ptr = next)
    {
        next = ptr->next;
        delete ptr;
    }
}
