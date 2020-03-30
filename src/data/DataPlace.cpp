//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#include <include/NombrePlaces.h>
#include <include/XMLPlaces.h>
#include <include/data/Data.h>
#include <iostream>
#include <vector>
#include "include/data/DataPlace.h"

XMLFilesName xmlFilesNameDP;
Data datadp;

/**
 * Action qui va créer le fichier XML initial des places de bateau lors du premier lancement du programme.
 * OPTI
 */
void DataPlace::createFirstPlacesFile() {
    NombrePlaces nombrePlaces;
    int comptNbPlacesQuaiPetites = nombrePlaces.quai.petites;
    int comptNbPlacesQuaiGrandes = nombrePlaces.quai.grandes;
    int comptNbPlacesHorsQuaiPetites = nombrePlaces.horsQuai.petites;
    int comptNbPlacesHorsQuaiGrandes = nombrePlaces.horsQuai.grandes;

    XMLDocument xmlDoc;
    XMLPlaces xmlPlaces;
    XMLNode *pRoot = xmlDoc.NewElement(xmlPlaces.listeDesPlaces);

    int i = nombrePlaces.total;

    for (int j = comptNbPlacesQuaiPetites; j > 0; j--) {
        XMLNode *nRoot = xmlDoc.NewElement(xmlPlaces.place.place);
        XMLElement *eNum = xmlDoc.NewElement(xmlPlaces.place.data.number);
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement(xmlPlaces.place.data.ifDock);
        eDock->SetText(true);
        XMLElement *eLenght = xmlDoc.NewElement(xmlPlaces.place.data.ifTall);
        eLenght->SetText(false);
        XMLElement *eElec = xmlDoc.NewElement(xmlPlaces.place.data.ifElec);
        eElec->SetText(true);
        XMLElement *eWater = xmlDoc.NewElement(xmlPlaces.place.data.ifWater);
        eWater->SetText(true);
        XMLElement *eBusy = xmlDoc.NewElement(xmlPlaces.place.data.ifBusy);
        eBusy->SetText(false);
        nRoot->InsertFirstChild(eNum);
        nRoot->InsertAfterChild(eNum, eDock);
        nRoot->InsertAfterChild(eDock, eLenght);
        nRoot->InsertAfterChild(eLenght, eElec);
        nRoot->InsertAfterChild(eElec, eWater);
        nRoot->InsertEndChild(eBusy);
        pRoot->InsertFirstChild(nRoot);
        i--;
    }
    for (int k = comptNbPlacesQuaiGrandes; k > 0; k--) {
        XMLNode *nRoot = xmlDoc.NewElement(xmlPlaces.place.place);
        XMLElement *eNum = xmlDoc.NewElement(xmlPlaces.place.data.number);
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement(xmlPlaces.place.data.ifDock);
        eDock->SetText(true);
        XMLElement *eLenght = xmlDoc.NewElement(xmlPlaces.place.data.ifTall);
        eLenght->SetText(true);
        XMLElement *eElec = xmlDoc.NewElement(xmlPlaces.place.data.ifElec);
        eElec->SetText(true);
        XMLElement *eWater = xmlDoc.NewElement(xmlPlaces.place.data.ifWater);
        eWater->SetText(true);
        XMLElement *eBusy = xmlDoc.NewElement(xmlPlaces.place.data.ifBusy);
        eBusy->SetText(false);
        nRoot->InsertFirstChild(eNum);
        nRoot->InsertAfterChild(eNum, eDock);
        nRoot->InsertAfterChild(eDock, eLenght);
        nRoot->InsertAfterChild(eLenght, eElec);
        nRoot->InsertAfterChild(eElec, eWater);
        nRoot->InsertEndChild(eBusy);
        pRoot->InsertFirstChild(nRoot);
        i--;
    }
    for (int l = comptNbPlacesHorsQuaiPetites; l > 0; l--) {
        XMLNode *nRoot = xmlDoc.NewElement(xmlPlaces.place.place);
        XMLElement *eNum = xmlDoc.NewElement(xmlPlaces.place.data.number);
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement(xmlPlaces.place.data.ifDock);
        eDock->SetText(false);
        XMLElement *eLenght = xmlDoc.NewElement(xmlPlaces.place.data.ifTall);
        eLenght->SetText(false);
        XMLElement *eElec = xmlDoc.NewElement(xmlPlaces.place.data.ifElec);
        eElec->SetText(false);
        XMLElement *eWater = xmlDoc.NewElement(xmlPlaces.place.data.ifWater);
        eWater->SetText(false);
        XMLElement *eBusy = xmlDoc.NewElement(xmlPlaces.place.data.ifBusy);
        eBusy->SetText(false);
        nRoot->InsertFirstChild(eNum);
        nRoot->InsertAfterChild(eNum, eDock);
        nRoot->InsertAfterChild(eDock, eLenght);
        nRoot->InsertAfterChild(eLenght, eElec);
        nRoot->InsertAfterChild(eElec, eWater);
        nRoot->InsertEndChild(eBusy);
        pRoot->InsertFirstChild(nRoot);
        i--;
    }
    for (int l = comptNbPlacesHorsQuaiGrandes; l > 0; l--) {
        XMLNode *nRoot = xmlDoc.NewElement(xmlPlaces.place.place);
        XMLElement *eNum = xmlDoc.NewElement(xmlPlaces.place.data.number);
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement(xmlPlaces.place.data.ifDock);
        eDock->SetText(false);
        XMLElement *eLenght = xmlDoc.NewElement(xmlPlaces.place.data.ifTall);
        eLenght->SetText(true);
        XMLElement *eElec = xmlDoc.NewElement(xmlPlaces.place.data.ifElec);
        eElec->SetText(false);
        XMLElement *eWater = xmlDoc.NewElement(xmlPlaces.place.data.ifWater);
        eWater->SetText(false);
        XMLElement *eBusy = xmlDoc.NewElement(xmlPlaces.place.data.ifBusy);
        eBusy->SetText(false);
        nRoot->InsertFirstChild(eNum);
        nRoot->InsertAfterChild(eNum, eDock);
        nRoot->InsertAfterChild(eDock, eLenght);
        nRoot->InsertAfterChild(eLenght, eElec);
        nRoot->InsertAfterChild(eElec, eWater);
        nRoot->InsertEndChild(eBusy);
        pRoot->InsertFirstChild(nRoot);
        i--;
    }
    xmlDoc.InsertFirstChild(pRoot);
    XMLError eResult = xmlDoc.SaveFile(xmlFilesNameDP.linkPlacesXMLFile);
}

