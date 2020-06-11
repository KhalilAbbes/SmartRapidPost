#include "departement.h"
#include <QString>
#include <QDebug>
departement::departement()
{
iddep=0;
nomdep="";
numdep=0;
nbrb=0;
nbre=0;
}
departement::departement(int iddep,QString nomdep,int numdep,int nbrb,int nbre)
{
    this->iddep=iddep;
    this->nomdep=nomdep;
    this->numdep=numdep;
    this->nbrb=nbrb;
    this->nbre=nbre;

}
int departement::get_iddep(){return iddep;}
QString departement::get_nomdep(){return nomdep;}
int departement::get_numdep(){return numdep;}
int departement::get_nbrb(){return nbrb;}
int departement::get_nbre(){return nbre;}

bool departement::ajouterdep()
{
    QSqlQuery query;
    QString res=QString::number(iddep);
    QString res1=QString::number(numdep);
    QString res2=QString::number(nbrb);
    QString res3=QString::number(nbre);
    query.prepare("INSERT INTO departement (IDDEP,NOMDEP,NUMDEP,NBRB,NBRE)"
                  "VALUES(:iddep, :nomdep, :numdep, :nbrb, :nbre)");
    query.bindValue(":iddep",res);
    query.bindValue(":nomdep",nomdep);
    query.bindValue(":numdep",res1);
    query.bindValue(":nbrb",res2);
    query.bindValue(":nbre",res3);
    return query.exec();
}
QSqlQueryModel * departement::afficherdep()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from departement");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Nom du departement"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Num du departement"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Nombre de bureaux"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Nombre des employés"));
    return model;
}

bool departement::supprimerdep(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from DEPARTEMENT where IDDEP = :idd ");
query.bindValue(":idd", res);
return    query.exec();
}
