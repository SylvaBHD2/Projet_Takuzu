//
// Created by lucas on 13/04/2022.
//

#include "P1.h"
#include <stdio.h>
#include<stdlib.h>
#include "P2.h"
#include "P3.h"


void entrerEssai(int **TabMask, int *tab,int taille){
    // cette fonction permet au joueur d'interagir avec la matrice
    int col=-1, ligne=-1, chiffre=-1, i=0;
    //saisie sécurisée
    while(col<=0 || col>taille || ligne>taille || ligne<=0 || (chiffre<0 || chiffre>1) || TabMask[ligne-1][col-1]==1) {
        if (i>0) {
//            printf("%d %d %d",ligne,col,TabMask[ligne][col]);
            printf("\nVariable impossible. Indiquez: [ ligne  colonne valeur ] : \n :");
        }
        scanf(" %d %d %d", &ligne, &col, &chiffre);
        i++;
    }
    // pour plus d'ergonomie, le joueur entre visuellement les coordonées, non comme en algorithmique
    ligne--,col--;
    tab[0] = ligne, tab[1]=col, tab[2]=chiffre;
}

int CoupValide(int ligne,int col,int essai,  int **Tab, int **TabMask,int taille) {
    // La fonction retourne 1 si le coup est correct, -1 si valide mais incorrect, et 0 si invalide
    if (Tab[ligne][col] == essai){
        return 1;}
    //decision pour coup correct ou incorrect
    else {
        //pour les lignes
        // il faut quatre '1' par ligne
        if ((sommeLigne(Tab, TabMask, ligne, taille) == taille / 2) &&
            (nombreSignificatifLigne(TabMask, ligne, taille) >= taille / 2)) {
            printf("Ligne non respectée ");
            if (essai == 1) {
                printf("Regardez le nombre de 1...");
                return 0;
            }
        }
        else {
            //il faut quatre '0' par ligne
            if ((sommeLigne(Tab, TabMask, ligne, taille) == 0) &&
                (nombreSignificatifLigne(TabMask, ligne, taille) >= taille / 2)) {
                if (essai == 0) {
                    printf("Regardez le nombre de 0...");
                    return 0;
                }
            }
            //condition particuliere ou il n'y a plus que des '1' a ajouter
            if (sommeLigne(Tab, TabMask, ligne, taille) == 1 &&
                       (nombreSignificatifLigne(TabMask, ligne, taille) >= (taille / 2)+1)) {
                if (essai == 1) {
                    printf("Regardez le nombre de 0...");
                    return 0;
                }
            }
            // pour les colonnes verifier le nombre de 1
            if ((sommeColonne(Tab, TabMask, col, taille) == taille / 2) &&
                (nombreSignificatifColonne(TabMask, col, taille) >= taille / 2)) {
                if (essai == 1) {
                    printf("Regardez le nombre de 1...");
                    return 0;
                }
            }
            else {
                // il ne faut pas plus de quatre '0'
                if ((sommeColonne(Tab, TabMask, col, taille) == 0) &&
                    (nombreSignificatifColonne(TabMask, col, taille) >= taille / 2)) {
                    if (essai == 0) {
                        printf("Regardez le nombre de 0...");
                        return 0;
                    }
                }
                //condition particuliere: dans le cas ou il ne reste que des 1 à poser
                if (sommeColonne(Tab, TabMask, col, taille) == (taille / 2) - 1 &&
                           (nombreSignificatifColonne(TabMask, col, taille) == (taille / 2) + 1)) {
                    if (essai == 0) {
                        printf(" colonne non respectée...");
                        return 0;
                    }
                }
                //condition particuliere : dans le cas ou il ne reste que des 1 à poser dans la colonne
                if (sommeColonne(Tab, TabMask, col, taille) == 1 && (nombreSignificatifColonne(TabMask, col, taille) >= (taille / 2)+1)) {
                    if (essai == 0) {
                        printf(" colonne non respectée...");
                        return 0;
                    }
                }
            }
            // verification des voisins
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
            }//verifie que l'essai ne creer pas une suite de trois fois le meme hciffre consécutivement dans la colonne
            if (verifSuiteCol(Tab, TabMask, ligne, col, taille) != 0) {
                if (essai != Tab[ligne + verifSuiteCol(Tab, TabMask, ligne, col, taille)][col] + 1) {
                    printf("Regardez les voisins de colonne...");
                    return 0;
                }
            } else {
                //verifie que l'essai ne creer pas une suite de trois fois le meme hciffre consécutivement dans la ligne
                if (verifSuiteLigne(Tab, TabMask, ligne, col, taille) != 0) {
                    if (essai != Tab[ligne + verifSuiteCol(Tab, TabMask, ligne, col, taille)][col]){
                        printf(" Solution : %d (voisins consecutifs dans la ligne",essai);
                        return 0;
                    }
                }
            }
        }
    }
    //si aucune des règle au dessus n'a été outrepassé alors on considère le coup incorrect mais pas invalide
    return (-1);
}

