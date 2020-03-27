//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "Place.h"

Place::Place() {}

Place::Place(int number, bool dock, bool tall, bool elec, bool water, bool busy) : number(number), dock(dock),
                                                                                   tall(tall), elec(elec), water(water),
                                                                                   busy(busy) {}

int Place::getNumber() const {
    return number;
}

void Place::setNumber(int number) {
    Place::number = number;
}

bool Place::isDock() const {
    return dock;
}

void Place::setDock(bool dock) {
    Place::dock = dock;
}

bool Place::isTall() const {
    return tall;
}

void Place::setTall(bool tall) {
    Place::tall = tall;
}

bool Place::isElec() const {
    return elec;
}

void Place::setElec(bool elec) {
    Place::elec = elec;
}

bool Place::isWater() const {
    return water;
}

void Place::setWater(bool water) {
    Place::water = water;
}

bool Place::isBusy() const {
    return busy;
}

void Place::setBusy(bool busy) {
    Place::busy = busy;
}
