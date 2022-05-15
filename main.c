#include <stdio.h>
#include "P3.h"
#include "P2.h"
#include "P1.h"
#include <stdlib.h>
#include <time.h>

int main() {
    //variable des choix pour le joueur
    int chc;
    int chx;
    srand( time( NULL ) );
    //affichage en console le plus agréable possible
    printf("\n###--------------------------------------------------------------------####\n\nBienvenue dans le jeu du TAKUZU!\n\n");
    printf("Pour commnencer, choisissez une action :\n");
    printf("\t1 - Jouer au jeu soi meme \n\t2 - Donner une grille a l'ordinateur \n\t3 - Voir la creation d'une grille automatiquement \n : ");
    //choix de fonctionnalité
    scanf(" %d", &chc);
    do{
        printf("Quelle taille?\n");
        printf("\t1 - en 4x4\n\t2 - en 8x8 \n : ");
        scanf(" %d", &chx);
    }while(chx!=1 && chx !=2);

// choix de fonctionnalité
switch (chc){
        // Jouer soi-meme
        case 1:{
            P1(chx);
            break;
        }

        // resoudre automatiqumement
        case 2:{
            P2(chx);
            break;}

        //generation de grille pseudo-aléatoire
        case 3:{
            P3(chx);
            break;
        }
        // saisie sécursiée
        default : printf("\nCe numero n'existe pas. \n");
    }
    printf("\nMerci d'avoir pris le temps de tester le jeu ! A bientot!\n");
    return 0;
}
