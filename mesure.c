#include "mesure.h"

oxy mesure(absorp myAbsorp, int** mem_calcul, oxy myOxy, val myVal)
{
    int periode;
    int ptpACR;
    int ptpACIR;
    float RsIR;
    float SpO2;
    if(passageZero<3){
        if(myAbsorp.ACR<0 && mem_calcul[0][1]>0){
            myVal.passageZero++;
        }
        else if(myAbsorp.ACR>0 && mem_calcul[0][1]<0){
            myVal.passageZero++;
        }
        if(passageZero>0){
            myVal.rang++;
            calculSpO2(periode, myOxy, myVal, myAbsorp);
        }
    }
    else{
        ptpACR=maxACR-minACR;
        ptpACIR=maxACIR-minACIR;
        RsIR=(ptpACR/myAbsorp.DCR)/(ptpACIR/myAbsorp.DCIR);
        if(RsIR>0.4 && RsIR<1){
            SpO2=-25*RsIR+110;
        }
        else if(RsIR>1 && RsIR<3.4){
            SpO2=-33.3*RsIR+113;
        }
        myOxy.SpO2= (int) SpO2;
        periode = rang*0.002;
        myOxy.pouls = calculPouls(periode, myOxy);
        rang=0;
        maxACR=0;
        minACR=0;
        maxACIR=0;
        minACIR=0;
    }
    mem_calcul[0][1] = myAbsorp.ACR;

}



