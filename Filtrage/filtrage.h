// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016


#ifndef FILTRAGE_H
#define FILTRAGE_H

// Includes.
#include "../main.h"



int FIR (int ACr_non_filtre, int ACir_non_filtre, int bufferFIR[2][51], float coeffFIR[51], float tab_filtre_FIR[2][2]);
void IIR (float tab_filtre_IIR[2], float tab_filtre_FIR[2][2]);


#endif
