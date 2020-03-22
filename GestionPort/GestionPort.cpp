//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "GestionPort.h"
#include <iostream>
#include "../Bateau/Bateau.h"

GestionPort::GestionPort() {}

void GestionPort::createReservation() {
    cout << "~~~ NOUVELLE RESERVATION ~~~" << endl;
    cout << " " << endl;
    createBoat(); //details Bateau
    //liste places dispo en fonction Bateau
    //choix place
    //creation usager (abonne ou passager aussi)
    //si supplements
    //affichage tarifs
    //paiement (tout si passager ou cotisation pour abonne)
    //edition facture pour abonne
}

void GestionPort::createBoat() {
    Bateau boat;
    int size = createBoatAskSize();
    boat.setTaille(size);
    if(size < 10) {
        boat.setSiCabine(false);
        boat.setTypeBateau("Voilier non habitable");
    } else if(size >= 10 && size <= 25) {
        boat.setSiCabine(true);
        boat.setTypeBateau("Voilier de type 1");
    } else {
        boat.setSiCabine(true);
        boat.setTypeBateau("Voilier de type 2");
    }
    cout << "Bateau catégorisé comme " << boat.getTypeBateau() << endl;
    cout << " " << endl;
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
    cout << "Taille du bateau ? (en mètres) ", cin >> size;
    while(size <= 0) {
        cin.clear();
        cout << "Erreur. Valeur négative, trop grande ou format incompatible." << endl;
        cout << "Taille du bateau ? (en mètres) ", cin >> size;
    }
    return size;
}
