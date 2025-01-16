#include "mydialog.h"
#include "ui_mydialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::setUserID(int id) {
    userId = id;
}

int MyDialog::getUserID() const {
    return userId;
}

void MyDialog::on_pushButton_clicked()
{
//     UserList list;
//     list.setModal(true);
//     list.exec();

    // hide();
     myList = new userlist(this);
     myList->show();


}

void MyDialog::on_profileBtn_clicked()
{
    int userId = getUserID();
    QString usernameFromDB,phoneFronDB;

    if(connDB.dbConnectionOpen()){
      QSqlQuery query;
      query.prepare("SELECT * FROM users WHERE id = :id");
      query.bindValue(":id", userId);
      query.exec();

        if (query.next()) {
           usernameFromDB = query.value(1).toString();
           phoneFronDB = query.value(3).toString();
        }
    }

    profileDailouge = new Profile(this);
    profileDailouge->setUserID(userId);
    profileDailouge->setUserInfo(usernameFromDB,phoneFronDB);
    profileDailouge->show();

     connDB.dbConnectionClose();
}
