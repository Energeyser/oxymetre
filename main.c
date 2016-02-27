// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#include "main.h"

int main()
{
    //declaration des variables
    char CheminFichier[40] = "./Data/record1/record1.dat"; //chemin vers le fichier de test
    int tab_non_filtre[4] = {0};
    int bufferFIR[51] = {0};
    int i = 0;


    Lecture_fichier(CheminFichier, tab_non_filtre); //lecture du fichier de test et remplissage du tableau avec les valeurs brutes

    //affichage pour verification du passage des valeurs de la fonction lecture vers le main
    printf("\n----------\n Fonction Main : \n----------\n\n");

    for ( i = 0; i < 4; i++ ) {
      printf( "tab_non_filtre[%d] : %d\n", i, tab_non_filtre[i]);
    }

    FIR(tab_non_filtre[0], tab_non_filtre[2], bufferFIR);



    return 0;
}
