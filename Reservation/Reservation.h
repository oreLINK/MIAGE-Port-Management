//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_RESERVATION_H
#define MIAGE_PORT_MANAGEMENT_RESERVATION_H


#include "../Client/Client.h"
#include "../Bateau/Bateau.h"
#include "../Place/Place.h"
#include "../Date/Date.h"

class Reservation {
public:
    Reservation();

    Reservation(const Client &client, const Bateau &bateau, const Place &place, const Date &dateArrivee,
                const Date &dateDepart, bool siSupplementElec, bool siSupplementEau, bool siAbonnement);

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

    bool isSiSupplementElec() const;

    void setSiSupplementElec(bool siSupplementElec);

    bool isSiSupplementEau() const;

    void setSiSupplementEau(bool siSupplementEau);

    bool isSiAbonnement() const;

    void setSiAbonnement(bool siAbonnement);

private:
    Client client;
    Bateau bateau;
    Place place;
    Date dateArrivee;
    Date dateDepart;
    bool siSupplementElec;
    bool siSupplementEau;
    bool siAbonnement;
};


#endif //MIAGE_PORT_MANAGEMENT_RESERVATION_H
