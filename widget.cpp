#include "ajouterdialog.h"
#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("Le Carnet d'Enedis");
    nbcolumn = 11;
    ui->tableWidget->setColumnCount(nbcolumn);
    ui->tableWidget->verticalHeader()->setVisible(true);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget->setHorizontalHeaderLabels({ "NNI", "Nom" , "Prénom" , "Mail", "Portable", "Poste", "Statut", "Adresse","Infos Famille n°1" ,"Infos Famille n°2","Infos Supp."});
    ui->tableWidget->setAlternatingRowColors(true);
    ui->tableWidget->setStyleSheet("alternate-background-color: #ecf0f1;background-color: white;");
    ui->label->setText("");
    importer();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_ajouterbutton_clicked()
{
    QString ID;
    QString nom;
    QString prenom;
    QString mail;
    QString phone;
    QString poste;
    QString statut;
    QString adresse;
    QString famille1;
    QString famille2;
    QString comment;
    AjouterDialog personne(this);
    personne.setWindowTitle("Ajouter...");
    personne.exec();
    ID=personne.ID();
    nom=personne.nom();
    prenom=personne.prenom();
    adresse=personne.adresse();
    phone=personne.phone();
    poste=personne.poste();
    mail=personne.mail();
    statut=personne.statut();
    famille1=personne.famille1();
    famille2=personne.famille2();
    statut=personne.statut();
    comment=personne.comment();
    if (personne.annulcommande || nom.isEmpty() || prenom.isEmpty() ) {
        return;
    }
    else {
        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 0, new QTableWidgetItem(ID));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 1, new QTableWidgetItem(nom));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 2, new QTableWidgetItem(prenom));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 3, new QTableWidgetItem(mail));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 4, new QTableWidgetItem(phone));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 5, new QTableWidgetItem(poste));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 6, new QTableWidgetItem(statut));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 7, new QTableWidgetItem(adresse));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 8, new QTableWidgetItem(famille1));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 9, new QTableWidgetItem(famille2));
        ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), 10, new QTableWidgetItem(comment));
    }
    sauvegarder();
}


void Widget::on_supprimerbutton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
    ui->label->setText("Suppression: OK");
}

void Widget::on_Sauvegarder_clicked()
{
    sauvegarder();
}

void Widget::on_importer_clicked()
{
    importer();
}

void Widget::sauvegarder()
{
    ofstream Exportation (mon_fichier);
    int nombredelignes = ui->tableWidget->verticalHeader()->count();
    for (int ligne=0;ligne<nombredelignes;ligne++){

        for (int colonne=0;colonne<nbcolumn;colonne++){
            QString donnee = ui->tableWidget->item(ligne,colonne)->text();

                           if (donnee.isEmpty()){
                               Exportation<< " " << ";"; //Texte dans le Tableau
                           }else{
                               Exportation<<donnee.toStdString().c_str() << ";"; //Texte dans le Tableau
                           }
        }

        Exportation << "\n";
    }
    ui->label->setText("Save: OK");

}

void Widget::importer()
{
    ifstream importation (mon_fichier.c_str(), ios::in);
    if(importation)
    {
        string ligneimportee;
        ui->tableWidget->clear();
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setHorizontalHeaderLabels({ "NNI", "Nom" , "Prénom" , "Mail", "Portable", "Poste", "Statut", "Adresse","Infos Famille n°1" ,"Infos Famille n°2","Infos Supp."});
        while ( getline(importation, ligneimportee) )
                {
                  QStringList message = QString::fromStdString(ligneimportee).split(";");
                  ui->tableWidget->insertRow(ui->tableWidget->rowCount());
                  for (int colonne=0;colonne<nbcolumn;colonne++){
                      ui->tableWidget->setItem((ui->tableWidget->rowCount()-1), colonne, new QTableWidgetItem(message.at(colonne)));
                  }
                }
        importation.close();
        ui->label->setText("Importation: OK");
    }
    else{
    ui->label->setText("Pas de contacts dans le dossier!");
    }

}

void Widget::demandersauvegarde()
{        QMessageBox msgBox;
         msgBox.setText("Le document est modifié");
         msgBox.setInformativeText("Souhaitez-vous le modifier ?");
         msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
         msgBox.setDefaultButton(QMessageBox::Save);
         int ret = msgBox.exec();
              switch (ret) {
                case QMessageBox::Save:
                    sauvegarder();
                    break;
                case QMessageBox::Discard:
                    return;
                    break;
                case QMessageBox::Cancel:
                    return;
                    break;
                default:
                    // ne doit pas se produire
                    break;
              }
}

void Widget::closeEvent(QCloseEvent *event)
{
    demandersauvegarde();
}
