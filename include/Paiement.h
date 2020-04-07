//
// Created by Yessoh BONNY on 28/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_PAIEMENT_H
#define MIAGE_PORT_MANAGEMENT_PAIEMENT_H

#include <vector>
#include <string>

using namespace std;

class Paiement {
public:
    Paiement();

    Paiement(int nbJours, int paiementJournalier, int paiementMensuelPremierMois, int paiementMensuel11Mois,
             int paiementAnnuel, int total, bool aPaye);

    int getNbJours() const;

    void setNbJours(int nbJours);

    int getPaiementJournalier() const;

    void setPaiementJournalier(int paiementJournalier);

    int getPaiementAnnuel() const;

    void setPaiementAnnuel(int paiementAnnuel);

    int getTotal() const;

    void setTotal(int total);

    int getPaiementMensuelPremierMois() const;

    void setPaiementMensuelPremierMois(int paiementMensuelPremierMois);

    int getPaiementMensuel11Mois() const;

    void setPaiementMensuel11Mois(int paiementMensuel11Mois);

    bool isAPaye() const;

    void setAPaye(bool aPaye);

private:
    int nbJours;
    int paiementJournalier = 0;
    int paiementMensuelPremierMois = 0;
    int paiementMensuel11Mois = 0;
    int paiementAnnuel = 0;
    int total;
    bool aPaye;
};


#endif //MIAGE_PORT_MANAGEMENT_PAIEMENT_H
