#define _USE_MATH_DEFINES
#include <math.h>
#include "algs.h"

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
    int a2= a * a, b2 = b * b;
    for (x = 0; x <= a; x++)
    {
        double yres = sqrt((a2 * b2 - b2 * x * x) / a2);
        y = round(yres);
        painter.drawPoint(xc + x, yc + y);
        painter.drawPoint(xc - x, yc + y);
        painter.drawPoint(xc - x, yc - y);
        painter.drawPoint(xc + x, yc - y);
    }
    for (y = 0; y <= b; y++)
    {
        double xres = sqrt((a2 * b2 - a2 * y * y) / b2);
        x = round(xres);
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
