#ifndef COLIS_H
#define COLIS_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
class colis
{

private:
QString source,destinataire;
int id;
float poids ;
public:
colis();
colis(int,float,QString,QString);
 int get_id();
QString get_source();
QString get_destinataire();
float get_poids();
bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
};

#endif // COLIS_H
