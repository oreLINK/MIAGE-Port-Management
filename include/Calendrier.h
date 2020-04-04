//
// Created by Aurélien BERTRAND on 02/04/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_CALENDRIER_H
#define MIAGE_PORT_MANAGEMENT_CALENDRIER_H

struct Calendrier {
    struct NombreJours {
        int janvier = 31;
        int fevrierBissextile = 29;
        int fevrierNonBissextile = 28;
        int mars = 31;
        int avril = 30;
        int mai = 31;
        int juin = 30;
        int juillet = 31;
        int aout = 31;
        int septembre = 30;
        int octobre = 31;
        int novembre = 30;
        int decembre = 31;
    };
    NombreJours nombreJours;
};

#endif //MIAGE_PORT_MANAGEMENT_CALENDRIER_H
