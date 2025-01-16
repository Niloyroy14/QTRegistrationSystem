#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "mydialog.h"
#include "connection.h"
#include "register.h"
#include "profile.h"
#include "mydialog.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

     connection connDB;


private slots:

    void on_loginBtn_clicked();

    void on_registerDailougOpen_clicked();

    void openDialog(int userId);

private:
    Ui::MainWindow *ui;
    Register *registerDailouge;
    Profile  *profileDailouge;
    MyDialog *mynewdailouge;
};

#endif // MAINWINDOW_H
