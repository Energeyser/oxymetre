#include "affichage.h"
#include <unistd.h>


void affichage(oxy myOxy){
    FILE* fichier = NULL;
    FILE* verrou = NULL;


    if( access( ".verrouData", F_OK ) != -1 )
    {

    }else{
        verrou = fopen(".verrouData", "w");
        fichier = fopen("Data.txt", "w+");
        fprintf(fichier, "%d\n%d", myOxy.SpO2, myOxy.pouls);
        fclose(fichier);
        fclose(verrou);
        remove(".verrouData") ;
    }
}
