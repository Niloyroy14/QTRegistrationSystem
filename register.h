#ifndef REGISTER_H
#define REGISTER_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "connection.h"


namespace Ui {
class Register;
}

class Register : public QDialog
{
    Q_OBJECT

public:
    explicit Register(QWidget *parent = nullptr);
    ~Register();

     connection connDB;

private slots:
    void on_registerButton_clicked();

    void on_signInButton_clicked();

private:
    Ui::Register *ui;
};

#endif // REGISTER_H
