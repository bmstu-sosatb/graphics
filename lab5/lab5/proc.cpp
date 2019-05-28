#include "proc.h"
point_t *head = nullptr;
point_t *tail = nullptr;

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

void free_list(point_t *head)
{
    point_t *next;
    for (point_t *ptr = head; ptr != nullptr; ptr = next)
    {
        next = ptr->next;
        delete ptr;
    }
}
