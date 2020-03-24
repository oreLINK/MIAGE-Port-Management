//
// Created by Aurélien BERTRAND on 22/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_INTERFACE_H
#define MIAGE_PORT_MANAGEMENT_INTERFACE_H

#include <string>

class Interface {
private:

public:
    void interfaceHome();

    std::string interfaceHomeResponse();

    bool ifWantGoHome(std::string cin);

    void erreur(std::string message, bool avecEspace);

    void home();

    void homeResponseCheck(std::string homeResponse);

    void info(std::string message, bool avecEspace);

    std::string getCin(std::string message, bool ifEspace);
};


#endif //MIAGE_PORT_MANAGEMENT_INTERFACE_H
