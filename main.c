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
    int mem_fir[2][51];
    FILE* descr = NULL;

    descr = initDescr();
    myAbsorp = fir(myAbsorp, mem_fir);

    finDescr(descr);

    return 0;
}
