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

    bool checkWantHome(string choice);

    int createBoatCheckChoice(string choice);

    bool checkBoatLength(string choice);

    int CountWords(const char *str);
};


#endif //MIAGE_PORT_MANAGEMENT_GESTIONPORT_H
