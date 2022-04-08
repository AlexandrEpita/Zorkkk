#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QGuiApplication>
#include <QPixmap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void readfile();

    void on_pushButton_Up_clicked();

    void on_pushButton_Left_clicked();

    void on_pushButton_Down_clicked();

    void on_pushButton_Right_clicked();

    void on_pushButton_Info_clicked();

    void on_pushButton_Leave_clicked();

    void on_lineEdit_editingFinished();

    void hideall();

    void restart();

    void showall();

    void on_pushButton_Leave_2_clicked();

    void on_pushButton_yes_clicked();

    void on_pushButton_yeschris_clicked();

    void on_pushButton_teleport_clicked();

    void on_lineEdit_5_editingFinished();

    void on_pushButton_attack_clicked();

    void on_pushButton_Maps_clicked();


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
