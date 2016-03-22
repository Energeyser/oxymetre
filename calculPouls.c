#include "calculPouls.h"

float calculPouls (float periode){
        float pouls;
        pouls = 1/(periode*60);
    printf("pouls : %f\n", pouls);
        return pouls;
        }
