#include <stdio.h>
#include "P3.h"
#include "P2.h"
#include "P1.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int chc;
    srand( time( NULL ) );
    int chx;
    printf("\n###--------------------------------------------------------------------####\n\nBienvenue dans le jeu du TAKUZU!\n\n");
    printf("Veuillez choisir une action :\n");
    printf("\t1 - jouer au jeu soi meme \n\t2 - voir une grille se solutionner automatiquement \n\t3 - creation d'une grille auto \n : ");
    scanf(" %d", &chc);
    do{
        printf("\t1 - resoudre en 4x4\n\t2 - resoudre en 8x8 \n : ");
        scanf(" %d", &chx);
    }while(chx!=2 && chx!=1);

    switch (chc){
        case 1:{
            P1(chx);
            break;
        }

        case 2:{
            P2(chx);
            break;}

        case 3:{
            //P3();
            break;
        }
        default : printf("\nCe numero d'exercice n'existe pas. \n");
    }
    return 0;
}
