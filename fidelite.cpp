#include "fidelite.h"

#include <QDebug>
#include "connexion.h"
fidelite::fidelite()
{
id=0;
num=0;
point=0;
date="";
}
fidelite::fidelite(int id,int num,QString date,int point)
{
  this->id=id;
  this->num=num;
  this->date=date;
  this->point=point;
}


int fidelite::get_id(){return  id;}
int fidelite::get_num(){return num;}
QString fidelite::get_date(){return  date;}
int fidelite::get_point(){return  point;}





bool fidelite::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
QString res1= QString::number(num);
QString res2= QString::number(point);

query.prepare("INSERT INTO FIDELITE (ID_CLIENT, NUM, DATES, POINT)"
                    "VALUES ( :id, :num, :date, :point)");
query.bindValue(":id", res);
query.bindValue(":num", res1);
query.bindValue(":date", date);
query.bindValue(":point", res2);




return    query.exec();
}

QSqlQueryModel * fidelite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fidelite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Client"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Num. de la carte "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date d'expiration"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Nombre de points"));




    return model;
}

bool fidelite::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from FIDELITE where NUM = :idd ");
query.bindValue(":idd", res);
return    query.exec();
}
