#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "promotion.h"
#include "fidelite.h"

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
    ui->tabpromotion->setModel(tmppromotion.afficher());//refresh
}

void MainWindow::on_pushButton_21_clicked()
{
    int ref = ui->lineEdit_ref->text().toInt();
    QString article= ui->lineEdit_article->text();
    float pourcentage= ui->lineEdit_pourcentage->text().toFloat();
    QString d=ui->lineEdit_d->text();
    QString f=ui->lineEdit_f->text();
    int statut=ui->lineEdit_statut->text().toInt();


  promotion p(ref,article,pourcentage,d,f,statut);
  bool test=p.ajouter();

  if(test)
{

ui->tabpromotion->setModel(tmppromotion.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une promotion"),
                  QObject::tr("Promotion ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une promotion"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


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
    ui->tabfidelite->setModel(tmpfidelite.afficher());//refresh


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
    int reff = ui->lineEdit_2->text().toInt();
    bool test=tmppromotion.supprimer(reff);
    if(test)
    {ui->tabpromotion->setModel(tmppromotion.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("Promotion supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une promotion"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



}

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit->text().toInt();
    int num= ui->lineEdit_4->text().toInt();
    QString date=ui->lineEdit_5->text();
    int point=ui->lineEdit_6->text().toInt();


  fidelite f(id,num,date,point);
  bool test=f.ajouter();

  if(test)
{

ui->tabfidelite->setModel(tmpfidelite.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une Carte"),
                  QObject::tr("Carte ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une Carte"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_7_clicked()
{
    int idd = ui->lineEdit_3->text().toInt();
    bool test=tmpfidelite.supprimer(idd);
    if(test)
    {ui->tabfidelite->setModel(tmpfidelite.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une Carte"),
                    QObject::tr("Carte supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une Carte"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_27_clicked()
{
    QSqlQuery query;
            QString num = ui->lineEdit_9->text();
            QString point=ui->lineEdit_8->text();
            query.prepare("update fidelite set point=point+:point WHERE NUM =:num");
            query.bindValue(":num",num);
            query.bindValue(":point",point);

            bool t=query.exec();
                   if(t)
                   {
                       ui->tabfidelite->setModel(tmpfidelite.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Ajouter des points"),
                                   QObject::tr("Points ajoutés.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Ajouter des points"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}

void MainWindow::on_pushButton_23_clicked()
{
    QSqlQuery query;
    QString ref = ui->lineEdit_ref_2->text();
    QString article= ui->lineEdit_article_2->text();
    QString pourcentage= ui->lineEdit_pourcentage_2->text();
    QString d=ui->lineEdit_d_2->text();
    QString f=ui->lineEdit_f_2->text();
    QString statut=ui->lineEdit_statut_2->text();
            query.prepare("update PROMOTIONS set REF=:ref ,ARTICLE=:article ,POURCENTAGE=:pourcentage ,DATE_DEBUT=:d ,DATE_FIN=:f ,STATUT=:statut WHERE REF =:ref");
            query.bindValue(":ref",ref);
            query.bindValue(":article",article);
            query.bindValue(":pourcentage",pourcentage);
            query.bindValue(":d",d);
            query.bindValue(":f",f);
            query.bindValue(":statut",statut);

            bool t=query.exec();
                   if(t)
                   {
                       ui->tabpromotion->setModel(tmppromotion.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Promotion modifié.\n"
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
    QString id = ui->lineEdit_7->text();
    QString num= ui->lineEdit_10->text();
    QString date= ui->lineEdit_11->text();
    QString point=ui->lineEdit_12->text();

            query.prepare("update fidelite set ID_CLIENT=:id ,NUM=:num ,DATES=:date ,POINT=:point WHERE ID_CLIENT =:id");
            query.bindValue(":id",id);
            query.bindValue(":num",num);
            query.bindValue(":date",date);
            query.bindValue(":point",point);


            bool t=query.exec();
                   if(t)
                   {
                       ui->tabfidelite->setModel(tmpfidelite.afficher());//refresh
                   QMessageBox::information(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Fidelite modifié.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);

                   }
                   else
                      { QMessageBox::critical(nullptr, QObject::tr("Modifier"),
                                   QObject::tr("Erreur !.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
}
}


