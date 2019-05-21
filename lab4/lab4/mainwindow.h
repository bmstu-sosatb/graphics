#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void clean_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QPainter *painter;
    void change_colour();
};

#endif // MAINWINDOW_H
