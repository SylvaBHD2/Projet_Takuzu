//
// Created by Buhard on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "P2.h"
#include "P1.h"
#include <time.h>
#define T_4 4

//fonctions
int remplirGrille(int Tab[T_4][T_4],int size){
    //crée une grille
//    int Tabsol[T_4][T_4];
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
           Tab[i][j]=0;
        }
    }
    return 0;
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

void masquerGrille(int tab[T_4][T_4],int size){
    // retourne un tableau rempli de 0 ou de 1 avec 50/50 de chance

    srand( time( NULL ) );
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
            if (rand()%2)
                tab[i][j]=0;
            else
                tab[i][j]=1;
        }
    }
//    return (int) tab[T_4][T_4];
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
//    printf("Entrée dans someligne");
    if (col==0)
        return (Tab[ligne][col]*TabMask[ligne][col]);
    else
        return(Tab[ligne][col]*TabMask[ligne][col] + sommeLigne(Tab, TabMask, ligne, col - 1));
}

int sommeColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col){
//    printf("Entrée dans somecol");
    //calcule la some d'une ligne d'une matrice 4x4 de facon récursive
    if (ligne==0)
        return (Tab[ligne][col]*TabMask[ligne][col]);
    else
        return(Tab[ligne][col]*TabMask[ligne][col]+sommeLigne(Tab, TabMask, ligne-1, col));
}

int nombreSignificatifLigne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col, int size){
    //retourne le nbr de 1  et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i<size;i++){
        if (TabMask[i][col]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int col,int size){
    //retourne le nbr de 1 et de 0 découverts dans une colonne
    int nbrUn=0;
    for (int i=0; i<size;i++){
        if (TabMask[ligne][i]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int verifierVoisinLigne(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose, sinon 0
    if (TabMask[ligne+1][col]==1 && TabMask[ligne-1][col]==1) {
        if (Tab[ligne + 1][col] == Tab[ligne - 1][col])
            return 1;
    }
    return 0;
}

int verifierVoisinCol(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col) {
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
void resouGrille(int Tab[T_4][T_4],int TabMask[T_4][T_4],int size) {

    while (verifFin(TabMask, size) != 1) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                // dès qu'il y a un 0
                if (TabMask[i][j] != 1) {
                    int idc = 0, essai = -1;
                    int t = 0;
//                    printf(" >---------------------------------------< \n");
//                    afficherGrilleMasquee(Tab,TabMask,size);
                    printf(" >---------------------------------------< \npret pour la prochaine action? \n");
                    scanf(" %d", &t);
                    printf(" Opération sur la case %d %d :\n", i, j);
                    printf(" \n Le tour: smligne %d  nbrsiniline %d", sommeLigne(TabMask, TabMask, j, size - 1),
                           nombreSignificatifLigne(Tab, TabMask, i, j,
                                                   size));
                    printf(" \n Le tour: smcol %d  nbrsinicol %d", sommeColonne(TabMask, TabMask, j, size - 1),
                           nombreSignificatifColonne(Tab, TabMask, i, j,
                                                     size));
                    // attention plusiers changements possibles avec voisin
                    if ((sommeLigne(TabMask, TabMask, j, size - 1) == 2) && (nombreSignificatifLigne(Tab, TabMask, i, j,
                                                                                                     size) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" solution 0 trouvee grace à sommeligne");
                    } else {
                        if ((sommeLigne(TabMask, TabMask, j, size - 1) == 0) &&
                            (nombreSignificatifLigne(Tab, TabMask, i, j, size) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace à sommeline");
                        }
                    }
                    // essai avc somme des colonnes
                    if ((sommeColonne(TabMask, TabMask, j, size - 1) == 2) &&
                        (nombreSignificatifColonne(Tab, TabMask, i, j,
                                                   size) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" solution 0 trouvee grace à sommeligne");
                    }
                    else {
                        if ((sommeColonne(TabMask, TabMask, j, size - 1) == 0) &&
                            (nombreSignificatifColonne(Tab, TabMask, i, j, size) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace à sommecol");
                        }
                    }
                    // verif voisins
                    if (idc != 0) {
                        if (verifierVoisinLigne(Tab, TabMask, i, j) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = TabMask[i][j] = TabMask[i][j + 1] % 2;
                            printf(" solution trouvee grace a voisin line ");
                        } else {
                            if (verifierVoisinCol(Tab, TabMask, i, j) == 1) {
                                // modulo pour inverser par rapport aux voisins
                                essai = TabMask[i][j] = TabMask[i + 1][j] % 2;
                                idc++;
                                printf(" solution trouvee grace a voisin col");
                            }
                        }
                    }
                    //voir si une solution a été trouvée
                    printf("\n SOLUTION : %d avec %d\n", essai,idc);
                    if (CoupValide(i, j, essai, Tab, TabMask, size)) {
                        TabMask[i][j] = 1;
                        printf("valid");
                    }
                    afficherGrilleMasquee(Tab, TabMask, size);
                    printf("\n<-------->\n");
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

    int Tab[T_4][T_4] = {{0,0,1,1},
                         {1,1,0,0},
                         {0,1,1,0},
                         {1,0,0,1},
    };
    int TabMask[T_4][T_4];
    afficherGrille(Tab, T_4);
    masquerGrille(TabMask,T_4);
    afficherGrille(TabMask,T_4);
    afficherGrilleMasquee(Tab,TabMask,T_4);
    resouGrille(Tab,TabMask,T_4);
}