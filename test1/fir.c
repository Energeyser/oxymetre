// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: filtrage fir


#include "fir.h"
#include "initMem.h"


absorp firTest(char* fileName){
    //initialisation des variables
    float acr, dcr, acir, dcir, x, y, ret;
    float** buffer = NULL;
    buffer = initMem(51,2);
    absorp indata, outdata;
    FILE* pf;
    pf=fopen(fileName,"r");
    if(pf==NULL){
            printf("Erreur lors de l'ouverture du fichier\n");
            exit(-3);
        }
    ret=fscanf(pf,"%d,%d,%d,%d,%c,%c", &acr, &dcr, &acir, &dcir, &x, &y);
    indata.acr=acr;
    indata.dcr=dcr;
    indata.acir=acir;
    indata.dcir=dcir;
    while(ret!=EOF){
        //tant que l'on est pas arrive a la fin du fichier on recupere les valeurs
        outdata=fir(indata, buffer); //appelle de la fonction
        ret=fscanf(pf,"%d,%d,%d,%d,%c,%c", &acr, &dcr, &acir, &dcir, &x, &y);
        indata.acr=acr;
        indata.dcr=dcr;
        indata.acir=acir;
        indata.dcir=dcir;
    }
    fclose(pf);
    return outdata;
}

absorp fir(absorp myAbsorp, float** buffer)
{
    float coeffFIR[51]={1.4774946e-019, 1.6465231e-004, 3.8503956e-004, 7.0848037e-004, 1.1840522e-003, 1.8598621e-003, 2.7802151e-003, 3.9828263e-003, 5.4962252e-003, 7.3374938e-003, 9.5104679e-003, 1.2004510e-002, 1.4793934e-002, 1.7838135e-002, 2.1082435e-002, 2.4459630e-002, 2.7892178e-002, 3.1294938e-002, 3.4578348e-002, 3.7651889e-002, 4.0427695e-002, 4.2824111e-002, 4.4769071e-002, 4.6203098e-002, 4.7081811e-002, 4.7377805e-002, 4.7081811e-002, 4.6203098e-002, 4.4769071e-002, 4.2824111e-002, 4.0427695e-002, 3.7651889e-002, 3.4578348e-002, 3.1294938e-002, 2.7892178e-002, 2.4459630e-002, 2.1082435e-002, 1.7838135e-002, 1.4793934e-002, 1.2004510e-002, 9.5104679e-003, 7.3374938e-003, 5.4962252e-003, 3.9828263e-003, 2.7802151e-003, 1.8598621e-003, 1.1840522e-003, 7.0848037e-004, 3.8503956e-004, 1.6465231e-004, 1.4774946e-019};
    int k,i = 0;
    float mem_fir[2] = {0};


    for(i=0;i<51;i++){
        if(i-1>=0){
            buffer[0][i-1] = buffer[0][i]; //decalage des valeurs

            buffer[1][i-1] = buffer[1][i];
        }
    }
    buffer[0][50] = myAbsorp.acr;
    buffer[1][50] = myAbsorp.acir;

    for(k=0;k<51;k++){
        mem_fir[0] += coeffFIR[k] * buffer[0][50-k];
        mem_fir[1] += coeffFIR[k] * buffer[1][50-k];
        myAbsorp.acr = mem_fir[0];
        myAbsorp.acir = mem_fir[1];
    }
    return myAbsorp;
}

