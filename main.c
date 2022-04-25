#include <stdio.h>
#include "P3.h"
#include "P2.h"
#include "P1.h"

int main() {
    int chc;
    printf("\n###--------------------------------------------------------------------####\n\nBienvenue dans le jeu du TAKUZU!\n");
    printf("Veuillez choisir une action :\n");
    printf("1 - jouer au jeu soi meme \n2 - voir une grille se solutionner automatiquement \n3 - creation d'une grille auto \n : ");
    scanf(" %d", &chc);

    switch (chc){
        case 1:{
            printf("Cette reponse est en developpement");
            P1();
            break;
        }

        case 2:{
            P2();
            break;}

        case 3:{
            printf("Cette reponse est en developpement");
//            P3();
            break;
        }
        default : printf("\nCe numero d'exercice n'existe pas. \n");
    }
    return 0;
}
