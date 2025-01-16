#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include "profile.h"
#include "connection.h"
#include "userlist.h"



namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

    connection connDB;
    void setUserID(int id);
    int getUserID() const;

private slots:
    void on_pushButton_clicked();

    void on_profileBtn_clicked();

private:
    Ui::MyDialog *ui;
    int userId;
    Profile  *profileDailouge;
    userlist *myList;
};

#endif // MYDIALOG_H
