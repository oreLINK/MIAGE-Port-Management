//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "include/GestionPort.h"
#include <iostream>
#include "include/Bateau.h"
#include "include/Reservation.h"
#include "include/Interface.h"
#include "include/data/Data.h"
#include "include/Tarifs.h"
#include "include/data/DataPlace.h"
#include "include/data/DataClient.h"
#include "include/data/DataDate.h"
#include "include/data/DataReservation.h"
#include "include/BateauType.h"
#include "include/Calendrier.h"

#include <sstream>
#include <cctype>
#include <vector>

Interface igp;
Data datagp;
DataPlace dataplaceGP;
DataClient dataClientGP;
DataDate dataDateGP;
DataReservation dataReservationGP;
BateauType bateauType;

string voilierNH = "Voilier non habitable";
string voilierT1 = "Voilier de type 1";
string voilierT2 = "Voilier de type 2";

GestionPort::GestionPort() {}

/**
 * Action pour créer une nouvelle réservation.
 */
void GestionPort::createReservation() {

    //introduction et creation de la nouvelle réservation
    igp.interfaceNewReservation();
    Reservation r;

    //choix du bateau
    igp.interfaceNewBoat();
    r.setBateau(createBoat());

    //choix de la place (liste des places libres)
    igp.interfaceNewPlace();
    vector<Place> listPlacesFree;
    if (r.getBateau().getTypeBateau() == bateauType.voilierType2String) {
        listPlacesFree = dataplaceGP.importPlacesFileCriteriaLength(true, true);
    } else {
        listPlacesFree = dataplaceGP.importPlacesFileCriteriaLength(false, true);
    }
    dataplaceGP.displayPlaces(listPlacesFree);
    Place place = choosePlace(listPlacesFree);
    r.setNumeroPlace(place.getNumber());
    igp.interfacePlaceInfos(dataplaceGP.extractPlaceFromNumber(dataplaceGP.importPlacesFile(), r.getNumeroPlace()));

    //choix du client (clients déjà enregistrés ou nouveau client)
    igp.interfaceChoixClient();
    Client client = chooseClient();
    r.setIdClient(client.getId());
    igp.interfaceClientInfo(dataClientGP.extractClientFromID(dataClientGP.importClientsFile(), r.getIdClient()));

    //choix des suppléments (eau et/ou electricité)
    igp.interfaceChoixSupplements();
    if (checkIfClientCanHaveSupplements(r)) {
        igp.info("Vous avez accès à des suppléments", true);
        r.setSupplementElec(checkIfClientWantElecSupplement());
        r.setSupplementEau(checkIfClientWantWaterSupplement());
        igp.interfaceInfosSupplements(r);
    } else {
        igp.info("Vous n'avez pas accès à des suppléments", true);
        r.setSupplementElec(false);
        r.setSupplementEau(false);
    }

    //choix du type d'engagement (forfait annuel ou journalier)
    igp.interfaceChoixEngagement();
    r.setAbonnement(chooseIfClientWantAbonnement());
    igp.interfaceInfosEngagement(r);

    //ajout du paiement en fonction de la réservation (type de bateau, durée séjour, suppléments, quai ou non)
    r.setPaiement(getPaiement(r));

    //ajout de la date d'arrivée (aujourd'hui) et de la date de départ en fonction de la réservation
    r.setDateArrivee(dataDateGP.getDateToday());
    if(r.isAbonnement()){
        r.setDateDepart(getDateDepartAbonnement(r.getDateArrivee()));
    } else {
        r.setDateDepart(getDateDepartNonAbonnement(r));
    }

    //affichage des dates d'arrivée et de départ
    igp.displayDates(r);

    //affichage des prix
    igp.showPrices(r);

    //verifie si le client a payé
    Paiement ancienPaiement = r.getPaiement();
    r.setPaiement(askClientSiPaye(ancienPaiement));

    //enregistrement de la réservation
    dataReservationGP.saveReservations(dataReservationGP.addReservation(r));

    //affichage de la réservation
    igp.displayReservations(dataReservationGP.importReservationsFile());
}

