//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATE_H
#define MIAGE_PORT_MANAGEMENT_DATE_H

#include <string>

using namespace std;

class Date {
public:
    Date();

    Date(int year, int month, int day);

    int getYear() const;

    void setYear(int year);

    int getMonth() const;

    void setMonth(int month);

    int getDay() const;

    void setDay(int day);

private:
    int year;
    int month;
    int day;
};


#endif //MIAGE_PORT_MANAGEMENT_DATE_H
