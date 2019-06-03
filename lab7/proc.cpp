#include "proc.h"
#include <windows.h>

otcekatel_t* create_otcekatel(int xleft, int xright, int yleft, int yright)
{
    otcekatel_t *o = new otcekatel_t;
    o->xleft = xleft;
    o->xright = xright;
    o->yleft = yleft;
    o->yright = yright;
    return o;
}

void free_otcekatel(otcekatel_t *otcek)
{
    delete otcek;
    otcek = nullptr;
}

lines_t* add_point(int xbeg, int ybeg, int xend, int yend, lines_t *tail)
{
    lines_t* l = new lines_t;
    l->xbeg = xbeg;
    l->ybeg = ybeg;
    l->xend = xend;
    l->yend = yend;
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