/**
 * Action qui va importer le fichier XML de la liste des places en vector, sans critères
 */
vector<Place> DataPlace::importPlacesFile() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(xmlFilesNameDP.linkPlacesXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement("Place");

    vector<Place> listePlaces;

    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        while (pElement != nullptr) {
            Place p;
            p.setNumber(datadp.extractIntFromXML(eResult, pElement, "number"));
            p.setDock(datadp.extractBoolFromXML(eResult, pElement, "ifDock"));
            p.setTall(datadp.extractBoolFromXML(eResult, pElement, "ifTall"));
            p.setElec(datadp.extractBoolFromXML(eResult, pElement, "ifElec"));
            p.setWater(datadp.extractBoolFromXML(eResult, pElement, "ifWater"));
            p.setBusy(datadp.extractBoolFromXML(eResult, pElement, "ifBusy"));
            listePlaces.push_back(p);
            pElement = pElement->NextSiblingElement("Place");
        }
    }
    return listePlaces;
}

/**
 * Action qui va afficher dans le terminal les détails de la place choisie
 * @param p place choisie
 */
void DataPlace::displayPlace(Place p) {
    string isDock = (p.isDock() == 0) ? "Hors quai" : "Sur quai";
    string isTall = (p.isTall() == 0) ? "taille normale" : "grande taille";
    string isElec = (p.isElec() == 0) ? "Pas d\'electricite" : "Acces a l\'electricite";
    string isWater = (p.isWater() == 0) ? "pas d\'eau" : "acces a l\'eau";
    string isBusy = (p.isBusy() == 0) ? "LIBRE" : "OCCUPEE";
    cout << "Place n°" << p.getNumber()
         << " [" << isBusy << "] - " << isDock << " et " << isTall << " (" << isElec << ", " << isWater << ")" << endl;
}

