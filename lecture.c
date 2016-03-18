// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: lecture des donnees envoyees par la carte de l'oxymetre

// Includes.
#include "lecture.h"

#define TAILLE_MAX 21



absorp lecture(FILE* fichier, int* etat)
{

    absorp myAbsorp;

    int i;
    char ligne[TAILLE_MAX] = "";
    char c_ACR[4], c_DCR[4], c_ACIR[4], c_DCIR[4];
    int ACR, DCR, ACIR, DCIR;

    fgets(ligne, TAILLE_MAX, fichier);
    if(&etat != 0){
        for(i=0; i<5; i++){
                c_ACR[i] = ligne[i];
        }
        for(i=6; i<10; i++){
                c_DCR[i] = ligne[i];
        }
        for(i=11; i<15; i++){
                c_ACIR[i] = ligne[i];
        }
        for(i=16; i<20; i++){
                c_ACIR[i] = ligne[i];
        }
    }
    myAbsorp.ACR = atoi(c_ACR);
    myAbsorp.DCR = atoi(c_DCR);
    myAbsorp.ACIR = atoi(c_ACIR);
    myAbsorp.DCIR = atoi(c_DCIR);

    return myAbsorp;
}
