//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#include <include/Reservation.h>
#include <include/tinyxml2.h>
#include <include/data/Data.h>
#include <iostream>
#include <vector>
#include "include/data/DataReservation.h"
#include "include/data/DataPlace.h"

XMLFilesName xmlFilesName;
XMLReservations xmlReservationsDR;

Data datadr;
BateauType bateauTypeDR;
DataPlace dataPlaceDR;


/**
 * Action qui va créer le premier fichier des réservations
 */
void DataReservation::createReservationsFile() {
    XMLDocument xmlDoc;
    XMLNode *pRoot = xmlDoc.NewElement(xmlReservationsDR.ListeDesReservations);

    Reservation r;

    r.setId(1);
    r.setIdClient(1);
    Bateau b(56, true, bateauTypeDR.voilierType2String);
    r.setBateau(b);
    r.setNumeroPlace(11);
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
    Paiement paie(15, 42, 0, 0, 0,630,false);
    r.setPaiement(paie);

    XMLNode *nRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.Reservation);

    XMLElement *rID = xmlDoc.NewElement(xmlReservationsDR.reservation.id);
    rID->SetText(r.getId());
    nRoot->InsertFirstChild(rID);

    XMLElement *rIDClient = xmlDoc.NewElement(xmlReservationsDR.reservation.idClient);
    rIDClient->SetText(r.getIdClient());
    nRoot->InsertAfterChild(rID, rIDClient);

    XMLNode *bateauRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.Bateau);
    XMLElement *bateauTaille = xmlDoc.NewElement(xmlReservationsDR.reservation.bateau.taille);
    bateauTaille->SetText(r.getBateau().getTaille());
    XMLElement *bateauSiCabine = xmlDoc.NewElement(xmlReservationsDR.reservation.bateau.siCabine);
    bateauSiCabine->SetText(r.getBateau().isSiCabine());
    XMLElement *bateauType = xmlDoc.NewElement(xmlReservationsDR.reservation.bateau.type);
    bateauType->SetText(r.getBateau().getTypeBateau().c_str());
    bateauRoot->InsertFirstChild(bateauTaille);
    bateauRoot->InsertAfterChild(bateauTaille, bateauSiCabine);
    bateauRoot->InsertEndChild(bateauType);
    nRoot->InsertAfterChild(rIDClient, bateauRoot);

    XMLElement *rIDPlace = xmlDoc.NewElement(xmlReservationsDR.reservation.numeroPlace);
    rIDPlace->SetText(r.getNumeroPlace());
    nRoot->InsertAfterChild(bateauRoot, rIDPlace);

    XMLNode *dateArriveeRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.DateArrivee);
    XMLElement *anneeArrivee = xmlDoc.NewElement(xmlReservationsDR.reservation.dateArrivee.annee);
    anneeArrivee->SetText(r.getDateArrivee().getYear());
    XMLElement *moisArrivee = xmlDoc.NewElement(xmlReservationsDR.reservation.dateArrivee.mois);
    moisArrivee->SetText(r.getDateArrivee().getMonth());
    XMLElement *jourArrivee = xmlDoc.NewElement(xmlReservationsDR.reservation.dateArrivee.jour);
    jourArrivee->SetText(r.getDateArrivee().getDay());
    dateArriveeRoot->InsertFirstChild(anneeArrivee);
    dateArriveeRoot->InsertAfterChild(anneeArrivee, moisArrivee);
    dateArriveeRoot->InsertEndChild(jourArrivee);
    nRoot->InsertAfterChild(rIDPlace, dateArriveeRoot);

    XMLNode *dateDepartRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.DateDepart);
    XMLElement *anneeDepart = xmlDoc.NewElement(xmlReservationsDR.reservation.dateDepart.annee);
    anneeDepart->SetText(r.getDateDepart().getYear());
    XMLElement *moisDepart = xmlDoc.NewElement(xmlReservationsDR.reservation.dateDepart.mois);
    moisDepart->SetText(r.getDateDepart().getMonth());
    XMLElement *jourDepart = xmlDoc.NewElement(xmlReservationsDR.reservation.dateDepart.jour);
    jourDepart->SetText(r.getDateDepart().getDay());
    dateDepartRoot->InsertFirstChild(anneeDepart);
    dateDepartRoot->InsertAfterChild(anneeDepart, moisDepart);
    dateDepartRoot->InsertEndChild(jourDepart);
    nRoot->InsertAfterChild(dateArriveeRoot, dateDepartRoot);

    XMLElement *rSuppElec = xmlDoc.NewElement(xmlReservationsDR.reservation.supplementElec);
    rSuppElec->SetText(r.isSupplementElec());
    nRoot->InsertAfterChild(dateDepartRoot, rSuppElec);

    XMLElement *rSuppWater = xmlDoc.NewElement(xmlReservationsDR.reservation.supplementEau);
    rSuppWater->SetText(r.isSupplementEau());
    nRoot->InsertAfterChild(rSuppElec, rSuppWater);

    XMLElement *rSuppAbonne = xmlDoc.NewElement(xmlReservationsDR.reservation.abonnement);
    rSuppAbonne->SetText(r.isAbonnement());
    nRoot->InsertAfterChild(rSuppWater, rSuppAbonne);

    XMLNode *paiementRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.Paiement);
    XMLElement *nombreJours = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.nombreJours);
    nombreJours->SetText(r.getPaiement().getNbJours());
    XMLElement *paiementJ = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementJournalier);
    paiementJ->SetText(r.getPaiement().getPaiementJournalier());
    XMLElement *paiementM1 = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementMensuelPremierMois);
    paiementM1->SetText(r.getPaiement().getPaiementMensuelPremierMois());
    XMLElement *paiementM11 = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementMensuel11Mois);
    paiementM11->SetText(r.getPaiement().getPaiementMensuel11Mois());
    XMLElement *paiementA = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementAnnuel);
    paiementA->SetText(r.getPaiement().getPaiementAnnuel());
    XMLElement *paiementT = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.total);
    paiementT->SetText(r.getPaiement().getTotal());
    XMLElement *isPaid = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.isPaid);
    isPaid->SetText(r.getPaiement().isAPaye());
    paiementRoot->InsertFirstChild(nombreJours);
    paiementRoot->InsertAfterChild(nombreJours, paiementJ);
    paiementRoot->InsertAfterChild(paiementJ, paiementM1);
    paiementRoot->InsertAfterChild(paiementM1, paiementM11);
    paiementRoot->InsertAfterChild(paiementM11, paiementA);
    paiementRoot->InsertAfterChild(paiementA, paiementT);
    paiementRoot->InsertEndChild(isPaid);
    nRoot->InsertAfterChild(rSuppAbonne, paiementRoot);

    pRoot->InsertFirstChild(nRoot);
    xmlDoc.InsertFirstChild(pRoot);
    XMLError eResult = xmlDoc.SaveFile(xmlFilesName.linkReservationsXMLFile);

    dataPlaceDR.changePlaceBusy(r.getNumeroPlace());
}

