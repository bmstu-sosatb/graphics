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

bool stack_is_empty(stack_t *top)
{
    if (top)
        return false;
    return true;
}

stack_t* push(stack_t *top, int x, int y)
{
    stack_t *elem = new stack_t;
    elem->x = x;
    elem->y = y;
    elem->prev = top;
    return elem;
}

stack_t* pop(stack_t *top, int *x, int *y)
{
    *x = top->x;
    *y = top->y;
    stack_t *prev = top->prev;
    delete top;
    return prev;
}

