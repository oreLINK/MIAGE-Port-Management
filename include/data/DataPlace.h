//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATAPLACE_H
#define MIAGE_PORT_MANAGEMENT_DATAPLACE_H

#include "Data.h"
#include "XMLFilesName.h"

class DataPlace {
private:

public:
    void createFirstPlacesFile();

    vector<struct Place> importPlacesFile();

    void displayPlace(Place p);

    void displayPlaces(vector<Place> p);

    bool checkIfPlacesFileExist();

    vector<Place> importPlacesFileCriteriaLength(bool isTall, bool isFree);

    bool checkNumberPlace(vector<Place> listPlaces, int choice);

    Place extractPlaceFromNumber(vector<Place> listPlaces, int choice);

    vector<int> extractListPlaceOccupied(vector<Reservation> r);

    vector<int> extractListPlaceOccupied();

    vector<int> compareAndReturnPlacesFree(vector<int> listePlaces, vector<int> listeOccupee);

    void changePlaceBusy(int numberPlace);
};


#endif //MIAGE_PORT_MANAGEMENT_DATAPLACE_H
