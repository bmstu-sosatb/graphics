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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEdit_x;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lineEdit_y;
    QPushButton *pushButton_add;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *border_color;
    QPushButton *pushButton_border;
    QLabel *fill_color;
    QPushButton *pushButton_fill;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton_slow;
    QRadioButton *radioButton_fast;
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEdit_xzatr;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QLineEdit *lineEdit_yzatr;
    QPushButton *pushButton_addzatr;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1400, 1200);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(350, 10, 900, 900));
        draw_label->setAutoFillBackground(false);
        draw_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        pushButton_clean = new QPushButton(centralWidget);
        pushButton_clean->setObjectName(QStringLiteral("pushButton_clean"));
        pushButton_clean->setGeometry(QRect(700, 920, 200, 40));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        pushButton_clean->setFont(font);
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 11, 191, 111));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(12);
        label->setFont(font1);

        horizontalLayout->addWidget(label);

        lineEdit_x = new QLineEdit(layoutWidget);
        lineEdit_x->setObjectName(QStringLiteral("lineEdit_x"));
        lineEdit_x->setFont(font);

        horizontalLayout->addWidget(lineEdit_x);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);

        horizontalLayout_2->addWidget(label_2);

        lineEdit_y = new QLineEdit(layoutWidget);
        lineEdit_y->setObjectName(QStringLiteral("lineEdit_y"));
        lineEdit_y->setFont(font);

        horizontalLayout_2->addWidget(lineEdit_y);


        verticalLayout->addLayout(horizontalLayout_2);

        pushButton_add = new QPushButton(layoutWidget);
        pushButton_add->setObjectName(QStringLiteral("pushButton_add"));
        pushButton_add->setFont(font);

        verticalLayout->addWidget(pushButton_add);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(1, 169, 191, 91));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        border_color = new QLabel(layoutWidget1);
        border_color->setObjectName(QStringLiteral("border_color"));

        gridLayout->addWidget(border_color, 0, 0, 1, 1);

        pushButton_border = new QPushButton(layoutWidget1);
        pushButton_border->setObjectName(QStringLiteral("pushButton_border"));
        pushButton_border->setFont(font);

        gridLayout->addWidget(pushButton_border, 0, 1, 1, 1);

        fill_color = new QLabel(layoutWidget1);
        fill_color->setObjectName(QStringLiteral("fill_color"));

        gridLayout->addWidget(fill_color, 1, 0, 1, 1);

        pushButton_fill = new QPushButton(layoutWidget1);
        pushButton_fill->setObjectName(QStringLiteral("pushButton_fill"));
        pushButton_fill->setFont(font);

        gridLayout->addWidget(pushButton_fill, 1, 1, 1, 1);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 290, 341, 121));
        verticalLayout_2 = new QVBoxLayout(layoutWidget2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_slow = new QRadioButton(layoutWidget2);
        radioButton_slow->setObjectName(QStringLiteral("radioButton_slow"));
        radioButton_slow->setFont(font);

        verticalLayout_2->addWidget(radioButton_slow);

        radioButton_fast = new QRadioButton(layoutWidget2);
        radioButton_fast->setObjectName(QStringLiteral("radioButton_fast"));
        radioButton_fast->setFont(font);

        verticalLayout_2->addWidget(radioButton_fast);

        pushButton = new QPushButton(layoutWidget2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFont(font);

        verticalLayout_2->addWidget(pushButton);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 450, 331, 131));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        verticalLayout_4->addWidget(label_6);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        lineEdit_xzatr = new QLineEdit(widget);
        lineEdit_xzatr->setObjectName(QStringLiteral("lineEdit_xzatr"));
        lineEdit_xzatr->setFont(font);

        horizontalLayout_3->addWidget(lineEdit_xzatr);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        lineEdit_yzatr = new QLineEdit(widget);
        lineEdit_yzatr->setObjectName(QStringLiteral("lineEdit_yzatr"));
        lineEdit_yzatr->setFont(font);

        horizontalLayout_4->addWidget(lineEdit_yzatr);


        verticalLayout_3->addLayout(horizontalLayout_4);

        pushButton_addzatr = new QPushButton(widget);
        pushButton_addzatr->setObjectName(QStringLiteral("pushButton_addzatr"));
        pushButton_addzatr->setFont(font);

        verticalLayout_3->addWidget(pushButton_addzatr);


        verticalLayout_4->addLayout(verticalLayout_3);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 600, 258, 211));
        verticalLayout_5 = new QVBoxLayout(widget1);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout_5->addWidget(label_3);

        textEdit = new QTextEdit(widget1);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        verticalLayout_5->addWidget(textEdit);

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
        fill_color->setText(QString());
        pushButton_fill->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\267\320\260\320\272\321\200\320\260\321\201\320\272\320\270", nullptr));
        radioButton_slow->setText(QApplication::translate("MainWindow", "\320\241 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\276\320\271 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        radioButton_fast->setText(QApplication::translate("MainWindow", "\320\221\320\265\320\267 \320\267\320\260\320\264\320\265\321\200\320\266\320\272\320\270 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\320\260\321\201\320\270\321\202\321\214", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "\320\227\320\220\320\242\320\240\320\220\320\222\320\236\320\247\320\235\320\253\320\231 \320\237\320\230\320\232\320\241\320\225\320\233\320\254", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "X: ", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Y: ", nullptr));
        pushButton_addzatr->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\321\201\321\202\320\270 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\242\320\236\320\247\320\232\320\230:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
