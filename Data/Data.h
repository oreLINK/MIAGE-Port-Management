//
// Created by Aurélien BERTRAND on 25/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATA_H
#define MIAGE_PORT_MANAGEMENT_DATA_H

#include "../Place/Place.h"

#include <string>
#include <TinyXML/tinyxml2.h>

using namespace std;

class Data {
public:
    Data();
    void createFirstPlacesFile();
    void importPlacesFile();
    vector<struct Place> importPlacesFileCriteriaLength(bool isTall, bool isFree);
    void displayPlaces(vector<Place> p);
    bool checkNumberPlace(vector<Place> listPlaces, int choice);
    Place extractPlaceFromNumber(vector<Place> listPlaces, int choice);
    bool checkIfPlacesFileExist();
    void createFirstClientFile();
    bool checkIfClientsFileExist();
private:
    char const *linkPlacesXMLFile = "Places.xml";
    char const* linkClientXMLFile = "Clients.xml";
    //Attention
    //nbPlacesQuai <= nbPlaces et
    //nbPlacesQuaiPetites <= nbPlacesQuai et
    //nbPlacesHorsQuaiPetites <= (nbPlaces-nbPlacesQuai)
    int const nbPlaces = 40;
    int const nbPlacesQuai = 30;
    int const nbPlacesQuaiPetites = 20;
    int const nbPlacesQuaiGrandes = nbPlacesQuai-nbPlacesQuaiPetites;
    int const nbPlacesHorsQuai = nbPlaces - nbPlacesQuai;
    int const nbPlacesHorsQuaiPetites = 7;
    int const nbPlacesHorsQuaiGrandes = nbPlacesHorsQuai-nbPlacesHorsQuaiPetites;

    int extractIntFromXML(tinyxml2::XMLError eResult, tinyxml2::XMLElement *elementFather, const char *id);

    bool extractBoolFromXML(tinyxml2::XMLError eResult, tinyxml2::XMLElement *elementFather, const char *id);

    void displayPlace(Place p);
};


#endif //MIAGE_PORT_MANAGEMENT_DATA_H
