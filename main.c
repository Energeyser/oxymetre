// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#include "main.h"

int main()
{
    struct absorp myAbsorp;
    struct oxy myOxy;
    bool etat = 1;
    int** mem_fir = NULL;
    int** mem_iir = NULL;
    FILE* descr = NULL;


    descr = initDescr();
    mem_fir = initMem(51,2);
    mem_iir = initMem(2,2);
    myAbsorp = fir(myAbsorp, mem_fir);

    finDescr(descr);
    finMem(mem_iir, 2);
    finMem(mem_fir, 2);

    return 0;
}
