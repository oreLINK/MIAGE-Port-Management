//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "include/GestionPort.h"
#include <iostream>
#include "include/Bateau.h"
#include "include/Reservation.h"
#include "include/Interface.h"
#include "include/Data.h"
#include "include/Tarifs.h"

#include <sstream>
#include <cctype>
#include <vector>

Interface igp;
Data datagp;

vector<Place> listPlacesFree;

GestionPort::GestionPort() {}

/**
 * Action pour créer une nouvelle réservation.
 */
void GestionPort::createReservation() {

    Tarifs t;
    cout << endl;

    igp.interfaceNewReservation();
    Reservation r;

    igp.interfaceNewBoat();
    Bateau boat = createBoat(); //details Bateau
    r.setBateau(boat);

    igp.interfaceNewPlace();
    if(r.getBateau().getTypeBateau() == "Voilier de type 2"){
        listPlacesFree = datagp.importPlacesFileCriteriaLength(true,true);
    } else {
        listPlacesFree = datagp.importPlacesFileCriteriaLength(false,true);
    }
    datagp.displayPlaces(listPlacesFree);
    Place place = choosePlace();
    r.setPlace(place);
    igp.interfacePlaceInfos(r.getPlace());

    igp.interfaceChoixClient();
    Client client = chooseClient();
    r.setClient(client);
    igp.interfaceClientInfo(r.getClient());

    igp.interfaceChoixSupplements();
    if(checkIfClientCanHaveSupplements(r)){
        igp.info("Vous avez accès à des suppléments",true);
        r.setSupplementElec(checkIfClientWantElecSupplement());
        r.setSupplementEau(checkIfClientWantWaterSupplement());
    } else {
        igp.info("Vous n'avez pas accès à des suppléments",true);
    }

    igp.interfaceChoixEngagement();
    r.setAbonnement(chooseIfClientWantAbonnement());

    //datagp.createFirstPlacesFile(); //liste places dispo en fonction Bateau
    //choix place
    //creation usager (abonne ou passager aussi)
    //si supplements
    //affichage tarifs
    //paiement (tout si passager ou cotisation pour abonne)
    //edition facture pour abonne
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

    string choice = igp.getCin("Taille du bateau ? (en mètres)",false); //récupération de la taille du bateau donnée par le client


    //tant qu'aucune erreur n'a été trouvée on recommence à demander la taille du bateau
    while(error) {
        if(!ifFirst) {
            choice = igp.getCin("Taille du bateau ? (en mètres)",false); //récupération de la taille du bateau donnée par le client
            //cout << choice << endl;
        }
        ifFirst = false;
        //si le mot rentré est celui pour retourner à l'accueil
        if(checkWantHome(choice)) {
                error = false; //on sort de la boucle d'erreur
                igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
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
                    boat.setTypeBateau("Voilier non habitable");
                } else if (size >= 10 && size <= 25) {
                    boat.setSiCabine(true);
                    boat.setTypeBateau("Voilier de type 1");
                } else {
                    boat.setSiCabine(true);
                    boat.setTypeBateau("Voilier de type 2");
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
    if(compare > 0) {
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
Place GestionPort::choosePlace() {
    Place place;
    string choice = igp.getCin("Numéro de place ?",false);
    bool error = true; //initialisation de la boucle d'erreur
    bool ifFirst = true; //initialisation du premier essai pour éviter de revenir ici

    while(error){
        if(!ifFirst) {
            choice = igp.getCin("Numéro de place ?",false);
        }
        ifFirst = false;
        if(checkWantHome(choice)) {
            error = false; //on sort de la boucle d'erreur
            igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
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
                if(datagp.checkNumberPlace(listPlacesFree, numberPlace)){
                    error = false; //on sort de la boucle d'erreur
                    place = datagp.extractPlaceFromNumber(listPlacesFree,numberPlace);
                } else {
                    igp.erreur("Numéro de place non valide",false);
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
    vector<Client> listClients = datagp.importClientsFile();
    igp.interfaceListeClients();
    datagp.displayClients(listClients);
    string choice = igp.getCin("[n pour nouveau] Numéro du client ?",false);
    bool error = true; //initialisation de la boucle d'erreur
    bool ifFirst = true; //initialisation du premier essai pour éviter de revenir ici

    //tant qu'une erreur est detectee on reste dans la boucle
    while(error){

        //si ce n'est pas le premier numéro de client rentré
        if(!ifFirst) {
            choice = igp.getCin("[n pour nouveau] Numéro du client ?",false);
        }
        ifFirst = false; //on indique que le premier essai a été utilisé

        //si la valeur rentrée est celle pour rentrer à l'accueil
        if(checkWantHome(choice)) {
            error = false; //on sort de la boucle d'erreur
            igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        } //sinon
        else {
            //si la valeur rentrée est celle pour créer un nouveau client
            if(checkWantNewClient(choice)) {
                igp.info("Création de client non disponible",false);
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
                    if(datagp.checkIDClient(listClients,IDchoose)){
                        error = false; //on sort de la boucle d'erreur
                        c = datagp.extractClientFromID(listClients,IDchoose);
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
    /**
    Client c;
    igp.interfaceNewClient();
    c.setNom(clientNouveauNom().c_str());
    c.setPrenom(clientNouveauPrenom().c_str());
    c.setEmail(clientNouveauEmail().c_str());
    c.setNumeroAdresse(clientNouveauNumeroAdresse());
    c.setAdresse(clientNouvelleAdresse().c_str());
    c.setCp(clientNouveauCP().c_str());
    c.setVille(clientNouvelleVille().c_str());
    vector<Client> listClients = datagp.importClientsFile();
    datagp.displayClients(listClients);
    listClients = datagp.addNewClient(listClients,c);
    datagp.displayClients(listClients);
    datagp.createNewClientFile(listClients);
     **/
}

string GestionPort::clientNouveauNom() {
    string choice = igp.getCin("Nom ?", false);
    if(checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

string GestionPort::clientNouveauPrenom() {
    string choice = igp.getCin("Prénom ?", false);
    if(checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

string GestionPort::clientNouveauEmail() {
    string choice = igp.getCin("Email ?", false);
    if(checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

int GestionPort::clientNouveauNumeroAdresse() {
    string choice = igp.getCin("Numéro d'adresse ?", false);
    bool error = true;
    bool ifFirst = true;
    int numAdresse;

    while(error){
        if(!ifFirst) {
            choice = igp.getCin("Numéro d'adresse ?",false);
        }
        ifFirst = false;
        if(checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if(!checkIfIntegerPositif(choice)) {
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
    string choice = igp.getCinLine("Adresse ?",false);
    if(checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

string GestionPort::clientNouveauCP() {
    string choice = igp.getCin("Code postal ?", false);
    if(checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    }
    return choice;
}

string GestionPort::clientNouvelleVille() {
    string choice = igp.getCin("Ville ?", false);
    if(checkWantHome(choice)) {
        igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
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
    if(r.getPlace().isDock()){
        if(r.getBateau().getTypeBateau() == "Voilier de type 1"
        || r.getBateau().getTypeBateau() == "Voilier de type 2"){
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

    while(error){
        if(!ifFirst) {
            choice = igp.getCin("Supplément éléctricité ? [oui/non]", false);
        }
        ifFirst = false;
        if(checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if(!checkSupplementsReponse(choice)) {
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

    while(error){
        if(!ifFirst) {
            choice = igp.getCin("Supplément eau ? [oui/non]", false);
        }
        ifFirst = false;
        if(checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if(!checkSupplementsReponse(choice)) {
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
bool GestionPort::checkSupplementsReponse(string choice) {
    bool ifOK = false;
    if(choice == "oui" || choice == "non"){
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
    if(choice == "oui"){
        reponse = true;
    }
    return reponse;
}

/**
 * Fonction qui va retourner la réponse du client sur son choix de prendre un abonnement pour sa réservation ou non
 * @return vrai s'il veut un abonnement, faux sinon
 */
bool GestionPort::chooseIfClientWantAbonnement() {
    string choice = igp.getCin("Abonnement ? [oui/non]", false);
    bool error = true;
    bool ifFirst = true;
    bool ifWant = false;

    while(error){
        if(!ifFirst) {
            choice = igp.getCin("Abonnement ? [oui/non]", false);
        }
        ifFirst = false;
        if(checkWantHome(choice)) {
            error = false;
            igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
            igp.home(); //affichage de l'interface d'accueil
        }
        if(!checkSupplementsReponse(choice)) {
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