/**
 * Fonction qui va vérifier si la fichier de la liste des réservations existe
 * @return vrai si le fichier existe déjà, faux sinon.
 */
bool DataReservation::checkIfReservationsFileExist() {
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(xmlFilesName.linkReservationsXMLFile);
    if (eResult == XML_ERROR_FILE_NOT_FOUND) {
        return false;
    } else {
        return true;
    }
}

/**
 * Action qui va importer le fichier XML de la liste des reservations en vector, sans critères
 */
vector<Reservation> DataReservation::importReservationsFile() {
    vector<Reservation> reservationsList;
    XMLDocument xmlDoc;
    XMLError eResult = xmlDoc.LoadFile(xmlFilesName.linkReservationsXMLFile);
    XMLNode *pRoot = xmlDoc.FirstChild();
    XMLElement *pElement = pRoot->FirstChildElement(xmlReservationsDR.reservation.Reservation);
    if (pElement == nullptr) {
        cout << "1. " << XML_ERROR_PARSING_ELEMENT << endl;
    } else {
        while (pElement != nullptr) {

            int id = datadr.extractIntFromXML(eResult, pElement, xmlReservationsDR.reservation.id);

            int idClient = datadr.extractIntFromXML(eResult, pElement, xmlReservationsDR.reservation.idClient);

            XMLElement *bElement = pElement->FirstChildElement(xmlReservationsDR.reservation.Bateau);

            Bateau b(datadr.extractIntFromXML(eResult, bElement, xmlReservationsDR.reservation.bateau.taille),
                     datadr.extractBoolFromXML(eResult, bElement, xmlReservationsDR.reservation.bateau.siCabine),
                     datadr.extractCharFromXML(eResult, bElement, xmlReservationsDR.reservation.bateau.type));

            int numPlace = datadr.extractIntFromXML(eResult,pElement,xmlReservationsDR.reservation.numeroPlace);

            XMLElement *dAElement = pElement->FirstChildElement(xmlReservationsDR.reservation.DateArrivee);

            Date dA(datadr.extractIntFromXML(eResult, dAElement, xmlReservationsDR.reservation.dateArrivee.annee),
                    datadr.extractIntFromXML(eResult, dAElement, xmlReservationsDR.reservation.dateArrivee.mois),
                    datadr.extractIntFromXML(eResult, dAElement, xmlReservationsDR.reservation.dateArrivee.jour));

            XMLElement *dDElement = pElement->FirstChildElement(xmlReservationsDR.reservation.DateDepart);

            Date dD(datadr.extractIntFromXML(eResult, dDElement, xmlReservationsDR.reservation.dateDepart.annee),
                    datadr.extractIntFromXML(eResult, dDElement, xmlReservationsDR.reservation.dateDepart.mois),
                    datadr.extractIntFromXML(eResult, dDElement, xmlReservationsDR.reservation.dateDepart.jour));

            bool siSuppElec = datadr.extractBoolFromXML(eResult,pElement,xmlReservationsDR.reservation.supplementElec);
            bool siSuppWater = datadr.extractBoolFromXML(eResult,pElement,xmlReservationsDR.reservation.supplementEau);
            bool siAbonnement= datadr.extractBoolFromXML(eResult,pElement,xmlReservationsDR.reservation.abonnement);

            XMLElement *paiementElement = pElement->FirstChildElement(xmlReservationsDR.reservation.Paiement);

            Paiement paie(datadr.extractIntFromXML(eResult,paiementElement,xmlReservationsDR.reservation.paiement.nombreJours),
                          datadr.extractIntFromXML(eResult,paiementElement,xmlReservationsDR.reservation.paiement.paiementJournalier),
                          datadr.extractIntFromXML(eResult,paiementElement,xmlReservationsDR.reservation.paiement.paiementMensuelPremierMois),
                          datadr.extractIntFromXML(eResult,paiementElement,xmlReservationsDR.reservation.paiement.paiementMensuel11Mois),
                          datadr.extractIntFromXML(eResult,paiementElement,xmlReservationsDR.reservation.paiement.paiementAnnuel),
                          datadr.extractIntFromXML(eResult,paiementElement,xmlReservationsDR.reservation.paiement.total),
                          datadr.extractBoolFromXML(eResult,paiementElement,xmlReservationsDR.reservation.paiement.isPaid));

            Reservation r(id,idClient,b,numPlace,dA,dD,siSuppElec,siSuppWater,siAbonnement,paie);

            reservationsList.push_back(r);

            pElement = pElement->NextSiblingElement(xmlReservationsDR.reservation.Reservation);
        }
    }
    return reservationsList;
}

