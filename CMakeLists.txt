cmake_minimum_required(VERSION 3.15)
project(MIAGE_Port_Management)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./TinyXML)

add_executable(MIAGE_Port_Management
        main.cpp
        src/GestionPort.cpp include/GestionPort.h
        src/Bateau.cpp include/Bateau.h
        src/Interface.cpp include/Interface.h
        src/Client.cpp include/Client.h
        src/Place.cpp include/Place.h
        src/Reservation.cpp include/Reservation.h
        src/Date.cpp include/Date.h
        src/data/Data.cpp include/data/Data.h
        src/tinyxml2.cpp include/tinyxml2.h src/Tarifs.cpp include/Tarifs.h src/Paiement.cpp include/Paiement.h include/XMLClient.h include/XMLPlaces.h include/NombrePlaces.h src/data/DataPlace.cpp include/data/DataPlace.h src/data/DataClient.cpp include/data/DataClient.h src/data/DataDate.cpp include/data/DataDate.h src/data/DataReservation.cpp include/data/DataReservation.h include/data/XMLFilesName.h include/BateauType.h include/data/XMLReservations.h include/Calendrier.h)
