#include "colis.h"
#include <QDebug>
#include "connexion.h"
colis::colis()
{
    id=0;
    poids=0;
    source="";
    destinataire="";
}

colis::colis(int id,float poids ,QString source ,QString destinataire  )
{
    this->id=id;
    this->poids=poids;
    this->source=source;
    this->destinataire=destinataire;
}
int colis::get_id()
{
    return id;
}
QString colis::get_source()
{
    return source;
}
QString colis::get_destinataire()
{
    return destinataire;
}
float colis::get_poids()
{
    return poids ;
}
bool colis::ajouter()
{
    QSqlQuery query;
    QString res= QString::number(id);
    QString res1= QString::number(poids);
    query.prepare("INSERT INTO colis(id,poids,source,destinataire)"
                  "VALUES(:id,:poids,:source,:destinataire)");
        query.bindValue(":id",res);
    query.bindValue(":poids",res1);
    query.bindValue(":source",source);
    query.bindValue(":destinataire",destinataire);
    return query.exec();
}
QSqlQueryModel * colis::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel() ;
    model->setQuery("select * from COLIS");
    model->setHeaderData(0 , Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1 , Qt::Horizontal, QObject::tr("POIDS"));
    model->setHeaderData(2 , Qt::Horizontal, QObject::tr("SOURCE"));
    model->setHeaderData(3 ,Qt::Horizontal, QObject::tr("DESTINATAIRE"));
            return model;
}
bool colis::supprimer(int idd)
{
    QSqlQuery query ;
    QString res= QString::number(idd);
    query.prepare("Delete from colis where ID= :id");
    query.bindValue(":id",res );
    return query.exec();
}
