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

//fonctions
int remplirGrille(int Tab[T_4][T_4],int taille){
    //crée une grille
//    int Tabsol[T_4][T_4];
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
           Tab[i][j]=0;
        }
    }
    return 0;
}

int remplirGrille2(int Tab[T_8][T_8],int taille){
    //crée une grille
//    int Tabsol[T_8][T_8];
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
            Tab[i][j]=0;
        }
    }
    return 0;
}


void afficherGrille(int tab[T_4][T_4], int taille){
    // afficher la grille
    printf("\n");
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
            printf(" |%d|\t", tab[i][j] );
        }
        printf("\n");
    }
}

void afficherGrille2(int tab[T_8][T_8], int taille){
    // afficher la grille
    printf("\n");
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
            printf(" |%d|\t", tab[i][j] );
        }
        printf("\n");
    }
}

void masquerGrille(int tab[T_4][T_4],int taille){
    // retourne un tableau rempli de 0 ou de 1 avec 50/50 de chance

    srand( time( NULL ) );
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
            if (rand()%2)
                tab[i][j]=0;
            else
                tab[i][j]=1;
        }
    }
//    return (int) tab[T_4][T_4];
}

void masquerGrille2(int tab[T_8][T_8],int taille){
    // retourne un tableau rempli de 0 ou de 1 avec 50/50 de chance

    srand( time( NULL ) );
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
            if (rand()%2)
                tab[i][j]=0;
            else
                tab[i][j]=1;
        }
    }
//    return (int) tab[T_8][T_8];
}

void afficherGrilleMasquee(int Tab[T_4][T_4],int TabMas[T_4][T_4], int taille){
    // Si la grille du masque en coordonnées (i,j) =  1 alors la grille principale est masquée sur ces coordonnées
    printf("\n");
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
            if (TabMas[i][j]==1){
                printf(" | %d | \t", Tab[i][j] );
                }
            else
                printf("      \t");
        }
        printf("\n--------------------------------");
        printf("\n");
    }
}

void afficherLignePtr( int* Tab, int taille) {
    printf("\n");
    for (int j = 0; j < taille; j++) {
        printf(" |%d|\t", *(Tab + j));
    }
}

void afficherGrillePtr(int **Tab, int nbrLigne, int nbrCol){
    for (int i = 0 ; i < nbrLigne ; i++){
        afficherLignePtr(Tab[i], nbrCol);
        printf("\n");
    }
}

void afficherGrilleMasquee2(int Tab[T_8][T_8],int TabMas[T_8][T_8], int taille){
    // Si la grille du masque en coordonnées (i,j) =  1 alors la grille principale est masquée sur ces coordonnées
    printf("\n");
    for (int i = 0 ; i < taille ; i++){
        for (int j = 0; j < taille; j++) {
            if (TabMas[i][j]==1)
                printf(" |%d|\t", Tab[i][j] );
            else
                printf("  \t");
        }
        printf("\n");
    }
}

// sert a la résolution auto
int sommeLigne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int ligne, int taille){
    int somme = 0;
    for (int i = 0; i < taille; i++){
        somme += TabMask[ligne][i] * Tab[ligne][i];
    }
    return somme;
}

int sommeLigne2(int Tab[T_8][T_8], int TabMask[T_8][T_8], int ligne, int taille){
    int somme=0;
    for (int i=0; i<taille;i++){
        somme+=TabMask[ligne][i]*Tab[ligne][i];
    }
    return somme;
}

int sommeColonne(int Tab[T_4][T_4], int TabMask[T_4][T_4], int col, int taille){
    int somme=0;
    for (int i=0; i<taille;i++){// faire somme - nbsin (represente le nbr de truc qu'on peut voir )
        somme+=TabMask[i][col]*Tab[i][col];
    }
    return somme;
}

int sommeColonne2(int Tab[T_8][T_8], int TabMask[T_8][T_8], int col, int taille){
    int somme=0;
    for (int i = 0; i < taille; i++){
        somme+=TabMask[i][col]*Tab[i][col];
    }
    return somme;
}

