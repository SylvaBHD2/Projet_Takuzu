//
// Created by lucas on 13/04/2022.
//

#include "P1.h"
#include <stdio.h>
#define T_4 4
#include "P2.h"
#include "P3.h"
#define T_8 8

int enterEssai(int Tab[T_4][T_4],int TabMask[T_4][T_4],int tab[3]){
    int col=-1, ligne=-1, chiffre=-1, i=0;
    while(col<0 || col>3 || ligne>3 || ligne<0 || (chiffre<0 || chiffre>1) || TabMask[ligne][col]==1) {
        if (i>0) {
            printf("\nune variable etait fausse, reessayez. indiquez:  ligne , colonne, 0/1 : ");
        }
//        else
//            printf("\nje rentre dans la boucle\n");
        scanf(" %d %d %d", &ligne, &col, &chiffre);
//        printf(" verif??? %d %d %d",ligne, col, chiffre );
        i++;
    }
    int tab2[3] = {ligne, col, chiffre};
    tab [0] = tab2[0];
    tab [1] = tab2[1];
    tab [2] = tab2[2];
   return tab2;
}

int enterEssai2(int Tab[T_8][T_8],int TabMask[T_8][T_8],int tab[3]){
    int col=-1, ligne=-1, chiffre=-1, i=0;
    while(col<0 || col>7 || ligne>7 || ligne<0 || (chiffre<0 || chiffre>1) || TabMask[ligne][col]==1) {
        if (i>0) {
            printf("\nUne variable etait fausse, reessayez. indiquez:  ligne , colonne, 0/1 : ");
        }
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

int CoupValide(int ligne,int col,int essai,  int Tab[T_4][T_4], int TabMask[T_4][T_4],int taille) {
    // retourne 1 si le coup est correct, 0 si valide mais inccorect, et si faux -1
    if (Tab[ligne][col] == essai){
        printf(" direct validé : essai = %d, %d",essai,Tab[ligne][col]);
        return 1;}
    else {
        printf(" délibération  : essai = %d, %d, ligne = %d et col = %d",essai,Tab[ligne][col],ligne,col);
        // algo de décision
        if ((sommeLigne(Tab, TabMask, col, col) == 2) && (nombreSignificatifLigne(TabMask, ligne, taille) >= 2)){
            return 0;
        }
        else {
            if ((sommeLigne(Tab, TabMask, col, col) == 0) && (nombreSignificatifLigne(TabMask, ligne, taille) >= 2)){
                return 0;
            }
        }
        // verif voisin peux y avoir un pb
        if (verifierVoisinLigne(Tab,TabMask,ligne,col)==1){

            // modulo pour inverser par rapport aux voisins
            if (essai == Tab[ligne][col+1]%2)
                printf("Regardez les voisins ...");
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

int CoupValide2(int ligne,int col,int essai, int TabMask[T_8][T_8] ,int Tab[T_8][T_8],int size) {
    // retourne 1 si le coup est correct, 0 si valide mais inccorect, et si faux -1
    if (Tab[ligne][col] == essai)
        return 1;
    else {
        // algo de décision
        if ((sommeLigne2(Tab, TabMask, col, col) == 2) && (nombreSignificatifLigne2(TabMask, ligne, size) >=2)){
            return 0;
        }
        else {
            if ((sommeLigne2(Tab, TabMask, col, col) == 0) && (nombreSignificatifLigne2(TabMask, ligne, size) >= 2)){
                return 0;
            }
        }
        // verif voisin peux y avoir un pb
        if (verifierVoisinLigne2(Tab,TabMask,ligne,col)==1){

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

int revelerIndice2(int TabMask[T_8][T_8],int size){
    for (int i = 0;i<size;i++)
        for (int j = 0; j < size; ++j) {
            if (TabMask[i][j]==0){
                TabMask[i][j]=1;
                return 1;
            }
        }
    return 0;
}

int jouer(int Tab[T_4][T_4],int TabMask[T_4][T_4],int size) {
    printf("\n>---------------------------------<\nLa partie commence : \n");
    // affichage de la première grille
    int nbr_vies = 3;
    while (verifFin(TabMask, size) == 0 && nbr_vies != 0) {
        afficherGrilleMasquee(Tab, TabMask, size);
        printf(" \n Que voulez vous faire? indiquez:  ligne , colonne, 0/1 :");
        // vérifie si le coup est valide
        int try[3];
        enterEssai(Tab, TabMask, try);
        printf("\nessai sur %d, %d avec %d ", try[0], try[1], try[2]);
        if (CoupValide(try[0], try[1], try[2], TabMask, Tab, size) == 1)
            TabMask[try[0]][try[1]] = 1;
        else if (CoupValide(try[0], try[1], try[2], TabMask, Tab, size) == -1) {
            nbr_vies--;
            printf("\nAttention vous venez de perdre une vie. Restant : %d", nbr_vies);
            revelerIndice(TabMask, size);
        } else {
            revelerIndice(TabMask, size);
            printf("\nLe coup est valide, mais ce n'est pas sla réponse, pour vous aider voici un indice :\n");
        }
    }
    if (verifFin(TabMask, size) == 1)
        printf("Vous avez fini le jeu, FELICITATIONS");
    if (nbr_vies == 0)
        printf("MALHEUREUSEMENT, c'est perdu !");
}
int jouer2(int Tab[T_8][T_8],int TabMask[T_8][T_8],int size){
    printf("\n>---------------------------------<\nLa partie commence : \n");
    // affichage de la première grille
    int nbr_vies=3;
    while (verifFin2(TabMask,size)==0 && nbr_vies!=0) {
        afficherGrilleMasquee2(Tab, TabMask, size);
        printf(" \n Que voulez vous faire? indiquez:  ligne , colonne, 0/1 :");
        // vérifie si le coup est valide
        int try[3];
        enterEssai2(Tab, TabMask, try);
        printf("\nessai sur %d, %d avec %d ",try[0],try[1],try[2]);
        if (CoupValide2(try[0], try[1], try[2], TabMask, Tab, size) == 1)
            TabMask[try[0]][try[1]] = 1;
        else if (CoupValide2(try[0], try[1], try[2], TabMask, Tab, size) == -1) {
            nbr_vies--;
            printf("\nAttention vous venez de perdre une vie. Restant : %d",nbr_vies);
            revelerIndice2(TabMask,size);
        } else {
            revelerIndice2(TabMask,size);
            printf("\nLe coup est valide, mais ce n'est pas la réponse, pour vous aider voici un indice :\n");
        }
    }
    if (verifFin2(TabMask,size)==1)
        printf("Vous avez fini le jeu, FELICITATIONS !");
    if (nbr_vies==0)
        printf("MALHEUREUSEMENT, c'est perdu !");
}

void P1(int choix){
    if (choix == 1){
        int Tab[T_4][T_4] = {{0,0,1,1},
                            {1,1,0,0},
                            {0,1,1,0},
                            {1,0,0,1},
                            };
        int TabMask[T_4][T_4];
        int nombre_vies = 3;
    //    remplirGrille(Tab,T_4);
//        afficherGrille(Tab, T_4);//P2
        masquerGrille(TabMask,T_4);//P2
//        afficherGrilleMasquee(Tab,TabMask,T_4);//P2
        jouer(Tab,TabMask,T_4);
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
        int nombre_vies = 3;
//    remplirGrille(Tab,T_4);
        afficherGrille2(Tab, T_8);//P2
        masquerGrille2(TabMask,T_8);//P2
        afficherGrilleMasquee2(Tab,TabMask,T_8);//P2
        jouer2(Tab,TabMask,T_8);}
}