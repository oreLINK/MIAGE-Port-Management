//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATADATE_H
#define MIAGE_PORT_MANAGEMENT_DATADATE_H


#include <include/Date.h>

class DataDate {
private:

public:
    Date getDateToday();

    string convertString(const char *cara);

    int convertInt(const char *cara);

    int convertMonth(string month);
};


#endif //MIAGE_PORT_MANAGEMENT_DATADATE_H
