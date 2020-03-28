//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_RESERVATION_H
#define MIAGE_PORT_MANAGEMENT_RESERVATION_H


#include "include/Client.h"
#include "include/Bateau.h"
#include "include/Place.h"
#include "include/Date.h"
#include "Tarifs.h"

class Reservation {
public:
    Reservation();

    Reservation(const Client &client, const Bateau &bateau, const Place &place, const Date &dateArrivee,
                const Date &dateDepart, bool siSupplementElec, bool siSupplementEau, bool siAbonnement);

    Reservation(const Client &client, const Bateau &bateau, const Place &place, const Date &dateArrivee,
                const Date &dateDepart, bool supplementElec, bool supplementEau, bool abonnement, const Tarifs &tarif);

    const Client &getClient() const;

    void setClient(const Client &client);

    const Bateau &getBateau() const;

    void setBateau(const Bateau &bateau);

    const Place &getPlace() const;

    void setPlace(const Place &place);

    const Date &getDateArrivee() const;

    void setDateArrivee(const Date &dateArrivee);

    const Date &getDateDepart() const;

    void setDateDepart(const Date &dateDepart);

    bool isSupplementElec() const;

    void setSupplementElec(bool supplementElec);

    bool isSupplementEau() const;

    void setSupplementEau(bool supplementEau);

    bool isAbonnement() const;

    void setAbonnement(bool abonnement);

    const Tarifs &getTarif() const;

    void setTarif(const Tarifs &tarif);

private:
    Client client;
    Bateau bateau;
    Place place;
    Date dateArrivee;
    Date dateDepart;
    bool supplementElec;
    bool supplementEau;
    bool abonnement;
    Tarifs tarif;
};


#endif //MIAGE_PORT_MANAGEMENT_RESERVATION_H
