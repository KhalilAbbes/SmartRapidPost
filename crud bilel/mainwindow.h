#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "colis.h"
#include <QMainWindow>
#include "courrier.h"
QT_BEGIN_NAMESPACE
namespace Ui
{ class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:

    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_lineEdit_Tri_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_TRICOLIS_clicked();

private:
    Ui::MainWindow *ui;
    colis tmpcolis;
     courrier tmpc ;
};
#endif // MAINWINDOW_H
