// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: ?

#include "finFichier.h"

int* initMem(taille_tableau){
    int* tableau = NULL;
    tableau = malloc(taille_tableau * sizeof(int));
    return tableau;
}
