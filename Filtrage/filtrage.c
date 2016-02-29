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

int FIR (int ACr_non_filtre, int ACir_non_filtre, int bufferFIR[2][51], float coeffFIR[51], float tab_filtre_FIR[2][2])
{
    int k,i = 0;
    tab_filtre_FIR[1][0] = tab_filtre_FIR[0][0];
    tab_filtre_FIR[1][1] = tab_filtre_FIR[0][1];
    tab_filtre_FIR[0][0] = 0;
    tab_filtre_FIR[0][1] = 0;

    for(i=0;i<51;i++){
        if(i-1>=0){
            bufferFIR[0][i-1] = bufferFIR[0][i];
            bufferFIR[1][i-1] = bufferFIR[1][i];
        }
    }
    bufferFIR[0][50] = ACr_non_filtre;
    bufferFIR[1][50] = ACir_non_filtre;

    for(k=0;k<51;k++){
        tab_filtre_FIR[0][0] += coeffFIR[k] * bufferFIR[0][50-k];
        tab_filtre_FIR[0][1] += coeffFIR[k] * bufferFIR[1][50-k];
    }
    return 1;
}


void IIR (float tab_filtre_IIR[2], float tab_filtre_FIR[2][2])
{
    tab_filtre_IIR[0] = tab_filtre_FIR[0][0] - tab_filtre_FIR[1][0] + 0.992 * tab_filtre_IIR[0];
    tab_filtre_IIR[1] = tab_filtre_FIR[0][1] - tab_filtre_FIR[1][1] + 0.992 * tab_filtre_IIR[1];
}
