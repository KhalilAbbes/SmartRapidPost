#ifndef PROMOTION_H
#define PROMOTION_H


#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
class promotion
{public:
    promotion();
    promotion(int,QString,float,QString,QString,int);
    int get_ref();
    QString get_article();
    float get_pourcentage();
    QString get_debut();
    QString get_fin();
    int get_statut();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString article,d,f;
    int ref;
    float pourcentage;

    int statut;
};

#endif // PROMOTION_H
