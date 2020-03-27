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

    Client(int id, const char *nom, const char *prenom, const char *email, int numeroAdresse, const char *adresse,
           const char *cp, const char *ville);

    int getId() const;

    void setId(int id);

    const char *getNom() const;

    void setNom(const char *nom);

    const char *getPrenom() const;

    void setPrenom(const char *prenom);

    const char *getEmail() const;

    void setEmail(const char *email);

    int getNumeroAdresse() const;

    void setNumeroAdresse(int numeroAdresse);

    const char *getAdresse() const;

    void setAdresse(const char *adresse);

    const char *getCp() const;

    void setCp(const char *cp);

    const char *getVille() const;

    void setVille(const char *ville);


private:
    int id;
    const char * nom;
    const char * prenom;
    const char * email;
    int numeroAdresse;
    const char * adresse;
    const char * cp;
    const char * ville;
public:
};


#endif //MIAGE_PORT_MANAGEMENT_CLIENT_H
