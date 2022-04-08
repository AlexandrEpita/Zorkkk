/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton_Down;
    QPushButton *pushButton_Right;
    QPushButton *pushButton_Left;
    QPushButton *pushButton_Up;
    QPushButton *pushButton_Leave;
    QComboBox *comboBox;
    QPushButton *pushButton_Info;
    QTextEdit *textEdit;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_Leave_2;
    QComboBox *comboBox_2;
    QPushButton *pushButton_yes;
    QPushButton *pushButton_yeschris;
    QPushButton *pushButton_teleport;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_attack;
    QPushButton *pushButton_Maps;
    QMenuBar *menubar;
    QMenu *menuZork_Game_for_the_players;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(806, 606);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton_Down = new QPushButton(centralwidget);
        pushButton_Down->setObjectName(QString::fromUtf8("pushButton_Down"));
        pushButton_Down->setEnabled(true);
        pushButton_Down->setGeometry(QRect(740, 520, 30, 30));
        pushButton_Right = new QPushButton(centralwidget);
        pushButton_Right->setObjectName(QString::fromUtf8("pushButton_Right"));
        pushButton_Right->setEnabled(true);
        pushButton_Right->setGeometry(QRect(770, 490, 30, 30));
        pushButton_Left = new QPushButton(centralwidget);
        pushButton_Left->setObjectName(QString::fromUtf8("pushButton_Left"));
        pushButton_Left->setEnabled(true);
        pushButton_Left->setGeometry(QRect(710, 490, 30, 30));
        pushButton_Up = new QPushButton(centralwidget);
        pushButton_Up->setObjectName(QString::fromUtf8("pushButton_Up"));
        pushButton_Up->setEnabled(true);
        pushButton_Up->setGeometry(QRect(740, 460, 30, 30));
        pushButton_Leave = new QPushButton(centralwidget);
        pushButton_Leave->setObjectName(QString::fromUtf8("pushButton_Leave"));
        pushButton_Leave->setEnabled(true);
        pushButton_Leave->setGeometry(QRect(0, 520, 90, 30));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setEnabled(true);
        comboBox->setGeometry(QRect(0, 430, 90, 30));
        pushButton_Info = new QPushButton(centralwidget);
        pushButton_Info->setObjectName(QString::fromUtf8("pushButton_Info"));
        pushButton_Info->setEnabled(true);
        pushButton_Info->setGeometry(QRect(0, 490, 90, 30));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setEnabled(true);
        textEdit->setGeometry(QRect(90, 430, 611, 121));
        textEdit->setReadOnly(true);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(315, 200, 120, 28));
        lineEdit->setClearButtonEnabled(true);
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(290, 160, 170, 28));
        lineEdit_2->setReadOnly(true);
        lineEdit_3 = new QLineEdit(centralwidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(0, 0, 100, 28));
        lineEdit_3->setReadOnly(true);
        pushButton_Leave_2 = new QPushButton(centralwidget);
        pushButton_Leave_2->setObjectName(QString::fromUtf8("pushButton_Leave_2"));
        pushButton_Leave_2->setEnabled(true);
        pushButton_Leave_2->setGeometry(QRect(0, 460, 90, 30));
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(710, 425, 90, 30));
        comboBox_2->setAcceptDrops(false);
        comboBox_2->setEditable(false);
        pushButton_yes = new QPushButton(centralwidget);
        pushButton_yes->setObjectName(QString::fromUtf8("pushButton_yes"));
        pushButton_yes->setGeometry(QRect(-8, 295, 410, 260));
        pushButton_yeschris = new QPushButton(centralwidget);
        pushButton_yeschris->setObjectName(QString::fromUtf8("pushButton_yeschris"));
        pushButton_yeschris->setGeometry(QRect(400, 295, 410, 260));
        pushButton_teleport = new QPushButton(centralwidget);
        pushButton_teleport->setObjectName(QString::fromUtf8("pushButton_teleport"));
        pushButton_teleport->setGeometry(QRect(720, 0, 83, 29));
        lineEdit_4 = new QLineEdit(centralwidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(2, 250, 661, 28));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(210, 110, 521, 231));
        lineEdit_5 = new QLineEdit(centralwidget);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(330, 80, 113, 28));
        pushButton_attack = new QPushButton(centralwidget);
        pushButton_attack->setObjectName(QString::fromUtf8("pushButton_attack"));
        pushButton_attack->setGeometry(QRect(0, 460, 90, 30));
        pushButton_Maps = new QPushButton(centralwidget);
        pushButton_Maps->setObjectName(QString::fromUtf8("pushButton_Maps"));
        pushButton_Maps->setGeometry(QRect(710, 395, 90, 30));
        MainWindow->setCentralWidget(centralwidget);
        textEdit->raise();
        pushButton_Down->raise();
        pushButton_Right->raise();
        pushButton_Left->raise();
        pushButton_Up->raise();
        pushButton_Leave->raise();
        comboBox->raise();
        pushButton_Info->raise();
        lineEdit->raise();
        lineEdit_2->raise();
        lineEdit_3->raise();
        pushButton_Leave_2->raise();
        comboBox_2->raise();
        pushButton_yes->raise();
        pushButton_yeschris->raise();
        pushButton_teleport->raise();
        lineEdit_4->raise();
        label->raise();
        lineEdit_5->raise();
        pushButton_attack->raise();
        pushButton_Maps->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 806, 25));
        menuZork_Game_for_the_players = new QMenu(menubar);
        menuZork_Game_for_the_players->setObjectName(QString::fromUtf8("menuZork_Game_for_the_players"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuZork_Game_for_the_players->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_Down->setText(QCoreApplication::translate("MainWindow", "v", nullptr));
        pushButton_Right->setText(QCoreApplication::translate("MainWindow", ">", nullptr));
        pushButton_Left->setText(QCoreApplication::translate("MainWindow", "<", nullptr));
        pushButton_Up->setText(QCoreApplication::translate("MainWindow", "^", nullptr));
        pushButton_Leave->setText(QCoreApplication::translate("MainWindow", "Leave", nullptr));
        pushButton_Info->setText(QCoreApplication::translate("MainWindow", "Restart", nullptr));
        lineEdit->setText(QString());
        lineEdit_2->setText(QCoreApplication::translate("MainWindow", "  What's your name Boss?", nullptr));
        pushButton_Leave_2->setText(QCoreApplication::translate("MainWindow", "Take", nullptr));
        pushButton_yes->setText(QCoreApplication::translate("MainWindow", "Yes", nullptr));
        pushButton_yeschris->setText(QCoreApplication::translate("MainWindow", "Yes Chris !", nullptr));
        pushButton_teleport->setText(QCoreApplication::translate("MainWindow", "teleport", nullptr));
        lineEdit_4->setText(QCoreApplication::translate("MainWindow", "Do you want the key that will allow you to wordle vs Lord Voldemort aka the m\303\251chant tr\303\250s tr\303\250s m\303\251chant (he is dangerous)!!", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "                        [Chamber of Secrets] --- [Lake] --- [Gare At\303\251faice]\n"
"    	         	                                         |\n"
"                                                                    |\n"
"                      [Life Question Room] --- [Spawn] --- [Bite]\n"
"	 		                            |\n"
" 		                                         |\n"
" [Room of Requirement]--[Corridor] --- [Hall] --- [Queen's Wardrobe]", nullptr));
        pushButton_attack->setText(QCoreApplication::translate("MainWindow", "Attack", nullptr));
        pushButton_Maps->setText(QCoreApplication::translate("MainWindow", "Map", nullptr));
        menuZork_Game_for_the_players->setTitle(QCoreApplication::translate("MainWindow", "Zork Game : for the players", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
