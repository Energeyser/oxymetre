// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet

#include "main.h"

int main()
{
    //declaration des variables
    char CheminValeurs[40] = "./Data/record1/record1.dat"; //chemin vers le fichier de test
    char CheminCoeffFIR[40] = "./Data/coeff.dat"; //chemin vers le fichier de test
    int tab_non_filtre[4] = {0};
    float bufferFIR[2][51] = {0};
    int rangBufferFIR = 0;
    float coeffFIR[51] = {0};
    int i, ligne = 0;

    LectureCoeffFIR(CheminCoeffFIR, coeffFIR);

    while(ligne<5000){
        Lecture_fichier(CheminValeurs, tab_non_filtre, ligne); //lecture du fichier de test et remplissage du tableau avec les valeurs brutes
        ligne ++;

        //affichage pour verification du passage des valeurs de la fonction lecture vers le main
        printf("\n----------\n Fonction Main : \n----------\n\n");

        for ( i = 0; i < 4; i++ ) {
          printf( "tab_non_filtre[%d] : %d\n", i, tab_non_filtre[i]);
        }

        //on recentre grossierement les valeurs AC autour de 0
        tab_non_filtre[0] -= 2048;
        tab_non_filtre[2] -= 2048;

        //affichage pour verification du passage des valeurs de la fonction lecture vers le main
        printf("\n----------\n Fonction Main : \n----------\n\n");

        for ( i = 0; i < 4; i++ ) {
          printf( "tab_non_filtre[%d] recentre : %d\n", i, tab_non_filtre[i]);
        }

        FIR(tab_non_filtre[0], tab_non_filtre[2], bufferFIR, rangBufferFIR, coeffFIR);
        if (rangBufferFIR<51){
            rangBufferFIR++;
        } else if (rangBufferFIR == 51){
            rangBufferFIR = 0;
        }

        printf("\n----------\n Fonction Main : \n----------\n\n");
        printf( "rangBufferFIR : %d\n",rangBufferFIR);
               for ( i = 0; i < 51; i++ ) {
            printf( "bufferFIR[0][%d] (ACr FIR)  : %f\n",i, bufferFIR[0][i]);
            printf( "bufferFIR[1][%d] (ACir FIR) : %f\n", i,bufferFIR[1][i]);
               }
    }
    return 0;
}
