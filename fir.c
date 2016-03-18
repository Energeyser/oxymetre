// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: ?

#include "fir.h"

//-------------------------------------------------------------------------
// Cette fonction elimine les composantes hautes frequences du signal fourni pour
// ne garder que le signal utile (autour de 1Hz)
// retourne une structure

absorp fir(absorp myAbsorp, int** mem_fir)
{
    /*int coeffFIR[51];
    int k,i = 0;
    myAbsorp.ACR;
    myAbsorp.ACIR;
    for(i=0;i<51;i++){
        if(i-1>=0){
            mem_fir[0][i-1] = mem_fir[0][i];
            mem_fir[1][i-1] = mem_fir[1][i];
        }
    }
    mem_fir[0][50] = myAbsorp.ACR;
    mem_fir[1][50] = myAbsorp.ACIR;

    for(k=0;k<51;k++){
        mem_fir[0][0] += coeffFIR[k] * mem_fir[0][50-k];
        mem_fir[0][1] += coeffFIR[k] * mem_fir[1][50-k];
        myAbsorp.ACR = mem_fir[0][0];
        myAbsorp.ACIR = mem_fir[0][1];
    }*/
    return myAbsorp;
}
