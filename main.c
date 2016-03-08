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
    int mem_fir;
    struct absorp mem_iir;
    int coeffFIR[51];
    //iir(myAbsorp, mem_iir);
    FILE* descr = NULL;

    descr = initDescr();
    myAbsorp = fir(myAbsorp, mem_fir);

    return 0;
}
