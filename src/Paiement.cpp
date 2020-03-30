//
// Created by Aurélien BERTRAND on 28/03/2020.
//

#include "include/Paiement.h"

Paiement::Paiement() {}

Paiement::Paiement(int nbJours, int paiementJournalier, int paiementMensuelPremierMois, int paiementMensuel11Mois,
                   int paiementAnnuel, int total) : nbJours(nbJours), paiementJournalier(paiementJournalier),
                                                    paiementMensuelPremierMois(paiementMensuelPremierMois),
                                                    paiementMensuel11Mois(paiementMensuel11Mois),
                                                    paiementAnnuel(paiementAnnuel), total(total) {}

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

int Paiement::getPaiementMensuelPremierMois() const {
    return paiementMensuelPremierMois;
}

void Paiement::setPaiementMensuelPremierMois(int paiementMensuelPremierMois) {
    Paiement::paiementMensuelPremierMois = paiementMensuelPremierMois;
}

int Paiement::getPaiementMensuel11Mois() const {
    return paiementMensuel11Mois;
}

void Paiement::setPaiementMensuel11Mois(int paiementMensuel11Mois) {
    Paiement::paiementMensuel11Mois = paiementMensuel11Mois;
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
