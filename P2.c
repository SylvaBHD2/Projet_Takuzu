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
    // affiche le tableau de pointeurs de maniere ergonomique
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
    // retourne un tableau rempli de 0 ou de 1 avec 1/2 de chance d'etre 1 ou 0
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
    // afficher la grille masqueée : si Mask(i,j) =  0 alors la grille principale est masquée sur ces coordonnées
    printf("\t");
    for(int i=0; i<taille;i++)
        printf("--------");
    printf("\n");
    // affichage ergonomique le plus agréable possible
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

// sert a la résolution auto
int sommeLigne(int **Tab, int **TabMask, int ligne, int taille){
    // fonction qui retourne la somme de tous les numéros d'un tableau
    int somme = 0;
    for (int i = 0; i < taille; i++){
        somme += Tab[ligne][i] * TabMask[ligne][i];
    }
    return somme;
}

int sommeColonne(int **Tab, int **TabMask, int col, int taille){
    // fonction qui retourne la somme de tous les numéros de la colonne d'un tableau
    int somme=0;
    for (int i=0; i<taille;i++){
        somme += Tab[i][col]*TabMask[i][col];
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
    //vérifie
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
    // regarde les voisins , et retourne 1 si une suite est comencée du coté positif ou -1 du coté négatif, sinon 0
    // si la colonne est l'extrème supérieur, on regarde seulement le coté négatif (écite les effets de bords)
    if (ligne >= taille-2){
        if (TabMask[ligne-1][col]==1 && TabMask[ligne-2][col]==1)
            if (Tab[ligne-1][col] == Tab[ligne-2][col]){
                return -1;}
        return 0;}
    // si la colonne est trop au l'extrème inférieur, on regarde seulement le coté positif
    if (ligne<=1){
        if (TabMask[ligne+1][col]==1 && TabMask[ligne+2][col]==1)
            if (Tab[ligne+1][col] == Tab[ligne+2][col]){
                return 1;}
        return 0;}
    //autres cas : au milieu de la matrice , pour le coté négatif
    if (TabMask[ligne-1][col]==1 && TabMask[ligne-2][col]==1 ){
        if (Tab[ligne-1][col] == Tab[ligne-2][col])
            return -1;
    }
    //autres cas : au milieu de la matrice , pour le coté positif
    if (TabMask[ligne+1][col]==1 && TabMask[ligne+2][col]==1 )
        if (Tab[ligne+1][col] == Tab[ligne+2][col]){
            return 1;}
    return 0;
}

int verifSuiteLigne(int **Tab, int **TabMask, int ligne, int col, int taille){
    // regarde les voisins , et retourne 1 si une suite est comencée du coté positif ou -1 du coté négatif, sinon 0
    // si la ligne l'extrème supérieur, on regarde seulement le coté négatif (évite les effets de bords)
    if (col>=taille-2){
        if (TabMask[ligne][col-1]==1 && TabMask[ligne][col-2]==1)
            if (Tab[ligne][col-1] == Tab[ligne][col-2])
                return -1;
        return 0;}
    // si la ligne est trop au l'extrème inférieur, on regarde seulement le coté positif
    if (col<=1){
        if (TabMask[ligne][col+1]==1 && TabMask[ligne][col+2]==1)
            if (Tab[ligne][col+1] == Tab[ligne][col+2])
                return 1;
        return 0;}
    //autres cas : au milieu de la matrice , pour le coté négatif
    if (TabMask[ligne][col-1]==1 && TabMask[ligne][col-2]==1 ){
        if (Tab[ligne][col-1] == Tab[ligne][col-2]){
            return -1;}
        }
    //autres cas : au milieu de la matrice , pour le coté positif
    if (TabMask[ligne][col+1]==1 && TabMask[ligne][col+2]==1 ){
        if (Tab[ligne][col+1] == Tab[ligne][col+2]){
            return 1;}
    }
    return 0;
}

int verifFin(int **TabMask,int taille){
    //retourne 1 si la matrice ne contiens aucune zone masquée, sinon 0
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (TabMask[i][j]==0)
                return 0;
        }
    }
    return 1;
}

