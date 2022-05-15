//
// Created by Buhard on 06/04/2022.
//

#ifndef PROJET_TAKUZU_P2_H
#define PROJET_TAKUZU_P2_H


void masquerGrille(int **tab,int taille);
void afficherGrilleMasquee(int **Tab, int **Tabmask, int taille);
void afficherGrille(int **Tab, int nbrLigne, int nbrCol);
void afficherLignePtr(int *Tab, int taille) ;
int sommeLigne(int **Tab, int **TabMask, int ligne, int taille);
int sommeColonne(int **Tab, int **TabMask, int col, int taille);
int nombreSignificatifColonne(int **TabMask, int col,int taille);
int nombreSignificatifLigne(int **TabMask, int ligne, int taille);
int verifierVoisinLigne(int **Tab,int **TabMask , int ligne, int col,int taille);
int verifierVoisinCol(int **Tab,int **TabMask, int ligne, int col,int taille);
int verifSuiteCol(int **Tab, int **TabMask, int ligne, int col, int taille);
int verifSuiteLigne(int **Tab, int **TabMask, int ligne, int col, int taille);
int verifFin(int **TabMask,int taille);
void resGrille(int **Tab, int **TabMask, int taille) ;
void P2(int choix);

#endif //PROJET_TAKUZU_P2_H
