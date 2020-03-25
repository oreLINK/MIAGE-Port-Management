//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "Interface.h"
#include "../GestionPort/GestionPort.h"
#include <iostream>

using namespace std;

GestionPort gp;

/**
 * HOME PAGE
 */

/**
 * Action.
 * Affichage de la page d'accueil de l'application.
 */
void Interface::home() {
    interfaceHome();
    string choice = interfaceHomeResponse();
    homeResponseCheck(choice);
}

void Interface::homeResponseCheck(string homeResponse) {
    if(homeResponse == "0") {
        exit(1);
    } else if(homeResponse == "1") {
        cout << "lala" << endl;
    } else if(homeResponse == "2") {
        gp.createReservation();
    } else {
        erreur("Choix incorrect",true);
        home();
    }
}

void Interface::interfaceHome() {
    cout << "~~~ GESTION PORT DE LA ROCHELLE ~~~" << endl;
    cout << " " << endl;
    cout << "1 : Statistiques du port" << endl;
    cout << "2 : Nouvelle réservation" << endl;
    cout << " " << endl;
    cout << "0 : Quitter (sauv. auto)" << endl;
    cout << " " << endl;
}

string Interface::interfaceHomeResponse() {
    return getCin("Choix ?",true);
}

/**
 * CIN
 */

string Interface::getCin(string message, bool ifEspace) {
    string choice;
    cout << "[q pour accueil] " << message << " ", cin >> choice;
    if(ifEspace) {
        cout << " " << endl;
    }
    return choice;
}

bool Interface::ifWantGoHome(string cin) {
    if(cin == "q") {
        return true;
    } else {
        return false;
    }
}

/**
 * ERRORS
 */

void Interface::erreur(string message, bool avecEspace) {
    cout << "Erreur. " << message << "." << endl;
    if(avecEspace) {
        cout << " " << endl;
    }
}

/**
 * INFORMATIONS
 */

void Interface::info(string message, bool avecEspace) {
    cout << "Info. " << message << "." << endl;
    if(avecEspace) {
        cout << " " << endl;
    }
}

/**
 * BOAT CREATION
 */


