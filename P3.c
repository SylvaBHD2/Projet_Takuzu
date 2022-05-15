//
// Created by lucas on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "P3.h"
#include "P2.h"
#include <time.h>
#define T_4 4


int random(int module){

    return rand()%module;
}

int puissance(int chiffre,int exposant){
    int res=1;
    for (int i = 0; i < exposant; ++i) {
        res*=chiffre;
    }
    return res;
}

void afficher_bin(int* tab,int taille){

    for (int i = 0; i < taille; ++i) {
        printf("%d",*(tab+(taille - 1 - i)));
    }
    printf("\n");
}

void transforme_binaire(int * tab, int numero, int taille){
    int *code_binaire = (int*) malloc(taille * sizeof(int));
    for (int i = 0; i < taille; ++i) {
        code_binaire[i] = numero%2;
        numero = numero/2;
        tab[i] = code_binaire[i];
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
    // retourne le tableau en inversé (0=1 et 1=0)
    for (int i = 0; i < taille; ++i) {
        if (tab [i]==1)
            (result [i]=0);
        else {
            if (tab [i] == 0)
                (result[i] = 1);
            else
                printf("erreur d'adresse");
        }
    }
}

int comparerLignes(int* tab, int* tab2, int taille){
    //vérifie que tab et tab2 soit bien différents
    int test = 1;
    for (int i = 0; i < taille; ++i) {
        if(tab[i]!=tab2[i]){
            test=0;
        }
    }
    return test;
}

int verifPres(int** tab, int* temp,int taille,int nbrligne){
    //vérifie que nouvelle ligne soit bien différente et ne soit pas l'inverse d'une des lignes de tab
    for (int i = 0; i < nbrligne; ++i) {
        int res = comparerLignes(temp,tab[i],taille);
        if(res==1){
            // si une similitude est trouvée on sort
            return 1;
        }
    }
    return 0;
}

int verifierVoisinsLigne(int* tab, int taille){
    int val2, val1;
    for (int i = 2; i < taille; ++i) {
        val2=tab[i-2];
        val1=tab[i-1];
        int alias= val2+val1+tab[i];
        if (alias==0 ||alias==3)
            return 0;
    }
    return 1;
}

int verifierVoisinsColonne(int** tab, int col, int taille){
    int val2, val1;
    printf("\nla colonne %d; ",col);
    for (int i = 2; i < taille; ++i) {
        val2 = tab[i-2][col];
        val1 = tab[i-1][col];
        int alias = val2+val1+tab[i][col];
        printf("\nl'indice %d ; %d",i,alias);
        if (alias==0 || alias>=3)
            printf("\nla colonne %d est mauvaise!",col);
            return 0;
    }
    printf("\nla colonne %d est good to go",col);
    return 1;
}

void melangerTab(int** grille, int taille){
    //mélange les lignes de la grille pour plus d'aléa
    if (taille==4){
        for (int i = 0; i < random(taille); ++i) {
            int choix_hasard = random(taille),choix_hasard2=random(taille);
            int* temp = grille[choix_hasard];
            grille[choix_hasard] = grille[choix_hasard2];
            grille[choix_hasard2] = temp;
        }
    }
//    else {
//        int temoin=0;
//        while(temoin==0){
//            printf("Mélange en cours (%d)...\n",temoin);
//            for (int i = 0; i < random(taille); ++i) {
//                int choix_hasard = random(taille),choix_hasard2=random(taille);
//                int* temp = grille[choix_hasard];
//                grille[choix_hasard] = grille[choix_hasard2];
//                grille[choix_hasard2] = temp;
//            }
//            afficherGrille(grille,taille,taille);
//            for (int j = 0; j < taille; ++j) {
//                if (verifierVoisinsColonne(grille,j,taille))
//                    temoin++;
//            }
//            if (temoin==taille)
//                temoin=1;
//            else
//                temoin=0;
//        }
//    }
}

int** creer_grille(int taille,int silence){
    int** tab_valide=(int**) malloc(taille*taille/2*sizeof(int*));
    int nbrLigne=0;
    for (int i = 0; i < puissance(2,taille); ++i) {
        //nouveau pointeur
        int* temp=(int* )malloc(sizeof(int)*taille);
        transforme_binaire(temp, i, taille);
        if ( (sommeTab(temp, taille) == taille/2 ) && (verifierVoisinsLigne(temp, taille) == 1) ) {
            tab_valide[nbrLigne] = temp;
            ++nbrLigne;
        }
    }
    afficherGrille(tab_valide, nbrLigne, taille);
    printf("Voici ci-dessus la liste des combinaisons valides (%d lignes)\n",nbrLigne);
    // création de la grille
    int **grille = (int**) malloc(taille*sizeof(int*));
    // ajout de l'aléa
    int choix_hasard=random(nbrLigne);
    if (!silence) printf("Maintenant, la generation:\n");
    // choix des lignes génératrices
    for (int i = 0; i < taille; ++i) {
        // sur les lignes paires, on met de nouvelle lignes si elle ne sont pas déja sur l'echequier
        if (i==0){
            grille[i] = tab_valide[choix_hasard];
        }
        else {
            if (i%2==0){
                choix_hasard=random(nbrLigne);
                // si la ligne est déja présente
                int res = verifPres(grille,tab_valide[choix_hasard],taille,i);
                while (res==1) {
                    choix_hasard = random(nbrLigne);
                    res = verifPres(grille,tab_valide[choix_hasard],taille,i);
                };
                grille[i] = tab_valide[choix_hasard];
            }
            //sur les lignes impaires, on inverse juste la ligne précédente
            else{
                int* ligne_inv = (int*) malloc(taille*sizeof(int));
                inverserLigne(grille[i-1],ligne_inv, taille);
                grille[i] = ligne_inv;
            }
        }
    }
    if (!silence) {
        printf("Voici la grille :\n");
        afficherGrille(grille,taille,taille);}
    //melanger grille pour plus d'aléa
    melangerTab(grille,taille);
    if (!silence){
        printf("Et voici la grille finale:\n");
        afficherGrille(grille,taille,taille);}
    return (int **) grille;
}

void P3(int choix,int silence){
    int taille=4*choix;
    creer_grille(taille,silence);
}