//
// Created by Buhard on 06/04/2022.
//

#ifndef PROJET_TAKUZU_P2_H
#define PROJET_TAKUZU_P2_H
#define T_4 4

int remplirGrille(int Tab[T_4][T_4],int size);
void afficherGrille(int tab[T_4][T_4], int size);
void masquerGrille(int tab[T_4][T_4],int size);
void afficherGrilleMasquee(int Tab[T_4][T_4],int TabMas[T_4][T_4], int size);
void afficherGrillePtr(int **Tab, int nbrLigne, int nbrCol);
void afficherLignePtr(int *Tab, int size) ;
int sommeLigne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col);
int sommeColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col);
int nombreSignificatifColonne(int TabMask[T_4][T_4], int col,int size);
int nombreSignificatifLigne(int TabMask[T_4][T_4], int ligne, int size);
int verifierVoisinLigne(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col);
int verifierVoisinCol(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col);
int verifFin(int TabMask[T_4][T_4],int size);
void resouGrille(int Tab[T_4][T_4],int TabMask[T_4][T_4],int size) ;
int comparerMatrice(int Tab[T_4][T_4],int Tab2[T_4][T_4],int ligne, int col);
void P2();

#endif //PROJET_TAKUZU_P2_H
