#ifndef USERLIST_H
#define USERLIST_H

#include <QDialog>
#include "connection.h"
#include <QSqlTableModel>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>

namespace Ui {
class userlist;
}

class userlist : public QDialog
{
    Q_OBJECT

public:
    explicit userlist(QWidget *parent = nullptr);
    ~userlist();
    connection connDB;

private:
    Ui::userlist *ui;
};

#endif // USERLIST_H
