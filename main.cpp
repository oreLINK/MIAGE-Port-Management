#include <iostream>
#include <include/Data.h>
#include <vector>
#include <string>
#include <sstream>
#include "include/Bateau.h"
#include "include/GestionPort.h"
#include "include/Interface.h"

using namespace std;

Interface it;
Data dmain;

/**
 * Classe principale de l'application. Lance l'application.
 * @return
 */
int main() {
    if(!dmain.checkIfPlacesFileExist()){
        dmain.createFirstPlacesFile();
    }
    if(!dmain.checkIfClientsFileExist()){
        dmain.createFirstClientFile();
    }
    if(!dmain.checkIfReservationsFileExist()){
        dmain.createReservationsFile();
    }
    it.home();
    return 0;
}

