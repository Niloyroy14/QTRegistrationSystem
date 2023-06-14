#include "mainwindow.h"
#include "ui_mainwindow.h"

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

                QString usernameFromDB = query.value(1).toString();
                QString passwordFromDB = query.value(2).toString();

                if(usernameFromDB == username && passwordFromDB == password){
                     QMessageBox::information(this, "Success", "Login Success");
                      MyDialog dailog;
                      dailog.setModal(true);
                      dailog.exec();
                }else{
                     QMessageBox::information(this, "Failed", "Login Failed");
                }
            }
        }
     }else{
        QMessageBox::information(this, "Not Connected", "Database Is Not Connected Successfully");
     }

    }
}

void MainWindow::on_registerDailougOpen_clicked()
{
       hide();
       registerDailouge = new Register(this);
       registerDailouge->show();
}
