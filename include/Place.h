//
// Created by Yessoh BONNY on 23/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_PLACE_H
#define MIAGE_PORT_MANAGEMENT_PLACE_H


class Place {
public:
    Place();

    Place(int number, bool dock, bool tall, bool elec, bool water, bool busy);

    int getNumber() const;

    void setNumber(int number);

    bool isDock() const;

    void setDock(bool dock);

    bool isTall() const;

    void setTall(bool tall);

    bool isElec() const;

    void setElec(bool elec);

    bool isWater() const;

    void setWater(bool water);

    bool isBusy() const;

    void setBusy(bool busy);

private:
    int number;
    bool dock;
    bool tall;
    bool elec;
    bool water;
    bool busy;
};


#endif //MIAGE_PORT_MANAGEMENT_PLACE_H
