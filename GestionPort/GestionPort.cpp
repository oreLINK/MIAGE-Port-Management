//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "GestionPort.h"
#include <iostream>
#include "../Bateau/Bateau.h"
#include "../Reservation/Reservation.h"
#include "../Interface/Interface.h"

#include <sstream>
#include <cctype>

Interface igp;

GestionPort::GestionPort() {}

void GestionPort::createReservation() {
    Reservation r;
    cout << "~~~ NOUVELLE RESERVATION ~~~" << endl;
    cout << " " << endl;
    createBoat(r); //details Bateau
    //liste places dispo en fonction Bateau
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
void GestionPort::createBoat(Reservation r) {
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
                cout << "Bateau catégorisé comme " << boat.getTypeBateau() << endl;
                cout << " " << endl;
                r.setBateau(boat);
            }
        }
    }

    /**
    //si la réponse est de retourner au menu d'accueil
    if (checkWantHome(choice)) {
        error = false; //il n'y a pas d'erreurs de format
        igp.info("Vous avez choisi de revenir à l'accueil",true); //affichage d'une information
        igp.home(); //affichage de l'interface d'accueil
    } //sinon
    else {
        while (error) {
            if(!firstTime) {
                //récupération de la taille du bateau donnée par le client
                choice = igp.getCin("Taille du bateau ? (en mètres)");
            } else {
                firstTime = false;
                //si le format n'est pas compatible
                if (!checkBoatLength(choice)) {
                    igp.erreur("Valeur négative ou format incompatible", false);
                } else {
                    //on convertit le string en int
                    size = stoi(choice);
                    //il n'y a pas d'erreurs de format
                    error = false;
                }
            }
        }
        boat.setTaille(size);
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
        cout << "Bateau catégorisé comme " << boat.getTypeBateau() << endl;
        cout << " " << endl;
        r.setBateau(boat);
    }
    **/
}

/**
 * Fonction.
 * Lors de la création d'un bateau, demande la taille en mètres de celui-ci au client.
 * Ne prend pas en compte les valeurs négatives ou égales à 0.
 *
 * /!\ VOIR POUR CHECK LE CIN ET N'ACCEPTER QUE LES NOMBRES /!\
 *
 * @return la taille du bateau
 */
int GestionPort::createBoatAskSize() {
    int size;
    string choice = igp.getCin("Taille du bateau ? (en mètres)",false);
    if (choice == "q") {

    }
    /**
    while(size <= 0) {
            cin.clear();
            cout << "Erreur. Valeur négative, trop grande ou format incompatible." << endl;
            cout << "Taille du bateau ? (en mètres) ", cin >> size;
    }
     **/
    return size;
}

int GestionPort::createBoatCheckChoice(string choice) {
    int size = stoi(choice);
    while (size <= 0) {
        cin.clear();
        igp.erreur("Valeur négative ou format incompatible", false);
        size = stoi(igp.getCin("Taille du bateau ? (en mètres)",false));
        /**
        cout << "Erreur. Valeur négative, trop grande ou format incompatible." << endl;
        cout << "Taille du bateau ? (en mètres) ", cin >> size;
         **/
    }

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

bool GestionPort::checkWantHome(string choice) {
    if (choice == "q") {
        return true;
    }
    return false;
}
