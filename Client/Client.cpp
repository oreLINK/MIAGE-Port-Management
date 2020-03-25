//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "Client.h"

Client::Client() {}

Client::Client(const string &nom, const string &prenom, const string &email, const string &adresse, const string &cp,
        const string &ville) : nom(nom), prenom(prenom), email(email), adresse(adresse), cp(cp), ville(ville) {}

const string &Client::getNom() const {
    return nom;
}

void Client::setNom(const string &nom) {
    Client::nom = nom;
}

const string &Client::getPrenom() const {
    return prenom;
}

void Client::setPrenom(const string &prenom) {
    Client::prenom = prenom;
}

const string &Client::getEmail() const {
    return email;
}

void Client::setEmail(const string &email) {
    Client::email = email;
}

const string &Client::getAdresse() const {
    return adresse;
}

void Client::setAdresse(const string &adresse) {
    Client::adresse = adresse;
}

const string &Client::getCp() const {
    return cp;
}

void Client::setCp(const string &cp) {
    Client::cp = cp;
}

const string &Client::getVille() const {
    return ville;
}

void Client::setVille(const string &ville) {
    Client::ville = ville;
}
