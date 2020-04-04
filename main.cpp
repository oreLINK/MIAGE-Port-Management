#include <iostream>
#include <include/data/Data.h>
#include <vector>
#include <string>
#include <sstream>
#include "include/Bateau.h"
#include "include/GestionPort.h"
#include "include/Interface.h"
#include "include/data/DataPlace.h"
#include "include/data/DataClient.h"
#include "include/data/DataReservation.h"

using namespace std;

Interface it;
DataPlace dataPlace;
DataClient dataClient;
DataReservation dataReservation;

/**
 * Classe principale de l'application. Lance l'application.
 * @return
 */
int main() {
    if(!dataPlace.checkIfPlacesFileExist()){
        dataPlace.createFirstPlacesFile();
    }
    if(!dataClient.checkIfClientsFileExist()){
        dataClient.createFirstClientFile();
    }
    if(!dataReservation.checkIfReservationsFileExist()){
        dataReservation.createReservationsFile();
    }
    it.home();
    return 0;
}

