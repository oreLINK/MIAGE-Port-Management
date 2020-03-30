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
#include "include/Data.h"
#include "include/tinyxml2.h"

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
    if (eResult == XML_ERROR_FILE_NOT_FOUND) {
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
bool Data::checkNumberPlace(vector<Place> listPlaces, int choice) {
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
Place Data::extractPlaceFromNumber(vector<Place> listPlaces, int choice) {
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

/**
 * Action qui va créer le fichier XML initial des clients de la marina lors du premier lancement du programme.
 */
void Data::createFirstClientFile() {
    XMLDocument xmlDoc;
    XMLNode *pRoot = xmlDoc.NewElement("ListeDesClients");

    Client c1(1, "DUPONT", "Martin", "dupont.martin@gmail.com", 7, "avenue des Eglantiers", "75000", "Paris");
    Client c2(2, "BERNIER", "Sophia", "berniersophia33@hotmail.com", 9, "rue des Cordeliers", "33000", "Bordeaux");
    Client c3(3, "LAFONT", "Richard", "lafont-richard@gmail.com", 8, "impasse des Deux", "64100", "Bayonne");

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
        eNom->SetText(listeClientInitial[i].getNom().c_str());
        XMLElement *ePrenom = xmlDoc.NewElement("prenom");
        ePrenom->SetText(listeClientInitial[i].getPrenom().c_str());
        XMLElement *eEmail = xmlDoc.NewElement("email");
        eEmail->SetText(listeClientInitial[i].getEmail().c_str());
        XMLElement *eNumAdresse = xmlDoc.NewElement("numadresse");
        eNumAdresse->SetText(listeClientInitial[i].getNumeroAdresse());
        XMLElement *eAdresse = xmlDoc.NewElement("adresse");
        eAdresse->SetText(listeClientInitial[i].getAdresse().c_str());
        XMLElement *eCP = xmlDoc.NewElement("cp");
        eCP->SetText(listeClientInitial[i].getCp().c_str());
        XMLElement *eVille = xmlDoc.NewElement("ville");
        eVille->SetText(listeClientInitial[i].getVille().c_str());
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
    XMLError eResult = xmlDoc.SaveFile(linkClientsXMLFile);
}

/**
 * Fonction qui va vérifier si la fichier de la liste des clients existe
 * @return vrai si le fichier existe déjà, faux sinon.
 */
bool Data::checkIfClientsFileExist() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkClientsXMLFile);
    if (eResult == XML_ERROR_FILE_NOT_FOUND) {
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
    XMLError eResult = xmlDoc.LoadFile(linkClientsXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement("Client");
    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        while (pElement != nullptr) {
            Client *c = new Client();
            c->setId(extractIntFromXML(eResult, pElement, "id"));
            c->setNom(extractCharFromXML(eResult, pElement, "nom"));
            c->setPrenom(extractCharFromXML(eResult, pElement, "prenom"));
            c->setEmail(extractCharFromXML(eResult, pElement, "email"));
            c->setNumeroAdresse(extractIntFromXML(eResult, pElement, "numadresse"));
            c->setAdresse(extractCharFromXML(eResult, pElement, "adresse"));
            c->setCp(extractCharFromXML(eResult, pElement, "cp"));
            c->setVille(extractCharFromXML(eResult, pElement, "ville"));
            clientsList.push_back(*c);
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
         << " (" << c.getEmail() << ") " << c.getNumeroAdresse() << " " << c.getAdresse() << " " << c.getCp() << " "
         << c.getVille() << endl;
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

/**
 * Fonction qui va vérifier si l'ID entré dans le programme existe bien
 * @param listClient liste des clients
 * @param choice ID choisi
 * @return vrai si l'ID est présent dans la liste, faux sinon.
 */
bool Data::checkIDClient(vector<Client> listClient, int choice) {
    bool ifOK = false;
    for (int i = 0; i < listClient.size(); i++) {
        if (listClient[i].getId() == choice) {
            ifOK = true;
        }
    }
    return ifOK;
}

/**
 * Fonction qui va retourner les informations du client choisi à partir de son ID
 * @param listClient liste des clients
 * @param choice ID de client choisi
 * @return le client à partir de l'ID choisi
 */
Client Data::extractClientFromID(vector<Client> listClient, int choice) {
    Client c;
    for (int i = 0; i < listClient.size(); i++) {
        if (listClient[i].getId() == choice) {
            c.setId(listClient[i].getId());
            c.setNom(listClient[i].getNom());
            c.setPrenom(listClient[i].getPrenom());
            c.setEmail(listClient[i].getEmail());
            c.setNumeroAdresse(listClient[i].getNumeroAdresse());
            c.setAdresse(listClient[i].getAdresse());
            c.setCp(listClient[i].getCp());
            c.setVille(listClient[i].getVille());
        }
    }
    return c;
}

int Data::numberOfClients(vector<Client> c) {
    int number = 0;
    for (int i = 0; i < c.size(); i++) {
        number++;
    }
    return number;
}

vector<Client> Data::addNewClient(vector<Client> listClient, Client c) {
    vector<Client> newList;
    c.setId(numberOfClients(listClient) + 1);
    newList.push_back(c);
    for (int i = listClient.size(); i > 0; i--) {
        newList.push_back(listClient[i]);
    }
    return newList;
}

void Data::createNewClientFile(vector<Client> listClients) {
    XMLDocument xmlDoc;
    XMLNode *pRoot = xmlDoc.NewElement("ListeDesClients");

    for (int i = 0; i < listClients.size(); i++) {
        XMLNode *nRoot = xmlDoc.NewElement("Client");
        XMLElement *eID = xmlDoc.NewElement("id");
        eID->SetText(listClients[i].getId());
        XMLElement *eNom = xmlDoc.NewElement("nom");
        eNom->SetText(listClients[i].getNom().c_str());
        XMLElement *ePrenom = xmlDoc.NewElement("prenom");
        ePrenom->SetText(listClients[i].getPrenom().c_str());
        XMLElement *eEmail = xmlDoc.NewElement("email");
        eEmail->SetText(listClients[i].getEmail().c_str());
        XMLElement *eNumAdresse = xmlDoc.NewElement("numadresse");
        eNumAdresse->SetText(listClients[i].getNumeroAdresse());
        XMLElement *eAdresse = xmlDoc.NewElement("adresse");
        eAdresse->SetText(listClients[i].getAdresse().c_str());
        XMLElement *eCP = xmlDoc.NewElement("cp");
        eCP->SetText(listClients[i].getCp().c_str());
        XMLElement *eVille = xmlDoc.NewElement("ville");
        eVille->SetText(listClients[i].getVille().c_str());
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
    XMLError eResult = xmlDoc.SaveFile(linkClientsXMLFile);
}

Date Data::getDateToday() {
    Date d;

    time_t curr_time;
    tm *curr_tm;
    char year_string[100];
    char month_string[100];
    char day_string[100];

    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(year_string, 50, "%Y", curr_tm);
    strftime(month_string, 50, "%B", curr_tm);
    strftime(day_string, 50, "%d", curr_tm);

    int y = convertInt(year_string);
    int m = convertMonth(convertString(month_string));
    int j = convertInt(day_string);

    d.setYear(y);
    d.setMonth(m);
    d.setDay(j);

    return d;
}

/**
 * Fonction qui va convertir le const char * en string
 * @param cara le char à convertir
 * @return le string correspondant
 */
string Data::convertString(const char *cara) {
    stringstream s;
    s << cara;
    string m;
    s >> m;
    return m;
}

/**
 * Fonction qui va convertir le const char * en Integer
 * @param cara le int à convertir
 * @return le string correspondant
 */
int Data::convertInt(const char *cara) {
    stringstream s;
    s << cara;
    int y;
    s >> y;
    return y;
}

int Data::convertMonth(string month) {
    int mois;
    if (month == "January") {
        mois = 1;
    } else if (month == "February") {
        mois = 2;
    } else if (month == "March") {
        mois = 3;
    } else if (month == "April") {
        mois = 4;
    } else if (month == "May") {
        mois = 5;
    } else if (month == "June") {
        mois = 6;
    } else if (month == "July") {
        mois = 7;
    } else if (month == "August") {
        mois = 8;
    } else if (month == "September") {
        mois = 9;
    } else if (month == "October") {
        mois = 10;
    } else if (month == "November") {
        mois = 11;
    } else {
        mois = 12;
    }
    return mois;
}

/**
 * Action qui va créer le premier fichier des réservations
 */
void Data::createReservationsFile() {
    XMLDocument xmlDoc;
    XMLNode *pRoot = xmlDoc.NewElement("ListeDesReservations");

    Reservation r;

    int id = 1;
    r.setId(id);
    Client c(1, "DUPONT", "Martin", "dupont.martin@gmail.com", 7, "avenue des Eglantiers", "75000", "Paris");
    r.setClient(c);
    Bateau b(56, true, "Voilier de type 2");
    r.setBateau(b);
    Place p(11, true, true, true, true, true);
    r.setPlace(p);
    Date dA(2020, 3, 20);
    r.setDateArrivee(dA);
    Date dD(2020, 4, 3);
    r.setDateDepart(dD);
    bool supplementElec = true;
    r.setSupplementElec(supplementElec);
    bool supplementEau = true;
    r.setSupplementEau(supplementEau);
    bool abonnement = false;
    r.setAbonnement(abonnement);
    Paiement paie(15, 42, 0, 0, 630);
    r.setPaiement(paie);

    XMLNode *nRoot = xmlDoc.NewElement("Reservation");

    XMLElement *rID = xmlDoc.NewElement("id");
    rID->SetText(r.getId());
    nRoot->InsertFirstChild(rID);

    XMLNode *clientRoot = xmlDoc.NewElement("Client");
    XMLElement *eID = xmlDoc.NewElement("id");
    eID->SetText(r.getId());
    XMLElement *eNom = xmlDoc.NewElement("nom");
    eNom->SetText(r.getClient().getNom().c_str());
    XMLElement *ePrenom = xmlDoc.NewElement("prenom");
    ePrenom->SetText(r.getClient().getPrenom().c_str());
    XMLElement *eEmail = xmlDoc.NewElement("email");
    eEmail->SetText(r.getClient().getEmail().c_str());
    XMLElement *eNumAdresse = xmlDoc.NewElement("numadresse");
    eNumAdresse->SetText(r.getClient().getNumeroAdresse());
    XMLElement *eAdresse = xmlDoc.NewElement("adresse");
    eAdresse->SetText(r.getClient().getAdresse().c_str());
    XMLElement *eCP = xmlDoc.NewElement("cp");
    eCP->SetText(r.getClient().getCp().c_str());
    XMLElement *eVille = xmlDoc.NewElement("ville");
    eVille->SetText(r.getClient().getVille().c_str());
    clientRoot->InsertFirstChild(eID);
    clientRoot->InsertAfterChild(eID, eNom);
    clientRoot->InsertAfterChild(eNom, ePrenom);
    clientRoot->InsertAfterChild(ePrenom, eEmail);
    clientRoot->InsertAfterChild(eEmail, eNumAdresse);
    clientRoot->InsertAfterChild(eNumAdresse, eAdresse);
    clientRoot->InsertAfterChild(eAdresse, eCP);
    clientRoot->InsertEndChild(eVille);
    nRoot->InsertAfterChild(rID,clientRoot);

    XMLNode *bateauRoot = xmlDoc.NewElement("Bateau");
    XMLElement *bateauTaille = xmlDoc.NewElement("taille");
    bateauTaille->SetText(r.getBateau().getTaille());
    XMLElement *bateauSiCabine = xmlDoc.NewElement("siCabine");
    bateauSiCabine->SetText(r.getBateau().isSiCabine());
    XMLElement *bateauType = xmlDoc.NewElement("type");
    bateauType->SetText(r.getBateau().getTypeBateau().c_str());
    bateauRoot->InsertFirstChild(bateauTaille);
    bateauRoot->InsertAfterChild(bateauTaille, bateauSiCabine);
    bateauRoot->InsertEndChild(bateauType);
    nRoot->InsertAfterChild(clientRoot,bateauRoot);

    XMLNode *placeRoot = xmlDoc.NewElement("Place");
    XMLElement *numberPlace = xmlDoc.NewElement("number");
    numberPlace->SetText(r.getPlace().getNumber());
    XMLElement *ifDockPlace = xmlDoc.NewElement("ifDock");
    ifDockPlace->SetText(r.getPlace().isDock());
    XMLElement *ifTallPlace = xmlDoc.NewElement("ifTall");
    ifTallPlace->SetText(r.getPlace().isTall());
    XMLElement *ifElecPlace = xmlDoc.NewElement("ifElec");
    ifElecPlace->SetText(r.getPlace().isElec());
    XMLElement *ifWaterPlace = xmlDoc.NewElement("ifWater");
    ifWaterPlace->SetText(r.getPlace().isWater());
    XMLElement *ifBusyPlace = xmlDoc.NewElement("ifBusy");
    ifBusyPlace->SetText(r.getPlace().isBusy());
    placeRoot->InsertFirstChild(numberPlace);
    placeRoot->InsertAfterChild(numberPlace, ifDockPlace);
    placeRoot->InsertAfterChild(ifDockPlace, ifTallPlace);
    placeRoot->InsertAfterChild(ifTallPlace, ifElecPlace);
    placeRoot->InsertAfterChild(ifElecPlace, ifWaterPlace);
    placeRoot->InsertEndChild(ifBusyPlace);
    nRoot->InsertAfterChild(bateauRoot,placeRoot);

    XMLNode *dateArriveeRoot = xmlDoc.NewElement("DateArrivee");
    XMLElement *anneeArrivee = xmlDoc.NewElement("annee");
    anneeArrivee->SetText(r.getDateArrivee().getYear());
    XMLElement *moisArrivee = xmlDoc.NewElement("mois");
    moisArrivee->SetText(r.getDateArrivee().getMonth());
    XMLElement *jourArrivee = xmlDoc.NewElement("jour");
    jourArrivee->SetText(r.getDateArrivee().getDay());
    dateArriveeRoot->InsertFirstChild(anneeArrivee);
    dateArriveeRoot->InsertAfterChild(anneeArrivee, moisArrivee);
    dateArriveeRoot->InsertEndChild(jourArrivee);
    nRoot->InsertAfterChild(placeRoot,dateArriveeRoot);

    XMLNode *dateDepartRoot = xmlDoc.NewElement("DateDepart");
    XMLElement *anneeDepart = xmlDoc.NewElement("annee");
    anneeDepart->SetText(r.getDateDepart().getYear());
    XMLElement *moisDepart = xmlDoc.NewElement("mois");
    moisDepart->SetText(r.getDateDepart().getMonth());
    XMLElement *jourDepart = xmlDoc.NewElement("jour");
    jourDepart->SetText(r.getDateDepart().getDay());
    dateDepartRoot->InsertFirstChild(anneeDepart);
    dateDepartRoot->InsertAfterChild(anneeDepart, moisDepart);
    dateDepartRoot->InsertEndChild(jourDepart);
    nRoot->InsertAfterChild(dateArriveeRoot,dateDepartRoot);

    XMLElement *rSuppElec = xmlDoc.NewElement("supplementElec");
    rSuppElec->SetText(r.isSupplementElec());
    nRoot->InsertAfterChild(dateDepartRoot,rSuppElec);

    XMLElement *rSuppWater = xmlDoc.NewElement("supplementEau");
    rSuppWater->SetText(r.isSupplementEau());
    nRoot->InsertAfterChild(rSuppElec,rSuppWater);

    XMLElement *rSuppAbonne = xmlDoc.NewElement("abonnement");
    rSuppAbonne->SetText(r.isAbonnement());
    nRoot->InsertAfterChild(rSuppWater,rSuppAbonne);

    XMLNode *paiementRoot = xmlDoc.NewElement("Paiement");
    XMLElement *nombreJours = xmlDoc.NewElement("nombreJours");
    nombreJours->SetText(r.getPaiement().getNbJours());
    XMLElement *paiementJ = xmlDoc.NewElement("paiementJournalier");
    paiementJ->SetText(r.getPaiement().getPaiementJournalier());
    XMLElement *paiementM = xmlDoc.NewElement("paiementMensuel");
    paiementM->SetText(r.getPaiement().getPaiementMensuel());
    XMLElement *paiementA = xmlDoc.NewElement("paiementAnnuel");
    paiementA->SetText(r.getPaiement().getPaiementAnnuel());
    XMLElement *paiementT = xmlDoc.NewElement("total");
    paiementT->SetText(r.getPaiement().getTotal());
    paiementRoot->InsertFirstChild(nombreJours);
    paiementRoot->InsertAfterChild(nombreJours, paiementJ);
    paiementRoot->InsertAfterChild(paiementJ, paiementM);
    paiementRoot->InsertAfterChild(paiementM, paiementA);
    paiementRoot->InsertEndChild(paiementT);
    nRoot->InsertAfterChild(rSuppAbonne,paiementRoot);

    pRoot->InsertFirstChild(nRoot);
    xmlDoc.InsertFirstChild(pRoot);
    XMLError eResult = xmlDoc.SaveFile(linkReservationsXMLFile);
}

/**
 * Fonction qui va vérifier si la fichier de la liste des réservations existe
 * @return vrai si le fichier existe déjà, faux sinon.
 */
bool Data::checkIfReservationsFileExist() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(linkReservationsXMLFile);
    if (eResult == XML_ERROR_FILE_NOT_FOUND) {
        return false;
    } else {
        return true;
    }
}


