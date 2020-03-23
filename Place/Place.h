//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_PLACE_H
#define MIAGE_PORT_MANAGEMENT_PLACE_H


class Place {
public:
    Place();

    Place(int tailleMax, bool siElec, bool siEau, bool siOccupe);

    int getTailleMax() const;

    void setTailleMax(int tailleMax);

    bool isSiElec() const;

    void setSiElec(bool siElec);

    bool isSiEau() const;

    void setSiEau(bool siEau);

    bool isSiOccupe() const;

    void setSiOccupe(bool siOccupe);

private:
    int tailleMax;
    bool siElec;
    bool siEau;
    bool siOccupe;
};


#endif //MIAGE_PORT_MANAGEMENT_PLACE_H
