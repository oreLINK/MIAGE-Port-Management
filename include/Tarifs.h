//
// Created by Aurélien BERTRAND on 28/03/2020.
//

#ifndef MIAGE_PORT_MANAGEMENT_TARIFS_H
#define MIAGE_PORT_MANAGEMENT_TARIFS_H

struct Tarifs {
    struct Abonne {
        struct Quai {
            struct VoilierNonHabitable {
                int paiementAnnuel = 500;
                int paiementMensuel[12] = {42,42,42,42,42,42,42,42,42,42,42,38};
            };
            struct VoilierType1 {
                int paiementAnnuel = 650;
                int paiementMensuel[12] = {55,55,55,55,55,55,55,55,55,55,55,45};
            };
            struct VoilierType2 {
                int paiementAnnuel = 800;
                int paiementMensuel[12] = {67,67,67,67,67,67,67,67,67,67,67,63};
            };
            VoilierNonHabitable voilierNonHabitable;
            VoilierType1 voilierType1;
            VoilierType2 voilierType2;
        };
        struct NonQuai {
            struct VoilierNonHabitable {
                int paiementAnnuel = 250;
                int paiementMensuel[12] = {21,21,21,21,21,21,21,21,21,21,21,19};
            };
            struct VoilierType1 {
                int paiementAnnuel = 325;
                int paiementMensuel[12] = {28,28,28,28,28,28,28,28,28,28,28,17};
            };
            struct VoilierType2 {
                int paiementAnnuel = 400;
                int paiementMensuel[12] = {34,34,34,34,34,34,34,34,34,34,34,26};
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
    Abonne abonne;
    NonAbonne nonAbonne;
    int supplementJournalier = 5;
};


#endif //MIAGE_PORT_MANAGEMENT_TARIFS_H
