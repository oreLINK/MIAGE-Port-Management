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
};


#endif //MIAGE_PORT_MANAGEMENT_GESTIONPORT_H
