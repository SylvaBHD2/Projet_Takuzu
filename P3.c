//
// Created by lucas on 06/04/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "P3.h"
#include "P2.h"
#define T_4 4

void afficher_bin(int* tab,int size){

    for (int i = 0; i < size; ++i) {
        printf("%d",*(tab+(size-1-i)));
    }
    printf("\n");
}

int* transforme_binaire(int numero, int size){
    int *code_binaire = (int*) malloc(size*sizeof(int));
    for (int i = 0; i < size; ++i) {
        *(code_binaire+i) = numero%2;
        numero=numero/2;
    }
    afficher_bin(code_binaire,size);
}

int** creer_grille(int taille){
    int** tab_valide=(int**) malloc(taille*sizeof(int*));
    for (int i = 0; i < taille*taille; ++i) {
        int temp=transforme_binaire(i,taille);
        if (sommeLigne(temp,taille,0,0))
            *(tab_valide+i)=temp;
    }
}

void P3(){
    int taille;
    printf("choisir taille 4 ou 8 \n");
    scanf("%d",&taille);



}

