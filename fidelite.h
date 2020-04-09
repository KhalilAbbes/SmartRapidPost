#ifndef FIDELITE_H
#define FIDELITE_H


#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class fidelite
{public:
    fidelite();
    fidelite(int,int,QString,int);
    int get_id();
    int get_num();
    QString get_date();
    int get_point();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString date;
    int id,num,point;
};
#endif // FIDELITE_H
