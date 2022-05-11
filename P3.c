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
//        printf("temoin diff %d _ %d",tab[i],tab2[i]);
        if(tab[i]!=tab2[i]){
            test=0;
        }
        printf("\n");
    }
    printf("sortie de la comparaison : %d",test);
    return test;
}

int verifPres(int** tab, int* temp,int taille,int nbrligne){
    //vérifie que nouvelle ligne soit bien différente et ne soit pas l'inverse d'une des lignes de tab
    printf("entree dans verifpres");
    for (int i = 0; i < nbrligne; ++i) {
        printf("\n%d eme boucle,\n ",i);
        afficherLignePtr(temp,taille);
        afficherLignePtr(tab[i],taille);
        int res = comparerLignes(temp,tab[i],taille);
        printf(" \nres est %d",res);
        if(res==1){
            // si une similitude est trouvée on sort
            printf("la ligne est trouvée");
            return 1;
        }
        printf("passé la condition if");
    }
    printf("la ligne n'est pas trouvée existe pas");
    return 0;
}

int verifierVoisins(int* tab,int taille){
    int val2, val1;
    for (int i = 2; i < taille; ++i) {
        val2=tab[i-2];
        val1=tab[i-1];
        int alias= val2+val1+tab[i];
        printf(" ; %d %d %d ==? %d ;",val1,val2,tab[i],alias);
        if (alias==0 ||alias==3)
            return 0;
    }
    return 1;
}

void melangerTab(int** grille, int taille){
    //mélange les lignes de la grille pour plus d'aléa
    for (int i = 0; i < random(taille); ++i) {
        int choix_hasard = random(taille),choix_hasard2=random(taille);
        printf("les choix hasardeux: %d %d ",choix_hasard,choix_hasard2);
        int* temp = grille[choix_hasard];
        *grille[choix_hasard] = *grille[choix_hasard2];
        *grille[choix_hasard2] = *temp;
    }
}

void creer_grille(int taille){
    int** tab_valide=(int**) malloc(taille*taille*sizeof(int*)); // pas opti
//    printf(" %d",taille*sizeof(int*));
    int nbrLigne=0;
    for (int i = 0; i < taille*taille; ++i) {
        //nouveau pointeur
        int* temp=(int* )malloc(sizeof(int)*taille);
        transforme_binaire(temp, i, taille);
        if ( (sommeTab(temp, taille) == taille/2 ) && (verifierVoisins(temp,taille)==1) ) {
            tab_valide[nbrLigne] = temp;
//            afficherLignePtr(temp, taille) ;
//            afficherLignePtr(tab_valide[nbrLigne], taille) ;
            ++nbrLigne;
        }
    }
    afficherGrillePtr(tab_valide, nbrLigne, taille);
    printf("ci dessus la liste des valides\n");

    // création de la grille
    int **grille = (int**) malloc(taille*sizeof(int*));
    // ajout de l'aléa
    int choix_hasard=random(nbrLigne);
//    printf("le choix hasardeux : %d (nbr de ligne = %d)",choix_hasard,nbrLigne);
    afficherLignePtr(tab_valide[choix_hasard],taille);

    printf("Maintenant, la généaration\n");
    // choix des lignes génératrices
    for (int i = 0; i < taille; ++i) {
        // sur les lignes paires, on met de nouvelle lignes si elle ne sont pas déja sur l'echequier
        if (i==0){
//            printf("initialisation\n");
            grille[i] = tab_valide[choix_hasard];
//            integrerLigne(grille,tab_valide[choix_hasard],i,taille);
            afficherLignePtr(tab_valide[choix_hasard],taille);
            printf(": cette ligne est mtn integree \n");}
        else {
            if (i%2==0){
                printf("entree dans les pairs:\n");
                choix_hasard=random(nbrLigne);
                printf("\nchoix du hasard: %d,\n", choix_hasard);
                // si la ligne est déja présente
                int res = verifPres(grille,tab_valide[choix_hasard],taille,i);
                printf("%d eme boucle, res est %d\n ",i,res);
                while (res==1) {
                    printf("\nchoix du hasard: %d,\n", choix_hasard);
                    choix_hasard = random(nbrLigne);
                    res = verifPres(grille,tab_valide[choix_hasard],taille,i);
                    printf("%d eme boucle, res est %d\n ",i,res);
                };
                printf("passé la pres");
//                integrerLigne(grille,tab_valide[choix_hasard],i,taille);
                grille[i] = tab_valide[choix_hasard];
                printf("ligne intégrer: \n");
                afficherLignePtr(tab_valide[choix_hasard],taille);
            }
            //sur les lignes impaires, on inverse juste la ligne précédente
            else{
                int* ligne_inv = (int*) malloc(taille*sizeof(int));
                inverserLigne(grille[i-1],ligne_inv, taille);
                grille[i] = ligne_inv;
                afficherLignePtr(ligne_inv,taille);
                printf(": cette ligne est mtn integree  \n");}
            }
    }
//    afficherGrille(grille,taille);
    printf("Voici la grille :\n");
    afficherGrillePtr(grille,taille,taille);
    //melanger grille
    melangerTab(grille,taille);
    printf("Voici la grille finale:\n");
    afficherGrillePtr(grille,taille,taille);
}

void P3(){
    int taille;
    printf("choisir taille 4 ou 8 :\n");
    scanf("%d",&taille);
    creer_grille(taille);
}