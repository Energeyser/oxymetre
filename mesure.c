#include "mesure.h"

oxy mesure(absorp myAbsorp, float* mem_calcul, oxy myOxy, int* passageZero, int* rang,float* maxACR, float* minACR, float* maxACIR, float* minACIR)
{
    int periode;
    int ptpACR;
    int ptpACIR;
    int i = 10;
    float RsIR;
    float SpO2;

    //printf("passageZero : %d\n", *passageZero);
    printf("myAbsorp.ACR : %f\n", myAbsorp.ACR);
    printf("mem_calcul : %f\n", *mem_calcul);


    if(*passageZero<3){

        if(myAbsorp.ACR<=0 && mem_calcul>=0){

            *passageZero = *passageZero + 1;
        }
        else if(myAbsorp.ACR>0 && mem_calcul<0){
            *passageZero++;
        }
        if(*passageZero>0){

            *rang = *rang + 1;
            //calculSpO2(periode, myOxy, *, myAbsorp);
        }
        //printf("rang : %d\n", *rang);

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
        *rang=0;
        *maxACR=0;
        *minACR=0;
        *maxACIR=0;
        *minACIR=0;
        *passageZero = 0;
    }
    printf("passageZero : %d\n", *passageZero);
     //printf("myAbsorp.ACR : %f\n", myAbsorp.ACR);
    *mem_calcul = myAbsorp.ACR;
    //printf("mem_calcul : %f\n", *mem_calcul);
    //printf("%f", mem_calcul);

    return myOxy;

}



