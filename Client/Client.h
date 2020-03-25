//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_CLIENT_H
#define MIAGE_PORT_MANAGEMENT_CLIENT_H

#include <string>

using namespace std;

class Client {
public:
    Client();

    Client(const string &nom, const string &prenom, const string &email, const string &adresse, const string &cp,
           const string &ville);

    const string &getNom() const;

    void setNom(const string &nom);

    const string &getPrenom() const;

    void setPrenom(const string &prenom);

    const string &getEmail() const;

    void setEmail(const string &email);

    const string &getAdresse() const;

    void setAdresse(const string &adresse);

    const string &getCp() const;

    void setCp(const string &cp);

    const string &getVille() const;

    void setVille(const string &ville);

private:
    string nom;
    string prenom;
    string email;
    string adresse;
    string cp;
    string ville;
public:
};


#endif //MIAGE_PORT_MANAGEMENT_CLIENT_H
