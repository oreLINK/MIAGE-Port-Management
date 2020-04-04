//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATARESERVATION_H
#define MIAGE_PORT_MANAGEMENT_DATARESERVATION_H


#include "Data.h"
#include "XMLFilesName.h"
#include "XMLReservations.h"
#include "../BateauType.h"

class DataReservation {
private:

public:
    void createReservationsFile();

    bool checkIfReservationsFileExist();

    vector<Reservation> importReservationsFile();

    vector<Reservation> addReservation(Reservation r);

    void saveReservations(vector<Reservation> r);

    string convertVectorIntToString(vector<int> v);
};


#endif //MIAGE_PORT_MANAGEMENT_DATARESERVATION_H
