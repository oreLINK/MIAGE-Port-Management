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
        src/Data.cpp include/Data.h
        src/tinyxml2.cpp include/tinyxml2.h src/Tarifs.cpp include/Tarifs.h src/Paiement.cpp include/Paiement.h)
