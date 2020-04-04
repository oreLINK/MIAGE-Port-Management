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
#include "Paiement.h"

class Reservation {
public:
    Reservation();

    Reservation(int id, int idClient, const Bateau &bateau, int numeroPlace, const Date &dateArrivee,
                const Date &dateDepart, bool supplementElec, bool supplementEau, bool abonnement,
                const Paiement &paiement);


    const Bateau &getBateau() const;

    void setBateau(const Bateau &bateau);

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

    const Paiement &getPaiement() const;

    void setPaiement(const Paiement &paiement);

    int getId() const;

    void setId(int id);

    int getIdClient() const;

    void setIdClient(int idClient);

    int getNumeroPlace() const;

    void setNumeroPlace(int numeroPlace);

private:
    int id;
    int idClient;
    Bateau bateau;
    int numeroPlace;
    Date dateArrivee;
    Date dateDepart;
    bool supplementElec;
    bool supplementEau;
    bool abonnement;
    Paiement paiement;
};


#endif //MIAGE_PORT_MANAGEMENT_RESERVATION_H
