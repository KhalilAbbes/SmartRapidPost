#include "employe.h"
#include <QDebug>
#include "connexion.h"
employe::employe()
{
id=0;
nom="";
prenom="";
num=0;
date="";
adresse="";
salaire=0;
statut="";
}
employe::employe(int id, QString nom, QString prenom,int num,QString date,QString adresse,float salaire,QString statut)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->num=num;
    this->date=date;
    this->adresse=adresse;
    this->salaire=salaire;
    this->statut=statut;
}
int employe::get_id(){return id;}
QString employe::get_nom(){return nom;}
QString employe::get_prenom(){return prenom;}
int employe::get_num(){return num;}
QString employe::get_date(){return date;}
QString employe::get_adresse(){return adresse;}
float employe::get_salaire(){return salaire;}
QString employe::get_statut(){return statut;}
bool employe::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
    QString res1=QString::number(num);
    QString res2=QString::number(salaire);

    query.prepare("INSERT INTO EMPLOYE (ID,NOM,PRENOM,NUM,DATEE,ADRESSE,SALAIRE,STATUT)"
                  "VALUES (:id, :nom, :prenom, :num, :date, :adresse, :salaire, :statut)");
    query.bindValue(":id", res);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":num", res1);
    query.bindValue(":date", date);
    query.bindValue(":adresse", adresse);
    query.bindValue(":salaire", res2);
    query.bindValue(":statut", statut);
    return  query.exec();
}
QSqlQueryModel * employe::afficher()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prénom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("Numero de telephone"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("Date de naissance"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    model->setHeaderData(7,Qt::Horizontal,QObject::tr("Statut"));
    return  model;

}
bool employe::supprimer(int idemploye)
{
    QSqlQuery query;
    QString res=QString::number(idemploye);
    query.prepare("Delete from employe where ID = :id ");
    query.bindValue(":id",res);
    return query.exec();
}
