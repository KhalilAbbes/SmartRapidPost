#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include "departement.h"

#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_11_clicked()
{
    ui->CRUD->setCurrentIndex(0);
}

void MainWindow::on_pushButton_12_clicked()
{
    ui->CRUD->setCurrentIndex(2);
}

void MainWindow::on_pushButton_13_clicked()
{
    ui->CRUD->setCurrentIndex(3);
    ui->tabemploye_3->setModel(tmpemploye.afficher());
}

void MainWindow::on_pushButton_21_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    QString nom=ui->lineEdit_nom_2->text();
    QString prenom=ui->lineEdit_prenom_2->text();
    int num=ui->lineEdit_num_2->text().toInt();
    QString date=ui->dateEdit_date_2->text();
    QString adresse=ui->lineEdit_adresse_2->text();
    float salaire=ui->lineEdit_salaire_2->text().toFloat();
    QString statut=ui->lineEdit_statut_3->text();
    employe e(id,nom,prenom,num,date,adresse,salaire,statut);
    bool test=e.ajouter();
    if(test)
    {
        ui->tabemploye_3->setModel(tmpemploye.afficher());
        QMessageBox::information(nullptr,QObject::tr("Ajouter un employé"),"Employé a été ajouté.");
    }
    else
      {
          QMessageBox::warning(nullptr,QObject::tr("Ajouter un employé"),"Erreur");
      }

}




void MainWindow::on_pushButton_14_clicked()
{
    ui->CRUD->setCurrentIndex(1);

}

void MainWindow::on_pushButton_26_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_22_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_19_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_30_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_10_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->CRUD_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_18_clicked()
{
    ui->CRUD_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->CRUD_2->setCurrentIndex(3);

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->CRUD_2->setCurrentIndex(2);
    ui->tabdepartement->setModel(tmpdepartement.afficherdep());//refresh


}

void MainWindow::on_pushButton_15_clicked()
{
    ui->CRUD_2->setCurrentIndex(0);

}

void MainWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->CRUD_2->setCurrentIndex(1);

}

void MainWindow::on_pushButton_6_clicked()
{
    int id=ui->lineEdit_idsupp_2->text().toInt();
    bool test=tmpemploye.supprimer(id);
    if(test)
    {ui->tabemploye_3->setModel(tmpemploye.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un employé"),
                    QObject::tr("Employé supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un employé"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);




}

void MainWindow::on_pushButton_5_clicked()
{
    int iddep = ui->lineEdit_iddep->text().toInt();
       QString nomdep=ui->lineEdit_nomdep->text();
       int numdep=ui->lineEdit_numdep->text().toInt();
       int nbrb=ui->lineEdit_nbrb->text().toInt();
       int nbre=ui->lineEdit_nbre->text().toInt();
       departement d(iddep,nomdep,numdep,nbrb,nbre);
       bool test=d.ajouterdep();
       if(test)
       {
           ui->tabdepartement->setModel(tmpdepartement.afficherdep());
           QMessageBox::information(nullptr,QObject::tr("Ajouter un departement"),"Departement a été ajouté.");
       }
       else
         {
             QMessageBox::warning(nullptr,QObject::tr("Ajouter un departement"),"Erreur");
         }

}

void MainWindow::on_pushButton_7_clicked()
{
    int idd = ui->lineEdit_suppdep->text().toInt();
    bool test=tmpdepartement.supprimerdep(idd);
    if(test)
    {ui->tabdepartement->setModel(tmpdepartement.afficherdep());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Departement supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un departement"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pushButton_23_clicked()
{
    QSqlQuery query;

        int id = ui->lineEdit_modid_3->text().toInt();
        QString nom=ui->lineEdit_modnom_3->text();
        QString prenom=ui->lineEdit_modprenom_3->text();
        int num=ui->lineEdit_modnum_3->text().toInt();
        QString date=ui->dateEdit_moddate_3->text();
        QString adresse=ui->lineEdit_modadresse_3->text();
        float salaire=ui->lineEdit_modsalaire_3->text().toFloat();
        QString statut=ui->lineEdit_modstatut_3->text();
        QString res=QString::number(id);
        QString res1=QString::number(num);
        QString res2=QString::number(salaire);
        query.prepare("update EMPLOYE set ID=:id ,NOM=:nom ,PRENOM=:prenom ,NUM=:num ,DATEE=:date ,ADRESSE=adresse ,SALAIRE=:salaire ,STATUT=:statut WHERE ID=:id");
        query.bindValue(":id", res);
        query.bindValue(":nom", nom);
        query.bindValue(":prenom", prenom);
        query.bindValue(":num",res1);
        query.bindValue(":date", date);
        query.bindValue(":adresse", adresse);
        query.bindValue(":salaire", res2);
        query.bindValue(":statut", statut);
        bool t=query.exec();
               if(t)
               {
                   ui->tabemploye_3->setModel(tmpemploye.afficher());//refresh
               QMessageBox::information(nullptr, QObject::tr("Modifier"),
                               QObject::tr("Employé modifié.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

               }
               else
                  { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                               QObject::tr("Erreur !.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_28_clicked()
{
    QSqlQuery query;
    int iddep = ui->lineEdit_iddep->text().toInt();
    QString nomdep= ui->lineEdit_nomdep->text();
    int numdep= ui->lineEdit_numdep->text().toInt();
    int nbrb=ui->lineEdit_nbrb->text().toInt();
    int nbre=ui->lineEdit_nbre->text().toInt();
    QString res=QString::number(iddep);
    QString res1=QString::number(numdep);
    QString res2=QString::number(nbrb);
    QString res3=QString::number(nbre);
            query.prepare("update departement set IDDEP=:iddep ,NOMDEP=:nomdep ,NUMDEP=:numdep ,NBRB=:nbrb ,NBRE=:nbre WHERE IDDEP =:iddep");
            query.bindValue(":iddep",res);
            query.bindValue(":nomdep",nomdep);
            query.bindValue(":numdep",res1);
            query.bindValue(":nbrb",res2);
            query.bindValue(":nbre",res3);


            bool t=query.exec();
                   if(t)
                   {
                       ui->tabdepartement->setModel(tmpdepartement.afficherdep());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Departement modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}





void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->CRUD_2->setCurrentIndex(4);
}

