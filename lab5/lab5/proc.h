#ifndef PROC_H
#define PROC_H

typedef struct point point_t;

struct point
{
    int x;
    int y;
    point_t *next;
};

point_t* add_point(int x, int y, point_t *tail);
void free_list(point_t *head);

#endif // PROC_H