/**
 * Action de création d'un bateau et de son enregistrement dans la réservation
 * @param r réservation où enregistrer le bateau
 */
Bateau GestionPort::createBoat() {
    Bateau boat; //création d'un bateau
    int size = 0; //initialisation de la taille du bateau
    bool error = true; //initialisation de la boucle d'erreur
    bool ifFirst = true; //initialisation du premier essai pour éviter de revenir ici

    string choice = igp.getCin("Taille du bateau ? (en mètres)",
                               false); //récupération de la taille du bateau donnée par le client


    //tant qu'aucune erreur n'a été trouvée on recommence à demander la taille du bateau
    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Taille du bateau ? (en mètres)",
                                false); //récupération de la taille du bateau donnée par le client
        }
        ifFirst = false;
        //si le mot rentré est celui pour retourner à l'accueil
        if (checkWantHome(choice)) {
            error = false; //on sort de la boucle d'erreur
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        } //sinon
        else {
            //si le format rentré est incompatible (contient lettres ou inférieur ou égal à 0)
            if (!checkIfIntegerPositif(choice)) {
                //on reste dans la boucle d'erreur
                igp.erreur("Valeur négative ou format incompatible", false); //affichage d'une erreur
                cin.clear();
                choice.empty();
            } //sinon le format est compatible
            else {
                error = false; //on sort de la boucle d'erreur
                istringstream(choice) >> size; //on convertir la CdC en integer
                boat.setTaille(size); //on enregistre la valeur dans le bateau
                if (size < 10) {
                    boat.setSiCabine(false);
                    boat.setTypeBateau(bateauType.voilierNonHabitableString);
                } else if (size >= 10 && size <= 25) {
                    boat.setSiCabine(true);
                    boat.setTypeBateau(bateauType.voilierType1String);
                } else {
                    boat.setSiCabine(true);
                    boat.setTypeBateau(bateauType.voilierType2String);
                }
                igp.typeBateauInfos(boat);
            }
        }
    }
    return boat;
}

/**
 * Fonction qui va vérifier si la donnée rentrée est un Integer > 0.
 * @param choice la chaine de caractères entrée dans le programme
 * @return vrai si le format est correct et faux sinon.
 */
bool GestionPort::checkIfIntegerPositif(string choice) {
    bool ifValid = false; //initialisation du booléen de validation comme format invalidé
    int compare; //declaration d'un integer
    istringstream(choice) >> compare; //conversion du string en integer
    //si l'integer est supérieur (format incompatible)
    if (compare > 0) {
        //format validé
        ifValid = true;
    }
    return ifValid;
}

/**
 * Fonction booléen qui va vérifier si la valeur rentrée dans le terminal est celle pour retourner à l'accueil
 * @param choice valeur rentrée dans le terminal
 * @return vrai si la valeur est celle pour revenir à l'accueil sinon faux
 */
bool GestionPort::checkWantHome(string choice) {
    if (choice == "q") {
        return true;
    }
    return false;
}

/**
 * Fonction qui va retourner la place correspondante au numéro donné
 * @return la place via son numéro
 */
Place GestionPort::choosePlace(vector<Place> listePlacesLibres) {
    Place place;
    string choice = igp.getCin("Numéro de place ?", false);
    bool error = true; //initialisation de la boucle d'erreur
    bool ifFirst = true; //initialisation du premier essai pour éviter de revenir ici

    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Numéro de place ?", false);
        }
        ifFirst = false;
        if (checkWantHome(choice)) {
            error = false; //on sort de la boucle d'erreur
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        } //sinon
        else {
            if (!checkIfIntegerPositif(choice)) {
                //on reste dans la boucle d'erreur
                igp.erreur("Valeur négative ou format incompatible", false); //affichage d'une erreur
                cin.clear();
                choice.empty();
            } //sinon le format est compatible
            else {
                int numberPlace;
                istringstream(choice) >> numberPlace;
                if (dataplaceGP.checkNumberPlace(listePlacesLibres, numberPlace)) {
                    error = false; //on sort de la boucle d'erreur
                    place = dataplaceGP.extractPlaceFromNumber(listePlacesLibres, numberPlace);
                } else {
                    igp.erreur("Numéro de place non valide", false);
                    cin.clear();
                    choice.empty();
                }
            }
        }
    }
    return place;
}

