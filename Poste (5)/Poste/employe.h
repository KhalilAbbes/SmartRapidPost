#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
class employe
{
public:
    employe();
    employe(int,QString,QString,int,QString,QString,float,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_num();
    QString get_date();
    QString get_adresse();
    float get_salaire();
    QString get_statut();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString nom,prenom,date,adresse,statut;
    int id,num;
    float salaire;
};

#endif // EMPLOYE_H
