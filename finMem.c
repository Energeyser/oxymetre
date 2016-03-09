// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: ?

#include "finMem.h"

void finMem(int** tab, int x){
    int i = 0;

    for(i=0 ; i < x ; i++){
        free(tab[i]);
    }

    free(tab);
    tab = NULL;
}
