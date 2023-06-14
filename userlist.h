#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include "connection.h"

namespace Ui {
class UserList;
}

class UserList : public QDialog
{
    Q_OBJECT

public:
    explicit UserList(QWidget *parent = nullptr);
    ~UserList();
     connection connDB;

private:
    Ui::UserList *ui;
    QSqlQueryModel *querymodel;
};

#endif // USERLIST_H