/**
 * Action qui va afficher l'ensemble des places enregistrées dans le vecteur
 * @param p ensemble des places enregistrées dans ce vecteur
 */
void DataPlace::displayPlaces(vector<Place> p) {
    for (int i = 0; i < p.size(); i++) {
        displayPlace(p[i]);
    }
    cout << " " << endl;
}

/**
 * Fonction qui va vérifier si la fichier de la liste des places existe
 * @return vrai si le fichier existe déjà, faux sinon.
 */
bool DataPlace::checkIfPlacesFileExist() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(xmlFilesNameDP.linkPlacesXMLFile);
    if (eResult == XML_ERROR_FILE_NOT_FOUND) {
        return false;
    } else {
        return true;
    }
}

/**
 * Action qui va importer le fichier XML de la liste des places en vector, avec critères
 */
vector<Place> DataPlace::importPlacesFileCriteriaLength(bool isTall, bool isFree) {
    vector<Place> placesList;
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(xmlFilesNameDP.linkPlacesXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement("Place");
    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        while (pElement != nullptr) {
            Place p;
            bool ifError = false;
            p.setNumber(datadp.extractIntFromXML(eResult, pElement, "number"));
            p.setDock(datadp.extractBoolFromXML(eResult, pElement, "ifDock"));
            p.setTall(datadp.extractBoolFromXML(eResult, pElement, "ifTall"));
            p.setElec(datadp.extractBoolFromXML(eResult, pElement, "ifElec"));
            p.setWater(datadp.extractBoolFromXML(eResult, pElement, "ifWater"));
            p.setBusy(datadp.extractBoolFromXML(eResult, pElement, "ifBusy"));
            //si on veut les grandes places libres
            if (isTall && isFree) {
                //si la place actuelle n'est pas grande ou qu'elle est occupée
                if (!p.isTall() || p.isBusy()) {
                    ifError = true;
                }
            } //si on veut les grandes places (libres et occupées)
            else if (isTall && !isFree) {
                //si la place actuelle n'est pas grande
                if (!p.isTall()) {
                    ifError = true;
                }
            } //si on veut les petites places libres
            else if (!isTall && isFree) {
                //si la place actuelle n'est pas petite ou qu'elle est occupée
                if (p.isTall() || p.isBusy()) {
                    ifError = true;
                }
            } //sinon on veut les petites places (libres et occupées)
            else {
                //si la place actuelle n'est pas petite
                if (p.isTall()) {
                    ifError = true;
                }
            }
            if (!ifError) {
                placesList.push_back(p);
            }
            pElement = pElement->NextSiblingElement("Place");
        }
    }
    return placesList;
}

/**
 * Fonction qui va vérifier dans le numéro de la place choisi est bien dans la liste des places donnée
 * @param listPlaces liste des places donnée
 * @param choice numéro de place choisi
 * @return vrai si le numéro est présent dans la liste, sinon faux.
 */
bool DataPlace::checkNumberPlace(vector<Place> listPlaces, int choice) {
    bool ifOK = false;
    for (int i = 0; i < listPlaces.size(); i++) {
        if (listPlaces[i].getNumber() == choice) {
            ifOK = true;
        }
    }
    return ifOK;
}

/**
 * Fonction qui va retourner les informations de la place choisie à partir de son numéro
 * @param listPlaces liste des places donnée
 * @param choice numéro de place choisi
 * @return la place à partir du numéro choisi
 */
Place DataPlace::extractPlaceFromNumber(vector<Place> listPlaces, int choice) {
    Place p;
    for (int i = 0; i < listPlaces.size(); i++) {
        if (listPlaces[i].getNumber() == choice) {
            p.setNumber(listPlaces[i].getNumber());
            p.setDock(listPlaces[i].isDock());
            p.setTall(listPlaces[i].isTall());
            p.setElec(listPlaces[i].isElec());
            p.setWater(listPlaces[i].isWater());
            p.setBusy(true);
        }
    }
    return p;
}