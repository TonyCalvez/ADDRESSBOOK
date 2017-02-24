#include "ajouterdialog.h"
#include "ui_ajouterdialog.h"

AjouterDialog::AjouterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AjouterDialog)
{
    ui->setupUi(this);
}

AjouterDialog::~AjouterDialog()
{
    delete ui;
}

QString AjouterDialog::ID() const
{
    return ui->lineEditID->text();
}

QString AjouterDialog::nom() const
{
    return ui->lineEditnom->text();
}

QString AjouterDialog::prenom() const
{
    return ui->lineEditprenom->text();
}

QString AjouterDialog::adresse() const
{
    return ui->lineEditadresse->text();
}

QString AjouterDialog::phone() const
{
    return ui->lineEditphone->text();
}

QString AjouterDialog::poste() const
{
    return ui->lineEditposte->text();
}

QString AjouterDialog::mail() const
{
    return ui->lineEditmail->text();
}

QString AjouterDialog::statut() const
{
    return ui->lineEditstatut->text();
}

QString AjouterDialog::comment() const
{
    return ui->lineEditcomment->text();
}

QString AjouterDialog::famille1() const
{
    return ui->lineEditFamille1->text();
}

QString AjouterDialog::famille2() const
{
    return ui->lineEditFamille2->text();
}

void AjouterDialog::on_validerButton_clicked()
{
    annulcommande=false;
    close();
}


void AjouterDialog::on_annulerButton_clicked()
{
    annulcommande=true;
    close();
}
