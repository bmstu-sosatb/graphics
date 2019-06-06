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

    void on_pushButton_lines_clicked();

    void on_pushButton_result_clicked();

    void on_pushButton_otcekatel_clicked();

    void on_pushButton_addline_clicked();

    void on_pushButton_cut_clicked();

private:
    Ui::MainWindow *ui;
    QPainter *painter;
    QPixmap *scene;
    QColor color_border;
    QColor color_lines;
    QColor color_result;
    void cut_line(lines_t *line);
};

#endif // MAINWINDOW_H
