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
    char c_ACR[5], c_DCR[5], c_ACIR[5], c_DCIR[5];
    c_ACR[4] = '\0';
    c_DCR[4] = '\0';
    c_ACIR[4] = '\0';
    c_DCIR[4] = '\0';
    int ACR, DCR, ACIR, DCIR;

    if(&etat != 0){
        for(i=0; i<4; i++){
                c_ACR[i] = fgetc(fichier);
        }

        fseek(fichier, 1, SEEK_CUR);
        printf("c_ACR : %s\n",c_ACR);

        for(i=0; i<4; i++){
                c_DCR[i] = fgetc(fichier);
        }

        fseek(fichier, 1, SEEK_CUR);
        printf("c_DCR : %s\n",c_DCR);

        for(i=0; i<4; i++){
                c_ACIR[i] = fgetc(fichier);
        }

        fseek(fichier, 1, SEEK_CUR);
        printf("c_ACIR : %s\n",c_ACIR);

        for(i=0; i<4; i++){
                c_DCIR[i] = fgetc(fichier);
        }

        fseek(fichier, 2, SEEK_CUR);
        printf("c_DCIR : %s\n",c_DCIR);

    }
    ACR = atoi(c_ACR) - 2048;
    myAbsorp.ACR = ACR;
    printf("ACR : %d\n", ACR);
    printf("myAbsorp.ACR : %d\n", myAbsorp.ACR);
    myAbsorp.DCR = atoi(c_DCR);
    printf("DCR : %d\n", myAbsorp.ACR);
    myAbsorp.ACIR = atoi(c_ACIR) - 2048;
    myAbsorp.DCIR = atoi(c_DCIR);

    return myAbsorp;
}
