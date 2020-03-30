//
// Created by Aurélien BERTRAND on 28/03/2020.
//

#include "include/Paiement.h"

Paiement::Paiement() {}

Paiement::Paiement(int nbJours, int paiementJournalier, int paiementMensuel, int paiementAnnuel, int total) : nbJours(
        nbJours), paiementJournalier(paiementJournalier), paiementMensuel(paiementMensuel), paiementAnnuel(
        paiementAnnuel), total(total) {}

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

int Paiement::getPaiementMensuel() const {
    return paiementMensuel;
}

void Paiement::setPaiementMensuel(int paiementMensuel) {
    Paiement::paiementMensuel = paiementMensuel;
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
