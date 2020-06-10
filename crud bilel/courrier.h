#ifndef COURRIER_H
#define COURRIER_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class courrier
{

public:
    courrier();
    courrier(int,int,QString,QString);
    QString get_expediteur();
    QString get_destinateur();
    int get_id();
    int get_nbrpiece();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
private:
    QString expediteur,destinateur;
    int id ,nbrpiece ;
};

#endif // COURRIER_H
