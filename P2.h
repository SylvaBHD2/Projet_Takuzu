//
// Created by Buhard on 06/04/2022.
//

#ifndef PROJET_TAKUZU_P2_H
#define PROJET_TAKUZU_P2_H
#define T_4 4
#define T_8 8


int remplirGrille(int Tab[T_4][T_4],int size);
void afficherGrille(int tab[T_4][T_4], int size);
void masquerGrille(int tab[T_4][T_4],int size);
void afficherGrilleMasquee(int Tab[T_4][T_4],int TabMas[T_4][T_4], int size);
int sommeLigne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col);
int sommeColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col);
int nombreSignificatifColonne(int TabMask[T_4][T_4], int col,int size);
int nombreSignificatifLigne(int TabMask[T_4][T_4], int ligne, int size);
int verifierVoisinLigne(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col);
int verifierVoisinCol(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col);
int verifFin(int TabMask[T_4][T_4],int size);
void resouGrille(int Tab[T_4][T_4],int TabMask[T_4][T_4],int size) ;
int comparerMatrice(int Tab[T_4][T_4],int Tab2[T_4][T_4],int ligne, int col);
int comparerMatrice(int Tab[T_4][T_4],int Tab2[T_4][T_4],int ligne, int col);
void P2();

int remplirGrille2(int Tab[T_8][T_8],int size);
void afficherGrille2(int tab[T_8][T_8], int size);
void masquerGrille2(int tab[T_8][T_8],int size);
void afficherGrilleMasquee2(int Tab[T_8][T_8],int TabMas[T_8][T_8], int size);
int sommeLigne2(int Tab[T_8][T_8], int TabMask[T_8][T_8], int ligne, int col);
int sommeColonne2(int Tab[T_8][T_8], int TabMask[T_8][T_8], int ligne, int col);
int nombreSignificatifColonne2(int TabMask[T_8][T_8], int col,int size);
int nombreSignificatifLigne2(int TabMask[T_8][T_8], int ligne, int size);
int verifierVoisinLigne2(int Tab[T_8][T_8],int TabMask[T_8][T_8], int ligne, int col);
int verifierVoisinCol2(int Tab[T_8][T_8],int TabMask[T_8][T_8], int ligne, int col);
int verifFin2(int TabMask[T_8][T_8],int size);
void resouGrille2(int Tab[T_8][T_8],int TabMask[T_8][T_8],int size) ;
int comparerMatrice2(int Tab[T_8][T_8],int Tab2[T_8][T_8],int ligne, int col);
int comparerMatrice2(int Tab[T_8][T_8],int Tab2[T_8][T_8],int ligne, int col);
#endif //PROJET_TAKUZU_P2_H