/**
 * Fonction qui va retourner le client en fonction de l'ID donné
 * @return le client par rapport à son numéro (ID)
 */
Client GestionPort::chooseClient() {
    Client c;
    vector<Client> listClients = dataClientGP.importClientsFile();
    igp.interfaceListeClients();
    dataClientGP.displayClients(listClients);
    string choice = igp.getCin("[n pour nouveau] Numéro du client ?", false);
    bool error = true; //initialisation de la boucle d'erreur
    bool ifFirst = true; //initialisation du premier essai pour éviter de revenir ici

    //tant qu'une erreur est detectee on reste dans la boucle
    while (error) {

        //si ce n'est pas le premier numéro de client rentré
        if (!ifFirst) {
            choice = igp.getCin("[n pour nouveau] Numéro du client ?", false);
        }
        ifFirst = false; //on indique que le premier essai a été utilisé

        //si la valeur rentrée est celle pour rentrer à l'accueil
        if (checkWantHome(choice)) {
            error = false; //on sort de la boucle d'erreur
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        } //sinon
        else {
            //si la valeur rentrée est celle pour créer un nouveau client
            if (checkWantNewClient(choice)) {
                igp.info("Création de client non disponible", false);
                createNewClient();
                dataClientGP.displayClients(dataClientGP.importClientsFile());
            } //sinon
            else {
                //si la valeur rentrée n'est pas compatible (doit être un Integer positif et non nul)
                if (!checkIfIntegerPositif(choice)) {
                    //on reste dans la boucle d'erreur
                    igp.erreur("Valeur négative ou format incompatible", false); //affichage d'une erreur
                    cin.clear();
                    choice.empty();
                } //sinon le format est compatible
                else {
                    int IDchoose;
                    istringstream(choice) >> IDchoose; //on convertir le string en Integer
                    //si l'ID client rentré dans le programme existe bien
                    if (dataClientGP.checkIDClient(listClients, IDchoose)) {
                        error = false; //on sort de la boucle d'erreur
                        c = dataClientGP.extractClientFromID(listClients, IDchoose);
                    } //sinon l'ID client n'existe pas
                    else {
                        igp.erreur("Cet ID client n'existe pas", false); //affichage d'une erreur
                        cin.clear();
                        choice.empty();
                    }
                }
            }
        }
    }
    return c;
}

/**
 * Fonction booléen qui va vérifier si la valeur rentrée dans le terminal est celle pour créer un nouveau client
 * @param choice valeur rentrée dans le terminal
 * @return vrai si la valeur est celle pour créer un nouveau client sinon faux
 */
bool GestionPort::checkWantNewClient(string choice) {
    if (choice == "n") {
        return true;
    }
    return false;
}

void GestionPort::createNewClient() {
    Client c;
    igp.interfaceNewClient();
    c.setNom(clientNouveauNom().c_str());
    c.setPrenom(clientNouveauPrenom().c_str());
    c.setEmail(clientNouveauEmail().c_str());
    c.setNumeroAdresse(clientNouveauNumeroAdresse());
    c.setAdresse(clientNouvelleAdresse().c_str());
    c.setCp(clientNouveauCP().c_str());
    c.setVille(clientNouvelleVille().c_str());
    vector<Client> vC = dataClientGP.addNewClient(c);
    dataClientGP.createNewClientFile(vC);
    igp.interfaceNewClientAdded();

}

