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

    int i = 0;
    char c_ACR[5], c_DCR[5], c_ACIR[5], c_DCIR[5];
    c_ACR[4] = '\0';
    c_DCR[4] = '\0';
    c_ACIR[4] = '\0';
    c_DCIR[4] = '\0';

    if(feof(fichier)){
        *etat = EOF;

    }

    //printf("etat : %d\n", *etat);

    if(*etat != EOF){
        for(i=0; i<4; i++){
                c_ACR[i] = fgetc(fichier);
        }

        fseek(fichier, 1, SEEK_CUR);

        for(i=0; i<4; i++){
                c_DCR[i] = fgetc(fichier);
        }

        fseek(fichier, 1, SEEK_CUR);

        for(i=0; i<4; i++){
                c_ACIR[i] = fgetc(fichier);
        }

        fseek(fichier, 1, SEEK_CUR);

        for(i=0; i<4; i++){
                c_DCIR[i] = fgetc(fichier);
        }

        fseek(fichier, 4, SEEK_CUR);

    }
    //printf("c_ACR = %s\n", c_ACR);
    myAbsorp.ACR = atof(c_ACR) - 2048;
    //printf("myAbsorp.ACR = %f\n", myAbsorp.ACR);
    myAbsorp.DCR = atof(c_DCR);
    myAbsorp.ACIR = atof(c_ACIR) - 2048;
    myAbsorp.DCIR = atof(c_DCIR);



    return myAbsorp;
}
