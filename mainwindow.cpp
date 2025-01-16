#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDate>
#include <QTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->userNameLogin->setPlaceholderText("Enter Your Username");
    ui->passwordLogin->setPlaceholderText("Enter Your Password");


}

MainWindow::~MainWindow()
{
    delete ui;
    //delete mynewdailouge;
}


void MainWindow::on_loginBtn_clicked()
{

    QString username = ui->userNameLogin->text();
    QString password = ui->passwordLogin->text();


    if(username.isEmpty() && password.isEmpty()){
         ui->usernameValidation->setText("Username is required");
         ui->passwordValidation->setText("Password is required");
    }else if(username.isEmpty()){
        ui->usernameValidation->setText("Username is required");
         ui->passwordValidation->setText("");
    }else if (password.isEmpty()) {
         ui->passwordValidation->setText("Password is required");
          ui->usernameValidation->setText("");
    }else{
        ui->usernameValidation->setText("");
        ui->passwordValidation->setText("");

      if(connDB.dbConnectionOpen()){
        QSqlQuery query(QSqlDatabase::database("MyConnect"));

        query.prepare(QString("SELECT * FROM users WHERE username = :username AND password = :password"));

        query.bindValue(":username",username);
        query.bindValue(":password",password);

        if(!query.exec()){
            QMessageBox::information(this, "Failed", "Qury Failed to Execute");
        }else{
            while(query.next()){
                int userId = query.value(0).toInt();
                QString usernameFromDB = query.value(1).toString();
                QString passwordFromDB = query.value(2).toString();
                QString phoneFronDB = query.value(3).toString();

                if(usernameFromDB == username && passwordFromDB == password){
                   //  QMessageBox::information(this, "Success", "Login Success");


                   //    hide(); // hide main window
                      //open my dialouge
                      openDialog(userId);
                      connDB.dbConnectionClose();

                      //open dailouge modal
                       /*
                       MyDialog dailog;
                       dailog.setModal(true);
                       dailog.exec();
                       */

                       //show user profile
                       /*
                        profileDailouge = new Profile(this);
                        profileDailouge->setUserID(userId);
                        profileDailouge->setUserInfo(usernameFromDB,phoneFronDB);
                        profileDailouge->show();
                        */
                }else{
                     QMessageBox::information(this, "Failed", "Login Failed");
                      connDB.dbConnectionClose();
                }
            }
        }
     }else{
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected Successfully");
         connDB.dbConnectionClose();
     }

    }
}


void MainWindow::openDialog(int userId) {
    qDebug() << "openDialog called";
    mynewdailouge = new MyDialog(this);
    /*
    connect(mynewdailouge, &MyDialog::finished, this, [=]() {
                mynewdailouge->hide(); // Reuse the dialog instead of destroying it
            });
    */
    mynewdailouge->setUserID(userId);
    mynewdailouge->exec();
}


void MainWindow::on_registerDailougOpen_clicked()
{
       hide();
       registerDailouge = new Register(this);
       registerDailouge->show();

}





