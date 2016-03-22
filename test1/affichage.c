// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction d'affichage du programme

#include "affichage.h"
void affichage(oxy myOxy){
    FILE* fichier = NULL;
    FILE* verrou = NULL;


    //on teste si le verrou existe
    if( access( ".verrouData", F_OK ) != -1 )
    {
        //si il existe, on ne fait rien
    }else{
        //si le verrou n'existe pas, on le cree afin de proteger le fichier data.txt lors de la modification
        verrou = fopen(".verrouData", "w");
        fichier = fopen("Data.txt", "w+");
        fprintf(fichier, "%d\n%d", myOxy.spo2, myOxy.pouls);
        fclose(fichier);
        fclose(verrou);
        remove(".verrouData") ;//suppression du fichier verrou une fois que les valeurs ont ete modifiees
    }

}
