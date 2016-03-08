// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#ifndef MAIN_H
#define MAIN_H
// Includes.
#include "fir.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct absorp absorp;
struct absorp{
    float ACR;
    float DCR;
    float ACIR;
    float DCIR;
};

typedef struct oxy oxy;
struct oxy{
    int SpO2;
    int pouls;
};

// Sources codes
#endif
