//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#include "include/data/DataDate.h"
#include "include/data/DataClient.h"
#include "include/NombrePlaces.h"
#include "include/XMLPlaces.h"
#include "include/tinyxml2.h"
#include "include/data/Data.h"
#include <include/Interface.h>
#include <include/Reservation.h>
#include <sstream>
#include <include/Date.h>
#include <Tcl/tclTomMath.h>
#include <include/Client.h>
#include <vector>
#include <array>
#include <iostream>
#include "include/data/DataDate.h"

/**
 *
 * @return
 */
Date DataDate::getDateToday() {
    Date d;

    time_t curr_time;
    tm *curr_tm;
    char year_string[100];
    char month_string[100];
    char day_string[100];

    time(&curr_time);
    curr_tm = localtime(&curr_time);

    strftime(year_string, 50, "%Y", curr_tm);
    strftime(month_string, 50, "%B", curr_tm);
    strftime(day_string, 50, "%d", curr_tm);

    int y = convertInt(year_string);
    int m = convertMonth(convertString(month_string));
    int j = convertInt(day_string);

    d.setYear(y);
    d.setMonth(m);
    d.setDay(j);

    return d;
}

/**
 * Fonction qui va convertir le const char * en string
 * @param cara le char à convertir
 * @return le string correspondant
 */
string DataDate::convertString(const char *cara) {
    stringstream s;
    s << cara;
    string m;
    s >> m;
    return m;
}

/**
 * Fonction qui va convertir le const char * en Integer
 * @param cara le int à convertir
 * @return le string correspondant
 */
int DataDate::convertInt(const char *cara) {
    stringstream s;
    s << cara;
    int y;
    s >> y;
    return y;
}

/**
 *
 * @param month
 * @return
 */
int DataDate::convertMonth(string month) {
    int mois;
    if (month == "January") {
        mois = 1;
    } else if (month == "February") {
        mois = 2;
    } else if (month == "March") {
        mois = 3;
    } else if (month == "April") {
        mois = 4;
    } else if (month == "May") {
        mois = 5;
    } else if (month == "June") {
        mois = 6;
    } else if (month == "July") {
        mois = 7;
    } else if (month == "August") {
        mois = 8;
    } else if (month == "September") {
        mois = 9;
    } else if (month == "October") {
        mois = 10;
    } else if (month == "November") {
        mois = 11;
    } else {
        mois = 12;
    }
    return mois;
}