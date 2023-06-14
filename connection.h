#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QSqlDatabase>
#include <QMessageBox>

namespace Ui {
class connection;
}

class connection : public QDialog
{
    Q_OBJECT

public:

    QSqlDatabase db;

    bool dbConnectionOpen(){

        db = QSqlDatabase::addDatabase("QMYSQL");

        db.setHostName("localhost");
        db.setDatabaseName("qt5");
        db.setUserName("root");
        db.setPassword("");

        if(db.open()){
           // QMessageBox::information(this, "Connected", "Database Connected Successfully");
            return true;
        }else{
            QMessageBox::information(this, "Not Connected", "Database Is Not Connected Successfully");
            return false;
        }
    }

    bool dbConnectionClose(){
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
        return false;
    }


    explicit connection(QWidget *parent = nullptr);
    ~connection();

private:
    Ui::connection *ui;
};

#endif // CONNECTION_H
