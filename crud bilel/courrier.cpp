#include "courrier.h"
#include <QDebug>
#include "connexion.h"

courrier::courrier()
{
   id=0;
   nbrpiece=0;
   expediteur="";
   destinateur="";

}
courrier::courrier(int id ,int nbrpiece ,QString expediteur ,QString destinateur )
{
    this->id=id;
    this->nbrpiece=nbrpiece;
    this->expediteur=expediteur;
    this->destinateur=destinateur;

}
int courrier::get_id(){return id;}
int courrier::get_nbrpiece(){return nbrpiece ;}
QString courrier::get_expediteur(){return expediteur;}
QString courrier::get_destinateur(){return destinateur;}

bool courrier::ajouter(){
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("INSERT INTO courrier (id ,nbrpiece,expediteur,destinateur) "
                        "VALUES (:id, :nbrpiece, :expediteur , :destinateur)");
    query.bindValue(":id", res);
    query.bindValue(":nbrpiece", nbrpiece);
    query.bindValue(":expediteur", expediteur);
    query.bindValue(":destinateur", destinateur);

    return    query.exec();

}
QSqlQueryModel * courrier::afficher()
{
    QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from COURRIER");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NBRPIECE"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("EXPEDITEUR"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESTINATEUR"));
    return model;
}
bool courrier::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from courrier where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
