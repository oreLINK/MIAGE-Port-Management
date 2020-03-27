//
// Created by Aurélien BERTRAND on 25/03/2020.
//

#include <iostream>
#include <array>
#include <vector>
#include <Client/Client.h>
#include <Tcl/tclTomMath.h>
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
 * Action qui va importer le fichier XML de la liste des places en vector, sans critères
 */
void Data::importPlacesFile() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkPlacesXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement("Place");
    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        vector<Place> placesList;
        while (pElement != nullptr) {
            Place p;
            p.setNumber(extractIntFromXML(eResult, pElement, "number"));
            p.setDock(extractBoolFromXML(eResult, pElement, "ifDock"));
            p.setTall(extractBoolFromXML(eResult, pElement, "ifTall"));
            p.setElec(extractBoolFromXML(eResult, pElement, "ifElec"));
            p.setWater(extractBoolFromXML(eResult, pElement, "ifWater"));
            p.setBusy(extractBoolFromXML(eResult, pElement, "ifBusy"));
            placesList.push_back(p);
            pElement = pElement->NextSiblingElement("Place");
        }
        displayPlaces(placesList);
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
        cout << "extractBoolFromXML(...) " << XML_ERROR_PARSING_ELEMENT << endl;
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
const char * Data::extractCharFromXML(XMLError eResult, XMLElement *elementFather, const char *id) {
    const char * iChar = nullptr;
    XMLElement *pElement = elementFather->FirstChildElement(id);
    if (pElement == nullptr) {
        cout << "extractBoolFromXML(...) " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        iChar = pElement->GetText();
    }
    return iChar;
}

/**
 * Action qui va afficher dans le terminal les détails de la place choisie
 * @param p place choisie
 */
void Data::displayPlace(Place p) {
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
void Data::displayPlaces(vector<Place> p) {
    for (int i = 0; i < p.size(); i++) {
        displayPlace(p[i]);
    }
    cout << " " << endl;
}

/**
 * Fonction qui va vérifier si la fichier de la liste des places existe
 * @return vrai si le fichier existe déjà, faux sinon.
 */
bool Data::checkIfPlacesFileExist() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkPlacesXMLFile);
    if(eResult == XML_ERROR_FILE_NOT_FOUND){
        return false;
    } else {
        return true;
    }
}

/**
 * Action qui va importer le fichier XML de la liste des places en vector, avec critères
 */
