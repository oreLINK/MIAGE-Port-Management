//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "include/Reservation.h"

Reservation::Reservation() {}

Reservation::Reservation(const Client &client, const Bateau &bateau, const Place &place, const Date &dateArrivee,
                         const Date &dateDepart, bool supplementElec, bool supplementEau, bool abonnement,
                         const Paiement &paiement) : client(client), bateau(bateau), place(place),
                                                     dateArrivee(dateArrivee), dateDepart(dateDepart),
                                                     supplementElec(supplementElec), supplementEau(supplementEau),
                                                     abonnement(abonnement), paiement(paiement) {}

const Client &Reservation::getClient() const {
    return client;
}

void Reservation::setClient(const Client &client) {
    Reservation::client = client;
}

const Bateau &Reservation::getBateau() const {
    return bateau;
}

void Reservation::setBateau(const Bateau &bateau) {
    Reservation::bateau = bateau;
}

const Place &Reservation::getPlace() const {
    return place;
}

void Reservation::setPlace(const Place &place) {
    Reservation::place = place;
}

const Date &Reservation::getDateArrivee() const {
    return dateArrivee;
}

void Reservation::setDateArrivee(const Date &dateArrivee) {
    Reservation::dateArrivee = dateArrivee;
}

const Date &Reservation::getDateDepart() const {
    return dateDepart;
}

void Reservation::setDateDepart(const Date &dateDepart) {
    Reservation::dateDepart = dateDepart;
}

bool Reservation::isSupplementElec() const {
    return supplementElec;
}

void Reservation::setSupplementElec(bool supplementElec) {
    Reservation::supplementElec = supplementElec;
}

bool Reservation::isSupplementEau() const {
    return supplementEau;
}

void Reservation::setSupplementEau(bool supplementEau) {
    Reservation::supplementEau = supplementEau;
}

bool Reservation::isAbonnement() const {
    return abonnement;
}

void Reservation::setAbonnement(bool abonnement) {
    Reservation::abonnement = abonnement;
}

const Paiement &Reservation::getPaiement() const {
    return paiement;
}

void Reservation::setPaiement(const Paiement &paiement) {
    Reservation::paiement = paiement;
}
