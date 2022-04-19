//
// Created by lucas on 19/04/2022.
//

#include "P1.h"
#define T_4 4
#include "P2.h"

void P1(){
    int Tab[T_4][T_4];
    remplirGrille(Tab,T_4);
    Tab[1][2]=1;
    Tab[2][1]=1;
    Tab[2][3]=1;
    afficherGrille(Tab, T_4);
    masquerGrille(Tab, T_4);
}