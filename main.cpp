#include <iostream>
#include "Bateau/Bateau.h"
#include "GestionPort/GestionPort.h"
#include "Interface/Interface.h"

using namespace std;

GestionPort gp;
Interface it;

void home();
void homeResponseCheck(int homeResponse);
void createReservation();
void createBoat();
int createBoatAskSize();

/**
 * Classe principale de l'application. Lance l'application.
 * @return
 */
int main() {
    home();
    return 0;
}

/**
 * Action.
 * Affichage de la page d'accueil de l'application.
 */
void home() {
    it.interfaceHome();
    int choice = it.interfaceHomeResponse();
    homeResponseCheck(choice);
}

void homeResponseCheck(int homeResponse) {
    switch(homeResponse) {
        case 0:
            exit(1);
            break;
        case 1:
            cout << "lala" << endl;
            break;
        case 2:
            gp.createReservation();
            break;
        default:
            cout << "Erreur. Veuillez choisir un choix." << endl;
            cout << " " << endl;
            main();
    }
}

