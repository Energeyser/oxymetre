#include "mesure.h"

struct oxy mesure(struct absorp myAbsorp, int** mem_calcul, struct oxy myOxy)
{
    int periode;
    int passageZero=0;
    int rang=0;
    int maxACR=0;
    int minACR=0;
    int maxACIR=0;
    int minACIR=0;
    int ptpACR;
    int ptpACIR;
    float RsIR;
    if(passageZero<3){
        if(myAbsorp.ACR<0 && mem_calcul[0][1]>0){
            passageZero++;
        }
        else if(myAbsorp.ACR>0 && mem_calcul[0][1]<0){
            passageZero++;
        }
        if(passageZero>0){
            rang++;
            myOxy.SpO2=calculSpO2(periode, myOxy, maxACR, minACR, maxACIR, minACIR, myAbsorp);
        }
    }
    else{
        ptpACR=maxACR-minACR;
        ptpACIR=maxACIR-minACIR;
        RsIR=(ptpACR/myAbsorp.DCR)/(ptpACIR/myAbsorp.DCIR);
        if(RsIR>0.4 && RsIR<1){
            myOxy.SpO2=-25*RsIR+110;
        }
        else if(RsIR>1 && RsIR<3.4){
            myOxy.SpO2=-33.3*RsIR+113;
        }
        periode = rang*0.002;
        myOxy.pouls = calculPouls(periode, myOxy);
        //myOxy.SpO2 = calculSpO2(periode, myOxy);
        rang=0;
        maxACR=0;
        minACR=0;
        maxACIR=0;
        minACIR=0;
    }
    mem_calcul[0][1] = myAbsorp.ACR;

}



