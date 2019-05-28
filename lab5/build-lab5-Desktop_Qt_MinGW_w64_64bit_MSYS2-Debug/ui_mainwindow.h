/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *draw_label;
    QPushButton *pushButton_clean;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_x;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_y;
    QPushButton *pushButton_add;
    QWidget *widget1;
    QGridLayout *gridLayout;
    QLabel *border_color;
    QPushButton *pushButton_border;
    QLabel *background_color;
    QPushButton *pushButton_background;
    QLabel *fill_color;
    QPushButton *pushButton_fill;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1400, 1000);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(230, 10, 710, 710));
        draw_label->setAutoFillBackground(false);
        draw_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_clean = new QPushButton(centralWidget);
        pushButton_clean->setObjectName(QStringLiteral("pushButton_clean"));
        pushButton_clean->setGeometry(QRect(495, 770, 201, 40));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        pushButton_clean->setFont(font);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 11, 191, 111));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineEdit_x = new QLineEdit(widget);
        lineEdit_x->setObjectName(QStringLiteral("lineEdit_x"));
        lineEdit_x->setFont(font);

        horizontalLayout->addWidget(lineEdit_x);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_y = new QLineEdit(widget);
        lineEdit_y->setObjectName(QStringLiteral("lineEdit_y"));
        lineEdit_y->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_y);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_add = new QPushButton(widget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setFont(font);

        verticalLayout->addWidget(pushButton_add);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 160, 191, 101));
        gridLayout = new QGridLayout(widget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        border_color = new QLabel(widget1);
        border_color->setObjectName(QStringLiteral("border_color"));

        gridLayout->addWidget(border_color, 0, 0, 1, 1);

        pushButton_border = new QPushButton(widget1);
        pushButton_border->setObjectName(QStringLiteral("pushButton_border"));
        pushButton_border->setFont(font);

        gridLayout->addWidget(pushButton_border, 0, 1, 1, 1);

        background_color = new QLabel(widget1);
        background_color->setObjectName(QStringLiteral("background_color"));

        gridLayout->addWidget(background_color, 1, 0, 1, 1);

        pushButton_background = new QPushButton(widget1);
        pushButton_background->setObjectName(QStringLiteral("pushButton_background"));
        pushButton_background->setFont(font);

        gridLayout->addWidget(pushButton_background, 1, 1, 1, 1);

        fill_color = new QLabel(widget1);
        fill_color->setObjectName(QStringLiteral("fill_color"));

        gridLayout->addWidget(fill_color, 2, 0, 1, 1);

        pushButton_fill = new QPushButton(widget1);
        pushButton_fill->setObjectName(QStringLiteral("pushButton_fill"));
        pushButton_fill->setFont(font);

        gridLayout->addWidget(pushButton_fill, 2, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 17));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        draw_label->setText(QString());
        pushButton_clean->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        label->setText(QApplication::translate("MainWindow", "X: ", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "Y: ", nullptr));
        pushButton_add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\276\321\207\320\272\321\203", nullptr));
        border_color->setText(QString());
        pushButton_border->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\263\321\200\320\260\320\275\320\270\321\206\321\213", nullptr));
        background_color->setText(QString());
        pushButton_background->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260", nullptr));
        fill_color->setText(QString());
        pushButton_fill->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
