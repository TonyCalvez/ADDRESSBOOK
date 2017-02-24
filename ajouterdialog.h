#ifndef AJOUTERDIALOG_H
#define AJOUTERDIALOG_H

#include <QDialog>

namespace Ui {
class AjouterDialog;
}

class AjouterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AjouterDialog(QWidget *parent = 0);
    ~AjouterDialog();
    QString ID() const;
    QString nom() const;
    QString prenom() const;
    QString adresse() const;
    QString phone() const;
    QString poste() const;
    QString mail() const;
    QString statut() const;
    QString comment() const;
    QString famille1() const;
    QString famille2() const;
    bool annulcommande;


private slots:
    void on_validerButton_clicked();

    void on_annulerButton_clicked();

private:
    Ui::AjouterDialog *ui;

};

#endif // AJOUTERDIALOG_H
