//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "include/Interface.h"
#include "include/GestionPort.h"
#include <iostream>

string version = "1.0";

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
    cout << "~~~ GESTION PORT DE LA ROCHELLE ~~~ " << version << endl;
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

string Interface::getCinLine(string message, bool ifEspace) {
    string choice;
    char input[150];
    cout << "[q pour accueil] " << message << " ", cin >> choice;
    if(ifEspace) {
        cout << " " << endl;
    }
    cin.getline(input, sizeof(input));
    choice = input;
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

void Interface::interfaceListeClients(){
    info("Liste des clients",false);
}

void Interface::interfaceClientInfo(Client c){
    cout << "Info. Le client choisi est le n°"<< c.getId() << " ("<< c.getNom() << " " << c.getPrenom() << ")"<< endl;
    cout << " " << endl;
}

/**
 * NOUVEAU CLIENT
 */

void Interface::interfaceNewClient(){
    cout << "~~~ NOUVEAU CLIENT ~~~" << endl;
    cout << " " << endl;
}

/**
 * SUPPLEMENTS
 */

void Interface::interfaceChoixSupplements(){
    cout << "~ Choix des suppléments ~" << endl;
    cout << " " << endl;
}

void Interface::interfaceInfosSupplements(Reservation r){
    if(r.isSupplementElec() && !r.isSupplementEau()){
        info("Le client a choisi le supplément éléctricité uniquement",true);
    } else if(!r.isSupplementElec() && r.isSupplementEau()){
        info("Le client a choisi le supplément eau uniquement",true);
    } else if(r.isSupplementElec() && r.isSupplementEau()){
        info("Le client a choisi les suppléments éléctricité et eau",true);
    } else {
        info("Le client n'a choisi aucun supplément",true);
    }
}

/**
 * DATES D'ARRIVEE ET DE DEPART
 */

void Interface::displayDates(Reservation r){
    cout << "Info. Votre réservation s'etend du "
    << r.getDateArrivee().getDay() << "/" << r.getDateArrivee().getMonth() << "/" << r.getDateArrivee().getYear() << " au "
    << r.getDateDepart().getDay() << "/" << r.getDateDepart().getMonth() << "/" << r.getDateDepart().getYear() << endl;
    cout << " " << endl;
}

/**
 * TARIFS
 */

void Interface::interfaceChoixEngagement(){
    cout << "~ Choix de la durée ~" << endl;
    cout << " " << endl;
}

void Interface::interfaceInfosEngagement(Reservation r){
    if(r.isAbonnement()){
        info("Vous avez choisi un abonnement avec engagement d'1 an",false);
    } else {
        info("Vous avez choisi le forfait Journée",false);
    }
}

void Interface::interfaceInfosNbJours(Paiement p){
    cout << "Info. Vous avez choisi le forfait " << p.getNbJours() << " Journée(s)" << endl;
}

void Interface::interfacePaiement(){
    cout << "~ Paiement ~" << endl;
    cout << " " << endl;
}


