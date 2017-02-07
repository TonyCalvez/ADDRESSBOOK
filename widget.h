#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <string>
#include <iostream>
#include <fstream>
#include "widget.h"
#include "ui_widget.h"

using namespace std;


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    string mon_fichier = "sauvegarde.csv";
    ~Widget();


private slots:
    void on_ajouterbutton_clicked();

    void on_supprimerbutton_clicked();

    void on_Sauvegarder_clicked();

    void on_importer_clicked();

    void sauvegarder();

    void importer();

    void demandersauvegarde();


private:
    Ui::Widget *ui;

    int nbcolumn;

protected:
     void closeEvent(QCloseEvent *event);
};

#endif // WIDGET_H
