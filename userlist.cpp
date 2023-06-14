#include "userlist.h"
#include "ui_userlist.h"

UserList::UserList(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UserList)
{
    ui->setupUi(this);

    if(connDB.dbConnectionOpen()){

        querymodel = new QSqlQueryModel();

        querymodel->setQuery("SELECT * FROM users");
        ui->tableView->setModel(querymodel);

    }
}

UserList::~UserList()
{
    delete ui;
}
