// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: lecture des donnees envoyees par la carte de l'oxymetre

// Includes.
#include "lecture.h"

#define TAILLE_MAX 1000

//-------------------------------------------------------------------------
// Cette fonction ouvre le fichier test et lit les donnees contenues a l'interieur
// Retourne un tableau avec les valeurs ACr, DCr, ACir et DCir non filtrees

void Lecture_fichier (char CheminValeurs[40], int tab_non_filtre[4])
{

	FILE *fichier = NULL;


    //ouverture du fichier
    fichier = fopen(CheminValeurs, "r");

    //on verifie que l'on a bien ouvert le fichier
    if (fichier != NULL)
    {
        //reccuperation des donnees et entree dans le tableau
        fscanf(fichier, "%d,%d,%d,%d", &tab_non_filtre[0], &tab_non_filtre[1], &tab_non_filtre[2], &tab_non_filtre[3]);
        //affichage pour verification
        printf("\n----------\n Fonction Lecture_Fichier : \n----------\n\n");
        printf("ACr : %d, DCr : %d, ACir : %d, DCir : %d \n", tab_non_filtre[0], tab_non_filtre[1], tab_non_filtre[2], tab_non_filtre[3]);


        fclose(fichier); //fermeture du fichier
    }
    else
    {
        //si il y a impossibilité d'ouvrir le fichier, on le signale à l'utilisateur
        printf("Impossible d'ouvrir le fichier...\n");
    }
}

void LectureCoeffFIR (char cheminCoeffFIR[40], float coeffFIR[51])
{

	FILE *fichier = NULL;
    char valCoeff[TAILLE_MAX] = "";
    int i = 0;


    //ouverture du fichier
    fichier = fopen(cheminCoeffFIR, "r");

    //on verifie que l'on a bien ouvert le fichier
    if (fichier != NULL)
    {
        for(i=0; i<51; i++)
        {
            fgets(valCoeff, TAILLE_MAX, fichier);
            coeffFIR[i] = atof(valCoeff);
        }


        fclose(fichier); //fermeture du fichier
    }
    else
    {
        //si il y a impossibilité d'ouvrir le fichier, on le signale à l'utilisateur
        printf("Impossible d'ouvrir le fichier...\n");
    }
}
