// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#ifndef MAIN_H
#define MAIN_H

// Includes.
#include "fir.h"
#include "iir.h"
#include "initDescr.h"

//bibliotheques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

struct absorp{
    float ACR;
    float DCR;
    float ACIR;
    float DCIR;
};

//structure contenant les valeurs du pouls et de SPO2
struct oxy{
    int SpO2;
    int pouls;
};

// Sources codes
#endif
