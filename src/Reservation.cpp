//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "include/Reservation.h"

Reservation::Reservation() {}

Reservation::Reservation(int id, int idClient, const Bateau &bateau, int numeroPlace, const Date &dateArrivee,
                         const Date &dateDepart, bool supplementElec, bool supplementEau, bool abonnement,
                         const Paiement &paiement) : id(id), idClient(idClient), bateau(bateau),
                                                     numeroPlace(numeroPlace), dateArrivee(dateArrivee),
                                                     dateDepart(dateDepart), supplementElec(supplementElec),
                                                     supplementEau(supplementEau), abonnement(abonnement),
                                                     paiement(paiement) {}

int Reservation::getId() const {
    return id;
}

void Reservation::setId(int id) {
    Reservation::id = id;
}

int Reservation::getIdClient() const {
    return idClient;
}

void Reservation::setIdClient(int idClient) {
    Reservation::idClient = idClient;
}

const Bateau &Reservation::getBateau() const {
    return bateau;
}

void Reservation::setBateau(const Bateau &bateau) {
    Reservation::bateau = bateau;
}

int Reservation::getNumeroPlace() const {
    return numeroPlace;
}

void Reservation::setNumeroPlace(int numeroPlace) {
    Reservation::numeroPlace = numeroPlace;
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