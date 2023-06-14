#include "register.h"
#include "ui_register.h"
#include "mainwindow.h"

MainWindow *mainw;

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
    ui->userName->setPlaceholderText("Enter Your Username");
    ui->password->setPlaceholderText("Enter Your Password");
    ui->email->setPlaceholderText("Enter Your Email");
    ui->phone->setPlaceholderText("Enter Your Phone");
}

Register::~Register()
{
    delete ui;
}

void Register::on_registerButton_clicked()
{
    //retrive data from input fields
      QString username = ui->userName->text();
      QString password = ui->password->text();
      QString email = ui->email->text();
      QString phone = ui->phone->text();

    if(username.isEmpty() && password.isEmpty() && email.isEmpty() && phone.isEmpty()){
         ui->regUNameValidation->setText("Username is required");
         ui->regPasswordValidation->setText("Password is required");
         ui->regEmailValidation->setText("Email is required");
         ui->regPhoneValidation->setText("Phone is required");
    }else{
        ui->regUNameValidation->setText("");
        ui->regPasswordValidation->setText("");
        ui->regEmailValidation->setText("");
        ui->regPhoneValidation->setText("");

    if(connDB.dbConnectionOpen()){

        //Run Inser query
         QSqlQuery query;
           query.prepare("INSERT INTO users (username, password, email, phone) "
                         "VALUES (:username, :password, :email, :phone)");
           query.bindValue(":username", username);
           query.bindValue(":password", password);
           query.bindValue(":email", email);
           query.bindValue(":phone", phone);
           if(query.exec()){
                  QMessageBox::information(this, "Inserted", "Registration Succesfully");

                  //back to mainwinwow after register
                  hide();
                  mainw = new MainWindow(this);
                  mainw->show();

           }else{
               QMessageBox::information(this, "Not Inserted", "Data Is Not Inserted");
           }

    }else{
        QMessageBox::information(this, "Not Connected", "Database is not connected");
    }
  }
}

void Register::on_signInButton_clicked()
{

    //back to mainwinwow for login
    hide();
    mainw = new MainWindow(this);
    mainw->show();
}
