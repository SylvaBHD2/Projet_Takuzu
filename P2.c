//
// Created by Buhard on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "P1.h"
#include "P2.h"
#include "P3.h"
#define T_4 4
#define T_8 8

void afficherGrille(int**Tab, int nbrLigne, int nbrCol){
    // Si la grille du masque en coordonnées (i,j) =  1 alors la grille principale est masquée sur ces coordonnées
    printf("\n\t");
    for(int i=0; i<nbrCol;i++)
        printf("--------");
    printf("\n");
    for (int i = 0 ; i < nbrLigne ; i++){
        printf("\t|");
        for (int j = 0; j < nbrCol; j++) {
            printf("   %d   |", Tab[i][j] );
        }
        printf("\n\t");
        for(int k=0; k<nbrCol;k++) {
            printf("--------");
        }
        printf("\t\n");
    }
}

void masquerGrille(int **tab,int taille){
    // retourne un tableau rempli de 0 ou de 1 avec 50/50 de chance
    for (int i = 0 ; i < taille ; i++){
        int* temp = (int*) malloc(taille*sizeof(int));
        for (int j = 0; j < taille; j++) {
            if (rand()%2) {
                temp[j]=0;
            }
            else {
                temp[j]=1;
            }
        }
        tab[i]=temp;
    }
}

void afficherGrilleMasquee(int**Tab, int **Tabmask, int taille){
    // Si la grille du masque en coordonnées (i,j) =  1 alors la grille principale est masquée sur ces coordonnées*
    printf("\t");
    for(int i=0; i<taille;i++)
        printf("--------");
    printf("\n");
    for (int i = 0 ; i < taille ; i++){
        printf("\t|");
        for (int j = 0; j < taille; j++) {
            if (Tabmask[i][j] == 1){
                printf("   %d   |", Tab[i][j] );;
            }
            else
                printf("       |");
        }
        printf("\n\t");
        for(int k=0; k<taille;k++) {
            printf("--------");
        }
        printf("\t\n");
    }
}


void afficherLignePtr( int* Tab, int taille) {
    printf("\n");
    for (int j = 0; j < taille; j++) {
        printf(" |%d|\t", *(Tab + j));
    }
}

// sert a la résolution auto
int sommeLigne(int **Tab, int **TabMask, int ligne, int taille){
    int somme = 0;
    for (int i = 0; i < taille; i++){
        somme += Tab[ligne][i] * TabMask[ligne][i];
//        printf("\nSomme de la ligne: Tab[%d][%d] == %d",ligne,i,Tab[ligne][i] * TabMask[ligne][i]);
    }
    return somme;
}

int sommeColonne(int **Tab, int **TabMask, int col, int taille){
    int somme=0;
    for (int i=0; i<taille;i++){
        somme += Tab[i][col]*TabMask[i][col];
//        printf("\nSomme de la col: Tab[%d][%d] == %d",i,col,Tab[i][col] * TabMask[i][col]);
    }
    return somme;
}

int nombreSignificatifColonne(int **TabMask, int col, int taille){
    //retourne le nbr de 1  et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i < taille; i++){
        if (TabMask[i][col]!=0)
            nbrUn++;
    }
    return nbrUn;
}


