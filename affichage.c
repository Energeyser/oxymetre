#include "affichage.h"
void affichage(oxy myOxy){
    FILE* fichier = NULL;
    FILE* verrou = NULL;


    verrou = fopen(".verrouData", "w");

    if (verrou == NULL)
    {
        verrou = fopen(".verrouData", "w");
        fichier = fopen("Data.txt", "w+");
        fprintf(fichier, "%d\n%d", myOxy.SpO2, myOxy.pouls);
        fclose(fichier);
    }
    fclose(verrou);

}
