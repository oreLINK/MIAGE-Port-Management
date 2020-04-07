//
// Created by Yessoh BONNY on 22/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_BATEAU_H
#define MIAGE_PORT_MANAGEMENT_BATEAU_H

#include <string>

using namespace std;

class Bateau {
public:
    Bateau();

    Bateau(int taille, bool siCabine);

    Bateau(int taille, bool siCabine, const string &typeBateau);

    int getTaille() const;
    void setTaille(int taille);
    bool isSiCabine() const;
    void setSiCabine(bool siCabine);

    const string &getTypeBateau() const;

    void setTypeBateau(const string &typeBateau);

private:
    int taille;
    bool siCabine;
    string typeBateau;
};


#endif //MIAGE_PORT_MANAGEMENT_BATEAU_H
