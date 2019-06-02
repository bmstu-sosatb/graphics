#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "proc.h"
#include <QMainWindow>
#include <QPainter>
#include <QPixmap>
#include <QMouseEvent>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mousePressEvent(QMouseEvent *event);

private slots:

    void on_pushButton_clean_clicked();

    void on_pushButton_border_clicked();

    void on_pushButton_fill_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_clicked();

    void on_pushButton_addzatr_clicked();

private:
    Ui::MainWindow *ui;
    QPainter *painter;
    QPixmap *scene;
    QColor color_border;
    QColor color_fill;
    QColor color_background;
};

#endif // MAINWINDOW_H
