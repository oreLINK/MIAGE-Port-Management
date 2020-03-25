//
// Created by Aurélien BERTRAND on 25/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATA_H
#define MIAGE_PORT_MANAGEMENT_DATA_H

#include "../Place/Place.h"

class Data {
public:
    Data();
    void createPlacesFile();
private:
    int tailleMax = 30;
    Place* listePlace = new Place[tailleMax];
};


#endif //MIAGE_PORT_MANAGEMENT_DATA_H
