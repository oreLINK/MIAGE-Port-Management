//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_XMLPLACES_H
#define MIAGE_PORT_MANAGEMENT_XMLPLACES_H

/**
 * Structure qui va définir les différentes balises du fichier Clients.xml
 */

struct XMLPlaces {
    struct Place {
        struct Data {
            const char * number = "number";
            const char * ifDock = "ifDock";
            const char * ifTall = "ifTall";
            const char * ifElec = "ifElec";
            const char * ifWater = "ifWater";
            const char * ifBusy = "ifBusy";
        };
        Data data;
        const char * place = "Place";
    };
    Place place;
    const char * listeDesPlaces = "ListeDesPlaces";
};

#endif //MIAGE_PORT_MANAGEMENT_XMLPLACES_H
