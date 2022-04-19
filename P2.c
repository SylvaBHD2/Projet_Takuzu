//
// Created by Buhard on 06/04/2022.
//
#include <stdio.h>
#include "P2.h"
#include <stdlib.h>
#define T_4 4

//fonctions
int remplirGrille(int Tab[T_4][T_4],int size){
    //crée une grille
    //**Tab = (int **) malloc(size * sizeof(int *));
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
           Tab[i][j]=0;
        }
    }
}

void afficherGrille(int tab[T_4][T_4], int size){
    printf("\n");
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
            printf(" |%d|\t", tab[i][j] );
        }
        printf("\n");
    }
}

int masquerGrille(int tab[T_4][T_4],int size){
    // retourne le tableau mais en masqué de manière aleatoire( 1/2 chance)
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
            if (rand()%2)
                tab[i][j]=0;
            else
                tab[i][j]=1;
        }
    }
    return tab;
}
/*
void afficherGrilleMasquee(int Tab[T_4][T_4],int TabMas[T_4][T_4], int size){
    printf("\n");
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
            if (TabMas[i][j]==1)
                printf(" |%d|\t", Tab[i][j] );
            else
                printf("  \t");
        }
        printf("\n");
    }
}

// sert a la résolution auto
int sommeLigne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col){
    //calcule la some d'une ligne d'une matrice 4x4 de facon récursive
    if (col==0 && TabMask[ligne][col]==1)
        return (Tab[ligne][col]);
    if (TabMask[ligne][col]==1)
        return Tab[ligne][col]+sommeLigne(Tab, TabMask, ligne, col - 1);
    return(Tab[ligne][col] + sommeLigne(Tab, TabMask, ligne, col - 1));
}

int sommeColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col){
    //calcule la some d'une ligne d'une matrice 4x4 de facon récursive
    if (col==0 && TabMask[ligne][col]==1)
        return (Tab[ligne][col]);
    if (TabMask[ligne][col]==1)
        return Tab[ligne][col]+sommeColonne(Tab, TabMask, ligne-1, col);
    return(Tab[ligne][col] + sommeColonne(Tab, TabMask, ligne-1, col));
}

int voisins(int Tab[T_4])[T_4], int ligne, int col){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose,
    int voisinLigne [2]={0,0};
    int voisinCol [2]={0,0};
    if (tab[ligne][col-1]==tab[ligne][col+1])
        return 1;
    if (tab[ligne-1][col] == tab[ligne+1][col])
        return 1;
    return 0;
}

int CoupValide(int i,int j,int essai, int Tab[T_4][T_4] ,int TabSolution[T_4][T_4],size) {
    // retourne 1 si le coup est correct, 0 si valide mais inccorect, et si faux
    if (TabSolution[i][j] == essai)
        return 1;
    else {
        // algo de décision
        if (sommeLigne(Tab, i, size) == 2 || sommeLigne(Tab, size, j) == 2)
            if (essai==1)
                printf("Coupe valide");
        else if (sommeLigne(Tab, i, size) == 1 || sommeLigne(Tab, size, j) == 1)
                printf("Coupe valide");
    }
    return(-1);
}

// marche pas car il faut que il manque le nbr de case pleine (si somme =2 mais 2 0)
void resoudreGrille(int Tab[T_4][T_4],int TabMask[T_4][T_4], int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (TabMask[i][j]!=1){
                printf(" Opération sur la case %d %d :", i,j);

                if (sommeligne)
            }
        }
    }
}

int comparerMatrice(int Tab[T_4][T_4],int Tab2[T_4][T_4],int ligne, int col){
    //retourne 1 si les 1 et 0 sont bien placés, 0 sinon (prends le masque en compte)

    for (int i = 0; i < T_4; ++i) {
        for (int j = 0; j < T_4; ++j) {
            if (Tab[i][j] != Tab2[i][j]) {
                return 0;
            }
            return 1;
        }

        int comparerMatrice(int Tab[T_4][T_4],int Tab2[T_4][T_4],int ligne, int col){
    //retourne 1 si les 1 et 0 sont bien placés, 0 sinon (prends le masque en compte)
    if (Tab[i][j] != Tab2[i][j])
        return 0;
    return 1;
        }

int nombreSignificatif(int Tab[T_4][T_4]) {
    //retourne le nbr de 0 et de 1 dans une colonne
    int nbrZero=0,nbrUn=0;
    int sol[2]={nbrZero,nbrUn};
    return sol;
}


//fonction principale
void P2(){
    int Tab[T_4][T_4];
    remplirGrille(Tab,T_4);
    afficherGrille(Tab, T_4);
    masquerGrille()
}*/