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
    int i, fcard, spo2 = 0;
    int ligne = 0;
    float tab_histo[2][5000] = {0};

    printf("ligne  : %d\n",ligne);

    LectureCoeffFIR(CheminCoeffFIR, coeffFIR);

    printf("lecture ok \n");
    while(ligne<5000){
        Lecture_fichier(CheminValeurs, tab_non_filtre, ligne); //lecture du fichier de test et remplissage du tableau avec les valeurs brutes
        ligne ++;

        //on recentre grossierement les valeurs AC autour de 0
        tab_non_filtre[0] -= 2048;
        tab_non_filtre[2] -= 2048;

        FIR(tab_non_filtre[0], tab_non_filtre[2], bufferFIR, coeffFIR, tab_filtre_FIR);


        IIR(tab_filtre_IIR, tab_filtre_FIR);

        for(i=0;i<5000;i++){
            if(i+1<5000){
                tab_histo[0][i+1] = tab_histo[0][i];
                tab_histo[1][i+1] = tab_histo[1][i];
            }
        }
        //pb au niveau de tab_filtre_IIR qui est bon dans la fct IIR mais pas dans le main
        printf("blbl : %d\n", tab_filtre_IIR[0]);
        tab_histo[0][0] = tab_filtre_IIR[0];
        tab_histo[1][0] = tab_filtre_IIR[1];
       Mesure(tab_histo,tab_filtre_IIR[0], tab_filtre_IIR[0], &spo2, &fcard);
    }
    return 0;
}
