//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "GestionPort.h"
#include <iostream>
#include "../Bateau/Bateau.h"
#include "../Reservation/Reservation.h"
#include "../Interface/Interface.h"
#include "../Data//Data.h"

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
            if (!checkBoatLength(choice)) {
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
 * Fonction qui va vérifier la taille du bateau entrée dans le programme (ne doit pas contenir de lettres et doit être
 * supérieur à 0.
 * @param choice la chaine de caractères entrée dans le programme
 * @return vrai si la taille est correcte et faux sinon.
 */
bool GestionPort::checkBoatLength(string choice) {
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

Place GestionPort::choosePlace() {
    Place place;
    string choice = igp.getCin("Numéro de place ?",false);
    bool error = true; //initialisation de la boucle d'erreur
    bool ifFirst = true; //initialisation du premier essai pour éviter de revenir ici

    while(error){
        if(!ifFirst) {
            choice = igp.getCin("Numéro de place ?",false);
            //cout << choice << endl;
        }
        ifFirst = false;
        if (!checkBoatLength(choice)) {
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
    return place;
}


