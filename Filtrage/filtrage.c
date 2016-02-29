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

void FIR (int ACr, int ACir, float bufferFIR[2][51], int rangBufferFIR, float coeffFIR[51])
{
    int k = 0;
    bufferFIR[0][rangBufferFIR] = ACr*coeffFIR[rangBufferFIR];
    bufferFIR[1][rangBufferFIR] = ACir*coeffFIR[rangBufferFIR];

    for(k=0;k<51;k++){
        if(rangBufferFIR < 0){
            rangBufferFIR = 50;
        }

        bufferFIR[0][rangBufferFIR] += coeffFIR[k]*(float)bufferFIR[0][rangBufferFIR-k];
        bufferFIR[1][rangBufferFIR] += coeffFIR[k]*(float)bufferFIR[1][rangBufferFIR-k];
    }

    //bufferFIR[0][rangBufferFIR] = floor((bufferFIR[0][rangBufferFIR])+0.5);
    //bufferFIR[1][rangBufferFIR] = floor((bufferFIR[1][rangBufferFIR])+0.5);

}
