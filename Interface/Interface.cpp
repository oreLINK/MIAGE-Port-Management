//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "Interface.h"
#include <iostream>

using namespace std;

/**
 * HOME PAGE
 */

void Interface::interfaceHome() {
    cout << "~~~ GESTION PORT DE LA ROCHELLE ~~~" << endl;
    cout << " " << endl;
    cout << "1 : Statistiques du port" << endl;
    cout << "2 : Nouvelle réservation" << endl;
    cout << " " << endl;
    cout << "0 : Quitter (sauv. auto)" << endl;
    cout << " " << endl;
}

int Interface::interfaceHomeResponse() {
    int choice;
    cout << "Choix ? ", cin >> choice;
    cout << " " << endl;
    return choice;
}

/**
 * BOAT CREATION
 */


