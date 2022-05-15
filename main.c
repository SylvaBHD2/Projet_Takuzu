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
    printf("Pour commnencer, choisissez une action :\n");
    printf("\t1 - Jouer au jeu soi meme \n\t2 - Donner une grille a l'ordinateur \n\t3 - Voir la creation d'une grille automatiquement \n : ");
    scanf(" %d", &chc);
    do{
        printf("Quelle taille?\n");
        printf("\t1 - en 4x4\n\t2 - en 8x8 \n : ");
        scanf(" %d", &chx);
    }while(chx==0);


switch (chc){
        case 1:{
            P1(chx);
            break;
        }

        case 2:{
            P2(chx);
            break;}

        case 3:{
            P3(chx,0);
            break;
        }
        default : printf("\nCe numero n'existe pas. \n");
    }
    printf("\nMerci d'avoir pris le temps de tester le jeu ! A bientot!\n");
    return 0;
}
