//
// Created by Aurélien BERTRAND on 25/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATA_H
#define MIAGE_PORT_MANAGEMENT_DATA_H

#include "include/Place.h"

#include <string>
#include <include/tinyxml2.h>
#include <include/Date.h>
#include <include/Reservation.h>

using namespace std;
using namespace tinyxml2;

class Data {
private:

public:
    Data();

    bool extractBoolFromXML(tinyxml2::XMLError eResult, tinyxml2::XMLElement *elementFather, const char *id);

    int extractIntFromXML(tinyxml2::XMLError eResult, tinyxml2::XMLElement *elementFather, const char *id);

    const char *extractCharFromXML(tinyxml2::XMLError eResult, tinyxml2::XMLElement *elementFather, const char *id);

    void createXMLFolder();
};


#endif //MIAGE_PORT_MANAGEMENT_DATA_H
