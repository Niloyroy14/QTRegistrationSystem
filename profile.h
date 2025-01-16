#ifndef PROFILE_H
#define PROFILE_H

#include <QDialog>
#include "connection.h"

namespace Ui {
class Profile;
}

class Profile : public QDialog
{
    Q_OBJECT

public:
    explicit Profile(QWidget *parent = nullptr);
    ~Profile();

     connection connDB;
     void setUserID(int id);
     int getUserID() const;
     void setUserInfo(const QString &username, const QString &phone);
    QString generateUniqueFileName(const QString &filePath);

private slots:
    void on_uploadButton_clicked();

private:
    Ui::Profile *ui;
    int userId;
};

#endif // PROFILE_H
