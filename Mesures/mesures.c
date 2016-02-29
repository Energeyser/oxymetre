#include "mesure.h"

void Mesure(float tab_histo[5000], int DCr, int DCir, int* spo2, int* fcard)
{
    int passageZero=0;
    int rang=1;
    int debutPeriode=0;
    int finPeriode=0;
    while(passageZero < 3){
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