string GestionPort::clientNouveauNom() {
    string choice = igp.getCinLine("Nom ?", false);
    if (checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

string GestionPort::clientNouveauPrenom() {
    string choice = igp.getCin("Prénom ?", false);
    if (checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

string GestionPort::clientNouveauEmail() {
    string choice = igp.getCin("Email ?", false);
    if (checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

int GestionPort::clientNouveauNumeroAdresse() {
    string choice = igp.getCin("Numéro d'adresse ?", false);
    bool error = true;
    bool ifFirst = true;
    int numAdresse;

    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Numéro d'adresse ?", false);
        }
        ifFirst = false;
        if (checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if (!checkIfIntegerPositif(choice)) {
            //on reste dans la boucle d'erreur
            igp.erreur("Valeur négative ou format incompatible", false); //affichage d'une erreur
            cin.clear();
            choice.empty();
        } //sinon le format est compatible
        else {
            error = false;
            istringstream(choice) >> numAdresse;
        }
    }
    return numAdresse;
}

string GestionPort::clientNouvelleAdresse() {
    string choice = igp.getCinLine("Adresse ?", false);
    if (checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

/**
char* GestionPort::convertStringToChar(string cara){
    char choice[cara.length()];
    for (int i = 0; i< sizeof(choice);i++){
        choice[i] = cara[i];
    }
    return choice;
}
 **/

string GestionPort::clientNouveauCP() {
    string choice = igp.getCin("Code postal ?", false);
    if (checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

string GestionPort::clientNouvelleVille() {
    string choice = igp.getCin("Ville ?", false);
    if (checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

/**
 * Fonction qui va vérifier si avec le type de place (quai ou hors-quai) et le type de bateau, le client peut avoir des suppléments
 * @param r Réservation du client
 * @return vrai si le client peu avoir des suppléments, faux sinon.
 */
bool GestionPort::checkIfClientCanHaveSupplements(Reservation r) {
    bool ifCan = false;
    if(dataplaceGP.extractPlaceFromNumber(dataplaceGP.importPlacesFile(), r.getNumeroPlace()).isDock()) {
        if (r.getBateau().getTypeBateau() == "Voilier de type 1"
            || r.getBateau().getTypeBateau() == "Voilier de type 2") {
            ifCan = true;
        }
    }
    return ifCan;
}

/**
 * Fonction qui va retourner la réponse du client sur son choix du supplément éléctricité
 * @return vrai si le client veut le supplément éléctricité, faux sinon
 */
bool GestionPort::checkIfClientWantElecSupplement() {
    string choice = igp.getCin("Supplément éléctricité ? [oui/non]", false);
    bool error = true;
    bool ifFirst = true;
    bool ifWant = false;

    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Supplément éléctricité ? [oui/non]", false);
        }
        ifFirst = false;
        if (checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if (!checkAskClientResponseYesNo(choice)) {
            //on reste dans la boucle d'erreur
            igp.erreur("Format incompatible", false); //affichage d'une erreur
            cin.clear();
            choice.empty();
        } //sinon le format est compatible
        else {
            error = false;
            ifWant = returnSupplementReponse(choice);
        }
    }
    return ifWant;
}

/**
 * Fonction qui va retourner la réponse du client sur son choix du supplément eau
 * @return vrai si le client veut le supplément eau, faux sinon
 */
bool GestionPort::checkIfClientWantWaterSupplement() {
    string choice = igp.getCin("Supplément eau ? [oui/non]", false);
    bool error = true;
    bool ifFirst = true;
    bool ifWant = false;

    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Supplément eau ? [oui/non]", false);
        }
        ifFirst = false;
        if (checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if (!checkAskClientResponseYesNo(choice)) {
            //on reste dans la boucle d'erreur
            igp.erreur("Format incompatible", false); //affichage d'une erreur
            cin.clear();
            choice.empty();
        } //sinon le format est compatible
        else {
            error = false;
            ifWant = returnSupplementReponse(choice);
        }
    }
    return ifWant;
}

/**
 * Fonction qui va vérifier que la réponse rentrée par le client est compatible par rapport à son choix de supplément
 * @param choice réponse du client
 * @return vrai si la réponse est soit "oui" ou "non", faux sinon
 */
bool GestionPort::checkAskClientResponseYesNo(string choice) {
    bool ifOK = false;
    if (choice == "oui" || choice == "non") {
        ifOK = true;
    }
    return ifOK;
}

/**
 * Fonction qui va convertir la réponse à un choix de supplément en booléen
 * @param choice réponse du client
 * @return vrai si la réponse est oui, faux sinon
 */
bool GestionPort::returnSupplementReponse(string choice) {
    bool reponse = false;
    if (choice == "oui") {
        reponse = true;
    }
    return reponse;
}

/**
 * Fonction qui va retourner la réponse du client sur son choix de prendre un abonnement pour sa réservation ou non
 * @return vrai s'il veut un abonnement, faux sinon
 */
bool GestionPort::chooseIfClientWantAbonnement() {
    string choice = igp.getCin("Abonnement d'1 an ? [oui/non]", false);
    bool error = true;
    bool ifFirst = true;
    bool ifWant = false;

    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Abonnement d'1 an ? [oui/non]", false);
        }
        ifFirst = false;
        if (checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if (!checkAskClientResponseYesNo(choice)) {
            //on reste dans la boucle d'erreur
            igp.erreur("Format incompatible", false); //affichage d'une erreur
            cin.clear();
            choice.empty();
        } //sinon le format est compatible
        else {
            error = false;
            ifWant = returnSupplementReponse(choice);
        }
    }
    return ifWant;
}


Paiement GestionPort::getPaiement(Reservation r) {
    Paiement p;
    Tarifs t;

    //si c'est un abonnement
    if (r.isAbonnement()) {
        int nbJours = 365;
        p.setNbJours(nbJours);

        int paiementAnnuelSansSupplements = getPaiementAnnuel(r);
        int paiementAnnuel = paiementAnnuelSansSupplements + (getPaiementJournalierSupplements(r) * 365);
        p.setPaiementAnnuel(paiementAnnuel);
        p.setTotal(paiementAnnuel);

        int paiementMensuelPremierMoisSansSupplements = getPaiementMensuel(r,t.typePaiement.paiementMensuelPremierMois);
        int paiementMensuel11MoisSansSupplements = getPaiementMensuel(r,t.typePaiement.paiementMensuel11Mois);
        int paiementMensuelPremierMoisDesSupplements = getPaiementMensuelSupplement(r,true);
        int paiementMensuel11MoisDesSupplements = getPaiementMensuelSupplement(r, false);
        int paiementMensuelPremierMois = paiementMensuelPremierMoisSansSupplements+paiementMensuelPremierMoisDesSupplements;
        int paiementMensuel11Mois = paiementMensuel11MoisSansSupplements+paiementMensuel11MoisDesSupplements;
        p.setPaiementMensuelPremierMois(paiementMensuelPremierMois);
        p.setPaiementMensuel11Mois(paiementMensuel11Mois);

    } else {
        int nbJours = askClientNombreJours();
        p.setNbJours(nbJours);
        igp.interfaceInfosNbJours(p);

        int paiementJournalier = getPaiementJournalier(r) + getPaiementJournalierSupplements(r);
        p.setPaiementJournalier(paiementJournalier);
        int total = nbJours * paiementJournalier;
        p.setTotal(total);
    }
    return p;
}

int GestionPort::getPaiementMensuelSupplement(Reservation r, bool isPremierMois){
    Tarifs t;
    int paiement = 0;
    if(r.isSupplementElec() && r.isSupplementEau()){
        if(isPremierMois){
            paiement = t.supplement.deuxSupplements.supplementsPremierMois;
        } else {
            paiement = t.supplement.deuxSupplements.supplements11Mois;
        }
    } else if((!r.isSupplementEau() && r.isSupplementElec()) || (r.isSupplementEau() && !r.isSupplementElec())){
        if(isPremierMois){
            paiement = t.supplement.unSupplement.supplementPremierMois;
        } else {
            paiement = t.supplement.unSupplement.supplement11Mois;
        }
    }
    return paiement;
}

/**
int GestionPort::getPaiementSupplementParMois(Reservation r, int paiementJournalierSupplements){
    int nombreJours;
    switch (r.getDateArrivee().getMonth()){
        case 1,3,5,7,8,10,12:
            nombreJours = 31;
            break:
        case 4,6,9,11:
            nombreJours = 30;
            break:
        case 2:
            if(ifYearBissextile(r.getDateArrivee())){
                nombreJours = 29;
            } else {
                nombreJours = 28;
            }
            break;
    }
    return nombreJours;
}
 **/

/**
 * Fonction qui va demander au client non abonné combien de jours il veut rester
 * @return le nombre de jours restants
 */
int GestionPort::askClientNombreJours() {
    string choice = igp.getCin("Combien de jours de réservation ?", false);
    bool error = true;
    bool ifFirst = true;
    int nombreJours;

    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Combien de jours de réservation ?", false);
        }
        ifFirst = false;
        if (checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if (!checkIfIntegerPositif(choice)) {
            //on reste dans la boucle d'erreur
            igp.erreur("Valeur négative ou format incompatible", false); //affichage d'une erreur
            cin.clear();
            choice.empty();
        } //sinon le format est compatible
        else {
            error = false;
            istringstream(choice) >> nombreJours;
        }
    }
    return nombreJours;
}

/**
 * Fonction qui va retourner le paiement journalier du client non-abonné en fonction de sa réservation
 * @param r la réservation du client non-abonné
 * @return son paiement journalier
 */
int GestionPort::getPaiementJournalier(Reservation r) {
    int paiementJournalier = 0;
    Tarifs t;
    //si le client est à quai
    if (dataplaceGP.extractPlaceFromNumber(dataplaceGP.importPlacesFile(), r.getNumeroPlace()).isDock()) {
        //si le bateau est un voilier non habitable
        if (r.getBateau().getTypeBateau() == voilierNH) {
            paiementJournalier = t.nonAbonne.quai.voilierNonHabitable.paiementJournalier;
        } //si le bateau est un voilier de type 1
        else if (r.getBateau().getTypeBateau() == voilierT1) {
            paiementJournalier = t.nonAbonne.quai.voilierType1.paiementJournalier;
        } //sinon le bateau est un voilier de type 2
        else {
            paiementJournalier = t.nonAbonne.quai.voilierType2.paiementJournalier;
        }
    } //sinon il est hors-quai
    else {
        //si le bateau est un voilier non habitable
        if (r.getBateau().getTypeBateau() == voilierNH) {
            paiementJournalier = t.nonAbonne.nonQuai.voilierNonHabitable.paiementJournalier;
        } //si le bateau est un voilier de type 1
        else if (r.getBateau().getTypeBateau() == voilierT1) {
            paiementJournalier = t.nonAbonne.nonQuai.voilierType1.paiementJournalier;
        } //sinon le bateau est un voilier de type 2
        else {
            paiementJournalier = t.nonAbonne.nonQuai.voilierType2.paiementJournalier;
        }
    }
    return paiementJournalier;
}

/**
* Fonction qui va retourner le paiement journalier du client non-abonné en fonction de sa réservation
* @param r la réservation du client non-abonné
* @return son paiement journalier
*/
int GestionPort::getPaiementMensuel(Reservation r, string typePaiement) {
    int paiement = 0;
    Tarifs t;
    //si le client est à quai
    if (dataplaceGP.extractPlaceFromNumber(dataplaceGP.importPlacesFile(), r.getNumeroPlace()).isDock()) {
        //si le bateau est un voilier non habitable
        if (r.getBateau().getTypeBateau() == voilierNH) {
            if(typePaiement == t.typePaiement.paiementMensuelPremierMois){
                paiement = t.abonne.quai.voilierNonHabitable.paiementMensuelPremierMois;
            } else {
                paiement = t.abonne.quai.voilierNonHabitable.paiementMensuel11Mois;
            }
        } //si le bateau est un voilier de type 1
        else if (r.getBateau().getTypeBateau() == voilierT1) {
            if(typePaiement == t.typePaiement.paiementMensuelPremierMois){
                paiement = t.abonne.quai.voilierType1.paiementMensuelPremierMois;
            } else {
                paiement = t.abonne.quai.voilierType1.paiementMensuel11Mois;
            }
        } //sinon le bateau est un voilier de type 2
        else {
            if(typePaiement == t.typePaiement.paiementMensuelPremierMois){
                paiement = t.abonne.quai.voilierType2.paiementMensuelPremierMois;
            } else {
                paiement = t.abonne.quai.voilierType2.paiementMensuel11Mois;
            }
        }
    } //sinon il est hors-quai
    else {
        //si le bateau est un voilier non habitable
        if (r.getBateau().getTypeBateau() == voilierNH) {
            if(typePaiement == t.typePaiement.paiementMensuelPremierMois){
                paiement = t.abonne.nonQuai.voilierNonHabitable.paiementMensuelPremierMois;
            } else {
                paiement = t.abonne.nonQuai.voilierNonHabitable.paiementMensuel11Mois;
            }
        } //si le bateau est un voilier de type 1
        else if (r.getBateau().getTypeBateau() == voilierT1) {
            if(typePaiement == t.typePaiement.paiementMensuelPremierMois){
                paiement = t.abonne.nonQuai.voilierType1.paiementMensuelPremierMois;
            } else {
                paiement = t.abonne.nonQuai.voilierType1.paiementMensuel11Mois;
            }
        } //sinon le bateau est un voilier de type 2
        else {
            if(typePaiement == t.typePaiement.paiementMensuelPremierMois){
                paiement = t.abonne.nonQuai.voilierType2.paiementMensuelPremierMois;
            } else {
                paiement = t.abonne.nonQuai.voilierType2.paiementMensuel11Mois;
            }
        }
    }
    return paiement;
}

/**
 * Fonction qui va retourner le paiement annuel du client abonné en fonction de sa réservation
 * @param r la réservation du client abonné
 * @return son paiement annuel
 */
int GestionPort::getPaiementAnnuel(Reservation r) {
    int paiementAnnuel = 0;
    Tarifs t;
    //si le client est à quai
    if (dataplaceGP.extractPlaceFromNumber(dataplaceGP.importPlacesFile(), r.getNumeroPlace()).isDock()) {
        //si le bateau est un voilier non habitable
        if (r.getBateau().getTypeBateau() == voilierNH) {
            paiementAnnuel = t.abonne.quai.voilierNonHabitable.paiementAnnuel;
        } //si le bateau est un voilier de type 1
        else if (r.getBateau().getTypeBateau() == voilierT1) {
            paiementAnnuel = t.abonne.quai.voilierType1.paiementAnnuel;
        } //sinon le bateau est un voilier de type 2
        else {
            paiementAnnuel = t.abonne.quai.voilierType2.paiementAnnuel;
        }
    } //sinon il est hors-quai
    else {
        //si le bateau est un voilier non habitable
        if (r.getBateau().getTypeBateau() == voilierNH) {
            paiementAnnuel = t.abonne.nonQuai.voilierNonHabitable.paiementAnnuel;
        } //si le bateau est un voilier de type 1
        else if (r.getBateau().getTypeBateau() == voilierT1) {
            paiementAnnuel = t.abonne.nonQuai.voilierType1.paiementAnnuel;
        } //sinon le bateau est un voilier de type 2
        else {
            paiementAnnuel = t.abonne.nonQuai.voilierType2.paiementAnnuel;
        }
    }
    return paiementAnnuel;
}

/**
 * Fonction qui va donner le paiement journalier des suppléments en fonction de la réservation
 * @param r la réservation
 * @return le paiement journalier des suppléments
 */
int GestionPort::getPaiementJournalierSupplements(Reservation r) {
    int paiementSupplements = 0;
    Tarifs t;
    //si un des deux suppléments a été choisi
    if ((r.isSupplementElec() && !r.isSupplementEau()) || (!r.isSupplementElec() && r.isSupplementEau())) {
        paiementSupplements = t.supplementJournalier;
    } else if (r.isSupplementElec() && r.isSupplementEau()) {
        paiementSupplements = t.supplementJournalier * 2;
    }
    return paiementSupplements;
}

/**
 * Fonction qui va retourner la date de départ d'un abonné (1 an plus tard)
 * @param d la date d'arrivée
 * @return la date de départ
 */
Date GestionPort::getDateDepartAbonnement(Date d){
    int newYear = d.getYear()+1;
    d.setYear(newYear);
    return d;
}

/**
 * Fonction qui va retourner la date de départ d'un non-abonné
 * @param r la réservation
 * @return la date de départ
 */
Date GestionPort::getDateDepartNonAbonnement(Reservation r){
    vector<int> nbJoursMois = createNbJoursMonth(ifYearBissextile(r.getDateArrivee()));
    return convertJoursInYearsMonthDays(r.getDateArrivee(),r.getPaiement().getNbJours(),nbJoursMois);
}

/**
 * Fonction qui va retourner la bissexetilité d'une année ou non
 * @param d la Date contenant l'année
 * @return vrai si l'année est bissextile, faux sinon
 */
bool GestionPort::ifYearBissextile(Date d){
    int year = d.getYear();
    bool ifBissextile = false;
    if((year%4 == 0 && year%100 != 0) || year%400 == 0){
        ifBissextile = true;
    }
    return ifBissextile;
}

vector<int> GestionPort::createNbJoursMonth(bool isBissextile){
    vector<int> v;
    if(isBissextile){
        v = {31,29,31,30,31,30,31,31,30,31,30,31};
    } else {
        v = {31,28,31,30,31,30,31,31,30,31,30,31};
    }
    return v;
}

/**
 * Fonction qui va retourner la date de départ en fonction de la date d'arrivée, du nombre de jours de réservation et
 * du nombre de jours de chaque mois
 * @param d Date d'arrivée
 * @param nbJours nombre de jours de réservation
 * @param nbJoursParMois nombre de jours par mois
 * @return la date de départ
 */
Date GestionPort::convertJoursInYearsMonthDays(Date d, int nbJours, vector<int> nbJoursParMois){

    Date dateDepart;
    int nbJoursRestants = nbJours;
    int anneeDepart = d.getYear();
    int moisDepart = d.getMonth();
    int jourDepart = d.getDay();

    while(nbJoursRestants > 0){
        //si le nombre de jours de réservation restants ne dépasse pas le mois actuel
        if(jourDepart+nbJoursRestants <= nbJoursParMois[moisDepart-1]){
            jourDepart = jourDepart+nbJoursRestants-1;
            nbJoursRestants = 0;
        } //sinon on doit avancer d'un mois
        else {
            //si c'est le mois de décembre
            if(d.getMonth() == 12){
                nbJoursRestants = nbJoursRestants-(nbJoursParMois[moisDepart-1]-jourDepart)-1; //on enleve aux jours restants la différence entre la date d'arrivée et la fin du mois
                anneeDepart = anneeDepart+1;
                moisDepart = 1;
            } //sinon c'est un autre mois
            else {
                nbJoursRestants = nbJoursRestants-(nbJoursParMois[moisDepart-1]-jourDepart)-1; //on enleve aux jours restants la différence entre la date d'arrivée et la fin du mois
                moisDepart = moisDepart+1;
            }
            jourDepart = 1;
        }
    }

    dateDepart.setYear(anneeDepart);
    dateDepart.setMonth(moisDepart);
    dateDepart.setDay(jourDepart);

    return dateDepart;
}

Paiement GestionPort::askClientSiPaye(Paiement p){
    string choice = igp.getCin("Le client a-t-il payé ? [oui/non]", false);
    bool error = true;
    bool ifFirst = true;
    bool aPaye = false;

    while (error) {
        if (!ifFirst) {
            choice = igp.getCin("Le client a-t-il payé ? [oui/non]", false);
        }
        ifFirst = false;
        if (checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil", true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if (!checkAskClientResponseYesNo(choice)) {
            //on reste dans la boucle d'erreur
            igp.erreur("Format incompatible", false); //affichage d'une erreur
            cin.clear();
            choice.empty();
        } //sinon le format est compatible
        else {
            error = false;
            aPaye = returnSupplementReponse(choice);
        }
    }

    p.setAPaye(aPaye);
    return p;
}



