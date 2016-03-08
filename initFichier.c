// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: ?

#include "initFichier.h"
FILE* initFichier(){
    FILE* descr = NULL;
    descr = fopen("./Data/record1/record1.dat", "r");

    return descr;
}
