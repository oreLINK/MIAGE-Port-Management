//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "Reservation.h"

Reservation::Reservation() {}

Reservation::Reservation(const Client &client, const Bateau &bateau, const Place &place, const Date &dateArrivee,
                         const Date &dateDepart, bool siSupplementElec, bool siSupplementEau, bool siAbonnement)
        : client(client), bateau(bateau), place(place), dateArrivee(dateArrivee), dateDepart(dateDepart),
          siSupplementElec(siSupplementElec), siSupplementEau(siSupplementEau), siAbonnement(siAbonnement) {}

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

bool Reservation::isSiSupplementElec() const {
    return siSupplementElec;
}

void Reservation::setSiSupplementElec(bool siSupplementElec) {
    Reservation::siSupplementElec = siSupplementElec;
}

bool Reservation::isSiSupplementEau() const {
    return siSupplementEau;
}

void Reservation::setSiSupplementEau(bool siSupplementEau) {
    Reservation::siSupplementEau = siSupplementEau;
}

bool Reservation::isSiAbonnement() const {
    return siAbonnement;
}

void Reservation::setSiAbonnement(bool siAbonnement) {
    Reservation::siAbonnement = siAbonnement;
}
