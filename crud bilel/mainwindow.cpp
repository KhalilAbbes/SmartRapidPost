#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTableView>
#include "colis.h"
#include "courrier.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tabcolis->setModel(tmpcolis.afficher());//refresh
    ui->tabcourrier->setModel(tmpc.afficher());//refresh
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    float poids = ui->lineEdit_poids->text().toInt();
    QString source= ui->lineEdit_source->text();
    QString destinataire= ui->lineEdit_destination->text();

 colis c(id,poids,source,destinataire);
  bool test=c.ajouter();
  if(test)
{

      ui->tabcolis->setModel(tmpcolis.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un courrier"),
                  QObject::tr("Courrier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un colis"),
                  QObject::tr("Erreur zab !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{ int id = ui->lineEdit_Sid->text().toInt();
    bool test=tmpcolis.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un courrier"),
                    QObject::tr("courrier supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tabcolis->setModel(tmpcolis.afficher());//refresh


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un courrier"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}






void MainWindow::on_pushButton_2_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    int nbrpiece = ui->lineEdit_nbrpiece->text().toInt();
    QString expediteur= ui->lineEdit_expediteur->text();
    QString destinateur= ui->lineEdit_destinateur->text();
 courrier e(id,nbrpiece,expediteur,destinateur);
  bool test=e.ajouter();
  if(test)
{

      ui->tabcourrier->setModel(tmpc.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un courrier"),
                  QObject::tr("Courrier ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un courrier"),
                  QObject::tr("Erreur  !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_3_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    bool test=tmpc.supprimer(id);
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("Supprimer un courrier"),
                    QObject::tr("courrier supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

        ui->tabcourrier->setModel(tmpc.afficher());//refresh


    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un courrier"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void MainWindow::on_pushButton_4_clicked()
{   //fonction TRI courrier
    QSqlQuery query;
        ui->listWidgetCourrier->clear();
        query.exec("select * from COURRIER ORDER BY ID ASC");
        while(query.next())
        {
         QString id=query.value(0).toString();
         QString nbrpiece=query.value(1).toString();
         QString expediteur=query.value(2).toString();
         QString destinateur=query.value(3).toString();
         QString ch=id+"                                 "+nbrpiece+"                                      "+expediteur+"                             "+destinateur;
         ui->listWidgetCourrier->addItem(ch);
        }
}

void MainWindow::on_pushButton_TRICOLIS_clicked()
{   //fonction TRI
    //colis(id,poids,source,destinataire)
    QSqlQuery query;
        ui->listWidgetCOLIS->clear();
        query.exec("select * from colis ORDER BY ID ASC");
        while(query.next())
        {
         QString id=query.value(0).toString();
         QString poids=query.value(1).toString();
         QString source=query.value(2).toString();
         QString destinataire=query.value(3).toString();
         QString ch=id+"                                 "+poids+"                                      "+source+"                             "+destinataire;
         ui->listWidgetCOLIS->addItem(ch);
        }
}



void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    //fonction recherch COLIS
        //colis(id,poids,source,destinataire)
       ui->listWidgetCOLIS->clear();
               QSqlQuery query;
               //query.prepare("SELECT * from COLIS where id=:nombre");
               query.prepare("SELECT * from colis where substr(to_char(POIDS),1,:size) like :nombre");
               query.bindValue(":nombre",arg1);
               query.bindValue(":size",arg1.size());
               query.exec();
               while(query.next())
               {
                   QString id=query.value(0).toString();
                   QString poids=query.value(1).toString();
                   QString source=query.value(2).toString();
                   QString destinataire=query.value(3).toString();
                   QString ch=id+"                                 "+poids+"                                      "+source+"                             "+destinataire;
                   ui->listWidgetCOLIS->addItem(ch);
               }
}
void MainWindow::on_lineEdit_Tri_textChanged(const QString &arg1)
{  //fonction recherch courrier

           ui->listWidgetCourrier->clear();
                   QSqlQuery query;
                   //query.prepare("SELECT * from COURRIER where ID=:nombre");
                   query.prepare("SELECT * from COURRIER  where substr(to_char(ID),1,:size) like :nombre");
                   query.bindValue(":nombre",arg1);
                   query.bindValue(":size",arg1.size());
                   query.exec();
                   while(query.next())
                   {
                       QString id=query.value(0).toString();
                       QString nbrpiece=query.value(1).toString();
                       QString expediteur=query.value(2).toString();
                       QString destinateur=query.value(3).toString();
                       QString ch=id+"                                  "+nbrpiece+"                                        "+expediteur+"                                              "+destinateur;
                       ui->listWidgetCourrier->addItem(ch);
                   }

}
