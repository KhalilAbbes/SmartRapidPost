#ifndef DEPARTEMENT_H
#define DEPARTEMENT_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QDialog>


class departement
{
public:
    departement();
    departement(int,QString,int,int,int);
    int get_iddep();
    QString get_nomdep();
    int get_numdep();
    int get_nbrb();
    int get_nbre();
    bool ajouterdep();
    QSqlQueryModel * afficherdep();
    bool supprimerdep(int);
private:
    int iddep ,numdep,nbrb,nbre;
    QString nomdep;
};

#endif // DEPARTEMENT_H
