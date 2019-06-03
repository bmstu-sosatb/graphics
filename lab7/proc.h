#ifndef PROC_H
#define PROC_H

#include <QPainter>
#include <QColor>
#include <QPixmap>

typedef struct otcekatel otcekatel_t;
typedef struct lines lines_t;

struct otcekatel
{
    int xleft;
    int yleft;
    int xright;
    int yright;
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
    lines_t *next;
};

struct codes
{
    int T1;
    int T2;
    int T3;
    int T4;
};

void free_otcekatel(otcekatel_t *otcek);
otcekatel_t* create_otcekatel();
lines_t* add_point(int xbeg, int ybeg, int xend, int yend, lines_t *tail);
void free_lines(lines_t *head);

#endif // PROC_H
