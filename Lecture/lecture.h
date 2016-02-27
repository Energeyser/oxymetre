// Projet: Oxymetre
// Auteurs: Axel AUBRY - Pierre PICARD
// Date de creation: 27/02/2016


#ifndef LECTURE_H
#define LECTURE_H

// Includes.
#include "../main.h"


void Lecture_fichier (char CheminValeurs[40], int tab_non_filtre[4], int ligne);
void LectureCoeffFIR(char CheminCoeffFIR[40], float coeffFIR[51]);

#endif
