#include "promotion.h"
#include <QDebug>
#include "connexion.h"
promotion::promotion()
{
ref=0;
article="";
pourcentage=0;
d="";
f="";
statut=0;
}
promotion::promotion(int ref,QString article,float pourcentage,QString d,QString f,int statut)
{
  this->ref=ref;
  this->article=article;
  this->pourcentage=pourcentage;
  this->d=d;
  this->f=f;
  this->statut=statut;



}
int promotion::get_ref(){return  ref;}
QString promotion::get_article(){return article;}
float promotion::get_pourcentage(){return  pourcentage;}
QString promotion::get_debut(){return  d;}
QString promotion::get_fin(){return  f;}
int promotion::get_statut(){return  statut;}





bool promotion::ajouter()
{
QSqlQuery query;
QString res= QString::number(ref);
QString res1= QString::number(pourcentage);
QString res2= QString::number(statut);

query.prepare("INSERT INTO PROMOTIONS (REF, ARTICLE, POURCENTAGE,DATE_DEBUT,DATE_FIN,STATUT)"
                    "VALUES ( :ref, :article, :pourcentage, :d, :f, :statut)");
query.bindValue(":ref", res);
query.bindValue(":article", article);
query.bindValue(":pourcentage", res1);
query.bindValue(":d", d);
query.bindValue(":f", f);
query.bindValue(":statut", res2);




return    query.exec();
}

QSqlQueryModel * promotion::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from promotions");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Ref"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("article "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("pourcentage"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("d"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("f"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("statut"));



    return model;
}

bool promotion::supprimer(int reff)
{
QSqlQuery query;
QString res= QString::number(reff);
query.prepare("Delete from PROMOTIONS where REF = :reff ");
query.bindValue(":reff", res);
return    query.exec();
}
