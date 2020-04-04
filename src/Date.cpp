//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "include/Date.h"

Date::Date() {}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {}

int Date::getYear() const {
    return year;
}

void Date::setYear(int year) {
    Date::year = year;
}

int Date::getMonth() const {
    return month;
}

void Date::setMonth(int month) {
    Date::month = month;
}

int Date::getDay() const {
    return day;
}

void Date::setDay(int day) {
    Date::day = day;
}
