#include "iir.h"
#include "initMem.h"

absorp iirTest(char* fileName){
    float acr, dcr, acir, dcir, x, y, ret;
    float** mem_iir = NULL;
    absorp indata, outdata;
    FILE* pf;

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
    printf("test1\n");
    while(ret!=EOF){
        outdata=iir(indata, mem_iir);
        ret=fscanf(pf,"%d,%d,%d,%d,%c,%c", &acr, &dcr, &acir, &dcir, &x, &y);
        indata.acr=acr;
        indata.dcr=dcr;
        indata.acir=acir;
        indata.dcir=dcir;
    }
    fclose(pf);
    return outdata;
}


absorp iir(absorp myAbsorp, float** mem_iir){
    mem_iir[0][1] = myAbsorp.acr - mem_iir[0][0] + 0.992 * mem_iir[0][1];
    mem_iir[1][1] = myAbsorp.acir - mem_iir[1][0] + 0.992 * mem_iir[1][1];

    mem_iir[0][0] = myAbsorp.acr;
    mem_iir[1][0] = myAbsorp.acir;

    myAbsorp.acr = mem_iir[0][1];
    myAbsorp.acir = mem_iir[1][1];

    return myAbsorp;
}


