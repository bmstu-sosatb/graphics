#include "proc.h"

lines_t cut_line(lines_t line, struct otcekatel *otcek, double eps)
{
    lines_t resline;
    struct point Rcur, T, Psr;
    int i = 1;
    M3:
    count_codes(otcek, &line);        //3
    if (line.Sbeg == 0 && line.Send == 0)   //4
    {
        resline = line;
        goto DRAW;
    }
    if (line.P != 0)     //5
        goto EXIT;
    T.x = line.xbeg;   //6
    T.y = line.ybeg;

    if (i > 2)    //7
    {
        count_codes(otcek, &line);
        if (line.P != 0)
            goto EXIT;
        else goto DRAW;
    }
    if (line.Send == 0)     //8
    {
        if (i == 1)
        {
            resline.xbeg = line.xend;
            resline.ybeg = line.yend;
        }
        else
        {
            resline.xend = line.xend;
            resline.yend = line.yend;
        }
        line.xbeg = line.xend;   //P1 = P2
        line.ybeg = line.yend;
        line.xend = T.x;   //P2=T
        line.yend =T.y;
        i++;
        goto M3;
    }
    M9:
    if (abs(line.xbeg - line.xend) <= eps && abs(line.ybeg - line.yend) <= eps)   //9
    {
        if (i == 1)
        {
            resline.xbeg = line.xbeg;
            resline.ybeg = line.ybeg;
        }
        else
        {
            resline.xend = line.xbeg;
            resline.yend = line.ybeg;
        }
        line.xbeg = line.xend;   //P1 = P2
        line.ybeg = line.yend;
        line.xend = T.x;   //P2=T
        line.yend =T.y;
        i++;
        int xb = line.xbeg, xe = line.xend, yb = line.ybeg, ye = line.yend;
        (void)xb;
        (void)xe;
        (void)ye;
        (void)yb;
        goto M3;
    }
    Psr.x = (line.xbeg + line.xend) / 2;     //10
    Psr.y = (line.ybeg +line.yend) / 2;
    Rcur.x = line.xbeg;    //R = P1      11
    Rcur.y = line.ybeg;
    line.xbeg = Psr.x;     //P1 = Psr       12
    line.ybeg = Psr.y;
    count_codes(otcek, &line);      //13, 14
    if (line.P != 0)
    {
        line.xbeg = Rcur.x;
        line.ybeg = Rcur.y;
        line.xend = Psr.x;
        line.yend = Psr.y;    //15
    }
    goto M9;    //16

    DRAW:
//    resline = line;
    resline.full = 1;
    return resline;
    EXIT:
//    resline = line;
    resline.full = 0;
    return resline;
}


void count_codes(struct otcekatel *otcek, lines_t *line)
{
    int left = otcek->xleft;
    int right = otcek->xright;
    int low = otcek-> ylow;
    int high = otcek->yhigh;
    (void)left;
    (void)right;
    (void)low;
    (void)high;

    if (line->xbeg < otcek->xleft)
        line->Tbeg.T1 = 1;
    else line->Tbeg.T1 = 0;
    if (line->xbeg > otcek->xright)
        line->Tbeg.T2 = 1;
    else line->Tbeg.T2 = 0;
    if (line->ybeg < otcek->ylow)
        line->Tbeg.T3 = 1;
    else line->Tbeg.T3 = 0;
    if (line->ybeg > otcek->yhigh)
        line->Tbeg.T4 = 1;
    else line->Tbeg.T4 = 0;

    if (line->xend < otcek->xleft)
        line->Tend.T1 = 1;
    else line->Tend.T1 = 0;
    if (line->xend > otcek->xright)
        line->Tend.T2 = 1;
    else line->Tend.T2 = 0;
    if (line->yend < otcek->ylow)
        line->Tend.T3 = 1;
    else line->Tend.T3 = 0;
    if (line->yend > otcek->yhigh)
        line->Tend.T4 = 1;
    else line->Tend.T4 = 0;

    line->Sbeg = line->Tbeg.T1 + line->Tbeg.T2 + line->Tbeg.T3 + line->Tbeg.T4;
    line->Send = line->Tend.T1 + line->Tend.T2 + line->Tend.T3 + line->Tend.T4;
    line->P = line->Tbeg.T1 * line->Tend.T1 + line->Tbeg.T2 * line->Tend.T2 + line->Tbeg.T3 * line->Tend.T3 + line->Tbeg.T4 * line->Tend.T4;
}

void swap(int *a, int  *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

otcekatel_t* create_otcekatel(int xleft, int xright, int ylow, int yhigh)
{
    otcekatel_t *o = new otcekatel_t;
    o->xleft = xleft;
    o->xright = xright;
    o->ylow = ylow;
    o->yhigh = yhigh;
    if (xleft < 0 || ylow < 0|| xright < 0 || yhigh < 0)
        o->full = 0;
    else o->full = 1;
    return o;
}

void free_otcekatel(otcekatel_t *otcek)
{
    delete otcek;
    otcek = nullptr;
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

