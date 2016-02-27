// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016
// Role: fonction principale du projet


int main()
{
    //declaration des variables
    char CheminFichier[40] = "./Data/record1/record1.dat"; //chemin vers le fichier de test
    int* tab_non_filtre = NULL; //pointeur vers les valeurs brutes
    int i = 0;


    tab_non_filtre = Lecture_fichier(CheminFichier); //lecture du fichier de test et remplissage du tableau avec les valeurs brutes

    //affichage pour verification du passage des valeurs de la fonction lecture vers le main
    for ( i = 0; i < 4; i++ ) {
      printf( "*(tab_non_filtre + %d) : %d\n", i, *(tab_non_filtre + i));
    }

    return 0;
}
