#include "mesure.h"

oxy mesure(absorp myAbsorp, float* mem_calcul, oxy myOxy, int* pointeursurZero, int* rang,float* maxACR, float* minACR, float* maxACIR, float* minACIR)
{
    int periode;
    int ptpACR;
    int ptpACIR;
    float RsIR;
    float SpO2;

    //printf("passageZero : %d\n", *passageZero);
    printf("myAbsorp.ACR : %f\n", myAbsorp.ACR);
    printf("mem_calcul : %f\n", *mem_calcul);


    if(*pointeursurZero<3){

        if(myAbsorp.ACR<0 && *mem_calcul>0){
            *pointeursurZero = *pointeursurZero+1;
        }
        else if(myAbsorp.ACR>0 && *mem_calcul<0){
            *pointeursurZero = *pointeursurZero+1;

        }
        if(*pointeursurZero>0){

            *rang = *rang + 1;
            //calculSpO2(periode, myOxy, maxACR, minACR, maxACIR, minACIR, myAbsorp);
        }
    }
    else{/*
        ptpACR=*maxACR-*minACR;
        ptpACIR=*maxACIR-*minACIR;
        RsIR=(ptpACR/myAbsorp.DCR)/(ptpACIR/myAbsorp.DCIR);
        if(RsIR>0.4 && RsIR<1){
            SpO2=-25*RsIR+110;
        }
        else if(RsIR>1 && RsIR<3.4){
            SpO2=-33.3*RsIR+113;
        }
        myOxy.SpO2= (int) SpO2;
        periode = *rang*0.002;
        myOxy.pouls = calculPouls(periode, myOxy);*/

        *rang=1;
        *maxACR=0;
        *minACR=0;
        *maxACIR=0;
        *minACIR=0;
        *pointeursurZero = 1;
    }
    printf("rang: %d\n",*rang);
    //printf("passageZero : %d\n", *pointeur);
     //printf("myAbsorp.ACR : %f\n", myAbsorp.ACR);
    *mem_calcul = myAbsorp.ACR;
    //printf("mem_calcul : %f\n", *mem_calcul);
    //printf("%f", mem_calcul);
    return myOxy;
}



