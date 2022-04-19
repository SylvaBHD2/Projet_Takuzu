//
// Created by lucas on 19/04/2022.
//

#include "P1.h"
#define T_4 4
#include "P2.h"

//int CoupValide(int i,int j,int essai, int TabMask[T_4][T_4] ,int TabSolution[T_4][T_4],size) {
//    // retourne 1 si le coup est correct, 0 si valide mais inccorect, et si faux
//    if (TabSolution[i][j] == essai)
//        return 1;
//    else {
//        // algo de décision
//        if (nombreSignificatifLigne(TabSolution,TabMask, ))
//            return -1;
//
//    return(0);
//}

void P1(){
    int Tab[T_4][T_4];
    remplirGrille(Tab,T_4);
    afficherGrille(Tab, T_4);
    masquerGrille(Tab, T_4);
}