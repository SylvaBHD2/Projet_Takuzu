//
// Created by lucas on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "P3.h"
#include "P2.h"
#include <time.h>
#define T_4 4

/*
int random(int module){
    srand( time( NULL ) );
    return rand()%module;
}

int puissance(int chiffre,int exposant){
    int res=1;
    for (int i = 0; i < exposant; ++i) {
        res*=chiffre;
    }
    return res;
}

void afficher_bin(int* tab,int size){

    for (int i = 0; i < size; ++i) {
        printf("%d",*(tab+(size-1-i)));
    }
    printf("\n");
}

void transforme_binaire(int * tab, int numero, int size){
    int *code_binaire = (int*) malloc(size*sizeof(int));
    for (int i = 0; i < size; ++i) {
        *(code_binaire+i) = numero%2;
        numero=numero/2;
        *(tab+i) = *(code_binaire+i);
    }
}

// sert a la construction auto
int sommeTab(int Tab[T_4],int size){
    int somme=0;
    for (int i=0; i<size;i++){
        somme+=Tab[i];
    }
    return somme;
}

void inverserLigne(int *tab,int taille){
    // retourne le tableau en inversé (0=1 et 1=0)
    int *temp=(int*)malloc(sizeof(int)*taille);
    for (int i = 0; i < taille; ++i) {
        if (*(tab+i)==1)
            (*(temp+i)=0);
        else {
            if (*(tab + i) == 0)
                (*(temp + i) = 1);
            else
                printf("erreur d'adresse");
        }
    }
}

int comparerLignes(int* tab, int* temp, int taille){
    //vérifie que temp  soit bien différente des lignes
    for (int i = 0; i < taille; ++i) {
        if(*(tab+i)!=*(temp+i)){
            return 1;
        }
    }
    return 0;
}

int verifPres(int** tab, int* temp,int taille){
    //vérifie que nouvelle ligne soit bien différente et ne soit pas l'inverse d'une des lignes de tab
    for (int i = 0; i < taille; ++i) {
        if( (comparerLignes(*temp,*(tab+i),taille)==0)){
            // si une similitude est trouvée
            return 1;
        }
    }
    return 0;
}

void integrerLigne(int **tab, int *ligne, int num, int taille){
    //integre la ligne dans le tableau a la ligne num
    for (int i = 0; i < taille; ++i) {
        *(*(tab+num)+i)=*(ligne+i);
    }
}

void creer_grille(int taille){
    int** tab_valide=(int**) malloc(taille*sizeof(int*));
//    int tab_valide_dur[4][4];
//    printf(" %d",taille*sizeof(int*));
    int nbrLigne=0;
    for (int i = 0; i < taille*taille; ++i) {
        int* temp=(int* )malloc(sizeof(int)*taille);
        transforme_binaire(temp, i, taille);
        if (sommeTab(temp, taille) == 2) {
            for (int j = 0; j < taille; j++) {
//                printf("%d,%d ;",j,nbrLigne);
//                *(*(tab_valide_dur+nbrLigne)+j) = *(temp+j);
//                tab_valide_dur[nbrLigne][j] = temp[j];
//                tab_valide_dur[nbrLigne][j] = *(temp+j);
            }
            afficherLignePtr(temp, taille) ;
//            afficherLignePtr((int *) tab_valide_dur[nbrLigne], taille) ;
            nbrLigne++;
        }
    }

    printf("\n");
    afficherGrillePtr(tab_valide_dur, nbrLigne, taille);
    printf("ci dessus la liste des valides\n");

    // création de la grille
    int **grille ;
    // ajout de l'aléa
    int choix_hasard=random(nbrLigne);
    printf("le choix hasardeux : %d (nbr de ligne = %d)",choix_hasard,nbrLigne);
    afficherLignePtr(*(tab_valide+choix_hasard),taille);

    printf("maintenant la généaration");
    // choix des lignes génératrices
    for (int i = 0; i < taille/2; ++i) {
        // sur les lignes paires, on met de nouvelle lignes si elle ne sont pas déja sur l'echequier
        if (i%2==0){
            choix_hasard=random(puissance(2,taille));
            // si la ligne est déja présente
            while (verifPres(grille,*(tab_valide+choix_hasard),taille)==1) {
                choix_hasard=random(puissance(2,taille));
            };
            integrerLigne(grille,*(tab_valide+choix_hasard),i,taille);
            printf("ligne intégrer: \n");
            afficherLignePtr(*(tab_valide+choix_hasard),taille);
        }
        //sur les lignes impaires   PENSER A FAIRE DES MALLOCS et ne pas donner de ptrs?
        else{
            int* ligne_inv ;
            inverserLigne(ligne_inv,taille);
            integrerLigne(grille,*(tab_valide+choix_hasard),i,taille);
        }
    }
    afficherGrille(grille,taille);
    afficherGrillePtr(grille,taille,taille);
}

void P3(){
    int taille;
    printf("choisir taille 4 ou 8 :\n");
    scanf("%d",&taille);
    creer_grille(T_4);
}
*/