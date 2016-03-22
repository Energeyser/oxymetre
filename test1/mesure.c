#include "mesure.h"

oxy mesureTest(char* fileName){
    float acr, dcr, acir, dcir, x, y, ret;
    oxy myOxy;
    myOxy.spo2=0;
    myOxy.pouls=0;
    int passageZero=1;
    int rang=0;
    float maxacr=0;
    float minacr=0;
    float maxacir=0;
    float minacir=0;
    float mem_calcul = 0;
    absorp indata;
    oxy outdata;
    FILE* pf;


    pf=fopen(fileName,"r");
    if(pf==NULL){
            printf("Erreur lors de l'ouverture du fichier\n");
        }
    ret=fscanf(pf,"%f,%f,%f,%f%c%c", &acr, &dcr, &acir, &dcir, &x, &y);
    indata.acr=acr;
    indata.dcr=dcr;
    indata.acir=acir;
    indata.dcir=dcir;
    while(ret!=EOF){
        myOxy=mesure(indata, &mem_calcul, myOxy, &passageZero, &rang, &maxacr, &minacr, &maxacir, &minacir);
        ret=fscanf(pf,"%f,%f,%f,%f%c%c", &acr, &dcr, &acir, &dcir, &x, &y);
        indata.acr=acr;
        indata.dcr=dcr;
        indata.acir=acir;
        indata.dcir=dcir;


    }
    fclose(pf);
    return myOxy;

}

oxy mesure(absorp myAbsorp, float* mem_calcul, oxy myOxy, int* pointeursurZero, int* rang,float* maxacr, float* minacr, float* maxacir, float* minacir)
{

    float periode;
    int ptpacr;
    int ptpacir;
    float RsIR;
    float spo2;
    float pouls;

        // Mise en memoire des valeurs min et max pour calcul de la valeur ptp

        if(myAbsorp.acr>*maxacr){
        *maxacr = myAbsorp.acr;
        }
        if(myAbsorp.acr<*minacr){
            *minacr = myAbsorp.acr;
        }
        if(myAbsorp.acir>*maxacir){
            *maxacir = myAbsorp.acir;
        }
        if(myAbsorp.acir<*minacir){
            *minacir = myAbsorp.acir;
        }

    // test du passage par zero pour calculer la periode
    if(*pointeursurZero<3){
        if(myAbsorp.acr<0 && *mem_calcul>0){
            *pointeursurZero = *pointeursurZero+1;
        }
        else if(myAbsorp.acr>0 && *mem_calcul<0){
            *pointeursurZero = *pointeursurZero+1;
        }
        if(*pointeursurZero>0){
            *rang = *rang + 1;

        }
    }

    // si on vient de passer la periode, on fait les calculs de SpO2 et du pouls et on reinitialise les variables
    else{
        // calcul des valeurs ptp
        ptpacr=*maxacr-*minacr;
        ptpacir=*maxacir-*minacir;

        // calcul du SpO2
        if(myAbsorp.dcr != 0 && myAbsorp.dcir != 0){
            RsIR=(ptpacr/myAbsorp.dcr)/(ptpacir/myAbsorp.dcir);
        }
        if(RsIR>0.4 && RsIR<1){
            spo2=-25*RsIR+110;
        }
        else if(RsIR>1 && RsIR<3.4){
            spo2=-33.3*RsIR+113;
        }
        myOxy.spo2= (int) spo2;

        // calcul du pouls
        periode = *rang*0.002;
        pouls = (1/periode)*60;
        myOxy.pouls= (int) pouls;
        // reinitialisation des variables
        *rang=0;
        *maxacr=0;
        *minacr=0;
        *maxacir=0;
        *minacir=0;
        *pointeursurZero = 1;

    }
    *mem_calcul = myAbsorp.acr;

    return myOxy;
}
