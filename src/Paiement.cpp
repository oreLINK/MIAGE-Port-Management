//
// Created by Aurélien BERTRAND on 28/03/2020.
//

#include "include/Paiement.h"

Paiement::Paiement() {}

int Paiement::getNbJours() const {
    return nbJours;
}

void Paiement::setNbJours(int nbJours) {
    Paiement::nbJours = nbJours;
}

int Paiement::getPaiementJournalier() const {
    return paiementJournalier;
}

void Paiement::setPaiementJournalier(int paiementJournalier) {
    Paiement::paiementJournalier = paiementJournalier;
}

const int *Paiement::getPaiementMensuel() const {
    return paiementMensuel;
}



int Paiement::getPaiementAnnuel() const {
    return paiementAnnuel;
}

void Paiement::setPaiementAnnuel(int paiementAnnuel) {
    Paiement::paiementAnnuel = paiementAnnuel;
}

int Paiement::getTotal() const {
    return total;
}

void Paiement::setTotal(int total) {
    Paiement::total = total;
}
