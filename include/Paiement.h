//
// Created by Aurélien BERTRAND on 28/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_PAIEMENT_H
#define MIAGE_PORT_MANAGEMENT_PAIEMENT_H


class Paiement {
public:
    Paiement();

    Paiement(int nbJours, int paiementJournalier, int paiementMensuel, int paiementAnnuel, int total);

    int getNbJours() const;

    void setNbJours(int nbJours);

    int getPaiementJournalier() const;

    void setPaiementJournalier(int paiementJournalier);

    int getPaiementAnnuel() const;

    void setPaiementAnnuel(int paiementAnnuel);

    int getTotal() const;

    void setTotal(int total);

    int getPaiementMensuel() const;

    void setPaiementMensuel(int paiementMensuel);

private:
    int nbJours;
    int paiementJournalier = 0;
    int paiementMensuel = 0;
    int paiementAnnuel = 0;
    int total;
};


#endif //MIAGE_PORT_MANAGEMENT_PAIEMENT_H
