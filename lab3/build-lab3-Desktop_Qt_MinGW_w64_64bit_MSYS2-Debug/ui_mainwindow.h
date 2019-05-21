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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
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
    QLabel *LinesColourLabel;
    QComboBox *LinesColourcomboBox;
    QLabel *BackgroundColorLabel;
    QComboBox *BackgroundColourcomboBox;
    QLabel *label;
    QRadioButton *radioButton_cda;
    QRadioButton *radioButton_brfloat;
    QRadioButton *radioButton_brint;
    QRadioButton *radioButton_brstep;
    QRadioButton *radioButton_vu;
    QRadioButton *radioButton_dll;
    QPushButton *pushButton_drawone;
    QPushButton *pushButton_drawmany;
    QWidget *layoutWidget1;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit_xbeg;
    QLabel *label_3;
    QLineEdit *lineEdit_ybeg;
    QLabel *label_4;
    QLineEdit *lineEdit_xend;
    QLabel *label_5;
    QLineEdit *lineEdit_yend;
    QWidget *layoutWidget2;
    QGridLayout *gridLayout_2;
    QLabel *label_7;
    QLineEdit *lineEdit_xc;
    QLabel *label_6;
    QLineEdit *lineEdit_yc;
    QLabel *label_8;
    QLineEdit *lineEdit_angle;
    QLabel *label_9;
    QLineEdit *lineEdit_len;
    QPushButton *pushButton_clean;
    QLabel *draw_label;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1400, 1000);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 471, 321));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        LinesColourLabel = new QLabel(layoutWidget);
        LinesColourLabel->setObjectName(QStringLiteral("LinesColourLabel"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(11);
        LinesColourLabel->setFont(font);

        verticalLayout->addWidget(LinesColourLabel);

        LinesColourcomboBox = new QComboBox(layoutWidget);
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->addItem(QString());
        LinesColourcomboBox->setObjectName(QStringLiteral("LinesColourcomboBox"));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(10);
        LinesColourcomboBox->setFont(font1);

        verticalLayout->addWidget(LinesColourcomboBox);

        BackgroundColorLabel = new QLabel(layoutWidget);
        BackgroundColorLabel->setObjectName(QStringLiteral("BackgroundColorLabel"));
        BackgroundColorLabel->setFont(font);

        verticalLayout->addWidget(BackgroundColorLabel);

        BackgroundColourcomboBox = new QComboBox(layoutWidget);
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->addItem(QString());
        BackgroundColourcomboBox->setObjectName(QStringLiteral("BackgroundColourcomboBox"));
        BackgroundColourcomboBox->setFont(font1);

        verticalLayout->addWidget(BackgroundColourcomboBox);

        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout->addWidget(label);

        radioButton_cda = new QRadioButton(layoutWidget);
        radioButton_cda->setObjectName(QStringLiteral("radioButton_cda"));
        radioButton_cda->setFont(font1);

        verticalLayout->addWidget(radioButton_cda);

        radioButton_brfloat = new QRadioButton(layoutWidget);
        radioButton_brfloat->setObjectName(QStringLiteral("radioButton_brfloat"));
        radioButton_brfloat->setEnabled(true);
        radioButton_brfloat->setFont(font1);

        verticalLayout->addWidget(radioButton_brfloat);

        radioButton_brint = new QRadioButton(layoutWidget);
        radioButton_brint->setObjectName(QStringLiteral("radioButton_brint"));
        radioButton_brint->setFont(font1);

        verticalLayout->addWidget(radioButton_brint);

        radioButton_brstep = new QRadioButton(layoutWidget);
        radioButton_brstep->setObjectName(QStringLiteral("radioButton_brstep"));
        radioButton_brstep->setFont(font1);

        verticalLayout->addWidget(radioButton_brstep);

        radioButton_vu = new QRadioButton(layoutWidget);
        radioButton_vu->setObjectName(QStringLiteral("radioButton_vu"));
        radioButton_vu->setFont(font1);

        verticalLayout->addWidget(radioButton_vu);

        radioButton_dll = new QRadioButton(layoutWidget);
        radioButton_dll->setObjectName(QStringLiteral("radioButton_dll"));
        radioButton_dll->setFont(font1);

        verticalLayout->addWidget(radioButton_dll);

        pushButton_drawone = new QPushButton(centralWidget);
        pushButton_drawone->setObjectName(QStringLiteral("pushButton_drawone"));
        pushButton_drawone->setGeometry(QRect(240, 390, 230, 46));
        pushButton_drawone->setFont(font);
        pushButton_drawmany = new QPushButton(centralWidget);
        pushButton_drawmany->setObjectName(QStringLiteral("pushButton_drawmany"));
        pushButton_drawmany->setGeometry(QRect(240, 590, 230, 50));
        pushButton_drawmany->setFont(font);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 350, 221, 121));
        gridLayout = new QGridLayout(layoutWidget1);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(8);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(11);
        font2.setBold(false);
        font2.setWeight(50);
        label_2->setFont(font2);

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        lineEdit_xbeg = new QLineEdit(layoutWidget1);
        lineEdit_xbeg->setObjectName(QStringLiteral("lineEdit_xbeg"));
        lineEdit_xbeg->setFont(font);

        gridLayout->addWidget(lineEdit_xbeg, 0, 1, 1, 1);

        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        lineEdit_ybeg = new QLineEdit(layoutWidget1);
        lineEdit_ybeg->setObjectName(QStringLiteral("lineEdit_ybeg"));
        lineEdit_ybeg->setFont(font);

        gridLayout->addWidget(lineEdit_ybeg, 1, 1, 1, 1);

        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font2);

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_xend = new QLineEdit(layoutWidget1);
        lineEdit_xend->setObjectName(QStringLiteral("lineEdit_xend"));
        lineEdit_xend->setFont(font);

        gridLayout->addWidget(lineEdit_xend, 2, 1, 1, 1);

        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        lineEdit_yend = new QLineEdit(layoutWidget1);
        lineEdit_yend->setObjectName(QStringLiteral("lineEdit_yend"));
        lineEdit_yend->setFont(font);

        gridLayout->addWidget(lineEdit_yend, 3, 1, 1, 1);

        gridLayout->setColumnStretch(0, 8);
        gridLayout->setColumnStretch(1, 5);
        layoutWidget2 = new QWidget(centralWidget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 551, 221, 121));
        gridLayout_2 = new QGridLayout(layoutWidget2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(8);
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(layoutWidget2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFont(font2);

        gridLayout_2->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_xc = new QLineEdit(layoutWidget2);
        lineEdit_xc->setObjectName(QStringLiteral("lineEdit_xc"));
        lineEdit_xc->setFont(font);

        gridLayout_2->addWidget(lineEdit_xc, 0, 1, 1, 1);

        label_6 = new QLabel(layoutWidget2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFont(font);

        gridLayout_2->addWidget(label_6, 1, 0, 1, 1);

        lineEdit_yc = new QLineEdit(layoutWidget2);
        lineEdit_yc->setObjectName(QStringLiteral("lineEdit_yc"));
        lineEdit_yc->setFont(font);

        gridLayout_2->addWidget(lineEdit_yc, 1, 1, 1, 1);

        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFont(font2);

        gridLayout_2->addWidget(label_8, 2, 0, 1, 1);

        lineEdit_angle = new QLineEdit(layoutWidget2);
        lineEdit_angle->setObjectName(QStringLiteral("lineEdit_angle"));
        lineEdit_angle->setFont(font);

        gridLayout_2->addWidget(lineEdit_angle, 2, 1, 1, 1);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFont(font2);

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        lineEdit_len = new QLineEdit(layoutWidget2);
        lineEdit_len->setObjectName(QStringLiteral("lineEdit_len"));
        lineEdit_len->setFont(font);

        gridLayout_2->addWidget(lineEdit_len, 3, 1, 1, 1);

        gridLayout_2->setColumnStretch(0, 8);
        gridLayout_2->setColumnStretch(1, 5);
        pushButton_clean = new QPushButton(centralWidget);
        pushButton_clean->setObjectName(QStringLiteral("pushButton_clean"));
        pushButton_clean->setGeometry(QRect(850, 760, 151, 41));
        pushButton_clean->setFont(font);
        draw_label = new QLabel(centralWidget);
        draw_label->setObjectName(QStringLiteral("draw_label"));
        draw_label->setEnabled(true);
        draw_label->setGeometry(QRect(590, 20, 710, 710));
        draw_label->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1400, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        LinesColourLabel->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \320\273\320\270\320\275\320\270\320\271:", nullptr));
        LinesColourcomboBox->setItemText(0, QApplication::translate("MainWindow", "\321\207\320\265\321\200\320\275\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(1, QApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(2, QApplication::translate("MainWindow", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(3, QApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(4, QApplication::translate("MainWindow", "\320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        LinesColourcomboBox->setItemText(5, QApplication::translate("MainWindow", "\321\201\320\270\320\275\320\270\320\271", nullptr));

        BackgroundColorLabel->setText(QApplication::translate("MainWindow", "\320\246\320\262\320\265\321\202 \321\204\320\276\320\275\320\260:", nullptr));
        BackgroundColourcomboBox->setItemText(0, QApplication::translate("MainWindow", "\320\261\320\265\320\273\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(1, QApplication::translate("MainWindow", "\321\207\320\265\321\200\320\275\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(2, QApplication::translate("MainWindow", "\320\266\320\265\320\273\321\202\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(3, QApplication::translate("MainWindow", "\320\272\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(4, QApplication::translate("MainWindow", "\321\201\320\270\320\275\320\270\320\271", nullptr));
        BackgroundColourcomboBox->setItemText(5, QApplication::translate("MainWindow", "\320\267\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));

        label->setText(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274:", nullptr));
        radioButton_cda->setText(QApplication::translate("MainWindow", "\320\246\320\224\320\220", nullptr));
        radioButton_brfloat->setText(QApplication::translate("MainWindow", " \320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\321\202\320\265\320\273\321\214\320\275\321\213\320\274\320\270 \321\207\320\270\321\201\320\273\320\260\320\274\320\270", nullptr));
        radioButton_brint->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \321\206\320\265\320\273\321\213\320\274\320\270 \321\207\320\270\321\201\320\273\320\260\320\274\320\270", nullptr));
        radioButton_brstep->setText(QApplication::translate("MainWindow", "\320\221\321\200\320\265\320\267\320\265\320\275\321\205\320\265\320\274\320\260 \321\201 \321\203\321\201\321\202\321\200\320\260\320\275\320\265\320\275\320\270\320\265\320\274 \321\201\321\202\321\203\320\277\320\265\320\275\321\207\320\260\321\202\320\276\321\201\321\202\320\270", nullptr));
        radioButton_vu->setText(QApplication::translate("MainWindow", "\320\222\321\203", nullptr));
        radioButton_dll->setText(QApplication::translate("MainWindow", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\321\207\320\275\321\213\320\271", nullptr));
        pushButton_drawone->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\200\320\265\320\267\320\276\320\272", nullptr));
        pushButton_drawmany->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\276\321\202\321\200\320\265\320\267\320\272\320\270", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\245 \320\275\320\260\321\207\320\260\320\273\320\260:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "Y \320\275\320\260\321\207\320\260\320\273\320\260:", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\320\245 \320\272\320\276\320\275\321\206\320\260:", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Y \320\272\320\276\320\275\321\206\320\260:", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "\320\245 \321\206\320\265\320\275\321\202\321\200\320\260:", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "Y \321\206\320\265\320\275\321\202\321\200\320\260:", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "\320\243\320\263\320\276\320\273:", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\320\224\320\273\320\270\320\275\320\260:", nullptr));
        pushButton_clean->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214 \320\262\321\201\320\265", nullptr));
        draw_label->setText(QString());
        menu->setTitle(QApplication::translate("MainWindow", "\320\220\320\273\320\263\320\276\321\200\320\270\321\202\320\274\321\213 \321\200\320\270\321\201\320\276\320\262\320\260\320\275\320\270\321\217 \320\276\321\202\321\200\320\265\320\267\320\272\320\276\320\262", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
