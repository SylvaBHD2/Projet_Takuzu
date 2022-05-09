//
// Created by lucas on 19/04/2022.
//

#ifndef PROJET_TAKUZU_P1_H
#define PROJET_TAKUZU_P1_H
#define T_4 4

int entrerEssai(int Tab[T_4][T_4],int TabMask[T_4][T_4]);
int CoupValide(int i,int j,int essai, int TabMask[T_4][T_4] ,int Tab[T_4][T_4],int size) ;
int revelerIndice(int TabMask[T_4][T_4],int size);
int jouer(int Tab[T_4][T_4],int TabMask[T_4][T_4],int size);

void P1();
#endif //PROJET_TAKUZU_P1_H
