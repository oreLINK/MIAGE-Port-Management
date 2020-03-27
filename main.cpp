#include <iostream>
#include <Data/Data.h>
#include <vector>
#include "Bateau/Bateau.h"
#include "GestionPort/GestionPort.h"
#include "Interface/Interface.h"

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
    it.home();
    return 0;
}

