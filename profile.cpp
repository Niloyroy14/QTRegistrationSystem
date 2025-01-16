#include "profile.h"
#include "ui_profile.h"
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
#include <QLabel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QDateTime>
#include <QRandomGenerator>
#include <QFileInfo>



Profile::Profile(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Profile)
{
    ui->setupUi(this);
}

void Profile::setUserID(int id) {
    userId = id;
}

int Profile::getUserID() const {
    return userId;
}

void Profile::setUserInfo(const QString &username, const QString &phone) {
    ui->profileNameLabel->setText(username);
    ui->phonelabelValue->setText(phone);
    int userId = getUserID();

    QString imagePath;
    QPixmap profileImage;

   if(connDB.dbConnectionOpen()){
     QSqlQuery query;
     query.prepare("SELECT * FROM users WHERE id = :id");
     query.bindValue(":id", userId);
     query.exec();

     // Set the path to your database field that stores the image path
     if (query.next()) {
         imagePath = query.value("image").toString();
     }

     // Load the image from the file path
     profileImage.load(imagePath);

     // Resize the image if necessary
     profileImage = profileImage.scaled(200, 200, Qt::KeepAspectRatio);

     // Set the image as the pixmap for the QLabel
     ui->userProfileView->setPixmap(profileImage);
     ui->userProfileView->setScaledContents(true);

    }

    //ui->userIdLabel->setText(QString::number(userid));
   // qDebug() << "UserID: " << userid;
}


QString Profile::generateUniqueFileName(const QString &filePath)
{
    // Get the original file name
    QFileInfo fileInfo(filePath);
    QString originalFileName = fileInfo.fileName();

    // Get the file extension
    QString fileExtension = fileInfo.completeSuffix();

    // Get the current timestamp
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString timestamp = currentDateTime.toString("yyyyMMdd_hhmmss");

    // Generate a random number
    quint32 randomNumber = QRandomGenerator::global()->generate();

    // Combine the timestamp, random number, original file name, and file extension to create a unique file name
    QString uniqueFileName = timestamp + "_" + QString::number(randomNumber) + "_" + originalFileName;

    return uniqueFileName;
}

Profile::~Profile()
{
    delete ui;
}


void Profile::on_uploadButton_clicked()
{
      int userid = getUserID();
    // Open a file dialog to select an image file
       QString filePath = QFileDialog::getOpenFileName(this, tr("Select Image"), "", tr("Image Files (*.png *.jpg *.jpeg)"));

       if (!filePath.isEmpty()){

            QImage image(filePath);

           // Load the selected image file
              if (!image.load(filePath))
              {
                  // Error handling if image loading fails
                  QMessageBox::critical(this, tr("Error"), tr("Failed to load image."));
                  return;
              }

            ui->userProfileView->setPixmap(QPixmap::fromImage(image));
            ui->userProfileView->setScaledContents(true);

            // Generate a unique file name
            QString uniqueFileName = generateUniqueFileName(filePath);

            // Create a directory to store the uploaded images if it doesn't exist
                 QString imagesFolderPath = QCoreApplication::applicationDirPath() + "/images";
                 QDir imagesDir(imagesFolderPath);
                 if (!imagesDir.exists())
                 {
                     imagesDir.mkpath(".");
                 }

                 // Move the file to the images folder
                 QString destinationPath = imagesFolderPath + "/" + uniqueFileName;

                 if (QFile::copy(filePath, destinationPath))
                 {
                     // Update the database with the new file path
                     QString resourceFilePath = destinationPath;

                     // ... Connect to the database and execute the SQL query to update the database as shown in the previous response

                     if(connDB.dbConnectionOpen()){

                         QSqlQuery query;
                          // Prepare the SQL query to update the database
                          QString queryString = "UPDATE users SET image = :picture WHERE id = :userId";
                          query.prepare(queryString);
                          query.bindValue(":picture", resourceFilePath);
                          query.bindValue(":userId", userid);
                             // Execute the query
                             if (query.exec()){
                                  // Database updated successfully
                                   QMessageBox::information(this, "Success", "Profile picture updated!");
                               }else{
                                     // Error updating the database
                                    QMessageBox::critical(this, "Error", "Failed to update the profile picture in the database.");
                               }
                     }
                 }
                 else
                 {
                     // Error moving the file
                     QMessageBox::critical(this, "Error", "Failed to move the file.");
                 }
             }


  }







