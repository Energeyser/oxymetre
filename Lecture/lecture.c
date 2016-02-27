// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: lecture des donnees envoyees par la carte de l'oxymetre

// Includes.
#include "lecture.h"

//-------------------------------------------------------------------------
// Cette fonction ouvre le fichier test et lit les donnees contenues a l'interieur
// Retourne un tableau avec les valeurs ACr, DCr, ACir et DCir non filtrees

int* Lecture_fichier (char CheminFichier[40])
{
    static int tab_non_filtre[4] = {0,0,0,0};

	FILE *fichier;


    //ouverture du fichier
    fichier = fopen("./Data/record1/record1.dat", "r");

    //on verifie que l'on a bien ouvert le fichier
    if (fichier != NULL)
    {
        fscanf(fichier, "%d,%d,%d,%d", &tab_non_filtre[0], &tab_non_filtre[1], &tab_non_filtre[2], &tab_non_filtre[3]);
        printf("ACr : %d, DCr : %d, ACir : %d, DCir : %d \n", tab_non_filtre[0], tab_non_filtre[1], tab_non_filtre[2], tab_non_filtre[3]);


        fclose(fichier); //fermeture du fichier
    }
    else
    {
        printf("Impossible d'ouvrir le fichier...\n");
    }

	return tab_non_filtre;
}
