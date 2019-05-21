#ifndef ALGS_H
#define ALGS_H

#include <QPainter>

void draw_circle_kan(int xc, int yc, int r, QPainter &painter);
void draw_circle_par(int xc, int yc, int r, QPainter &painter);
void draw_ellipse_kan(int xc, int yc, int a, int b, QPainter &painter);
void draw_ellipse_par(int xc, int yc, int a, int b, QPainter &painter);


#endif // ALGS_H
