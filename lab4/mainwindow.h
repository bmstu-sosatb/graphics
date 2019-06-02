#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPixmap>

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
    void on_pushButton_drawonecir_clicked();

    void on_pushButton_drawmanycir_clicked();

    void on_pushButton_drawoneel_clicked();

    void on_pushButton_drawmanyel_clicked();

    void on_pushButton_clean_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap *scene;
    QPainter *painter;
    void change_colour();
};

#endif // MAINWINDOW_H
