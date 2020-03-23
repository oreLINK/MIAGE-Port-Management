cmake_minimum_required(VERSION 3.15)
project(MIAGE_Port_Management)

set(CMAKE_CXX_STANDARD 14)

add_executable(MIAGE_Port_Management main.cpp GestionPort/GestionPort.cpp GestionPort/GestionPort.h Bateau/Bateau.cpp Bateau/Bateau.h Interface/Interface.cpp Interface/Interface.h Client/Client.cpp Client/Client.h Place/Place.cpp Place/Place.h Reservation/Reservation.cpp Reservation/Reservation.h Date/Date.cpp Date/Date.h)