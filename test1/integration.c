#include "define.h"
#include "mesure.h"
#include "lecture.h"
#include "fir.h"
#include "iir.h"
#include "mesure.h"
#include "affichage.h"
#include "initMem.h"
#include "integration.h"

void integrationTest(char* fileName)
{
    float acr, dcr, acir, dcir, x, y, ret;
    absorp myAbsorp;
    oxy myOxy;
    myOxy.spo2=0;
    myOxy.pouls=0;
    int passageZero=1;
    int rang=1;
    float maxACR=0;
    float minACR=0;
    float maxACIR=0;
    float minACIR=0;
    int etat = 1;
    float** buffer = NULL;
    float** mem_iir = NULL;
    int i = 0;
    absorp indata;
    FILE* pf;
    float mem_calcul = 0;


    buffer = initMem(51,2);
    mem_iir = initMem(2,2);


    pf=fopen(fileName,"r");
    if(pf==NULL){
            printf("Erreur lors de l'ouverture du fichier\n");

        }

    ret=fscanf(pf,"%d,%d,%d,%d,%c,%c", &acr, &dcr, &acir, &dcir, &x, &y);
    indata.acr=acr;
    indata.dcr=dcr;
    indata.acir=acir;
    indata.dcir=dcir;
    while(etat==1){

        myAbsorp = lecture(pf ,&etat);

        myAbsorp = fir(myAbsorp, buffer);

        myAbsorp = iir(myAbsorp, mem_iir);

        myOxy = mesure(myAbsorp, &mem_calcul, myOxy, &passageZero, &rang, &maxACR, &minACR, &maxACIR, &minACIR);


        affichage(myOxy);
        printf("spo2: %d , pouls: %d\n", myOxy.spo2, myOxy.pouls);

    }
    fclose(pf);
    finMem(mem_iir, 2);
    finMem(buffer, 2);

}

void finMem(float** tab, int x){
    int i = 0;

    for(i=0 ; i < x ; i++){
        free(tab[i]);
    }

    free(tab);
    tab = NULL;
}

