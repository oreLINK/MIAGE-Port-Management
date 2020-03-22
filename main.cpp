#include <iostream>

using namespace std;

void home();
int homeResponse();
void homeResponseCheck(int homeResponse);
void createReservation();

int main() {
    home();
    return 0;
}

void home() {
    cout << "~~~ GESTION PORT DE LA ROCHELLE ~~~" << endl;
    cout << " " << endl;
    cout << "1 : Statistiques du port" << endl;
    cout << "2 : Nouvelle réservation" << endl;
    cout << " " << endl;
    cout << "0 : Quitter (sauv. auto)" << endl;
    cout << " " << endl;
    int choice = homeResponse();
    homeResponseCheck(choice);
}

int homeResponse() {
    int choice;
    cout << "Choix ? ", cin >> choice;
    cout << " " << endl;
    return choice;
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
            //lala
            break;
        default:
            cout << "Erreur. Veuillez choisir un choix." << endl;
            cout << " " << endl;
            main();
    }
}

void createReservation() {
    //details Bateau
    //liste places dispo en fonction Bateau
    //choix place
    //creation usager (abonne ou passager aussi)
    //si supplements
    //affichage tarifs
    //paiement (tout si passager ou cotisation pour abonne)
    //edition facture pour abonne
}