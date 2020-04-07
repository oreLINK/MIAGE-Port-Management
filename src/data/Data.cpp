//
// Created by Aurélien BERTRAND on 25/03/2020.
//

#include <iostream>
#include <array>
#include <vector>
#include <include/Client.h>
#include <Tcl/tclTomMath.h>
#include <include/Date.h>
#include <sstream>
#include <include/Reservation.h>
#include <include/Interface.h>
#include <sys/stat.h>
#include "include/data/Data.h"
#include "include/tinyxml2.h"
#include "include/XMLPlaces.h"
#include "include/NombrePlaces.h"
#include "include/data/DataClient.h"
#include "include/data/DataDate.h"
#include "include/data/DataReservation.h"

using namespace tinyxml2;
using namespace std;

Interface idata;

Data::Data() {}

/**
 * Action qui va créer le dossier xml si celui-ci n'existe pas
 */
void Data::createXMLFolder(){
    struct stat st = {0};
    if (stat("xml/", &st) == -1) {
        mkdir("xml/", 0700);
    }
}

/**
 * Fonction qui va retourner l'integer d'un élément XML
 * @param eResult element de retour, soit l'integer soit le message d'erreur
 * @param elementFather noeud XML parent (le premier qui est décalé à gauche en remontant)
 * @param id le nom de l'attribut à retrouver
 * @return l'integer retrouvé, sinon 0
 */
int Data::extractIntFromXML(XMLError eResult, XMLElement *elementFather, const char *id) {
    int iNumber = 0;
    XMLElement *pElement = elementFather->FirstChildElement(id);
    if (pElement == nullptr) {
        cout << "extractIntFromXML(...) " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        eResult = pElement->QueryIntText(&iNumber);
    }
    return iNumber;
}

/**
 * Fonction qui va retourner le booléen d'un élément XML
 * @param eResult element de retour, soit le booléen soit le message d'erreur
 * @param elementFather noeud XML parent (le premier qui est décalé à gauche en remontant)
 * @param id le nom de l'attribut à retrouver
 * @return 0 si le booléen est faux, 1 sinon.
 */
bool Data::extractBoolFromXML(XMLError eResult, XMLElement *elementFather, const char *id) {
    bool iBool = false;
    XMLElement *pElement = elementFather->FirstChildElement(id);
    if (pElement == nullptr) {
        //cout << "extractBoolFromXML(...) " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        eResult = pElement->QueryBoolText(&iBool);
    }
    return iBool;
}

/**
 * Fonction qui va retourner le booléen d'un élément XML
 * @param eResult element de retour, soit le booléen soit le message d'erreur
 * @param elementFather noeud XML parent (le premier qui est décalé à gauche en remontant)
 * @param id le nom de l'attribut à retrouver
 * @return 0 si le booléen est faux, 1 sinon.
 */
const char *Data::extractCharFromXML(XMLError eResult, XMLElement *elementFather, const char *id) {
    const char *iChar = nullptr;
    XMLElement *pElement = elementFather->FirstChildElement(id);
    if (pElement == nullptr) {
        cout << "extractBoolFromXML(...) " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        iChar = pElement->GetText();
    }
    return iChar;
}




