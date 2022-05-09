//
// Created by lucas on 19/04/2022.
//
#include <stdio.h>
#include "P1.h"
#define T_4 4
#include "P2.h"

int enterEssai(int Tab[T_4][T_4],int TabMask[T_4][T_4],int tab[3]){
    int col=-1, ligne=-1, chiffre=-1, i=0;
    while(col<0 || col>3 || ligne>3 || ligne<0 || (chiffre<0 || chiffre>1) || TabMask[ligne][col]==1) {
        if (i>0) {
            printf("\nune variable etait fausse, reessayez. indiquez:  ligne , colonne, 0/1 : ");
        }
        else
            printf("\nje rentre dans la boucle\n");
        scanf(" %d %d %d", &ligne, &col, &chiffre);
        printf("%d %d %d",ligne, col, chiffre );
        i++;
    }
    int tab2[3] = {ligne, col, chiffre};
    tab [0] = tab2[0];
    tab [1] = tab2[1];
    tab [2] = tab2[2];
   return tab2;
}

int CoupValide(int ligne,int col,int essai, int TabMask[T_4][T_4] ,int Tab[T_4][T_4],int size) {
    // retourne 1 si le coup est correct, 0 si valide mais inccorect, et si faux -1
    if (Tab[ligne][col] == essai)
        return 1;
    else {
        // algo de décision
        if ((sommeLigne(Tab, TabMask, col, col) == 2) && (nombreSignificatifLigne(TabMask, ligne, size) >=2)){
            return 0;
        }
        else {
            if ((sommeLigne(Tab, TabMask, col, col) == 0) && (nombreSignificatifLigne(TabMask, ligne, size) >= 2)){
                return 0;
            }
        }
        // verif voisin peux y avoir un pb
        if (verifierVoisinLigne(Tab,TabMask,ligne,col)==1){

            // modulo pour inverser par rapport aux voisins
            if (essai == Tab[ligne][col+1]%2)
                return 0;
            return -1;
        }
        else {
            // modulo pour inverser par rapport aux voisins
            if (essai == Tab[ligne][col+1]%2)
                return 0;
            return -1;
        }
        return(-1);
    }
}

int revelerIndice(int TabMask[T_4][T_4],int size){
    for (int i = 0;i<size;i++)
        for (int j = 0; j < size; ++j) {
            if (TabMask[i][j]==0){
                TabMask[i][j]=1;
                return 1;
            }
        }
    return 0;
}

int jouer(int Tab[T_4][T_4],int TabMask[T_4][T_4],int size){
    printf("\n>---------------------------------<\nLa partie commence : \n");
    // affichage de la première grille
    int nbr_vies=3;
    while (verifFin(TabMask,size)==0 && nbr_vies!=0) {
        afficherGrilleMasquee(Tab, TabMask, size);
        printf(" \n Que voulez vous faire? indiquez:  ligne , colonne, 0/1 :");
        // vérifie si le coup est valide
        int try[3];
        enterEssai(Tab, TabMask, try);
        printf("\nessai sur %d, %d avec %d ",try[0],try[1],try[2]);
        if (CoupValide(try[0], try[1], try[2], TabMask, Tab, size) == 1)
            TabMask[try[0]][try[1]] = 1;
        else if (CoupValide(try[0], try[1], try[2], TabMask, Tab, size) == -1) {
            nbr_vies--;
            printf("\nAttention vous venez de perdre une vie. Restant : %d",nbr_vies);
            revelerIndice(TabMask,size);
        } else {
            revelerIndice(TabMask,size);
            printf("\nLe coup est valide, mais ce n'est pas sla réponse, pour vous aider voici un indice :\n");
        }
    }
    if (verifFin(TabMask,size)==1)
        printf("Vous avez fini le jeu, FELICITATIONS");
    if (nbr_vies==0)
        printf("MALHEUREUSEMENT, c'est perdu !");
}

void P1(){
    int Tab[T_4][T_4] = {{0,0,1,1},
                        {1,1,0,0},
                        {0,1,1,0},
                        {1,0,0,1},
                        };
    int TabMask[T_4][T_4];
    int nombre_vies = 3;
//    remplirGrille(Tab,T_4);
    afficherGrille(Tab, T_4);
    masquerGrille(TabMask,T_4);
    afficherGrilleMasquee(Tab,TabMask,T_4);
    jouer(Tab,TabMask,T_4);
}