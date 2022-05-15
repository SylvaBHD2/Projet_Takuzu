//
// Created by lucas on 13/04/2022.
//

#include "P1.h"
#include <stdio.h>
#include<stdlib.h>
#include "P2.h"
#include "P3.h"



void entrerEssai(int **TabMask, int *tab,int taille){
    int col=-1, ligne=-1, chiffre=-1, i=0;
    while(col<=0 || col>taille || ligne>taille || ligne<=0 || (chiffre<0 || chiffre>1) || TabMask[ligne-1][col-1]==1) {
        if (i>0) {
//            printf("%d %d %d",ligne,col,TabMask[ligne][col]);
            printf("\nVariable impossible. Indiquez: [ ligne  colonne valeur ] : \n :");
        }
        scanf(" %d %d %d", &ligne, &col, &chiffre);
        i++;
    }
    ligne--,col--;
    tab[0] = ligne, tab[1]=col, tab[2]=chiffre;
}

int CoupValide(int ligne,int col,int essai,  int **Tab, int **TabMask,int taille) {
    // retourne 1 si le coup est correct, -1 si valide mais incorrect, et si faux 0
    if (Tab[ligne][col] == essai){
        return 1;}
    else {
        // algo de décision
        //pour les lignes
        if ((sommeLigne(Tab, TabMask, ligne, taille) == taille / 2) &&
            (nombreSignificatifLigne(TabMask, ligne, taille) >= taille / 2)) {
            printf("ligne non respectée 1");
            return 0;
        } else {
            if ((sommeLigne(Tab, TabMask, ligne, taille) == 0) &&
                (nombreSignificatifLigne(TabMask, ligne, taille) >= taille / 2)) {
                printf("ligne non respectée 2");
                return 0;
            }
            //condition particuliere pour les lignes
            if (sommeLigne(Tab, TabMask, ligne, taille) == 1 &&
                       (nombreSignificatifLigne(TabMask, ligne, taille) >= (taille / 2)+1)) {
                printf("la solution est evidente");
                return 0;
            }
            // pour les colonnes
            if ((sommeColonne(Tab, TabMask, col, taille) == taille / 2) &&
                (nombreSignificatifColonne(TabMask, col, taille) >= taille / 2)) {
                printf(" colonne non respectée 1");
                return 0;}
            else {
                if ((sommeColonne(Tab, TabMask, col, taille) == 0) &&
                    (nombreSignificatifColonne(TabMask, col, taille) >= taille / 2)) {
                    printf(" colonne non respectée 2");
                    return 0;
                }
                    //condition particuliere
                if (sommeColonne(Tab, TabMask, col, taille) == (taille / 2) - 1 &&
                           (nombreSignificatifColonne(TabMask, col, taille) == (taille / 2) + 1)) {
                    printf(" colonne non respectée 4 :%d == %d",nombreSignificatifColonne(TabMask, ligne, taille),(taille / 2) + 1);
                    return 0;
                }
                //condition particuliere
                if (sommeColonne(Tab, TabMask, col, taille) == 1 && (nombreSignificatifColonne(TabMask, col, taille) >= (taille / 2)+1)) {
                    printf("la solution est evidente 2");
                    return 0;
                }
            }
            // verif voisin
            if (verifierVoisinLigne(Tab, TabMask, ligne, col, taille) == 1) {
                // modulo pour inverser par rapport aux voisins
                if (essai == Tab[ligne][col + 1] % 2) {
                    printf("Regardez les voisins de ligne...");
                    return 0;
                }
            } else {
                if (verifierVoisinCol(Tab, TabMask, ligne, col, taille) == 1) {
                    // modulo pour inverser par rapport aux voisins
                    if (essai == Tab[ligne + 1][col] % 2) {
                        printf("Regardez les voisins de colonne...");
                        return 0;
                    }
                }
            }
            return (-1);
        }
    }
}

int revelerIndice(int** TabMask,int taille){
    for (int i = 0; i < taille; i++)
        for (int j = 0; j < taille; ++j) {
            if (TabMask[i][j]==0){
                TabMask[i][j]=1;
                return 1;
            }
        }
    return 0;
}

int jouer(int** Tab,int **TabMask,int taille) {
    printf("\n>---------------------------------<\nLa partie commence : \n");
    // affichage de la première grille
    int nbr_vies = 3;
    while (verifFin(TabMask, taille) == 0 && nbr_vies != 0) {
        printf("<----------------Debut du Tour------------------>\n\n");
        afficherGrilleMasquee(Tab, TabMask, taille);
        printf(" \n Que voulez vous faire? Indiquez: [ ligne  colonne valeur ] :\n :");
        // vérifie si le coup est valide
        int* try= (int*)malloc(sizeof(int)*3);
        entrerEssai(TabMask, try,taille);
//        printf("\n Le try : %d %d %d \n",try[0],try[1],try[2]);
        if (CoupValide(try[0], try[1], try[2], Tab , TabMask,taille) == 1){
            TabMask[try[0]][try[1]] = 1;
            printf("\nBRAVO! c'est la bonne reponse ! \n");}
        else if (CoupValide(try[0], try[1], try[2], Tab, TabMask, taille) == 0) {
            nbr_vies--;
            printf("\nAttention vous venez de perdre une vie. Restant : %d\n Pour vous aider, ajoutons un indice... \n", nbr_vies);
            revelerIndice(TabMask, taille);
        } else {
            revelerIndice(TabMask, taille);
            printf("\nLe coup est valide, mais ce n'est pas la réponse...\n");
        }
    }
    if (verifFin(TabMask, taille) == 1)
        printf("Vous avez fini le jeu, FELICITATIONS");
    if (nbr_vies == 0)
        printf("MALHEUREUSEMENT, c'est perdu !");
}


void P1(int choix){
    int taille=choix*4;
    int **Tab = creer_grille(taille,1);
    int** TabMask=(int**)malloc(sizeof(int*)*taille);
    masquerGrille(TabMask,taille);
    jouer(Tab,TabMask,taille);
    free(Tab);
    free(TabMask);
}
