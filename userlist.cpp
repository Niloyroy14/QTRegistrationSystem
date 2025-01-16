#include "userlist.h"
#include "ui_userlist.h"
#include <QDebug>


userlist::userlist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userlist)
{
    ui->setupUi(this);

    if(connDB.dbConnectionOpen()){

          QSqlQueryModel  *querymodel = new QSqlQueryModel();

            querymodel->setQuery("SELECT id,username,phone,email FROM users");
            querymodel->setHeaderData(0, Qt::Horizontal, tr("ID"));
            querymodel->setHeaderData(1, Qt::Horizontal, tr("User Name"));
            querymodel->setHeaderData(2, Qt::Horizontal, tr("Phone"));
            querymodel->setHeaderData(3, Qt::Horizontal, tr("Email"));
            querymodel->setHeaderData(4, Qt::Horizontal, tr("Image"));

         //   QString imagePath = querymodel->data(querymodel->index(5, 1)).toString();
           // qDebug()<<imagePath;

            ui->tableView->setModel(querymodel);


            connDB.close();
    }

}

userlist::~userlist()
{
    delete ui;
}