int nombreSignificatifLigne(int **TabMask, int ligne, int taille){
    //retourne le nbr de 1 et de 0 découverts dans une colonne
    int nbrUn=0;
    for (int i=0; i<taille;i++){
        if (TabMask[ligne][i]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int verifierVoisinCol(int **Tab,int **TabMask, int ligne, int col,int taille){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose, sinon 0
    if (ligne==0 || ligne==taille)
        return 0;
    if (TabMask[ligne+1][col]==1 && TabMask[ligne-1][col]==1) {
        if (Tab[ligne + 1][col] == Tab[ligne - 1][col])
            return 1;
    }
    return 0;
}

int verifierVoisinLigne(int **Tab ,int** TabMask, int ligne, int col,int taille) {
    if (col==0 || col==taille)
        return 0;
    if ((TabMask[ligne][col + 1] == 1) && (TabMask[ligne][col - 1] == 1)) {
        if (Tab[ligne][col - 1] == Tab[ligne][col + 1])
            return 1;
    }
    return 0;
}


int verifFin(int **TabMask,int taille){
    //retourne 1 si la patrice ne contiens aucune zone masquée
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (TabMask[i][j]==0)
                return 0;
        }
    }
    return 1;
}


void resGrille(int **Tab, int** TabMask, int taille) {
    int antiblocage=0;
    while (verifFin(TabMask, taille) != 1) {
        for (int i = 0; i < taille; ++i) {
            for (int j = 0; j < taille; ++j) {
                // dès qu'il y a un 0
                if (TabMask[i][j] != 1) {
                    int idc = 0, essai = -1;
                    int retour_utilisateur = 0;
                    printf(" \n>-------------------Tour suivant-------------------< \n ");
                    afficherGrilleMasquee(Tab,TabMask,taille);
                    printf("  - Operation sur la case %d %d :\n", i+1, j+1);
                    int Somme_ligne = sommeLigne(Tab, TabMask, i, taille) ;
                    int Somme_col=sommeColonne(Tab, TabMask, j, taille ) ;
                    printf("\nL'ordinateur reflechi... Pret? (tapez 1) \n");
                    scanf(" %d", &retour_utilisateur);
                    if ((Somme_ligne == taille/2) && (nombreSignificatifLigne(TabMask, i,taille) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" Solution : 0 (somme de la ligne) ");
                    }
                    else {
                        if (Somme_ligne==0 &&(nombreSignificatifLigne(TabMask, i, taille) >= taille/2)) {
                            idc++;
                            essai = 1;
                            printf(" Solution : 1 trouvee (somme de la ligne) ");
                        }
                        else if (Somme_ligne==1 &&(nombreSignificatifLigne(TabMask, i, taille) == 3)){
                            essai=1,idc++;
                            printf(" Solution : 1 ( ligne evidente)");}
                    }
                    // essai avc somme des colonnes
                    if (Somme_col == taille/2 && (nombreSignificatifColonne(TabMask, j,taille) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" Solution: 0  (somme de la colonne)");
                    }
                    else {
                        if ((Somme_col == 0) &&(nombreSignificatifColonne(TabMask, j, taille) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" Solution 1 ( somme de la colonne)");
                        }
                        else if (Somme_col==1 &&(nombreSignificatifColonne(TabMask, i, taille) == 3)){
                            essai=1,idc++;
                            printf(" Solution : 1 ( colonne evidente)");}
                    }
                    // verif voisins
                    if (idc == 0) {
                        if (verifierVoisinLigne(Tab, TabMask, i, j,taille) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = Tab[i][j + 1]+1 % 2;
                            printf(" Solution (voisins dans la ligne) ");
                        }
                        else {
                            if (verifierVoisinCol(Tab, TabMask, i, j,taille) == 1) {
                                // modulo pour inverser par rapport aux voisins
                                essai = Tab[i + 1][j]+1 % 2;
                                idc++;
                                printf(" Solution (voisins dans la colonne)");
                            }
                        }
                    }
                    //voir si une solution a été trouvée
                    if (antiblocage >= 1 && essai==-1){
                        essai=rand()%2;
                        printf("Le Bot donne un coup au hasard, pour se debloquer...\n");
                        antiblocage=0;}
                    //verification de la solution
                    if (essai != -1){
                        printf("\n Il a fait son choix : %d\n", essai);
                        if (CoupValide(i, j, essai, Tab, TabMask, taille)==1) {
                            TabMask[i][j] = 1;
                            printf("Validation du changement dans le tableau :");
                            antiblocage=0;
                        }
                        else if (!CoupValide(i, j, essai, Tab, TabMask, taille) && idc != 0)
                                printf("IL A RATE  : %d ", CoupValide(i, j, essai, Tab, TabMask, taille));
                            else {
                                if (idc == 0){
                                    antiblocage++;
                                    printf("Rien n'a pu etre trouvé pour cette case...");}
                                else
                                    printf("Il s'est trompé mais le coup etait valide...");
                            }
                    }
                    else{
                        printf("Il n'est pas possible de savoir maintenant sur cette case...");
                    }
                }
            }
        }
    }
    printf("\n ><------------------FIN-------------><\nVoila, c'est fini!\n");
}

//fonction principale
void P2(int choix){
    int** Tab;
    int taille=choix*4;
    Tab= creer_grille(taille,1);
    int **TabMask=(int**)malloc(sizeof(int*)*taille);
    masquerGrille(TabMask,taille);
    printf("la partie commence, l'ordinateur voit la meme chose que vous:\n");
    masquerGrille(TabMask,taille);
    resGrille(Tab, TabMask, taille);
}