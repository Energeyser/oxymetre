// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: lecture des donnees envoyees par la carte de l'oxymetre
// Includes.
#include "lecture.h"
#define TAILLE_MAX 21
absorp lecture(FILE* fichier, int* etat)
{
    //declaration des variables
    absorp myAbsorp;
    int i, j= 0;
    char c_ACR[5], c_DCR[5], c_ACIR[5], c_DCIR[5];
    c_ACR[4] = '\0';
    c_DCR[4] = '\0';
    c_ACIR[4] = '\0';
    c_DCIR[4] = '\0';
    int virgule = 0;
    int x=0;
    char caractere;
    //on verifie que le fichier n'est pas termine
if(*etat != EOF){
    // on parcours une ligne complete (21 caracteres)
    for(i=0; i<21; i++){
        // on crée un compteur qui permet de remplir chaque caractere (de 0 à 3)
        if(j>3){
            j=0;
        }
        //printf("j %d\n", j);
        // on reccupere le dernier caractere
        caractere = fgetc(fichier);
        // si c'est une virgule, on incremente le compteur de virgules
        if(caractere == ','){
            //printf("virgule++\n");
            virgule ++;
            j=0;
        }else if (caractere == EOF){ // si le caractere signale la fin du fichier, on change l'etat et on sort de la boucle
            //printf("EOF\n");
            *etat = EOF;
            i = 100;
        }else if (caractere == '\r' || caractere == '\n'){ // si on arrive a la fin de la ligne
            //printf("r\n");
            if(virgule < 3){ // et si on a pas reccupere 4 valeurs
                //printf("virgule : %d\n", virgule);
                for(i=0; i<4; i++){ // on reinitialise les caracteres (on annule la ligne)
                    c_ACR[i] = 0;
                    c_DCR[i] = 0;
                    c_ACIR[i] = 0;
                    c_DCIR[i] = 0;
                }
                x=0;
                // et on reinitialise le compteur de la ligne et le compteur de virgules
                virgule = 0;
                i=0;
            }else if(x == 1){ // sinon on sort de la boucle (passage a la ligne suivante)
                //printf("i=100\n");
                i=100;
                x=0;
            }
            j=0;
            x++;
        }
        else{ // si on a pas de caracteres autres que des chiffres
            if(virgule == 0){ // premier nombre -> ACR
                //printf("caractere = %c\n", caractere);
                c_ACR[j] = caractere;
                j++;
                //printf("c_ACR = %s\n", c_ACR);
            }
            if(virgule == 1){ // 2eme nombre -> DCR
                //printf("caractere = %c\n", caractere);
                c_DCR[j] = caractere;
                j++;
                // printf("c_DCR = %s\n", c_DCR);
            }
            if(virgule == 2){ // 3eme nombre -> ACIR
                //printf("caractere = %c\n", caractere);
                c_ACIR[j] = caractere;
                j++;
                //printf("c_ACIR = %s\n", c_ACIR);
            }
            if(virgule == 3){ // 4eme nombre -> DCIR
                //printf("caractere = %c\n", caractere);
                c_DCIR[j] = caractere;
                j++;
                // printf("c_DCIR = %s\n", c_DCIR);
            }
            // on transforme les caracteres en flottants et on les integre dans une structure
            // on fait egalement le recentrage pour les valeurs AC
            myAbsorp.acr = atof(c_ACR) - 2048;
            myAbsorp.dcr = atof(c_DCR);
            myAbsorp.acir = atof(c_ACIR) - 2048;
            myAbsorp.dcir = atof(c_DCIR);
        }
    }
}
    //printf("ACR : %f, DCR : %f, ACIR : %f; DCIR : %f\n", myAbsorp.ACR, myAbsorp.DCR, myAbsorp.ACIR, myAbsorp.DCIR);


    //on retourne la structure contenant les valeurs
    return myAbsorp;
}
