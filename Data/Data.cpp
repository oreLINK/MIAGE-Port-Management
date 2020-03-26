//
// Created by Aurélien BERTRAND on 25/03/2020.
//

#include <iostream>
#include <array>
#include <vector>
#include "Data.h"
#include "../TinyXML/tinyxml2.h"

using namespace tinyxml2;
using namespace std;

Data::Data() {}

/**
 * Action qui va créer le fichier XML initial des places de bateau lors du premier lancement du programme.
 */
void Data::createFirstPlacesFile() {
    int comptNbPlacesQuaiPetites = nbPlacesQuaiPetites;
    int comptNbPlacesQuaiGrandes = nbPlacesQuaiGrandes;
    int comptNbPlacesHorsQuaiPetites = nbPlacesHorsQuaiPetites;
    int comptNbPlacesHorsQuaiGrandes = nbPlacesHorsQuaiGrandes;

    XMLDocument xmlDoc;
    XMLNode *pRoot = xmlDoc.NewElement("ListeDesPlaces");

    int i = nbPlaces;

    for (int j = comptNbPlacesQuaiPetites; j > 0; j--) {
        XMLNode *nRoot = xmlDoc.NewElement("Place");
        XMLElement *eNum = xmlDoc.NewElement("number");
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement("ifDock");
        eDock->SetText(true);
        XMLElement *eLenght = xmlDoc.NewElement("ifTall");
        eLenght->SetText(false);
        XMLElement *eElec = xmlDoc.NewElement("ifElec");
        eElec->SetText(true);
        XMLElement *eWater = xmlDoc.NewElement("ifWater");
        eWater->SetText(true);
        XMLElement *eBusy = xmlDoc.NewElement("ifBusy");
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
        XMLNode *nRoot = xmlDoc.NewElement("Place");
        XMLElement *eNum = xmlDoc.NewElement("number");
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement("ifDock");
        eDock->SetText(true);
        XMLElement *eLenght = xmlDoc.NewElement("ifTall");
        eLenght->SetText(true);
        XMLElement *eElec = xmlDoc.NewElement("ifElec");
        eElec->SetText(true);
        XMLElement *eWater = xmlDoc.NewElement("ifWater");
        eWater->SetText(true);
        XMLElement *eBusy = xmlDoc.NewElement("ifBusy");
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
        XMLNode *nRoot = xmlDoc.NewElement("Place");
        XMLElement *eNum = xmlDoc.NewElement("number");
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement("ifDock");
        eDock->SetText(false);
        XMLElement *eLenght = xmlDoc.NewElement("ifTall");
        eLenght->SetText(false);
        XMLElement *eElec = xmlDoc.NewElement("ifElec");
        eElec->SetText(false);
        XMLElement *eWater = xmlDoc.NewElement("ifWater");
        eWater->SetText(false);
        XMLElement *eBusy = xmlDoc.NewElement("ifBusy");
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
        XMLNode *nRoot = xmlDoc.NewElement("Place");
        XMLElement *eNum = xmlDoc.NewElement("number");
        eNum->SetText(i);
        XMLElement *eDock = xmlDoc.NewElement("ifDock");
        eDock->SetText(false);
        XMLElement *eLenght = xmlDoc.NewElement("ifTall");
        eLenght->SetText(true);
        XMLElement *eElec = xmlDoc.NewElement("ifElec");
        eElec->SetText(false);
        XMLElement *eWater = xmlDoc.NewElement("ifWater");
        eWater->SetText(false);
        XMLElement *eBusy = xmlDoc.NewElement("ifBusy");
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
    XMLError eResult = xmlDoc.SaveFile(linkPlacesXMLFile);
}

/**
 * Action qui va importer le fichier XML de la liste des places en vector
 */
void Data::importPlacesFile() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkPlacesXMLFile);
    XMLNode * pRoot = xmlDoc.FirstChild();
    XMLElement * pElement = pRoot->FirstChildElement("Place");
    if(pElement == nullptr){
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        vector<Place> placesList;
        while(pElement != nullptr){
            Place p;
            p.setNumber(extractIntFromXML(eResult,pElement,"number"));
            p.setDock(extractBoolFromXML(eResult,pElement,"ifDock"));
            p.setTall(extractBoolFromXML(eResult,pElement,"ifTall"));
            p.setElec(extractBoolFromXML(eResult,pElement,"ifElec"));
            p.setWater(extractBoolFromXML(eResult,pElement,"ifWater"));
            p.setBusy(extractBoolFromXML(eResult,pElement,"ifBusy"));
            placesList.push_back(p);
            pElement = pElement->NextSiblingElement("Place");
        }
        displayPlaces(placesList);
    }
}

int Data::extractIntFromXML(XMLError eResult, XMLElement * elementFather, const char * id){
    int iNumber = 0;
    XMLElement * pElement = elementFather->FirstChildElement(id);
    if(pElement == nullptr){
        cout << "extractIntFromXML(...) " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        eResult = pElement->QueryIntText(&iNumber);
    }
    return iNumber;
}

bool Data::extractBoolFromXML(XMLError eResult, XMLElement * elementFather, const char * id){
    bool iBool = false;
    XMLElement * pElement = elementFather->FirstChildElement(id);
    if(pElement == nullptr){
        cout << "extractBoolFromXML(...) " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        eResult = pElement->QueryBoolText(&iBool);
    }
    return iBool;
}

void Data::displayPlace(Place p){
    string isDock = (p.isDock() == 0) ? "Hors quai" : "Sur quai";
    string isTall = (p.isTall() == 0) ? "taille normale" : "grande taille";
    string isElec = (p.isElec() == 0) ? "Pas d\'electricite" : "Acces a l\'electricite";
    string isWater = (p.isWater() == 0) ? "pas d\'eau" : "acces a l\'eau";
    string isBusy = (p.isBusy() == 0) ? "LIBRE" : "OCCUPEE";
    cout << "Place n°" << p.getNumber()
    << " [" << isBusy << "] - " << isDock << " et " << isTall << " (" << isElec << ", " << isWater << ")" << endl;
}

void Data::displayPlaces(vector<Place> p){
    for(int i = 0; i < p.size(); i++){
        displayPlace(p[i]);
    }
}