vector<Place> Data::importPlacesFileCriteriaLength(bool isTall, bool isFree) {
    vector<Place> placesList;
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkPlacesXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement("Place");
    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        while (pElement != nullptr) {
            Place p;
            bool ifError = false;
            p.setNumber(extractIntFromXML(eResult, pElement, "number"));
            p.setDock(extractBoolFromXML(eResult, pElement, "ifDock"));
            p.setTall(extractBoolFromXML(eResult, pElement, "ifTall"));
            p.setElec(extractBoolFromXML(eResult, pElement, "ifElec"));
            p.setWater(extractBoolFromXML(eResult, pElement, "ifWater"));
            p.setBusy(extractBoolFromXML(eResult, pElement, "ifBusy"));
            //si on veut les grandes places libres
            if(isTall && isFree) {
                //si la place actuelle n'est pas grande ou qu'elle est occupée
                if(!p.isTall() || p.isBusy()){
                    ifError = true;
                }
            } //si on veut les grandes places (libres et occupées)
            else if (isTall && !isFree) {
                //si la place actuelle n'est pas grande
                if(!p.isTall()){
                    ifError = true;
                }
            } //si on veut les petites places libres
            else if (!isTall && isFree) {
                //si la place actuelle n'est pas petite ou qu'elle est occupée
                if(p.isTall() || p.isBusy()){
                    ifError = true;
                }
            } //sinon on veut les petites places (libres et occupées)
            else {
                //si la place actuelle n'est pas petite
                if(p.isTall()){
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
bool Data::checkNumberPlace(vector<Place> listPlaces, int choice){
    bool ifOK = false;
    for (int i = 0; i < listPlaces.size(); i++) {
        if(listPlaces[i].getNumber() == choice){
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
Place Data::extractPlaceFromNumber(vector<Place> listPlaces, int choice){
    Place p;
    for (int i = 0; i < listPlaces.size(); i++) {
        if(listPlaces[i].getNumber() == choice){
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

/**
 * Action qui va créer le fichier XML initial des clients de la marina lors du premier lancement du programme.
 */
void Data::createFirstClientFile(){
    XMLDocument xmlDoc;
    XMLNode *pRoot = xmlDoc.NewElement("ListeDesClients");

    Client c1(1,"DUPONT","Martin","dupont.martin@gmail.com",7,"avenue des Eglantiers","75000","Paris");
    Client c2(2,"BERNIER","Sophia","berniersophia33@hotmail.com",9,"rue des Cordeliers","33000","Bordeaux");
    Client c3(3,"LAFONT","Richard","lafont-richard@gmail.com",8,"impasse des Deux","64100","Bayonne");

    vector<Client> listeClientInitial;
    listeClientInitial.push_back(c3);
    listeClientInitial.push_back(c2);
    listeClientInitial.push_back(c1);

    displayClients(listeClientInitial);

    for (int i = 0; i < listeClientInitial.size(); i++) {
        XMLNode *nRoot = xmlDoc.NewElement("Client");
        XMLElement *eID = xmlDoc.NewElement("id");
        eID->SetText(listeClientInitial[i].getId());
        XMLElement *eNom = xmlDoc.NewElement("nom");
        eNom->SetText(listeClientInitial[i].getNom());
        XMLElement *ePrenom = xmlDoc.NewElement("prenom");
        ePrenom->SetText(listeClientInitial[i].getPrenom());
        XMLElement *eEmail = xmlDoc.NewElement("email");
        eEmail->SetText(listeClientInitial[i].getEmail());
        XMLElement *eNumAdresse = xmlDoc.NewElement("numadresse");
        eNumAdresse->SetText(listeClientInitial[i].getNumeroAdresse());
        XMLElement *eAdresse = xmlDoc.NewElement("adresse");
        eAdresse->SetText(listeClientInitial[i].getAdresse());
        XMLElement *eCP = xmlDoc.NewElement("cp");
        eCP->SetText(listeClientInitial[i].getCp());
        XMLElement *eVille = xmlDoc.NewElement("ville");
        eVille->SetText(listeClientInitial[i].getVille());
        nRoot->InsertFirstChild(eID);
        nRoot->InsertAfterChild(eID, eNom);
        nRoot->InsertAfterChild(eNom, ePrenom);
        nRoot->InsertAfterChild(ePrenom, eEmail);
        nRoot->InsertAfterChild(eEmail, eNumAdresse);
        nRoot->InsertAfterChild(eNumAdresse, eAdresse);
        nRoot->InsertAfterChild(eAdresse, eCP);
        nRoot->InsertEndChild(eVille);
        pRoot->InsertFirstChild(nRoot);
    }
    xmlDoc.InsertFirstChild(pRoot);
    XMLError eResult = xmlDoc.SaveFile(linkClientXMLFile);
}

/**
 * Fonction qui va vérifier si la fichier de la liste des clients existe
 * @return vrai si le fichier existe déjà, faux sinon.
 */
bool Data::checkIfClientsFileExist() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkClientXMLFile);
    if(eResult == XML_ERROR_FILE_NOT_FOUND){
        return false;
    } else {
        return true;
    }
}

/**
 * Action qui va importer le fichier XML de la liste des clients en vector, sans critères
 */
vector<Client> Data::importClientsFile() {
    vector<Client> clientsList;
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkClientXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement("Client");
    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        while (pElement != nullptr) {
            Client c;
            c.setId(extractIntFromXML(eResult,pElement,"id"));
            c.setNom(extractCharFromXML(eResult,pElement,"nom"));
            c.setPrenom(extractCharFromXML(eResult,pElement,"prenom"));
            c.setEmail(extractCharFromXML(eResult,pElement,"email"));
            c.setNumeroAdresse(extractIntFromXML(eResult,pElement,"numadresse"));
            c.setAdresse(extractCharFromXML(eResult,pElement,"adresse"));
            c.setCp(extractCharFromXML(eResult,pElement,"cp"));
            c.setVille(extractCharFromXML(eResult,pElement,"ville"));
            clientsList.push_back(c);
            pElement = pElement->NextSiblingElement("Client");
        }
    }
    return clientsList;
}

/**
 * Action qui va afficher dans le terminal les détails de la place choisie
 * @param p place choisie
 */
void Data::displayClient(Client c) {
    cout << "Client n°" << c.getId() << " - " << c.getNom() << " " << c.getPrenom()
    << " (" << c.getEmail() << ") " << c.getNumeroAdresse() << " " << c.getAdresse() << " " << c.getCp() << " " << c.getVille() << endl;
}

/**
 * Action qui va afficher l'ensemble des places enregistrées dans le vecteur
 * @param p ensemble des places enregistrées dans ce vecteur
 */
void Data::displayClients(vector<Client> c) {
    for (int i = 0; i < c.size(); i++) {
        displayClient(c[i]);
    }
    cout << " " << endl;
}


