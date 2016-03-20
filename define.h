// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#ifndef DEFINE_H
#define DEFINE_H



//bibliotheques
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

typedef struct {

    float ACR;
    float DCR;
    float ACIR;
    float DCIR;
} absorp;

//structure contenant les valeurs du pouls et de SPO2

typedef struct {
    int SpO2;
    int pouls;
} oxy;

// Sources codes
#endif
