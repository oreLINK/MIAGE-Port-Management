//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_INTERFACE_H
#define MIAGE_PORT_MANAGEMENT_INTERFACE_H

#include <string>
#include <include/Bateau.h>
#include <include/Place.h>
#include "Client.h"
#include "Reservation.h"

using namespace std;

class Interface {
private:

public:
    void interfaceHome();

    string interfaceHomeResponse();

    bool ifWantGoHome(string cin);

    void erreur(string message, bool avecEspace);

    void home();

    void homeResponseCheck(string homeResponse);

    void info(string message, bool avecEspace);

    string getCin(string message, bool ifEspace);

    void typeBateauInfos(Bateau b);

    void interfaceNewReservation();

    void interfaceNewBoat();

    void interfaceNewPlace();

    void interfacePlaceInfos(Place p);

    void interfaceChoixClient();

    void interfaceListeClients();

    void interfaceClientInfo(Client c);

    void interfaceNewClient();

    string getCinLine(string message, bool ifEspace);

    void interfaceChoixSupplements();

    void interfaceChoixEngagement();

    void interfaceInfosSupplements(Reservation r);

    void interfaceInfosEngagement(Reservation r);

    void interfaceInfosNbJours(Paiement p);

    void interfacePaiement();

    void displayDates(Reservation r);

    void displayReservation(Reservation r);

    void displayClient(Client c);

    void displayBateau(Bateau b);

    void displayPlace(Place p);

    void showPrices(Reservation r);

    void displayReservations(vector<Reservation> r);
};


#endif //MIAGE_PORT_MANAGEMENT_INTERFACE_H
