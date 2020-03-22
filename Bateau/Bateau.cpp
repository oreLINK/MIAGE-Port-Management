//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#include "Bateau.h"

Bateau::Bateau(int taille, bool siCabine, const string &typeBateau) : taille(taille), siCabine(siCabine), typeBateau(typeBateau) {}

Bateau::Bateau() {}

int Bateau::getTaille() const {
    return taille;
}

void Bateau::setTaille(int taille) {
    Bateau::taille = taille;
}

bool Bateau::isSiCabine() const {
    return siCabine;
}

void Bateau::setSiCabine(bool siCabine) {
    Bateau::siCabine = siCabine;
}

const string &Bateau::getTypeBateau() const {
    return typeBateau;
}

void Bateau::setTypeBateau(const string &typeBateau) {
    Bateau::typeBateau = typeBateau;
}

