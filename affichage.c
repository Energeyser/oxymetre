#include "affichage.h"
void affichage(oxy myOxy){
    FILE* fichier = NULL;

    fichier = fopen("Data.txt", "w+");

    if (fichier != NULL)
    {
        fprintf(fichier, "%d\n%d", myOxy.SpO2, myOxy.pouls);
        fclose(fichier);
    }

}
