#include "mesures.h"

void Mesure(float tab_histo[2][5000], int DCr, int DCir, int* spo2, int* fcard)
{
    int passageZero, periode, temp = 0;
    int rang=1;
    int debutPeriode=0;
    int finPeriode=0;

    while(rang < 5000){
        //printf("tab_histo[rang] : %f\n", tab_histo[rang]);
        if(passageZero < 3){
        if(tab_histo[rang-1]<0 && tab_histo[rang]>0){
            passageZero++;
            if(passageZero==1){
                debutPeriode=rang;
            }
            else if(passageZero==3){
                finPeriode=rang;
            }
        }
        else if(tab_histo[rang-1]>0 && tab_histo[rang]<0){
            passageZero++;
             if(passageZero==1){
                debutPeriode=rang;
            }
            else if(passageZero==3){
                finPeriode=rang;
            }
        }
    rang++;
        }
    }

    //printf("finperiode : %d \n", finPeriode);
    //printf("debutperiode : %d \n", debutPeriode);
    //periode=(finPeriode-debutPeriode);
    //temp = 1/(periode*120000);
    //fcard=&temp;
    //printf("fcard: %d \n", &fcard);
}
