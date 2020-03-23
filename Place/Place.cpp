//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "Place.h"

Place::Place() {}

Place::Place(int tailleMax, bool siElec, bool siEau, bool siOccupe) : tailleMax(tailleMax), siElec(siElec),
                                                                      siEau(siEau), siOccupe(siOccupe) {}

int Place::getTailleMax() const {
    return tailleMax;
}

void Place::setTailleMax(int tailleMax) {
    Place::tailleMax = tailleMax;
}

bool Place::isSiElec() const {
    return siElec;
}

void Place::setSiElec(bool siElec) {
    Place::siElec = siElec;
}

bool Place::isSiEau() const {
    return siEau;
}

void Place::setSiEau(bool siEau) {
    Place::siEau = siEau;
}

bool Place::isSiOccupe() const {
    return siOccupe;
}

void Place::setSiOccupe(bool siOccupe) {
    Place::siOccupe = siOccupe;
}
