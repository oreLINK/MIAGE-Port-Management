//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_GESTIONPORT_H
#define MIAGE_PORT_MANAGEMENT_GESTIONPORT_H


#include "../Reservation/Reservation.h"

class GestionPort {
private:

public:
    GestionPort();
    void createReservation();
    void createBoat();
    int createBoatAskSize();

    void createBoat(Reservation r);
};


#endif //MIAGE_PORT_MANAGEMENT_GESTIONPORT_H
