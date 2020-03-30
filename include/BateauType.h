//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_BATEAUTYPE_H
#define MIAGE_PORT_MANAGEMENT_BATEAUTYPE_H

#include <string>

using namespace std;

struct BateauType {
    char const * voilierNonHabitableChar = "Voilier non habitable";
    string voilierNonHabitableString = "Voilier non habitable";
    char const * voilierType1Char = "Voilier de type 1";
    string voilierType1String = "Voilier de type 1";
    char const * voilierType2Char = "Voilier de type 2";
    string voilierType2String = "Voilier de type 2";
};

#endif //MIAGE_PORT_MANAGEMENT_BATEAUTYPE_H