int nombreSignificatifColonne(int TabMask[T_4][T_4], int col, int taille){
    //retourne le nbr de 1  et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i < taille; i++){
        if (TabMask[i][col]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifColonne2(int TabMask[T_8][T_8], int col, int taille){
    //retourne le nbr de 1  et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i<taille;i++){
        if (TabMask[i][col]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifLigne(int TabMask[T_4][T_4], int ligne,int taille){
    //retourne le nbr de 1 et de 0 découverts dans une colonne
    int nbrUn=0;
    for (int i=0; i<taille;i++){
        if (TabMask[ligne][i]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int nombreSignificatifLigne2(int TabMask[T_8][T_8], int ligne,int taille){
    //retourne le nbr de 1 et de 0 découverts dans une ligne
    int nbrUn=0;
    for (int i=0; i<taille;i++){
        if (TabMask[ligne][i]!=0)
            nbrUn++;
    }
    return nbrUn;
}

int verifierVoisinCol(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose, sinon 0
    if (ligne==0 || ligne==T_4)
        return 0;
    if (TabMask[ligne+1][col]==1 && TabMask[ligne-1][col]==1) {
        if (Tab[ligne + 1][col] == Tab[ligne - 1][col])
            return 1;
    }
    return 0;
}

int verifierVoisinLigne(int Tab[T_4][T_4],int TabMask[T_4][T_4], int ligne, int col) {
    if (col==0 || col==T_4)
        return 0;
    if ((TabMask[ligne][col + 1] == 1) && (TabMask[ligne][col - 1] == 1)) {
        if (Tab[ligne][col - 1] == Tab[ligne][col + 1])
            return 1;
    }
    return 0;
}

int verifierVoisinLigne2(int Tab[T_8][T_8],int TabMask[T_8][T_8], int ligne, int col){
    // regarde les voisins immédiats, et retourne 1 si c'est possible d'en déduire qlqchose, sinon 0
    if (ligne==0 || ligne==T_4)
        return 0;
    if (TabMask[ligne+1][col]==1 && TabMask[ligne-1][col]==1) {
        if (Tab[ligne + 1][col] == Tab[ligne - 1][col])
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

int verifFin(int TabMask[T_4][T_4],int taille){
    //retourne 1 si la patrice ne contiens aucune zone masquée
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (TabMask[i][j]==0)
                return 0;
        }
    }
    return 1;
}

int verifFin2(int TabMask[T_8][T_8],int taille){
    //retourne 1 si la patrice ne contiens aucune zone masquée
    for (int i = 0; i < taille; ++i) {
        for (int j = 0; j < taille; ++j) {
            if (TabMask[i][j]==0)
                return 0;
        }
    }
    return 1;
}

void resouGrille(int Tab[T_4][T_4],int TabMask[T_4][T_4],int taille) {
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
                    printf("  - Operation sur la case %d %d :\n", i, j);
                    int Somme_ligne = sommeLigne(Tab, TabMask, i, taille) ;
                    int Somme_col=sommeColonne(Tab, TabMask, j, taille ) ;
                    printf("\nL'ordinateur reflechi... Pret? (tapez 1) \n");
                    scanf(" %d", &retour_utilisateur);
                    if ((Somme_ligne == taille/2) && (nombreSignificatifLigne(TabMask, i,taille) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" Solution : 0 somme de la ligne %d",sommeLigne(Tab, TabMask, j, taille) == 0);
                    }
                    else {
                        if (Somme_ligne==0 &&(nombreSignificatifLigne(TabMask, i, taille) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace a sommeline %d", sommeLigne(Tab, TabMask, j, taille));
                        }
                        else if (Somme_ligne==1 &&(nombreSignificatifLigne(TabMask, i, taille) == 3)){
                            essai=1,idc++;
                            printf(" essai 1 Trouvé grace a nvelle fonction");}
                    }
                    // essai avc somme des colonnes
                    if (Somme_col == taille/2 && (nombreSignificatifColonne(TabMask, j,taille) >= 2)) {
                        essai = 0;
                        idc++;
                        printf(" solution 0 trouvee grace à sommecol");
                    }
                    else {
                        if ((Somme_col == 0) &&(nombreSignificatifColonne(TabMask, j, taille) >= 2)) {
                            idc++;
                            essai = 1;
                            printf(" solution 1 trouvee grace à sommecol");
                        }
                        else if (Somme_col==1 &&(nombreSignificatifColonne(TabMask, i, taille) == 3)){
                            essai=1,idc++;
                            printf(" essai 1 trouvé grace a nvelle fonction");}
                    }
                    // verif voisins
                    if (idc == 0) {
                        if (verifierVoisinLigne(Tab, TabMask, i, j) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = Tab[i][j + 1]+1 % 2;
                            printf(" solution trouvee grace a voisin line :; %d",essai);
                        }
                        else {
                            if (verifierVoisinCol(Tab, TabMask, i, j) == 1) {
                                // modulo pour inverser par rapport aux voisins
                                essai = Tab[i + 1][j]+1 % 2;
                                idc++;
                                printf(" solution trouvee grace a voisin col;: %d", essai);
                            }
                        }
                    }
                    //voir si une solution a été trouvée
                    if (antiblocage >= taille/2 && essai==-1){
                        essai=rand()%2;
                        printf("Le Bot donne un coup au hasard, pour se debloquer...\n");
                        antiblocage=0;}
                    if (essai != -1){
                        printf("\n Il a fait son choix : %d avec %d changements\n", essai,idc);
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
                        printf("Il n'est pas possible de svaoir maintenant sur cette case...");
                    }
                    printf("\n<-------------fin du tour------------->\n");
                }
            }
        }
    }
    printf("\n ><------------------FIN-------------><\nVoila, c'est fini! A bientot !\n");

}

void resouGrille2(int Tab[T_8][T_8],int TabMask[T_8][T_8],int taille) {

    while (verifFin2(TabMask, taille) != 1) {
        for (int i = 0; i < taille; ++i) {
            for (int j = 0; j < taille; ++j) {
                // dès qu'il y a un 0
                if (TabMask[i][j] != 1) {
                    int idc = 0, essai = -1;
                    int t = 0;
                    printf(" >---------------------------------------< \n");
                    afficherGrilleMasquee2(Tab,TabMask,taille);
                    printf("\npret pour la prochaine action?(tapez 1) \n :");
                    //uniquement pour appuyer bouton
                    scanf(" %d", &t);
                    printf(" Operation sur la case %d %d :\n", i, j);
                    printf(" \n Le tour: somme de ligne: %d ; signiLigne: %d \n", sommeLigne2(TabMask, TabMask, i, taille - 1),
                           nombreSignificatifLigne2(TabMask, i,taille));
                    printf(" \n Le tour: somme de colonne %d  signiCol %d\n", sommeColonne2(TabMask, TabMask, j, taille - 1),
                           nombreSignificatifColonne2(TabMask, j,taille));
                    // attention plusiers changements possibles avec voisin
                    if ((sommeLigne2(TabMask, TabMask, j, taille - 1) == 4) && (nombreSignificatifLigne2(TabMask, i,taille) >= 4)) {
                        essai = 0;
                        idc++;
                        printf(" solution : 0 trouve grace a sommeligne");
                    }
                    else{
                        if ((sommeLigne2(TabMask, TabMask, j, taille - 1) == 0)&&(nombreSignificatifLigne2(TabMask, i, taille) >= 4)) {
                            idc++;
                            essai = 1;
                            printf(" solution : 1 trouvee grace a sommeline");
                        }
                    }
                    // essai avc somme des colonnes
                    if ((sommeColonne2(TabMask, TabMask, j, taille - 1) == 4) &&
                        (nombreSignificatifColonne2(TabMask, j,taille) >= 4)) {
                        essai = 0;
                        idc++;
                        printf(" solution : 0 trouvee grace à sommeligne");
                    }
                    else {
                        if ((sommeColonne2(TabMask, TabMask, j, taille - 1) == 0) &&
                            (nombreSignificatifColonne2(TabMask, j, taille) >= 4)) {
                            idc++;
                            essai = 1;
                            printf("solution : 1 trouvee grace à la somme des colonnes!\n");
                        }
                    }
                    // verif voisins
                    if (idc == 0) {
                        if (verifierVoisinLigne2(Tab, TabMask, i, j) == 1) {
                            // modulo pour inverser par rapport aux voisins
                            essai = TabMask[i][j] = TabMask[i][j + 1] % 2;
                            printf(" solution : %d trouvee grace a voisin line ",essai);
                        }
                        else {
                            if (verifierVoisinCol2(Tab, TabMask, i, j) == 1) {
                                // modulo pour inverser par rapport aux voisins
                                essai = TabMask[i][j] = TabMask[i + 1][j] % 2;
                                idc++;
                                printf(" solution %d trouvee grace a voisin col",essai);
                            }
                        }
                    }
                    //voir si une solution a été trouvée
                    printf("\n SOLUTION : %d avec %d\n", essai,idc);
                    if (CoupValide2(i, j, essai, Tab, TabMask, taille)) {
                        TabMask[i][j] = 1;
                        printf("validation du changement dans le tableau");
                    }
                    else
                        printf(" Le coup valide lign 413%d ",CoupValide2(i, j, essai, Tab, TabMask, taille)) ;
                    afficherGrilleMasquee2(Tab, TabMask, taille);
                    printf("\n<----fin du tour---->\n");
                }
            }
        }
    }
}


//fonction principale
void P2(int choix){
    if (choix == 1){
    int Tab[T_4][T_4] = {{0,0,1,1},
                         {1,1,0,0},
                         {0,1,1,0},
                         {1,0,0,1},
    };
    int TabMask[T_4][T_4];
    printf("la partie commence, l'ordinateur voit la meme chose que vous:\n");
    masquerGrille(TabMask,T_4);
    resouGrille(Tab,TabMask,T_4);
    }

    else{
    int Tab[T_8][T_8] = {{1,0,1,1,0,1,0,0},
                         {1,0,1,0,1,0,0,1},
                         {0,1,0,1,1,0,1,0},
                         {0,1,0,1,0,1,1,0},
                         {1,0,1,0,0,1,0,1},
                         {0,1,0,0,1,0,1,1},
                         {0,0,1,1,0,1,1,0},
                         {1,1,0,0,1,0,0,1}
    };
    int TabMask[T_8][T_8];
    masquerGrille2(TabMask,T_8);
    resouGrille2(Tab,TabMask,T_8);
    }
}