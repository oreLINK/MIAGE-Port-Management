//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_NOMBREPLACES_H
#define MIAGE_PORT_MANAGEMENT_NOMBREPLACES_H

/**
 * Structure qui va définir le nombre de places par type de place (quai ou non, grande ou petite)
 */

struct NombrePlaces {
    struct Quai {
        int const total = 30;
        int const grandes = 10;
        int const petites = 20;
    };
    struct HorsQuai {
        int const total = 10;
        int const grandes = 3;
        int const petites = 7;
    };
    Quai quai;
    HorsQuai horsQuai;
    int const total = 40;
};

#endif //MIAGE_PORT_MANAGEMENT_NOMBREPLACES_H
