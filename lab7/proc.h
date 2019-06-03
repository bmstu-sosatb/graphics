#ifndef PROC_H
#define PROC_H

#include <QPainter>
#include <QColor>
#include <QPixmap>

typedef struct otcekatel otcekatel_t;
typedef struct lines lines_t;

struct point
{
    int x;
    int y;
};

struct otcekatel
{
    int xleft;
    int ylow;
    int xright;
    int yhigh;
    int full;
};

struct codes
{
    int T1;
    int T2;
    int T3;
    int T4;
};

struct lines
{
    int xbeg;
    int ybeg;
    int xend;
    int yend;
    struct codes Tbeg;
    struct codes Tend;
    int Sbeg;
    int Send;
    int P;
    int full;
    lines_t *next;
};

lines_t cut_line(lines_t line, struct otcekatel *otcek, double eps);
void count_codes(struct otcekatel *otcek, lines_t *line);
void swap(int *a, int  *b);
void free_otcekatel(otcekatel_t *otcek);
otcekatel_t* create_otcekatel(int xleft, int xright, int ylow, int yhigh);
lines_t* add_line(int xbeg, int ybeg, int xend, int yend, lines_t *tail);
void free_lines(lines_t *head);

#endif // PROC_H
