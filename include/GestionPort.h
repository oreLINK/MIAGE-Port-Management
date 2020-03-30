//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_GESTIONPORT_H
#define MIAGE_PORT_MANAGEMENT_GESTIONPORT_H


#include "Reservation.h"

class GestionPort {
private:

public:
    GestionPort();

    void createReservation();

    Bateau createBoat(Reservation r);

    bool checkWantHome(string choice);

    bool checkIfIntegerPositif(string choice);

    Bateau createBoat();

    Place choosePlace();

    Client chooseClient();

    bool checkWantNewClient(string choice);

    void createNewClient();

    string clientNouveauNom();

    string clientNouveauPrenom();

    string clientNouveauEmail();

    int clientNouveauNumeroAdresse();

    string clientNouvelleAdresse();

    string clientNouveauCP();

    string clientNouvelleVille();

    bool checkIfClientCanHaveSupplements(Reservation r);

    bool checkSupplementsReponse(string choice);

    bool returnSupplementReponse(string choice);

    bool checkIfClientWantElecSupplement();

    bool checkIfClientWantWaterSupplement();

    bool chooseIfClientWantAbonnement();

    Paiement getPaiement(Reservation r);

    int askClientNombreJours();

    int getPaiementJournalier(Reservation r);

    int getPaiementJournalierSupplements(Reservation r);

    int getPaiementAnnuel(Reservation r);

    int *getPaiementMensuel(Reservation r);

    void showPrices(Reservation r);

    Date getDateDepartAbonnement(Date d);

    Date getDateDepartNonAbonnement(Reservation r);

    bool ifYearBissextile(Date d);

    vector<int> createNbJoursMonth(bool ifBissextile);

    Date convertJoursInYearsMonthDays(Date d, int nbJours, vector<int> nbJoursParMois);
};


#endif //MIAGE_PORT_MANAGEMENT_GESTIONPORT_H
