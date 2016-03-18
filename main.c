// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#include "define.h"
#include "initMem.h"
#include "fir.h"
#include "lecture.h"
#include "initFichier.h"


int main()
{
    absorp myAbsorp;
    oxy myOxy;
    val myVal;
    myVal.passageZero=0;
    myVal.rang=0;
    myVal.maxACR=0;
    myVal.maxDCR=0;
    myVal.maxACIR=0;
    myVal.maxDCIR=0;
    int etat = 1;
    int** mem_fir = NULL;
    int** mem_iir = NULL;
    FILE* descr = NULL;

    descr = initFichier();
    mem_fir = initMem(51,2);
    mem_iir = initMem(2,2);
    myAbsorp = lecture(descr,&etat);
    printf("ACR : %d, DCR : %d, ACIR : %d; DCIR : %d\n", myAbsorp.ACR, myAbsorp.DCR, myAbsorp.ACIR, myAbsorp.DCIR);
    myAbsorp = fir(myAbsorp, mem_fir);

    finDescr(descr);
    finMem(mem_iir, 2);
    finMem(mem_fir, 2);

    return 0;
}

