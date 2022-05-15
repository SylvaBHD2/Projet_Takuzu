//
// Created by lucas on 19/04/2022.
//

#ifndef PROJET_TAKUZU_P1_H
#define PROJET_TAKUZU_P1_H
#define T_4 4
#define T_8 8

void entrerEssai(int **TabMask, int *tab);
int CoupValide(int i,int j,int essai,int **Tab,int** TabMask ,int taille) ;
int revelerIndice(int **TabMask,int taille);
int jouer(int **Tab,int **TabMask,int taille);
void P1(int taille);
#endif //PROJET_TAKUZU_P1_H
