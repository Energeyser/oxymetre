// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: filtrage du signal (elimination des hautes fréquences)

// Includes.
#include "filtrage.h"

//-------------------------------------------------------------------------
// Cette fonction elimine les composantes hautes frequences du signal fourni pour
// ne garder que le signal utile (autour de 1Hz)
// Ne retourne rien, mais modifie le buffer FIR

struct fir(myAbsorp, mem_fir){
    myAbsorp.ACR
    myAbsorp.ACIR

    for(i=0;i<51;i++){
        if(i-1>=0){
            men_fir[0][i-1] =men_fir[0][i];
            men_fir[1][i-1] = men_fir[1][i];
        }
    }
    men_fir[0][50] = ACr_non_filtre;
    men_fir[1][50] = ACir_non_filtre;

    for(k=0;k<51;k++){
        myAbsorp.ACR += coeffFIR[k] * men_fir[0][50-k];
        myAbsorp.ACIR += coeffFIR[k] * men_fir[1][50-k];
    }
    return myAbsorp;
}
