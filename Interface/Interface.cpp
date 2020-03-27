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
 * RESERVATION
 */

void Interface::interfaceNewReservation(){
    cout << "~~~ NOUVELLE RESERVATION ~~~" << endl;
    cout << " " << endl;
}

/**
 * BOAT CREATION
 */

void Interface::interfaceNewBoat(){
    cout << "~ Choix du bateau ~" << endl;
    cout << " " << endl;
}

/**
 * Action qui va afficher le type de place requis en fonction du type de bateau
 * @param b le bateau
 */
void Interface::typeBateauInfos(Bateau b){
    info("Bateau catégorisé comme "+b.getTypeBateau(),false);
    if(b.getTypeBateau()=="Voilier de type 2"){
        info("Place de grande taille requise",true);
    } else {
        info("Place de taille normale requise",true);
    }
}

/**
 * LISTE DES PLACES
 */

void Interface::interfaceNewPlace(){
    cout << "~ Choix de la place ~" << endl;
    cout << " " << endl;
}

void Interface::interfacePlaceInfos(Place p){
    cout << "Info. Vous avez choisi la place n°"<< p.getNumber() << endl;
    cout << " " << endl;
}

/**
 * CLIENTS
 */

void Interface::interfaceChoixClient(){
    cout << "~ Choix du client ~" << endl;
    cout << " " << endl;
}


