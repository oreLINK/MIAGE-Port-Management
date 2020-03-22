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
/**
void createReservation() {
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



void createBoat() {
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
    cout << "Votre bateau a été catégorisé comme " << boat.getTypeBateau() << endl;
    cout << " " << endl;
}

*/

/**
 * Fonction.
 * Lors de la création d'un bateau, demande la taille en mètres de celui-ci au client.
 * Ne prend pas en compte les valeurs négatives ou égales à 0.
 *
 * /!\ VOIR POUR CHECK LE CIN ET N'ACCEPTER QUE LES NOMBRES /!\
 *
 * @return la taille du bateau
 */

/**
int createBoatAskSize() {
    int size;
    cout << "Taille du bateau ? (en mètres) ", cin >> size;
    while(size <= 0) {
        cin.clear();
        cout << "Erreur. Valeur négative, trop grande ou format incompatible." << endl;
        cout << "Taille du bateau ? (en mètres) ", cin >> size;
    }
    return size;
}

void typeBoatInformation(string typeBateau) {
    if(typeBateau == "Voilier non habitable") {
        cout << "Place normale - Branchements non autorisés" << endl;
        cout << " " << endl;
    } else if(typeBateau == "Voilier de type 1") {
        cout << "Place normale - Branchements autorisés (sur quai)" << endl;
        cout << " " << endl;
    } else {
        cout << "Place normale - Branchements non autorisés" << endl;
        cout << " " << endl;
    }
}
*/

