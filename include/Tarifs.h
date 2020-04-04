//
// Created by Aurélien BERTRAND on 28/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_TARIFS_H
#define MIAGE_PORT_MANAGEMENT_TARIFS_H

#include <string>

using namespace std;

struct Tarifs {
    struct Abonne {
        struct Quai {
            struct VoilierNonHabitable {
                int paiementAnnuel = 500;
                int paiementMensuelPremierMois = 38;
                int paiementMensuel11Mois = 42;
            };
            struct VoilierType1 {
                int paiementAnnuel = 650;
                int paiementMensuelPremierMois = 45;
                int paiementMensuel11Mois = 55;
            };
            struct VoilierType2 {
                int paiementAnnuel = 800;
                int paiementMensuelPremierMois = 63;
                int paiementMensuel11Mois = 67;
            };
            VoilierNonHabitable voilierNonHabitable;
            VoilierType1 voilierType1;
            VoilierType2 voilierType2;
        };
        struct NonQuai {
            struct VoilierNonHabitable {
                int paiementAnnuel = 250;
                int paiementMensuelPremierMois = 19;
                int paiementMensuel11Mois = 21;
            };
            struct VoilierType1 {
                int paiementAnnuel = 325;
                int paiementMensuelPremierMois = 17;
                int paiementMensuel11Mois = 28;
            };
            struct VoilierType2 {
                int paiementAnnuel = 400;
                int paiementMensuelPremierMois = 26;
                int paiementMensuel11Mois = 34;
            };
            VoilierNonHabitable voilierNonHabitable;
            VoilierType1 voilierType1;
            VoilierType2 voilierType2;
        };
        Quai quai;
        NonQuai nonQuai;
    };
    struct NonAbonne {
        struct Quai {
            struct VoilierNonHabitable {
                int paiementJournalier = 20;
            };
            struct VoilierType1 {
                int paiementJournalier = 26;
            };
            struct VoilierType2 {
                int paiementJournalier = 32;
            };
            VoilierNonHabitable voilierNonHabitable;
            VoilierType1 voilierType1;
            VoilierType2 voilierType2;
        };
        struct NonQuai {
            struct VoilierNonHabitable {
                int paiementJournalier = 10;
            };
            struct VoilierType1 {
                int paiementJournalier = 13;
            };
            struct VoilierType2 {
                int paiementJournalier = 16;
            };
            VoilierNonHabitable voilierNonHabitable;
            VoilierType1 voilierType1;
            VoilierType2 voilierType2;
        };
        Quai quai;
        NonQuai nonQuai;
    };
    struct TypePaiement {
        string paiementJournalier = "paiementJournalier";
        string paiementMensuelPremierMois = "paiementMensuelPremierMois";
        string paiementMensuel11Mois = "paiementMensuel11Mois";
        string paiementAnnuel = "paiementAnnuel";
    };
    struct Supplement {
        struct UnSupplement {
            int totalSupplements = 1825;
            int supplementPremierMois = 142;
            int supplement11Mois = 153;
        };
        struct DeuxSupplements {
            int totalSupplements = 3650;
            int supplementsPremierMois = 295;
            int supplements11Mois = 305;
        };
        UnSupplement unSupplement;
        DeuxSupplements deuxSupplements;
    };
    TypePaiement typePaiement;
    Abonne abonne;
    NonAbonne nonAbonne;
    Supplement supplement;
    int supplementJournalier = 5;
};


#endif //MIAGE_PORT_MANAGEMENT_TARIFS_H
