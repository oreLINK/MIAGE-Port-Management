//
// Created by Aurélien BERTRAND on 23/03/2020.
//

#include "Client.h"

Client::Client() {}

Client::Client(int id, const char *nom, const char *prenom, const char *email, const char *adresse, const char *cp,
               const char *ville) : id(id), nom(nom), prenom(prenom), email(email), adresse(adresse), cp(cp),
                                    ville(ville) {}

int Client::getId() const {
    return id;
}

void Client::setId(int id) {
    Client::id = id;
}

const char *Client::getNom() const {
    return nom;
}

void Client::setNom(const char *nom) {
    Client::nom = nom;
}

const char *Client::getPrenom() const {
    return prenom;
}

void Client::setPrenom(const char *prenom) {
    Client::prenom = prenom;
}

const char *Client::getEmail() const {
    return email;
}

void Client::setEmail(const char *email) {
    Client::email = email;
}

const char *Client::getAdresse() const {
    return adresse;
}

void Client::setAdresse(const char *adresse) {
    Client::adresse = adresse;
}

const char *Client::getCp() const {
    return cp;
}

void Client::setCp(const char *cp) {
    Client::cp = cp;
}

const char *Client::getVille() const {
    return ville;
}

void Client::setVille(const char *ville) {
    Client::ville = ville;
}