int revelerIndice(int** TabMask,int taille){
    //révèle un indice en changeant la premiere case de Tabmask égale à 0 (sert pour cacher le numéro)
    for (int i = 0; i < taille; i++)
        for (int j = 0; j < taille; ++j) {
            //dès que la case est nulle, on la change pour donner l'indice
            if (TabMask[i][j]==0){
                TabMask[i][j]=1;
                return 1;
            }
        }
    return 0;
}

void jouer(int** Tab,int **TabMask,int taille) {
    //jeu pour qu ele joueur essaye de remplir lui meme la grille
    printf("\n>---------------------------------<\nLa partie commence : \n");
    // affichage de la première grille
    int nbr_vies = 3;
    //tant que la matrice masquée à des cases d'ombre
    while (verifFin(TabMask, taille) == 0 && nbr_vies != 0) {
        printf("<----------------Debut du Tour------------------>\n\n");
        //affiche la grille au debut du tour
        afficherGrilleMasquee(Tab, TabMask, taille);
        printf(" \n Que voulez vous faire? Indiquez: [ ligne  colonne valeur ] :\n :");
        // entrer un coup
        int* try= (int*)malloc(sizeof(int)*3);
        entrerEssai(TabMask, try,taille);
        //verification du coup
        int verification=CoupValide(try[0], try[1], try[2], Tab , TabMask,taille);
        //si le coup est correct, on fait passer TabMask[i][j] à 1
        if ( verification == 1){
            TabMask[try[0]][try[1]] = 1;
            printf("\nBRAVO! c'est la bonne reponse ! \n");}
        //sinon, il faut savoir si le coup est invalide
        else if (verification == 0) {
            //on perd une vie si le coup est invalide
            nbr_vies--;
            printf("\nAttention vous venez de perdre une vie. Restant : %d\n ", nbr_vies);
        } else {
            //sinon, un indice est révélé
            revelerIndice(TabMask, taille);
            printf("\nLe coup est valide, mais ce n'est pas la réponse...Pour vous aider, ajoutons un indice... \n\n");
        }
    }
    //à la fin du jeu, on vérifie si el joueur à gagné ou perdu
    if (verifFin(TabMask, taille) == 1)
        printf("Vous avez fini le jeu, FELICITATIONS");
    if (nbr_vies == 0)
        printf("MALHEUREUSEMENT, c'est perdu !");
}


void P1(int choix){
    //définition des constante en fonction du choix des joueurs
    int taille=choix*4;
    //creation des deux tableau dynamiques
    int **Tab = creer_grille(taille,0);
    int** TabMask=(int**)malloc(sizeof(int*)*taille);
    masquerGrille(TabMask,taille);
    //fonction pour jouer
    jouer(Tab,TabMask,taille);
    //on libère l'espace alloué a la fin du programme
    free(Tab);
    free(TabMask);
}
