//
// Created by Aurélien BERTRAND on 30/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_DATACLIENT_H
#define MIAGE_PORT_MANAGEMENT_DATACLIENT_H


#include "include/data/Data.h"
#include "XMLFilesName.h"

class DataClient {
private:

public:
    void createFirstClientFile();

    bool checkIfClientsFileExist();

    vector<Client> importClientsFile();

    void displayClients(vector<Client> c);

    bool checkIDClient(vector<Client> listClient, int choice);

    Client extractClientFromID(vector<Client> listClient, int choice);

    int numberOfClients(vector<Client> c);

    vector<Client> addNewClient(Client c);

    void createNewClientFile(vector<Client> listClients);

    vector<Client> switchClientList(vector<Client> vC);
};


#endif //MIAGE_PORT_MANAGEMENT_DATACLIENT_H
