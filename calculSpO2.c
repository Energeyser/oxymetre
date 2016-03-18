#include "calculSpO2.h"

int calculSpO2( int periode, struct oxy myOxy, int maxACR, int minACR, int maxACIR, int minACIR, struct absorp myAbsorp){
    if(myAbsorp.ACR>maxACR){
        maxACR = myAbsorp.ACR;
    }
    if(myAbsorp.ACR<minACR){
        minACR = myAbsorp.ACR;
    }
    if(myAbsorp.ACIR>maxACIR){
        maxACIR = myAbsorp.ACIR;
    }
    if(myAbsorp.ACIR<minACIR){
        minACIR = myAbsorp.ACIR;
    }

}
