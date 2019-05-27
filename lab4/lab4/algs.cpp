#define _USE_MATH_DEFINES
#include <math.h>
#include "algs.h"


void draw_circle_br(int xc, int yc, int r, QPainter &painter)
{
    int x = 0, y = r;
    double deltai = 2 - 2 * r;
    double d;

    while (y >= 0)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);
        if (deltai < 0)
        {
            d = 2 * (deltai + y) - 1;
            x++;
            if (d < 0)
                deltai += 2 * x + 1;
            else
            {
                y--;
                deltai += 2 * (x - y + 1);
            }
        }
        else if (deltai > 0)
        {
            d = 2 * (deltai - x) - 1;
            y--;
            if (d < 0)
            {
                x++;
                deltai += 2 * (x - y + 1);
            }
            else
                deltai -= 2 * y - 1;
        }
        else
        {
            x++;
            y--;
            deltai += 2 * (x - y + 1);
        }
    }
}

void draw_ellipse_br(int xc, int yc, int a, int b, QPainter &painter)
{
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    double deltai = a2 + b2 - 2 * a2 * b;
    double d;

    while (y >= 0)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);
        if (deltai < 0)
        {
            d = 2 * (deltai + a2 * y) - a2;
            x++;
            if (d < 0)
                deltai += b2 * (2 * x + 1);
            else
            {
                y--;
                deltai += 2 * (b2 * x - a2 * y) + a2 + b2;
            }
        }
        else if (deltai > 0)
        {
            d = 2 * (deltai - b2 * x) - b2;
            y--;
            if (d > 0)
                deltai -= a2 * (2 * y - 1);
            else
            {
                x++;
                deltai += 2 * (b2 * x - a2 * y) + a2 + b2;
            }
        }
        else
        {
            x++;
            y--;
            deltai += 2 * (b2 * x - a2 * y) + a2 + b2;
        }
    }
}

void draw_circle_srt(int xc, int yc, int r, QPainter &painter)
{
    int x = 0, y = r;
    int xchng = r / sqrt(2);
    int delta = - 2 * y;
    int df = 0;
    double fprob = 1.25 - r;

    while (x <= xchng)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);

        if (fprob >= 0)
        {
            y--;
            delta += 2;
            fprob += delta;
        }
        df += 2;
        fprob += df;
        x++;
    }

    delta = 2 * x;
    df = -2 * y;
    fprob += - x - y;

    while (y >= 0)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);

        if (fprob < 0)
        {
            x++;
            delta += 2;
            fprob += delta;
        }
        df += 2;
        fprob += df;
        y--;
    }
}

void draw_ellipse_srt(int xc, int yc, int a, int b, QPainter &painter)
{
    int x = 0, y = b;
    int a2 = a * a, b2 = b * b;
    int xchng = a2 / sqrt(a2 + b2);
    int delta = - 2 * a2 * y;
    int df = 0;
    double fprob = b2 - a2 * b + 0.25 * a2;

    while (x <= xchng)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);

        if (fprob >= 0)
        {
            y--;
            delta += 2 * a2;
            fprob += delta;
        }
        df += 2 * b2;
        fprob += df + b2;
        x++;
    }

    delta = 2 * b2 * x;
    df = -2 * a2 * y;
    fprob += 0.75 * (a2 - b2) - b2 * x - a2 * y;

    while (y >= 0)
    {
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);

        if (fprob < 0)
        {
            x++;
            delta += 2 * b2;
            fprob += delta;
        }
        df += 2 * a2;
        fprob += df + a2;
        y--;
    }
}

void draw_circle_kan(int xc, int yc, int r, QPainter &painter)
{
    int x, y;
    for (x = 0; x <= r; x++)
    {
        double yres = sqrt(r * r - x * x);
        y = round(yres);
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);
    }
    for (y = 0; y <= r; y++)
    {
        double xres = sqrt(r * r - y * y);
        x = round(xres);
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);
    }
}

void draw_circle_par(int xc, int yc, int r, QPainter &painter)
{
    double delta_t = 1 / (double) r;
    for (double t = 0; t <= M_PI_2; t += delta_t)
    {
        int x = round(r * cos(t));
        int y = round(r * sin(t));
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);
    }
}


void draw_ellipse_kan(int xc, int yc, int a, int b, QPainter &painter)
{
    int x, y;
    int a2 = a * a, b2 = b * b;
    if (a != 0)
        for (x = 0; x <= a; x++)
        {
            double yres = b * sqrt((1 - x * x / (double)a2));
            y = (int)round(yres);
            painter.drawPoint(xc + x, yc + y);
            painter.drawPoint(xc - x, yc + y);
            painter.drawPoint(xc - x, yc - y);
            painter.drawPoint(xc + x, yc - y);
        }
    if (b != 0)
        for (y = 0; y <= b; y++)
        {
            double xres = a * sqrt((1 - y * y / (double)b2));
            x = (int)round(xres);
            painter.drawPoint(xc + x, yc + y);
            painter.drawPoint(xc - x, yc + y);
            painter.drawPoint(xc - x, yc - y);
            painter.drawPoint(xc + x, yc - y);
        }
}

void draw_ellipse_par(int xc, int yc, int a, int b, QPainter &painter)
{
    double delta_t;
    if (a > b)
        delta_t = 1 / (double) a;
    else delta_t = 1 / (double) b;
    for (double t = 0; t <= M_PI_2; t += delta_t)
    {
        int x = round(a * cos(t));
        int y = round(b * sin(t));
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);
    }
}

void draw_circle_dll(int xc, int yc, int r, QPainter &painter)
{
    painter.drawEllipse(xc - r, yc - r, r * 2, r * 2);
}

void draw_ellipse_dll(int xc, int yc, int a, int b, QPainter &painter)
{
    painter.drawEllipse(xc - a, yc - b, a * 2, b * 2);
}


void draw_many_circle(int xc, int yc, int rbeg, int rend, int step, QPainter &painter, void (*func)(int, int, int, QPainter&))
{
    while (rbeg <= rend)
    {
        func(xc, yc, rbeg, painter);
        rbeg += step;
    }
}

void draw_many_ellipse(int xc, int yc, int abeg, int bbeg, int step, int n, QPainter &painter, void (*func)(int, int, int, int, QPainter&))
{
    double correct = (double) bbeg / (double) abeg;
    for (int i = 0; i < n; i++)
    {
        func(xc, yc, abeg, bbeg, painter);
        abeg += step;
        bbeg = abeg * correct;
    }
}
