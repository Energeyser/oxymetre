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
    val myVal;
    myVal.passageZero=0;
    myVal.rang=0;
    myVal.maxACR=0;
    myVal.minACR=0;
    myVal.maxACIR=0;
    myVal.minACIR=0;
    int etat = 1;
    float** mem_fir = NULL;
    float** mem_iir = NULL;
    int mem_calcul[1][2]={0};
    FILE* descr = NULL;
    int i;

    descr = initFichier();
    mem_fir = initMem(51,2);
    mem_iir = initMem(2,2);

    for(i=0; i<5000; i++){

    myAbsorp = lecture(descr,&etat);
    //printf("Sortie lecture :\n");
    //printf("ACR : %f, DCR : %f, ACIR : %f; DCIR : %f\n", myAbsorp.ACR, myAbsorp.DCR, myAbsorp.ACIR, myAbsorp.DCIR);
    myAbsorp = fir(myAbsorp, mem_fir);
    //printf("Sortie fir :\n");
    //printf("ACR : %d, DCR : %d, ACIR : %d; DCIR : %d\n", (int) myAbsorp.ACR, (int) myAbsorp.DCR, (int) myAbsorp.ACIR, (int) myAbsorp.DCIR);
    myAbsorp = iir(myAbsorp, mem_iir);
    //printf("%d ACR : %d, DCR : %d, ACIR : %d; DCIR : %d\n", i, (int) myAbsorp.ACR, (int) myAbsorp.DCR, (int) myAbsorp.ACIR, (int) myAbsorp.DCIR);
    myOxy = mesure(myAbsorp, mem_calcul, myOxy, myVal)
    //printf("SpO2: %d, pouls: %d\n",myOxy.SpO2, myOxy.pouls);
    }

    finDescr(descr);
    finMem(mem_iir, 2);
    finMem(mem_fir, 2);

    return 0;
}

