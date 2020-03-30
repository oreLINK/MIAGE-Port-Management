//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#include <include/Client.h>
#include <include/data/Data.h>
#include <iostream>
#include <vector>
#include <include/Interface.h>
#include "include/data/DataClient.h"

Interface idc;
XMLFilesName xmlFilesNamedc;
Data datadc;

/**
 * Action qui va créer le fichier XML initial des clients de la marina lors du premier lancement du programme.
 */
void DataClient::createFirstClientFile() {
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
    XMLError eResult = xmlDoc.SaveFile(xmlFilesNamedc.linkClientsXMLFile);
}

/**
 * Fonction qui va vérifier si la fichier de la liste des clients existe
 * @return vrai si le fichier existe déjà, faux sinon.
 */
bool DataClient::checkIfClientsFileExist() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(xmlFilesNamedc.linkClientsXMLFile);
    if (eResult == XML_ERROR_FILE_NOT_FOUND) {
        return false;
    } else {
        return true;
    }
}

/**
 * Action qui va importer le fichier XML de la liste des clients en vector, sans critères
 */
vector<Client> DataClient::importClientsFile() {
    vector<Client> clientsList;
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(xmlFilesNamedc.linkClientsXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement("Client");
    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        while (pElement != nullptr) {
            Client *c = new Client();
            c->setId(datadc.extractIntFromXML(eResult, pElement, "id"));
            c->setNom(datadc.extractCharFromXML(eResult, pElement, "nom"));
            c->setPrenom(datadc.extractCharFromXML(eResult, pElement, "prenom"));
            c->setEmail(datadc.extractCharFromXML(eResult, pElement, "email"));
            c->setNumeroAdresse(datadc.extractIntFromXML(eResult, pElement, "numadresse"));
            c->setAdresse(datadc.extractCharFromXML(eResult, pElement, "adresse"));
            c->setCp(datadc.extractCharFromXML(eResult, pElement, "cp"));
            c->setVille(datadc.extractCharFromXML(eResult, pElement, "ville"));
            clientsList.push_back(*c);
            pElement = pElement->NextSiblingElement("Client");
        }
    }
    return clientsList;
}

/**
 * Action qui va afficher l'ensemble des places enregistrées dans le vecteur
 * @param p ensemble des places enregistrées dans ce vecteur
 */
void DataClient::displayClients(vector<Client> c) {
    for (int i = 0; i < c.size(); i++) {
        idc.displayClient(c[i]);
    }
    cout << " " << endl;
}

/**
 * Fonction qui va vérifier si l'ID entré dans le programme existe bien
 * @param listClient liste des clients
 * @param choice ID choisi
 * @return vrai si l'ID est présent dans la liste, faux sinon.
 */
bool DataClient::checkIDClient(vector<Client> listClient, int choice) {
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
Client DataClient::extractClientFromID(vector<Client> listClient, int choice) {
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

int DataClient::numberOfClients(vector<Client> c) {
    int number = 0;
    for (int i = 0; i < c.size(); i++) {
        number++;
    }
    return number;
}

vector<Client> DataClient::addNewClient(Client c) {
    vector<Client> newList = importClientsFile();
    c.setId(numberOfClients(newList) + 1);
    newList.push_back(c);
    for (int i = newList.size(); i > 0; i--) {
        newList.push_back(newList[i]);
    }
    return newList;
}

void DataClient::createNewClientFile(vector<Client> listClients) {
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
    XMLError eResult = xmlDoc.SaveFile(xmlFilesNamedc.linkClientsXMLFile);
}