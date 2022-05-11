//
// Created by lucas on 19/04/2022.
//

#ifndef PROJET_TAKUZU_P1_H
#define PROJET_TAKUZU_P1_H
#define T_4 4
#define T_8 8

int enterEssai(int Tab[T_4][T_4],int TabMask[T_4][T_4],int tab[3]);
int enterEssai2(int Tab[T_8][T_8],int TabMask[T_8][T_8],int tab[3]);
int CoupValide(int i,int j,int essai, int TabMask[T_4][T_4] ,int Tab[T_4][T_4],int size) ;
int CoupValide2(int i,int j,int essai, int TabMask[T_8][T_8] ,int Tab[T_8][T_8],int size) ;
int revelerIndice(int TabMask[T_4][T_4],int size);
int revelerIndice2(int TabMask[T_8][T_8],int size);
int jouer(int Tab[T_4][T_4],int TabMask[T_4][T_4],int size);
int jouer2(int Tab[T_8][T_8],int TabMask[T_8][T_8],int size);
void P1(int choix);
#endif //PROJET_TAKUZU_P1_H
