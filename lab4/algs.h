#ifndef ALGS_H
#define ALGS_H

#include <QPainter>

void draw_circle_br(int xc, int yc, int r, QPainter &painter);
void draw_ellipse_br(int xc, int yc, int a, int b, QPainter &painter);
void draw_circle_srt(int xc, int yc, int r, QPainter &painter);
void draw_ellipse_srt(int xc, int yc, int a, int b, QPainter &painter);
void draw_circle_kan(int xc, int yc, int r, QPainter &painter);
void draw_circle_par(int xc, int yc, int r, QPainter &painter);
void draw_ellipse_kan(int xc, int yc, int a, int b, QPainter &painter);
void draw_ellipse_par(int xc, int yc, int a, int b, QPainter &painter);
void draw_circle_dll(int xc, int yc, int r, QPainter &painter);
void draw_ellipse_dll(int xc, int yc, int a, int b, QPainter &painter);
void draw_many_circle(int xc, int yc, int rbeg, int rend, int step, QPainter &painter, void (*func)(int, int, int, QPainter&));
void draw_many_ellipse(int xc, int yc, int abeg, int bbeg, int step, int n, QPainter &painter, void (*func)(int, int, int, int, QPainter&));

#endif // ALGS_H
