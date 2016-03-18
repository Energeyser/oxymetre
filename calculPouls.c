#include "calculPouls.h"

int calculPouls (int periode, oxy myOxy){
        float pouls;
        pouls = 1/(periode*60);
        myOxy.pouls= (int) pouls;
        return myOxy.pouls;
        }
