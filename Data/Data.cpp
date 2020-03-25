//
// Created by Aurélien BERTRAND on 25/03/2020.
//

#include <iostream>
#include <array>
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
    importPlacesFile();
}

void Data::importPlacesFile() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkPlacesXMLFile);
    XMLNode * pRoot = xmlDoc.FirstChild();
    if(pRoot == nullptr){
        cout << XML_ERROR_FILE_READ_ERROR << endl;
    }
    XMLElement * pElement = pRoot->FirstChildElement("Place");
    if(pElement == nullptr){
        cout << XML_ERROR_PARSING_ELEMENT << endl;
    }
    int * number = nullptr;
    eResult = pElement->QueryIntAttribute("number",number);
    cout << number << endl;
}
