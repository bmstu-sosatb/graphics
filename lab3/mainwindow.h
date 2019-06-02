#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QtCore>
#include <QtGui>
#include <QPixmap>
#include <QPen>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void draw_brfloat(int xbeg, int ybeg, int xend, int yend);
    void draw_brint(int xbeg, int ybeg, int xend, int yend);
    void draw_brstep(int xbeg, int ybeg, int xend, int yend);
    void draw_vu(int xbeg, int ybeg, int xend, int yend);
    void draw_dll(int xbeg, int ybeg, int xend, int yend);
    void draw_cda(int xbeg, int ybeg, int xend, int yend);
    void drawmany(int xc, int yc, int angle, int len, void (MainWindow::*draw)(int, int, int, int));

private slots:
    void drawone_clicked();
    void clean_clicked();
    void drawmany_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QPainter *painter;
    void change_colour(void);

};

#endif // MAINWINDOW_H
