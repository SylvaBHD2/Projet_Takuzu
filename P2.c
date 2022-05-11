//
// Created by Buhard on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "P2.h"
#include "P1.h"
#include <time.h>
#define T_4 4
#define T_8 8

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

int remplirGrille2(int Tab[T_8][T_8],int size){
    //crée une grille
//    int Tabsol[T_8][T_8];
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
            Tab[i][j]=0;
        }
    }
    return 0;
}


void afficherGrille(int tab[T_4][T_4], int size){
    // afficher la grille
    printf("\n");
    for (int i = 0 ; i < size ; i++){
        for (int j = 0; j < size; j++) {
            printf(" |%d|\t", tab[i][j] );
        }
        printf("\n");
    }
}

void afficherGrille2(int tab[T_8][T_8], int size){
    // afficher la grille
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

void masquerGrille2(int tab[T_8][T_8],int size){
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
//    return (int) tab[T_8][T_8];
}

void afficherGrilleMasquee(int Tab[T_4][T_4],int TabMas[T_4][T_4], int size){
    // Si la grille du masque en coordonnées (i,j) =  1 alors la grille principale est masquée sur ces coordonnées
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

void afficherLignePtr( int* Tab, int size) {
    printf("\n");
    for (int j = 0; j < size; j++) {
        printf(" |%d|\t", *(Tab + j));
    }
}

void afficherGrillePtr(int **Tab, int nbrLigne, int nbrCol){
    printf("\n entree dans la fonction");
    for (int i = 0 ; i < nbrLigne ; i++){
        afficherLignePtr((int *) (Tab + i), nbrCol);
        printf("fin de l'affichage");
        printf("\n");
    }
}

void afficherGrilleMasquee2(int Tab[T_8][T_8],int TabMas[T_8][T_8], int size){
    // Si la grille du masque en coordonnées (i,j) =  1 alors la grille principale est masquée sur ces coordonnées
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
int sommeLigne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int size){
    int somme=0;
    for (int i=0; i<size;i++){
        somme+=TabMask[ligne][i]*Tab[ligne][i];
    }
    return somme;
}

int sommeLigne2(int Tab[T_8][T_8], int TabMask[T_8][T_8], int ligne, int size){
    int somme=0;
    for (int i=0; i<size;i++){
        somme+=TabMask[ligne][i]*Tab[ligne][i];
    }
    return somme;
}

int sommeColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int col, int size){
    int somme=0;
    for (int i=0; i<size;i++){
        somme+=TabMask[i][col]*Tab[i][col];
    }
    return somme;
}

int sommeColonne2(int Tab[T_8][T_8], int TabMask[T_8][T_8], int col, int size){
    int somme=0;
    for (int i=0; i<size;i++){
        somme+=TabMask[i][col]*Tab[i][col];
    }
    return somme;
}

int nombreSignificatifColonne(int TabMask[T_4][T_4], int col, int size){
    //retourne le nbr de 1  et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i<size;i++){
        if (TabMask[i][col]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifColonne2(int TabMask[T_8][T_8], int col, int size){
    //retourne le nbr de 1  et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i<size;i++){
        if (TabMask[i][col]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifLigne(int TabMask[T_4][T_4], int ligne,int size){
    //retourne le nbr de 1 et de 0 découverts dans une colonne
    int nbrUn=0;
    for (int i=0; i<size;i++){
        if (TabMask[ligne][i]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifLigne2(int TabMask[T_8][T_8], int ligne,int size){
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

int verifierVoisinLigne2(int Tab[T_8][T_8],int TabMask[T_8][T_8], int ligne, int col){
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

int verifierVoisinCol2(int Tab[T_8][T_8],int TabMask[T_8][T_8], int ligne, int col) {
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

int verifFin2(int TabMask[T_8][T_8],int size){
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
                    printf(" >---------------------------------------< \n");
                    afficherGrilleMasquee(Tab,TabMask,size);
                    printf("\npret pour la prochaine action? \n");
                    //uniquement pour appuyer bouton
                    scanf(" %d", &t);
                    printf(" Opération sur la case %d %d :\n", i, j);
                    printf(" \n Le tour: smligne %d  nbrsiniline %d", sommeLigne(TabMask, TabMask, i, size - 1),
                           nombreSignificatifLigne(TabMask, i,size));
                    printf(" \n Le tour: smcol %d  nbrsinicol %d\n", sommeColonne(TabMask, TabMask, j, size - 1),
                           nombreSignificatifColonne(TabMask, j,size));
                    // attention plusiers changements possibles avec voisin
                    if ((sommeLigne(TabMask, TabMask, j, size - 1) == 2) && (nombreSignificatifLigne(TabMask, i,size) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" solution 0 trouvee grace a sommeligne");
                    }
                    else{
                        if ((sommeLigne(TabMask, TabMask, j, size - 1) == 0)&&(nombreSignificatifLigne(TabMask, i, size) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace a sommeline");
                        }
                    }
                    // essai avc somme des colonnes
                    if ((sommeColonne(TabMask, TabMask, j, size - 1) == 2) &&
                        (nombreSignificatifColonne(TabMask, j,size) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" solution 0 trouvee grace à sommeligne");
                    }
                    else {
                        if ((sommeColonne(TabMask, TabMask, j, size - 1) == 0) &&
                            (nombreSignificatifColonne(TabMask, j, size) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace à sommecol");
                        }
                    }
                    // verif voisins
                    if (idc == 0) {
                        if (verifierVoisinLigne(Tab, TabMask, i, j) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = TabMask[i][j] = TabMask[i][j + 1] % 2;
                            printf(" solution trouvee grace a voisin line ");
                        }
                        else {
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
                        printf("validation du changement dans le tableau");
                    }
                    else
                        printf("%d ",CoupValide(i, j, essai, Tab, TabMask, size)) ;
                    afficherGrilleMasquee(Tab, TabMask, size);
                    printf("\n<----fin du tour---->\n");
                }
            }
        }
    }
}

void resouGrille2(int Tab[T_8][T_8],int TabMask[T_8][T_8],int size) {

    while (verifFin2(TabMask, size) != 1) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                // dès qu'il y a un 0
                if (TabMask[i][j] != 1) {
                    int idc = 0, essai = -1;
                    int t = 0;
                    printf(" >---------------------------------------< \n");
                    afficherGrilleMasquee2(Tab,TabMask,size);
                    printf("\npret pour la prochaine action? \n");
                    //uniquement pour appuyer bouton
                    scanf(" %d", &t);
                    printf(" Opération sur la case %d %d :\n", i, j);
                    printf(" \n Le tour: smligne %d  nbrsiniline %d", sommeLigne2(TabMask, TabMask, i, size - 1),
                           nombreSignificatifLigne2(TabMask, i,size));
                    printf(" \n Le tour: smcol %d  nbrsinicol %d\n", sommeColonne2(TabMask, TabMask, j, size - 1),
                           nombreSignificatifColonne2(TabMask, j,size));
                    // attention plusiers changements possibles avec voisin
                    if ((sommeLigne2(TabMask, TabMask, j, size - 1) == 2) && (nombreSignificatifLigne2(TabMask, i,size) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" solution 0 trouvee grace a sommeligne");
                    }
                    else{
                        if ((sommeLigne2(TabMask, TabMask, j, size - 1) == 0)&&(nombreSignificatifLigne2(TabMask, i, size) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace a sommeline");
                        }
                    }
                    // essai avc somme des colonnes
                    if ((sommeColonne2(TabMask, TabMask, j, size - 1) == 2) &&
                        (nombreSignificatifColonne2(TabMask, j,size) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" solution 0 trouvee grace à sommeligne");
                    }
                    else {
                        if ((sommeColonne2(TabMask, TabMask, j, size - 1) == 0) &&
                            (nombreSignificatifColonne2(TabMask, j, size) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace à sommecol");
                        }
                    }
                    // verif voisins
                    if (idc == 0) {
                        if (verifierVoisinLigne2(Tab, TabMask, i, j) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = TabMask[i][j] = TabMask[i][j + 1] % 2;
                            printf(" solution trouvee grace a voisin line ");
                        }
                        else {
                            if (verifierVoisinCol2(Tab, TabMask, i, j) == 1) {
                                // modulo pour inverser par rapport aux voisins
                                essai = TabMask[i][j] = TabMask[i + 1][j] % 2;
                                idc++;
                                printf(" solution trouvee grace a voisin col");
                            }
                        }
                    }
                    //voir si une solution a été trouvée
                    printf("\n SOLUTION : %d avec %d\n", essai,idc);
                    if (CoupValide2(i, j, essai, Tab, TabMask, size)) {
                        TabMask[i][j] = 1;
                        printf("validation du changement dans le tableau");
                    }
                    else
                        printf("%d ",CoupValide2(i, j, essai, Tab, TabMask, size)) ;
                    afficherGrilleMasquee2(Tab, TabMask, size);
                    printf("\n<----fin du tour---->\n");
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

int comparerMatrice2(int Tab[T_8][T_8],int Tab2[T_8][T_8],int ligne, int col){
    //retourne 1 si les 1 et 0 sont bien placés, 0 sinon (prends le masque en compte)
    for (int i = 0; i < T_8; ++i) {
        for (int j = 0; j < T_8; ++j) {
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