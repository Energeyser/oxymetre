// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: ?

#include "iir.h"

//-------------------------------------------------------------------------
//
//
// retourne une structure

struct absorp iir(struct absorp myAbsorp, int** mem_iir)
{
    mem_iir[0][1] = myAbsorp.ACR - mem_iir[0][0] + 0.992 * mem_iir[0][1];
    mem_iir[1][1] = myAbsorp.ACIR - mem_iir[1][0] + 0.992 * mem_iir[1][1];

    mem_iir[0][0] = myAbsorp.ACR;
    mem_iir[1][0] = myAbsorp.ACIR;

    myAbsorp.ACR = mem_iir[0][1];
    myAbsorp.ACIR = mem_iir[1][1];

    return myAbsorp;
}
