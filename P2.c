//
// Created by Buhard on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "P1.h"
#include "P2.h"
#include "P3.h"


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

int verifierVoisinLigne(int **Tab ,int** TabMask, int ligne, int col,int taille) {
    if (col==0 || col==(taille-1))
        return 0;
    if ((TabMask[ligne][col + 1] == 1) && (TabMask[ligne][col - 1] == 1)) {
        if (Tab[ligne][col - 1] == Tab[ligne][col + 1])
            return 1;
    }
    return 0;
}

int verifierVoisinCol(int **Tab,int **TabMask, int ligne, int col,int taille){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose, sinon 0
    if (ligne==0 || ligne==(taille-1))
        return 0;
    if (TabMask[ligne+1][col]==1 && TabMask[ligne-1][col]==1) {
        if (Tab[ligne + 1][col] == Tab[ligne - 1][col])
            return 1;
    }
    return 0;
}

int verifSuiteCol(int **Tab, int **TabMask, int ligne, int col, int taille){
    // regarde les voisins immédiats, et retourne 1 ou -1 si c'est possible d'en déduire qlqchose, sinon 0 ,
    if (ligne >= taille-2){
        if (TabMask[ligne-1][col]==1 && TabMask[ligne-2][col]==1)
            if (Tab[ligne-1][col] == Tab[ligne-2][col]){
                return -1;}
        return 0;}
    if (ligne<=1){
        if (TabMask[ligne+1][col]==1 && TabMask[ligne+2][col]==1)
            if (Tab[ligne+1][col] == Tab[ligne+2][col]){
                return 1;}
        return 0;}
    //autres cas
    if (TabMask[ligne-1][col]==1 && TabMask[ligne-2][col]==1 ){
        if (Tab[ligne-1][col] == Tab[ligne-2][col])
            return -1;
    }
    if (TabMask[ligne+1][col]==1 && TabMask[ligne+2][col]==1 )
        if (Tab[ligne+1][col] == Tab[ligne+2][col]){
            return 1;}
    return 0;
}

int verifSuiteLigne(int **Tab, int **TabMask, int ligne, int col, int taille){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose, sinon 0 sinon -1
    if (col>=taille-2){
        if (TabMask[ligne][col-1]==1 && TabMask[ligne][col-2]==1)
            if (Tab[ligne][col-1] == Tab[ligne][col-2])
                return -1;
        return 0;}
    if (col<=1){
        if (TabMask[ligne][col+1]==1 && TabMask[ligne][col+2]==1)
            if (Tab[ligne][col+1] == Tab[ligne][col+2])
                return 1;
        return 0;}
    //autres cas
    if (TabMask[ligne][col-1]==1 && TabMask[ligne][col-2]==1 ){
        if (Tab[ligne][col-1] == Tab[ligne][col-2]){
            return -1;}
        }
    if (TabMask[ligne][col+1]==1 && TabMask[ligne][col+2]==1 ){
        if (Tab[ligne][col+1] == Tab[ligne][col+2]){
            return 1;}
    }
    return 0;
}


