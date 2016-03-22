#include "mesure.h"

oxy mesure(absorp myAbsorp, float* mem_calcul, oxy myOxy, int* pointeursurZero, int* rang,float* maxACR, float* minACR, float* maxACIR, float* minACIR)
{
    float periode;
    int ptpACR;
    int ptpACIR;
    float RsIR;
    float SpO2;

        // Mise en memoire des valeurs min et max pour calcul de la valeur ptp

        if(myAbsorp.ACR>*maxACR){
        *maxACR = myAbsorp.ACR;
        }
        if(myAbsorp.ACR<*minACR){
            *minACR = myAbsorp.ACR;
        }
        if(myAbsorp.ACIR>*maxACIR){
            *maxACIR = myAbsorp.ACIR;
        }
        if(myAbsorp.ACIR<*minACIR){
            *minACIR = myAbsorp.ACIR;
        }

    // test du passage par zero pour calculer la periode
    if(*pointeursurZero<3){
        if(myAbsorp.ACR<0 && *mem_calcul>0){
            *pointeursurZero = *pointeursurZero+1;
        }
        else if(myAbsorp.ACR>0 && *mem_calcul<0){
            *pointeursurZero = *pointeursurZero+1;
        }
        if(*pointeursurZero>0){
            *rang = *rang + 1;
            printf("rang: %d\n", *rang);
        }
    }
    // si on vient de passer la periode, on fait les calculs de SpO2 et du pouls et on reinitialise les variables
    else{
        // calcul des valeurs ptp
        ptpACR=*maxACR-*minACR;
        ptpACIR=*maxACIR-*minACIR;

        // calcul du SpO2
        if(myAbsorp.DCR != 0 && myAbsorp.DCIR != 0){
            RsIR=(ptpACR/myAbsorp.DCR)/(ptpACIR/myAbsorp.DCIR);
        }
        if(RsIR>0.4 && RsIR<1){
            SpO2=-25*RsIR+110;
        }
        else if(RsIR>1 && RsIR<3.4){
            SpO2=-33.3*RsIR+113;
        }
        myOxy.SpO2= (int) SpO2;

        // calcul du pouls
        periode = *rang*0.002;
        myOxy.pouls = (1/periode)*60;

        // reinitialisation des variables
        *rang=1;
        *maxACR=0;
        *minACR=0;
        *maxACIR=0;
        *minACIR=0;
        *pointeursurZero = 1;
    }
    *mem_calcul = myAbsorp.ACR;
    printf("SpO2 : %d , Pouls : %d \n", myOxy.SpO2, myOxy.pouls);
    return myOxy;
}



