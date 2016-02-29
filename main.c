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
    float tab_filtre_FIR[2][2] = {0};
    float tab_filtre_IIR[2] = {0};
    int bufferFIR[2][51] = {0};
    float coeffFIR[51] = {0};
    int i, ligne = 0;
    int tab_histo[2][5000] = {0};

    LectureCoeffFIR(CheminCoeffFIR, coeffFIR);

    while(ligne<5000){
        Lecture_fichier(CheminValeurs, tab_non_filtre, ligne); //lecture du fichier de test et remplissage du tableau avec les valeurs brutes
        ligne ++;

        //affichage pour verification du passage des valeurs de la fonction lecture vers le main
        /*printf("\n----------\n Fonction Main : \n----------\n\n");

        for ( i = 0; i < 4; i++ ) {
          printf( "tab_non_filtre[%d] : %d\n", i, tab_non_filtre[i]);
        }*/

        //on recentre grossierement les valeurs AC autour de 0
        tab_non_filtre[0] -= 2048;
        tab_non_filtre[2] -= 2048;

        //affichage pour verification du passage des valeurs de la fonction lecture vers le main
        /*printf("\n----------\n Fonction Main : \n----------\n\n");

        for ( i = 0; i < 4; i++ ) {
          printf( "tab_non_filtre[%d] recentre : %d\n", i, tab_non_filtre[i]);
        }*/

        FIR(tab_non_filtre[0], tab_non_filtre[2], bufferFIR, coeffFIR, tab_filtre_FIR);

        printf("\n----------\n Fonction Main : \n----------\n\n");
        printf("Ligne : %d\n",ligne);
        printf( "ACr filtre FIR : %f\n",tab_filtre_FIR[0][0]);
        printf( "ACir filtre FIR : %f\n",tab_filtre_FIR[0][1]);
        printf( "ACr filtre FIR - 1 : %f\n",tab_filtre_FIR[1][0]);
        printf( "ACir filtre FIR - 1 : %f\n",tab_filtre_FIR[1][1]);
               for ( i = 0; i < 51; i++ ) {
            //printf( "bufferFIR[0][%d] (ACr FIR)  : %f\n",i, bufferFIR[0][i]);
            //printf( "bufferFIR[1][%d] (ACir FIR) : %f\n", i,bufferFIR[1][i]);
               }

        IIR(tab_filtre_IIR, tab_filtre_FIR);
        for(i=0;i<5000;i++){
            if(i+1<5000){
                tab_histo[0][i+1] = tab_histo[0][i];
                tab_histo[1][i+1] = tab_histo[1][i];
            }
        }
        tab_histo[0][5000] = tab_filtre_IIR[0];
        tab_histo[1][5000] = tab_filtre_IIR[1];

        printf( "ACr filtree IIR : %f\n",tab_filtre_IIR[0]);
        printf( "ACir filtree IIR : %f\n",tab_filtre_IIR[1]);
    }
    return 0;
}
