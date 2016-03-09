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
    int** mem_fir;
    FILE* descr = NULL;


    descr = initDescr();
    mem_fir = initMem(51,2);
    mem_fir[1][1] = 1;
    printf("mem_fir[2][2] = %d", mem_fir[1][1]);
    myAbsorp = fir(myAbsorp, mem_fir);

    finDescr(descr);

    return 0;
}