int verifFin(int **TabMask,int taille){
    //retourne 1 si la matrice ne contiens aucune zone masquée
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
                    afficherGrilleMasquee(Tab, TabMask, taille);
                    printf("  - Operation sur la case %d %d :\n", i + 1, j + 1);
                    int Somme_ligne = sommeLigne(Tab, TabMask, i, taille);
                    int Somme_col = sommeColonne(Tab, TabMask, j, taille);
                    printf("\nL'ordinateur reflechit... Pret? (tapez 1) \n");
                    scanf(" %d", &retour_utilisateur);
                    if ((Somme_ligne == taille / 2) && (nombreSignificatifLigne(TabMask, i, taille) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" Solution : 0 (somme de la ligne) ");
                    } else {
                        if (Somme_ligne == 0 && (nombreSignificatifLigne(TabMask, i, taille) >= taille / 2)) {
                            idc++;
                            essai = 1;
                            printf(" Solution : 1 (somme de la ligne) ");
                        }
                        else
                            if (Somme_ligne == 1 &&
                                   (nombreSignificatifLigne(TabMask, i, taille) >= (taille / 2) + 1)){
                            essai = 1, idc++;
                            printf(" Solution : 1 ( ligne evidente)");
                            }
                            else{ if (nombreSignificatifLigne(TabMask, i, taille)==taille-1 && (nombreSignificatifLigne(TabMask, i, taille)-Somme_ligne)==taille/2){
                                    essai = 1, idc++;
                                    printf(" Solution : 1 ( ligne evidente)");
                                }
                            }


                        }
                    // essai avc somme des colonnes
                    if (Somme_col == taille / 2 && (nombreSignificatifColonne(TabMask, j, taille) >= taille / 2)) {
                        essai = 0;
                        idc++;
                        printf(" Solution: 0  (somme de la colonne)");
                    }
                    else {
                        if ((Somme_col == 0) && (nombreSignificatifColonne(TabMask, j, taille) >= taille / 2)) {
                            idc++;
                            essai = 1;
                            printf(" Solution 1 ( somme de la colonne)");
                        } else if (Somme_col == 1 &&
                                   (nombreSignificatifColonne(TabMask, j, taille) >= (taille) / 2 + 1)) {
                            essai = 1, idc++;
                            printf(" Solution : 1 ( colonne evidente car %d-1 zeros)",
                                   (nombreSignificatifColonne(TabMask, i, taille)));
                        } else {
                            if (nombreSignificatifColonne(TabMask, j, taille)==taille-1 && (nombreSignificatifColonne(TabMask, j, taille) - Somme_ligne) == taille / 2) {
                                essai = 1, idc++;
                                printf(" Solution : 1 ( colonne evidente)");
                            }
                        }
                    }
                    // verif voisins
                    if (idc == 0) {
                        if (verifierVoisinLigne(Tab, TabMask, i, j, taille) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = (Tab[i][j + 1] + 1) % 2;
                            idc++;
                            printf(" Solution %d(voisins dans la ligne) ", essai);
                        } else {
                            if (verifierVoisinCol(Tab, TabMask, i, j, taille) == 1) {
                                // modulo pour inverser par rapport aux voisins
                                essai = (Tab[i + 1][j] + 1) % 2;
                                idc++;
                                printf(" Solution : %d(voisins dans la colonne)", essai);
                            }
                        }
                        if (verifSuiteCol(Tab, TabMask, i, j, taille) != 0) {
                            essai = (Tab[i + verifSuiteCol(Tab, TabMask, i, j, taille)][j] + 1) % 2;
                            printf(" Solution :%d (voisins consecutifs dans la colonne) : %d", essai,
                                   (Tab[i][j + verifSuiteCol(Tab, TabMask, i, j, taille)] + 1));
                            idc++;
                        } else {
                            if (verifSuiteLigne(Tab, TabMask, i, j, taille) != 0) {
                                printf("calcul de lalias");
                                int alias = j+verifSuiteLigne(Tab, TabMask, i, j, taille);
                                essai = (Tab[i][alias] + 1) % 2;
                                printf(" Solution : %d (voisins consecutifs dans la ligne) voisin= %d i: %d et j : %d",
                                       essai, (Tab[i][alias]),i, alias);
                                idc++;
                            }
                        }
                    }
                    //voir si une solution a été trouvée ou si le bot est bloqué
                    if (antiblocage >= taille/2 && essai == -1) {
                        printf("Le Bot donne un coup au hasard, pour se debloquer...\n");
                        essai = rand() % 2;
                        antiblocage = 0;
                    }
                    //verification de la solution
                    if (essai != -1) {
                        if (CoupValide(i, j, essai, Tab, TabMask, taille) == 1) {
                            TabMask[i][j] = 1;
                            printf("Validation du changement dans le tableau :");
                            antiblocage = 0;
                        }
                        else if(!CoupValide(i, j, essai, Tab, TabMask, taille) && idc != 0)
                            printf("IL A RATE  : %d ", CoupValide(i, j, essai, Tab, TabMask, taille));

                    }
                    else {
                        if (idc == 0) {
                            antiblocage++;
                            printf("Impossible de savoir pour cette case a cet instant...");
                        }
                    }
                }
            }
        }
    }
    printf("\n ><----------------FIN----------------><\nVoila, c'est fini!\n");
    afficherGrille(Tab,taille,taille);
}


//fonction principale
void P2(int choix){
    int** Tab;
    int taille=choix*4;
    Tab= creer_grille(taille,1);
    int **TabMask=(int**)malloc(sizeof(int*)*taille);
    masquerGrille(TabMask,taille);
    printf("La partie commence, l'ordinateur voit la meme chose que vous:\n");
    masquerGrille(TabMask,taille);
    resGrille(Tab, TabMask, taille);
}