//
// Created by lucas on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "P3.h"
#include "P2.h"
#include <time.h>


int random(int module){
    //retourne un nombre entier positif aléatoire compris entre 0 et module
    return rand()%module;
}

int puissance(int chiffre,int exposant){
    // peremt de calculer chiffre à la puissance exposant
    int res=1;
    for (int i = 0; i < exposant; ++i) {
        res*=chiffre;
    }
    return res;
}

void transforme_binaire(int * tab, int numero, int taille){
    //transforme un entier poisitf en son écriture binaire
    int *code_binaire = (int*) malloc(taille * sizeof(int));
    for (int i = 0; i < taille; ++i) {
        // ajout de ce nouveau tableau
        tab[i] = numero%2;
        // ici l'ecriture est inversée, mais ce n'est pas grave pour la suite qui ne dépend pas de l'ordre
        numero = numero/2;
    }
}

// sert a la construction auto
int sommeTab(int* Tab,int taille){
    int somme=0;
    for (int i=0; i < taille; i++){
        somme+=Tab[i];
    }
    return somme;
}

void inverserLigne(int *tab,int *result,int taille){
    // inverse le tableau binaire(0->1 et 1->0)
    for (int i = 0; i < taille; ++i) {
        if (tab [i]==1)
            (result [i]=0);
        else {
            if (tab [i] == 0)
                (result[i] = 1);
        }
    }
}

int comparerLignes(int* tab, int* tab2, int taille){
    //vérifie que tab et tab2 soit bien différents
    int test = 1;
    for (int i = 0; i < taille; ++i) {
        //si une similitude est toruvée, on retourne 0
        if(tab[i]!=tab2[i]){
            test=0;
        }
    }
    return test;
}

int verifPres(int** tab, int* temp,int taille,int nbrligne){
    //vérifie que nouvelle ligne soit bien différente de toute les lignes de tab
    for (int i = 0; i < nbrligne; ++i) {
        int res = comparerLignes(temp,tab[i],taille);
        if(res==1){
            // si une similitude est trouvée on retourne 1
            return 1;
        }
    }
    return 0;
}

int verifierVoisinsLigne(int* tab, int taille){
    //verifie que tab ne contient pas 3 valeurs qui se suivent
    for (int i = 2; i < taille; ++i) {
        int alias= tab[i-1]+tab[i-2]+tab[i];
        if (alias==0 || alias==3)
            return 0;
    }
    return 1;
}

void melangerTab(int** grille, int taille){
    //mélange les lignes de la grille 4x4 pour plus d'aléa (8x8 non pris en compte car trop complexe)
    if (taille==4){
        for (int i = 0; i < random(taille); ++i) {
            int choix_hasard = random(taille),choix_hasard2=random(taille);
            // les deux lignes sont interchangées
            int* temp = grille[choix_hasard];
            grille[choix_hasard] = grille[choix_hasard2];
            grille[choix_hasard2] = temp;
        }
    }
}

int** creer_grille(int taille,int silence){
    int retour_utilisateur;
    //la fcontion crée une grille de taille paire valide pour le jeu du Takuzu
    int** tab_valide=(int**) malloc(taille*taille/2*sizeof(int*));
    //comtpeur de possibilités de combinaison
    int nbrLigne=0;
    //tranformation de chaque entier positif convenant à la taille de la grille
    for (int i = 0; i < puissance(2,taille); ++i) {
        //nouveau pointeur
        int* temp=(int* )malloc(sizeof(int)*taille);
        //transforme le numéro sous forme d'ecriture binaire
        transforme_binaire(temp, i, taille);
        //si l'ecriture est valide, on l'ajoute au tableau des combinaisons possibles
        if ( (sommeTab(temp, taille) == taille/2 ) && (verifierVoisinsLigne(temp, taille) == 1) ) {
            tab_valide[nbrLigne] = temp;
            ++nbrLigne;
        }
    }
    //affichage de toute les combinaison possibles
    if(silence==1){
        afficherGrille(tab_valide, nbrLigne, taille);
        printf("Voici ci-dessus la liste des combinaisons valides (%d lignes)\n",nbrLigne);
    }
    // création de la grille
    int **grille = (int**) malloc(taille*sizeof(int*));
    // ajout de l'aléa
    int choix_hasard=random(nbrLigne);
    printf("\nPret? (tapez 1) \n");
    scanf(" %d", &retour_utilisateur);
    if (silence==2) printf("Maintenant, la generation:\n");
    // choix des lignes génératrices
    for (int i = 0; i < taille; ++i) {
        // sur les lignes paires, on met de nouvelle lignes si elle ne sont pas déja sur l'echequier
        if (i==0){
            //pour la premiere lgine, on choisit une au hasard parmi les combinaison possibles
            grille[i] = tab_valide[choix_hasard];
        }
        else {
            //sur les lignes paires, on choisit de nouvelles combinaisons
            if (i%2==0){
                choix_hasard=random(nbrLigne);
                // si la ligne est déja présente, on ne l'ajoute pas
                int res = verifPres(grille,tab_valide[choix_hasard],taille,i);
                while (res==1) {
                    choix_hasard = random(nbrLigne);
                    res = verifPres(grille,tab_valide[choix_hasard],taille,i);
                };
                //ajout de la ligne dans la grille finale
                grille[i] = tab_valide[choix_hasard];
            }
            //sur les lignes impaires, on inverse juste la ligne précédente
            else{
                int* ligne_inv = (int*) malloc(taille*sizeof(int));
                inverserLigne(grille[i-1],ligne_inv, taille);
                grille[i] = ligne_inv;
            }
        }
        // interaction avec l'utilisateur
        if(silence==2 && i!=0){
            printf("\nUne ligne a ete ajoutee... Pret? (tapez 1) \n");
            scanf(" %d", &retour_utilisateur);
            afficherGrille(grille,i,taille);}
    }
    if (silence==2) {
        printf("Voici la grille :\n");
        afficherGrille(grille,taille,taille);}
    //melanger grille pour plus d'aléa
    melangerTab(grille,taille);
    if (silence==2){
        printf("\nLa grille se melange... Pret? (tapez 1) \n");
        scanf(" %d", &retour_utilisateur);
        printf("Et voici la grille finale:\n");
        afficherGrille(grille,taille,taille);}
    //libérer l'espace alloué
    return (int **) grille;
}

void P3(int choix){
    //définition des variable
    int taille=4*choix, chc;
    //menu de choix
    do{
        printf("Quelle partie de l'algo vous interesse?\n");
        printf("\t1 - Voir uniquement les combinaisons possibles\n\t2 - Generer une grille entiere valide \n : ");
        scanf(" %d", &chc);
    }while(chc!=1 && chc !=2);
    //algorithme
    int **Temp=creer_grille(taille,chc);
    free(Temp);
}