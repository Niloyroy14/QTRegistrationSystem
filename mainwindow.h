#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "mydialog.h"
#include "connection.h"
#include  "register.h"


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

private:
    Ui::MainWindow *ui;
    Register *registerDailouge;

};

#endif // MAINWINDOW_H
