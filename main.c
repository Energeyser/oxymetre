// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#include "define.h"
#include "initMem.h"
#include "fir.h"
#include "iir.h"
#include "lecture.h"
#include "initFichier.h"
#include "mesure.h"


int main()
{
    absorp myAbsorp;
    oxy myOxy;
    myOxy.SpO2=0;
    myOxy.pouls=0;
    int passageZero=1;
    int rang=1;
    float maxACR=0;
    float minACR=0;
    float maxACIR=0;
    float minACIR=0;
    int etat = 1;
    float** mem_fir = NULL;
    float** mem_iir = NULL;
    int i = 0;

    float mem_calcul = 0;
    FILE* descr = NULL;

    descr = initFichier();
    mem_fir = initMem(51,2);
    mem_iir = initMem(2,2);


   for(i = 0; i<5000; i++){

    myAbsorp = lecture(descr,&etat);
    //printf("Sortie lecture :\n");
    //printf("ACR : %f, DCR : %f, ACIR : %f; DCIR : %f\n", myAbsorp.ACR, myAbsorp.DCR, myAbsorp.ACIR, myAbsorp.DCIR);
    myAbsorp = fir(myAbsorp, mem_fir);
    //printf("Sortie fir :\n");
    //printf("ACR : %d, DCR : %d, ACIR : %d; DCIR : %d\n", (int) myAbsorp.ACR, (int) myAbsorp.DCR, (int) myAbsorp.ACIR, (int) myAbsorp.DCIR);
    myAbsorp = iir(myAbsorp, mem_iir);
    //printf("ACR : %d, DCR : %d, ACIR : %d; DCIR : %d\n", (int) myAbsorp.ACR, (int) myAbsorp.DCR, (int) myAbsorp.ACIR, (int) myAbsorp.DCIR);

    myOxy = mesure(myAbsorp, &mem_calcul, myOxy, &passageZero, &rang, &maxACR, &minACR, &maxACIR, &minACIR);
    printf("ACR: %f \n", myAbsorp.ACR);

       //printf("mem_calcul : %f\n", mem_calcul);
        //printf("passageZero: %d\n", passageZero);


    affichage(myOxy);
    }

    finDescr(descr);
    finMem(mem_iir, 2);
    finMem(mem_fir, 2);

    return 0;
}

