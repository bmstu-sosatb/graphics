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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *LinesColourcomboBox;
    QLabel *label_2;
    QComboBox *BackgroundColourcomboBox;
    QLabel *label_3;
    QRadioButton *radioButton_kan;
    QRadioButton *radioButton_par;
    QRadioButton *radioButton_br;
    QRadioButton *radioButton_srt;
    QRadioButton *radioButton_dll;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QLineEdit *lineEdit_r;
    QLabel *label_5;
    QLineEdit *lineEdit_xc1cir;
    QLabel *label_6;
    QLineEdit *lineEdit_yc1cir;
    QPushButton *pushButton_drawonecir;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLineEdit *lineEdit_xc2cir;
    QLabel *label_11;
    QLineEdit *lineEdit_yc2cir;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit_rbeg;
    QLabel *label_8;
    QLineEdit *lineEdit_rend;
    QLabel *label_9;
    QLineEdit *lineEdit_stepcir;
    QPushButton *pushButton_drawmanycir;
    QWidget *layoutWidget3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_19;
    QLineEdit *lineEdit_xcel;
    QLabel *label_20;
    QLineEdit *lineEdit_ycel;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_17;
    QLineEdit *lineEdit_a;
    QLabel *label_18;
    QLineEdit *lineEdit_b;
    QPushButton *pushButton_drawoneel;
    QLabel *draw_label;
    QLabel *label_22;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_12;
    QLineEdit *lineEdit_xc2el;
    QLabel *label_13;
    QLineEdit *lineEdit_yc2el;
    QLabel *label_16;
    QLineEdit *lineEdit_nel;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_14;
    QLineEdit *lineEdit_abeg;
    QLabel *label_15;
    QLineEdit *lineEdit_bbeg;
    QLabel *label_21;
    QLineEdit *lineEdit_stepel;
    QPushButton *pushButton_drawmanyel;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1400, 1000);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 10, 341, 381));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(4);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        label->setFont(font);

        verticalLayout->addWidget(label);

        LinesColourcomboBox = new QComboBox(layoutWidget);
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->setObjectName(QStringLiteral("LinesColourcomboBox"));
        LinesColourcomboBox->setFont(font);

        verticalLayout->addWidget(LinesColourcomboBox);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        verticalLayout->addWidget(label_2);

        BackgroundColourcomboBox = new QComboBox(layoutWidget);
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->setObjectName(QStringLiteral("BackgroundColourcomboBox"));
        BackgroundColourcomboBox->setFont(font);

        verticalLayout->addWidget(BackgroundColourcomboBox);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        verticalLayout->addWidget(label_3);

        radioButton_kan = new QRadioButton(layoutWidget);
        radioButton_kan->setObjectName(QStringLiteral("radioButton_kan"));
        radioButton_kan->setFont(font);

        verticalLayout->addWidget(radioButton_kan);

        radioButton_par = new QRadioButton(layoutWidget);
        radioButton_par->setObjectName(QStringLiteral("radioButton_par"));
        radioButton_par->setFont(font);

        verticalLayout->addWidget(radioButton_par);

        radioButton_br = new QRadioButton(layoutWidget);
        radioButton_br->setObjectName(QStringLiteral("radioButton_br"));
        radioButton_br->setFont(font);

        verticalLayout->addWidget(radioButton_br);

        radioButton_srt = new QRadioButton(layoutWidget);
        radioButton_srt->setObjectName(QStringLiteral("radioButton_srt"));
        radioButton_srt->setFont(font);

        verticalLayout->addWidget(radioButton_srt);

        radioButton_dll = new QRadioButton(layoutWidget);
        radioButton_dll->setObjectName(QStringLiteral("radioButton_dll"));
        radioButton_dll->setFont(font);

        verticalLayout->addWidget(radioButton_dll);

        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 410, 391, 81));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);

        horizontalLayout->addWidget(label_4);

        lineEdit_r = new QLineEdit(layoutWidget1);
        lineEdit_r->setObjectName(QStringLiteral("lineEdit_r"));

        horizontalLayout->addWidget(lineEdit_r);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        lineEdit_xc1cir = new QLineEdit(layoutWidget1);
        lineEdit_xc1cir->setObjectName(QStringLiteral("lineEdit_xc1cir"));

        horizontalLayout->addWidget(lineEdit_xc1cir);

        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        horizontalLayout->addWidget(label_6);

        lineEdit_yc1cir = new QLineEdit(layoutWidget1);
        lineEdit_yc1cir->setObjectName(QStringLiteral("lineEdit_yc1cir"));

        horizontalLayout->addWidget(lineEdit_yc1cir);


        verticalLayout_2->addLayout(horizontalLayout);

        pushButton_drawonecir = new QPushButton(layoutWidget1);
        pushButton_drawonecir->setObjectName(QStringLiteral("pushButton_drawonecir"));
        pushButton_drawonecir->setFont(font);

        verticalLayout_2->addWidget(pushButton_drawonecir);

        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 520, 501, 111));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font);

        horizontalLayout_3->addWidget(label_10);

        lineEdit_xc2cir = new QLineEdit(layoutWidget2);
        lineEdit_xc2cir->setObjectName(QStringLiteral("lineEdit_xc2cir"));

        horizontalLayout_3->addWidget(lineEdit_xc2cir);

        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font);

        horizontalLayout_3->addWidget(label_11);

        lineEdit_yc2cir = new QLineEdit(layoutWidget2);
        lineEdit_yc2cir->setObjectName(QStringLiteral("lineEdit_yc2cir"));

        horizontalLayout_3->addWidget(lineEdit_yc2cir);


        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font);

        horizontalLayout_2->addWidget(label_7);

        lineEdit_rbeg = new QLineEdit(layoutWidget2);
        lineEdit_rbeg->setObjectName(QStringLiteral("lineEdit_rbeg"));

        horizontalLayout_2->addWidget(lineEdit_rbeg);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font);

        horizontalLayout_2->addWidget(label_8);

        lineEdit_rend = new QLineEdit(layoutWidget2);
        lineEdit_rend->setObjectName(QStringLiteral("lineEdit_rend"));

        horizontalLayout_2->addWidget(lineEdit_rend);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font);

        horizontalLayout_2->addWidget(label_9);

        lineEdit_stepcir = new QLineEdit(layoutWidget2);
        lineEdit_stepcir->setObjectName(QStringLiteral("lineEdit_stepcir"));

        horizontalLayout_2->addWidget(lineEdit_stepcir);


        verticalLayout_3->addLayout(horizontalLayout_2);

        pushButton_drawmanycir = new QPushButton(layoutWidget2);
        pushButton_drawmanycir->setObjectName(QStringLiteral("pushButton_drawmanycir"));
        pushButton_drawmanycir->setFont(font);

        verticalLayout_3->addWidget(pushButton_drawmanycir);


        verticalLayout_4->addLayout(verticalLayout_3);

        layoutWidget3 = new QWidget(centralWidget);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 670, 471, 141));
        verticalLayout_7 = new QVBoxLayout(layoutWidget3);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_19 = new QLabel(layoutWidget3);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setFont(font);

        horizontalLayout_6->addWidget(label_19);

        lineEdit_xcel = new QLineEdit(layoutWidget3);
        lineEdit_xcel->setObjectName(QStringLiteral("lineEdit_xcel"));

        horizontalLayout_6->addWidget(lineEdit_xcel);

        label_20 = new QLabel(layoutWidget3);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setFont(font);

        horizontalLayout_6->addWidget(label_20);

        lineEdit_ycel = new QLineEdit(layoutWidget3);
        lineEdit_ycel->setObjectName(QStringLiteral("lineEdit_ycel"));

        horizontalLayout_6->addWidget(lineEdit_ycel);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_17 = new QLabel(layoutWidget3);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setFont(font);

        horizontalLayout_7->addWidget(label_17);

        lineEdit_a = new QLineEdit(layoutWidget3);
        lineEdit_a->setObjectName(QStringLiteral("lineEdit_a"));

        horizontalLayout_7->addWidget(lineEdit_a);

        label_18 = new QLabel(layoutWidget3);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setFont(font);

        horizontalLayout_7->addWidget(label_18);

        lineEdit_b = new QLineEdit(layoutWidget3);
        lineEdit_b->setObjectName(QStringLiteral("lineEdit_b"));

        horizontalLayout_7->addWidget(lineEdit_b);


        verticalLayout_7->addLayout(horizontalLayout_7);

        pushButton_drawoneel = new QPushButton(layoutWidget3);
        pushButton_drawoneel->setObjectName(QStringLiteral("pushButton_drawoneel"));
        pushButton_drawoneel->setFont(font);

        verticalLayout_7->addWidget(pushButton_drawoneel);

        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setGeometry(QRect(590, 20, 710, 710));
        draw_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        label_22 = new QLabel(centralWidget);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(130, 1740, 38, 16));
        label_22->setFont(font);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(2, 830, 481, 121));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_12 = new QLabel(widget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFont(font);

        horizontalLayout_4->addWidget(label_12);

        lineEdit_xc2el = new QLineEdit(widget);
        lineEdit_xc2el->setObjectName(QStringLiteral("lineEdit_xc2el"));

        horizontalLayout_4->addWidget(lineEdit_xc2el);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFont(font);

        horizontalLayout_4->addWidget(label_13);

        lineEdit_yc2el = new QLineEdit(widget);
        lineEdit_yc2el->setObjectName(QStringLiteral("lineEdit_yc2el"));

        horizontalLayout_4->addWidget(lineEdit_yc2el);

        label_16 = new QLabel(widget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setFont(font);

        horizontalLayout_4->addWidget(label_16);

        lineEdit_nel = new QLineEdit(widget);
        lineEdit_nel->setObjectName(QStringLiteral("lineEdit_nel"));

        horizontalLayout_4->addWidget(lineEdit_nel);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_14 = new QLabel(widget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFont(font);

        horizontalLayout_5->addWidget(label_14);

        lineEdit_abeg = new QLineEdit(widget);
        lineEdit_abeg->setObjectName(QStringLiteral("lineEdit_abeg"));

        horizontalLayout_5->addWidget(lineEdit_abeg);

        label_15 = new QLabel(widget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setFont(font);

        horizontalLayout_5->addWidget(label_15);

        lineEdit_bbeg = new QLineEdit(widget);
        lineEdit_bbeg->setObjectName(QStringLiteral("lineEdit_bbeg"));

        horizontalLayout_5->addWidget(lineEdit_bbeg);

        label_21 = new QLabel(widget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setFont(font);

        horizontalLayout_5->addWidget(label_21);

        lineEdit_stepel = new QLineEdit(widget);
        lineEdit_stepel->setObjectName(QStringLiteral("lineEdit_stepel"));

        horizontalLayout_5->addWidget(lineEdit_stepel);


        verticalLayout_5->addLayout(horizontalLayout_5);

        pushButton_drawmanyel = new QPushButton(widget);
        pushButton_drawmanyel->setObjectName(QStringLiteral("pushButton_drawmanyel"));
        pushButton_drawmanyel->setFont(font);

        verticalLayout_5->addWidget(pushButton_drawmanyel);

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
        label->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\271:", nullptr));
        LinesColourcomboBox->setItemText(0, QApplication::translate("MainWindow", "\321\207\320\265\321\200\320\275\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(1, QApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(2, QApplication::translate("MainWindow", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(3, QApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(4, QApplication::translate("MainWindow", "\321\201\320\270\320\275\320\270\320\271", nullptr));
        LinesColourcomboBox->setItemText(5, QApplication::translate("MainWindow", "\320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));

        label_2->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        BackgroundColourcomboBox->setItemText(0, QApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(1, QApplication::translate("MainWindow", "\321\207\320\265\321\200\320\275\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(2, QApplication::translate("MainWindow", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(3, QApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(4, QApplication::translate("MainWindow", "\321\201\320\270\320\275\320\270\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(5, QApplication::translate("MainWindow", "\320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));

        label_3->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\261\320\276\321\200 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274\320\260:", nullptr));
        radioButton_kan->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\275\320\276\320\275\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        radioButton_par->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\270\321\207\320\265\321\201\320\272\320\276\320\265 \321\203\321\200\320\260\320\262\320\275\320\265\320\275\320\270\320\265", nullptr));
        radioButton_br->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260", nullptr));
        radioButton_srt->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \321\201\321\200\320\265\320\264\320\275\320\265\320\271 \321\202\320\276\321\207\320\272\320\270", nullptr));
        radioButton_dll->setText(QApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "R =", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Xc =", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Yc =", nullptr));
        pushButton_drawonecir->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\321\214", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "Xc =", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "Yc =", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "R \320\275\320\260\321\207 =", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "R \320\272\320\276\320\275\320\265\321\207 =", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263 =", nullptr));
        pushButton_drawmanycir->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \321\201\320\277\320\265\320\272\321\202\321\200 \320\276\320\272\321\200\321\203\320\266\320\275\320\276\321\201\321\202\320\265\320\271", nullptr));
        label_19->setText(QApplication::translate("MainWindow", "Xc =", nullptr));
        label_20->setText(QApplication::translate("MainWindow", "Yc =", nullptr));
        label_17->setText(QApplication::translate("MainWindow", "a =", nullptr));
        label_18->setText(QApplication::translate("MainWindow", "b =", nullptr));
        pushButton_drawoneel->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \321\215\320\273\320\273\320\270\320\277\321\201", nullptr));
        draw_label->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        label_22->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276:", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Xc =", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Yc =", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276:", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "a \320\275\320\260\321\207 =", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "b \320\275\320\260\321\207 =", nullptr));
        label_21->setText(QApplication::translate("MainWindow", "\320\250\320\260\320\263 =", nullptr));
        pushButton_drawmanyel->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \321\201\320\277\320\265\320\272\321\202\321\200 \321\215\320\273\320\273\320\270\320\277\321\201\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
