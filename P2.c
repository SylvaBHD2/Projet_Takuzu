//
// Created by Buhard on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "P2.h"
#define T_4 4

//fonctions
int remplirGrille(int Tab[T_4][T_4],int size){
    //crée une grille
    int Tabsol[T_4][T_4];
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
           Tab[i][j]=0;
        }
    }
    return Tab;
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

int nombreSignificatifLigne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col,int size){
    //retourne le nbr de 1  et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i<size;i++){
        if (TabMask!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col,int size){
    //retourne le nbr de 1 et de 0 découverts dans une colonne
    int nbrUn=0;
    for (int i=0; i<size;i++){
        if (TabMask!=0)
            nbrUn++;
    }
    return nbrUn;
}

int verifierVoisinLigne(int Tab[T_4][T_4],TabMask[T_4][T_4], int ligne, int col){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose, sinon 0
    if (TabMask[ligne+1][col]==1 && TabMask[ligne-1][col]==1) {
        if (Tab[ligne + 1][col] == Tab[ligne - 1][col])
            return 1;
    }
    return 0;
}

int verifierVoisinCol(int Tab[T_4][T_4],TabMask[T_4][T_4], int ligne, int col) {
    if (TabMask[ligne][col + 1] == 1 && TabMask[ligne][col + 1] == 1) {
        if (Tab[ligne][col - 1] == Tab[ligne][col + 1])
            return 1;
    }
    return 0;
}

int verifFin(int TabMask[T_4][T_4],int size){
    //retourne 1 si la patrice ne contiens aucune zone masquée
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (TabMask[i][j]==0)
                return 0;
        }
    }
    return 1;
}

// marche pas car il faut que il manque le nbr de case pleine (si somme =2 mais 2 0)
void resouGrille(int Tab[T_4][T_4],int TabMask[T_4][T_4], int col, int ligne,int size) {

    while (verifFin(TabMask,size)!=1) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                // dès qu'il y a un 0
                if (TabMask[i][j] != 1) {
                    printf(" Opération sur la case %d %d :", i, j);
                    // attention plusiers changements possibles avec voisin
                    if ((sommeLigne(TabMask[i][j], TabMask[i][j], j, j) == 2) && (nombreSignificatifLigne(Tab,TabMask,i,j,size)==2)){
                        TabMask[i][j] = 0;
                        printf(" solution trouvée");
                        afficherGrilleMasquee(Tab,TabMask,size);
                    }
                    else {
                        if ((sommeLigne(TabMask[i][j], TabMask[i][j], j, j) == 0) && (nombreSignificatifLigne(Tab,TabMask,i,j,size)==2)){

                            TabMask[i][j] = 1;
                            printf(" solution trouvée");
                            afficherGrilleMasquee(Tab,TabMask,size);
                        }
                    }
                    // verif voisin peux y avoir un pb
                    if (verifierVoisinLigne(Tab,TabMask,ligne,col)==1){
                        // modulo pour inverser par rapport aux voisins
                        TabMask[i][j]=TabMask[i][j+1]%2;
                        printf(" solution trouvée");
                        afficherGrilleMasquee(Tab,TabMask,size);
                    }
                    else {
                        if (verifierVoisinCol(Tab,TabMask,ligne,col)==1){
                            // modulo pour inverser par rapport aux voisins
                            TabMask[i][j]=TabMask[i+1][j]%2;
                            printf(" solution trouvée");
                            afficherGrilleMasquee(Tab,TabMask,size);
                        }
                    }
                }
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
    }
}

//fonction principale
void P2(){
    int Tab[T_4][T_4];
    remplirGrille(Tab,T_4);
    afficherGrille(Tab, T_4);
    masquerGrille();
}