vector<Reservation> DataReservation::addReservation(Reservation r){
    vector<Reservation> vR = importReservationsFile();
    r.setId(vR.size()+1);
    vR.push_back(r);
    return vR;
}


void DataReservation::saveReservations(vector<Reservation> r){
    XMLDocument xmlDoc;
    XMLNode *pRoot = xmlDoc.NewElement(xmlReservationsDR.ListeDesReservations);

    for (int i = 0; i < r.size(); i++) {
        XMLNode *nRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.Reservation);

        XMLElement *rID = xmlDoc.NewElement(xmlReservationsDR.reservation.id);
        rID->SetText(r[i].getId());
        nRoot->InsertFirstChild(rID);

        XMLElement *rIDClient = xmlDoc.NewElement(xmlReservationsDR.reservation.idClient);
        rIDClient->SetText(r[i].getIdClient());
        nRoot->InsertAfterChild(rID, rIDClient);

        XMLNode *bateauRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.Bateau);
        XMLElement *bateauTaille = xmlDoc.NewElement(xmlReservationsDR.reservation.bateau.taille);
        bateauTaille->SetText(r[i].getBateau().getTaille());
        XMLElement *bateauSiCabine = xmlDoc.NewElement(xmlReservationsDR.reservation.bateau.siCabine);
        bateauSiCabine->SetText(r[i].getBateau().isSiCabine());
        XMLElement *bateauType = xmlDoc.NewElement(xmlReservationsDR.reservation.bateau.type);
        bateauType->SetText(r[i].getBateau().getTypeBateau().c_str());
        bateauRoot->InsertFirstChild(bateauTaille);
        bateauRoot->InsertAfterChild(bateauTaille, bateauSiCabine);
        bateauRoot->InsertEndChild(bateauType);
        nRoot->InsertAfterChild(rIDClient, bateauRoot);

        XMLElement *rIDPlace = xmlDoc.NewElement(xmlReservationsDR.reservation.numeroPlace);
        rIDPlace->SetText(r[i].getNumeroPlace());
        nRoot->InsertAfterChild(bateauRoot, rIDPlace);

        XMLNode *dateArriveeRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.DateArrivee);
        XMLElement *anneeArrivee = xmlDoc.NewElement(xmlReservationsDR.reservation.dateArrivee.annee);
        anneeArrivee->SetText(r[i].getDateArrivee().getYear());
        XMLElement *moisArrivee = xmlDoc.NewElement(xmlReservationsDR.reservation.dateArrivee.mois);
        moisArrivee->SetText(r[i].getDateArrivee().getMonth());
        XMLElement *jourArrivee = xmlDoc.NewElement(xmlReservationsDR.reservation.dateArrivee.jour);
        jourArrivee->SetText(r[i].getDateArrivee().getDay());
        dateArriveeRoot->InsertFirstChild(anneeArrivee);
        dateArriveeRoot->InsertAfterChild(anneeArrivee, moisArrivee);
        dateArriveeRoot->InsertEndChild(jourArrivee);
        nRoot->InsertAfterChild(rIDPlace, dateArriveeRoot);

        XMLNode *dateDepartRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.DateDepart);
        XMLElement *anneeDepart = xmlDoc.NewElement(xmlReservationsDR.reservation.dateDepart.annee);
        anneeDepart->SetText(r[i].getDateDepart().getYear());
        XMLElement *moisDepart = xmlDoc.NewElement(xmlReservationsDR.reservation.dateDepart.mois);
        moisDepart->SetText(r[i].getDateDepart().getMonth());
        XMLElement *jourDepart = xmlDoc.NewElement(xmlReservationsDR.reservation.dateDepart.jour);
        jourDepart->SetText(r[i].getDateDepart().getDay());
        dateDepartRoot->InsertFirstChild(anneeDepart);
        dateDepartRoot->InsertAfterChild(anneeDepart, moisDepart);
        dateDepartRoot->InsertEndChild(jourDepart);
        nRoot->InsertAfterChild(dateArriveeRoot, dateDepartRoot);

        XMLElement *rSuppElec = xmlDoc.NewElement(xmlReservationsDR.reservation.supplementElec);
        rSuppElec->SetText(r[i].isSupplementElec());
        nRoot->InsertAfterChild(dateDepartRoot, rSuppElec);

        XMLElement *rSuppWater = xmlDoc.NewElement(xmlReservationsDR.reservation.supplementEau);
        rSuppWater->SetText(r[i].isSupplementEau());
        nRoot->InsertAfterChild(rSuppElec, rSuppWater);

        XMLElement *rSuppAbonne = xmlDoc.NewElement(xmlReservationsDR.reservation.abonnement);
        rSuppAbonne->SetText(r[i].isAbonnement());
        nRoot->InsertAfterChild(rSuppWater, rSuppAbonne);

        XMLNode *paiementRoot = xmlDoc.NewElement(xmlReservationsDR.reservation.Paiement);
        XMLElement *nombreJours = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.nombreJours);
        nombreJours->SetText(r[i].getPaiement().getNbJours());
        XMLElement *paiementJ = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementJournalier);
        paiementJ->SetText(r[i].getPaiement().getPaiementJournalier());
        XMLElement *paiementM1 = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementMensuelPremierMois);
        paiementM1->SetText(r[i].getPaiement().getPaiementMensuelPremierMois());
        XMLElement *paiementM11 = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementMensuel11Mois);
        paiementM11->SetText(r[i].getPaiement().getPaiementMensuel11Mois());
        XMLElement *paiementA = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.paiementAnnuel);
        paiementA->SetText(r[i].getPaiement().getPaiementAnnuel());
        XMLElement *paiementT = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.total);
        paiementT->SetText(r[i].getPaiement().getTotal());
        XMLElement *isPaid = xmlDoc.NewElement(xmlReservationsDR.reservation.paiement.isPaid);
        isPaid->SetText(r[i].getPaiement().isAPaye());
        paiementRoot->InsertFirstChild(nombreJours);
        paiementRoot->InsertAfterChild(nombreJours, paiementJ);
        paiementRoot->InsertAfterChild(paiementJ, paiementM1);
        paiementRoot->InsertAfterChild(paiementM1, paiementM11);
        paiementRoot->InsertAfterChild(paiementM11, paiementA);
        paiementRoot->InsertAfterChild(paiementA, paiementT);
        paiementRoot->InsertEndChild(isPaid);
        nRoot->InsertAfterChild(rSuppAbonne, paiementRoot);

        pRoot->InsertFirstChild(nRoot);


    }
    dataPlaceDR.changePlaceBusy(r[r.size()-1].getNumeroPlace());
    xmlDoc.InsertFirstChild(pRoot);
    XMLError eResult = xmlDoc.SaveFile(xmlFilesName.linkReservationsXMLFile);
}
