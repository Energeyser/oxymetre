// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: ?

#include "initMem.h"

float** initMem(int x,int y){
    int i,j;
    float **ptr=NULL;

    ptr = malloc(y * sizeof(*ptr));       //On alloue y pointeurs.
    if(ptr == NULL){
        printf("Erreur d'allocation de la memoire.\n");
    } else{
    }

    for(i=0 ; i < y ; i++){
         ptr[i] = malloc(x * sizeof(**ptr) );       //On alloue des tableaux de y variables.
         if(ptr[i] == NULL){ //En cas d'erreur d'allocation
             printf("Erreur d'allocation de la memoire.\n");
             for(i = i-1 ; i >= 0 ; i--){
                 free(ptr[i]);
             }            //On parcourt la boucle dans l'ordre inverse pour libérer ce qui a déjà été alloué
                free(ptr);
         }
    }
    for(i=0; i<y; i++){
        for(j=0; j<x; j++){
            ptr[i][j] = 0;
        }
    }
    return ptr;
}
