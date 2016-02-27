#include <stdio.h>
#include <stdlib.h>

int main()
{
    char CheminFichier[40] = "./Data/record1/record1.dat";
    int* tab_non_filtre = NULL;
    int i = 0;

    tab_non_filtre = Lecture_fichier(CheminFichier);

      for ( i = 0; i < 4; i++ ) {
      printf( "*(tab_non_filtre + %d) : %d\n", i, *(tab_non_filtre + i));
   }

    return 0;
}
