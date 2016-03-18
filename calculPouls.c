#include "calculPouls.h"

int calculPouls (int periode, struct oxy myOxy){
            myOxy.pouls = 1/(periode*60);
            return myOxy.pouls;
        }
