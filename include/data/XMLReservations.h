//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_XMLRESERVATIONS_H
#define MIAGE_PORT_MANAGEMENT_XMLRESERVATIONS_H

/**
 *
 */

struct XMLReservations {
    struct Reservation {
        struct Bateau {
            const char * taille = "taille";
            const char * siCabine = "siCabine";
            const char * type = "type";
        };
        struct DateArrivee {
            const char * annee = "annee";
            const char * mois = "mois";
            const char * jour = "jour";
        };
        struct DateDepart {
            const char * annee = "annee";
            const char * mois = "mois";
            const char * jour = "jour";
        };
        struct Paiement {
            const char * nombreJours = "nombreJours";
            const char * paiementJournalier = "paiementJournalier";
            const char * paiementMensuelPremierMois = "paiementMensuelPremierMois";
            const char * paiementMensuel11Mois = "paiementMensuel11Mois";
            const char * paiementAnnuel = "paiementAnnuel";
            const char * total = "total";
        };
        Bateau bateau;
        DateArrivee dateArrivee;
        DateDepart dateDepart;
        Paiement paiement;
        const char * Reservation = "Reservation";
        const char * Bateau = "Bateau";
        const char * DateArrivee = "DateArrivee";
        const char * DateDepart = "DateDepart";
        const char * Paiement = "Paiement";
        const char * id = "id";
        const char * idClient = "idClient";
        const char * numeroPlace = "numeroPlace";
        const char * supplementElec = "supplementElec";
        const char * supplementEau = "supplementEau";
        const char * abonnement = "abonnement";
    };
    Reservation reservation;
    const char * ListeDesReservations = "ListeDesReservations";
};

#endif //MIAGE_PORT_MANAGEMENT_XMLRESERVATIONS_H
