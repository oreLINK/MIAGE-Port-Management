cmake_minimum_required(VERSION 3.15)
project(MIAGE_Port_Management)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(./TinyXML)

add_executable(MIAGE_Port_Management
        main.cpp
        GestionPort/GestionPort.cpp GestionPort/GestionPort.h
        Bateau/Bateau.cpp Bateau/Bateau.h
        Interface/Interface.cpp Interface/Interface.h
        Client/Client.cpp Client/Client.h
        Place/Place.cpp Place/Place.h
        Reservation/Reservation.cpp Reservation/Reservation.h
        Date/Date.cpp Date/Date.h
        Data/Data.cpp Data/Data.h
        ./TinyXML/tinyxml2.cpp ./TinyXML/tinyxml2.h)
