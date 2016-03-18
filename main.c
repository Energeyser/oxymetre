// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#include "define.h"
#include "initMem.h"
#include "fir.h"
#include "lecture.h"

int main()
{
    absorp myAbsorp;
    oxy myOxy;
    int etat = 1;
    int** mem_fir = NULL;
    int** mem_iir = NULL;
    FILE* descr = NULL;

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