void resGrille(int **Tab, int** TabMask, int taille) {
    // fonction pour résoudre la matrice de manière automatique. En cas de blocage, joue au hasard
    int antiblocage=0;
    //boucle de jeu
    while (verifFin(TabMask, taille) != 1) {
        for (int i = 0; i < taille; ++i) {
            for (int j = 0; j < taille; ++j) {
                // dès qu'il y a un 0
                if (TabMask[i][j] != 1) {
                    // Definitions des varaiables
                    int idc = 0, essai = -1;
                    int retour_utilisateur = 0;
                    printf(" \n>-------------------Tour suivant-------------------< \n ");
                    //affiche la grille au debut de tour
                    afficherGrilleMasquee(Tab, TabMask, taille);
                    printf("  - Operation sur la case %d %d :\n", i + 1, j + 1);
                    int Somme_ligne = sommeLigne(Tab, TabMask, i, taille);
                    int Somme_col = sommeColonne(Tab, TabMask, j, taille);
                    //attend pour la saisie, ce qui permet de résoudre pas à pas la grille
                    printf("\nL'ordinateur reflechit... Pret? (tapez 1) \n");
                    scanf(" %d", &retour_utilisateur);
                    //Début de l'algorithme de décision , debut des conditions pour les lignes
                    if ((Somme_ligne == taille / 2) && (nombreSignificatifLigne(TabMask, i, taille) >= 2)) {
                        essai = 0;
                        idc++;
                        //annonce le resultat pour permettre à l'utilisateur de suivre
                        printf(" Solution : 0 (somme de la ligne) ");
                    } else {
                        //si il y a la moitié de '0', alors la réponse est 1
                        if (Somme_ligne == 0 && (nombreSignificatifLigne(TabMask, i, taille) >= taille / 2)) {
                            idc++;
                            essai = 1;
                            printf(" Solution : 1 (somme de la ligne) ");
                        }
                        else{
                            //si il y a quatre de '0', alors la réponse est 1
                            if (Somme_ligne == 1 &&
                                   (nombreSignificatifLigne(TabMask, i, taille) >= (taille / 2) + 1)){
                                essai = 1, idc++;
                                printf(" Solution : 1 ( ligne evidente)");
                            }
                            else{ if (nombreSignificatifLigne(TabMask, i, taille)==taille-1 &&
                                (nombreSignificatifLigne(TabMask, i, taille)-Somme_ligne)==taille/2){
                                    essai = 1, idc++;
                                    printf(" Solution : 1 ( ligne evidente)");
                                }
                            }
                        }
                    }
                    // essai avec la somme des chiffres dans la colonnes,il y a la moitié de '1', alors la réponse est 0
                    if (Somme_col == taille / 2 && (nombreSignificatifColonne(TabMask, j, taille) >= taille / 2)) {
                        essai = 0;
                        idc++;
                        printf(" Solution: 0  (somme de la colonne)");
                    }
                    else {
                        //si il y a la moitié de '0', alors la réponse est 1
                        if ((Somme_col == 0) && (nombreSignificatifColonne(TabMask, j, taille) >= taille / 2)) {
                            idc++;
                            essai = 1;
                            printf(" Solution 1 ( somme de la colonne)");
                        }
                        else //si il y a la moitié de '0', alors la réponse est 1
                            if (Somme_col == 1 &&
                                   (nombreSignificatifColonne(TabMask, j, taille) >= (taille) / 2 + 1)) {
                            essai = 1, idc++;
                            printf(" Solution : 1 ( colonne evidente car %d-1 zeros)",
                                   (nombreSignificatifColonne(TabMask, i, taille)));
                            }
                            else {//si il ne manque qu'un 1, alors la réponse est 1
                                if (nombreSignificatifColonne(TabMask, j, taille)==taille-1 &&
                                    (nombreSignificatifColonne(TabMask, j, taille) - Somme_ligne) == taille / 2) {
                                    essai = 1, idc++;
                                    printf(" Solution : 1 ( colonne evidente)");
                            }
                        }
                    }
                    // cherche la solution en fonction des voisins de la case choisie
                    if (idc == 0) {
                        //si il y deux fois le meme chiffre de chaque coté dans la ligne
                        if (verifierVoisinLigne(Tab, TabMask, i, j, taille) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = (Tab[i][j + 1] + 1) % 2;
                            idc++;
                            printf(" Solution %d(voisins dans la ligne) ", essai);
                        } else {
                            //si il y deux fois le meme chiffre de chaque coté dans la colonne
                            if (verifierVoisinCol(Tab, TabMask, i, j, taille) == 1) {
                                // modulo pour inverser par rapport aux voisins
                                essai = (Tab[i + 1][j] + 1) % 2;
                                idc++;
                                printf(" Solution : %d(voisins dans la colonne)", essai);
                            }
                        }
                        // cherche la solution si les voisins au dessus ou en dessous forment une suite de 2
                        if (verifSuiteCol(Tab, TabMask, i, j, taille) != 0) {
                            essai = (Tab[i + verifSuiteCol(Tab, TabMask, i, j, taille)][j] + 1) % 2;
                            printf(" Solution :%d (voisins consecutifs dans la colonne) : %d", essai,
                                   (Tab[i][j + verifSuiteCol(Tab, TabMask, i, j, taille)] + 1));
                            idc++;
                        } else {
                            // cherche la solution si les voisins a gauche ou a droite forment une suite de 2
                            if (verifSuiteLigne(Tab, TabMask, i, j, taille) != 0) {
                                essai = (Tab[i][j+verifSuiteLigne(Tab, TabMask, i, j, taille)] + 1) % 2;
                                printf(" Solution : %d (voisins consecutifs dans la ligne",essai);
                                idc++;
                            }
                        }
                    }
                    //voir si une solution a été trouvée ou si le bot est bloqué
                    if (antiblocage >= taille/2 && essai == -1) {
                        printf("Le Bot donne un coup au hasard, pour se debloquer...\n");
                        // si il a été bloqué pendant un tour entier, joue un coup au hasard
                        essai = rand() % 2;
                        //remet le blocage à zéro
                        antiblocage = 0;
                    }
                    //verification de la solution
                    // si l'algorithme à toruvé une solution
                    if (essai != -1) {
                        if (CoupValide(i, j, essai, Tab, TabMask, taille) == 1) {
                            // le masque est dévoilé
                            TabMask[i][j] = 1;
                            printf("\nValidation du changement dans le tableau :");
                            antiblocage = 0;
                        }
                        //sinon, alors le coup peut etre invalide ou incorrect
                        else if(!CoupValide(i, j, essai, Tab, TabMask, taille) && idc != 0)
                            printf("IL A RATE  : %d ", CoupValide(i, j, essai, Tab, TabMask, taille));
                    }
                    else {
                        //Si aucune condition n'a pu etre vérifiée
                        if (idc == 0) {
                            // on augmente d'un tour l'indice de blocage
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
    //allocation dynamique et création des variables
    int taille=choix*4;
    int** Tab;
    Tab= creer_grille(taille,1);
    int **TabMask=(int**)malloc(sizeof(int*)*taille);
    //création du masque aléatoire
    masquerGrille(TabMask,taille);
    //début de la partie
    printf("La partie commence, l'ordinateur voit la meme chose que vous:\n");
    masquerGrille(TabMask,taille);
    //on lance l'algorythme de recherche
    resGrille(Tab, TabMask, taille);
    //on libere l'espace alloué
    free(Tab);
    free(TabMask);
}