//
// Created by lucas on 06/04/2022.
//

#ifndef PROJET_TAKUZU_P3_H
#define PROJET_TAKUZU_P3_H
#define T_4 4
#endif //PROJET_TAKUZU_P3_H

int random(int module);
int puissance(int chiffre,int exposant);
void transforme_binaire(int * tab, int numero, int size);
int sommeTab(int Tab[T_4],int size);
void inverserLigne(int *tab,int *result,int taille);
int comparerLignes(int* tab, int* tab2, int taille);
int verifPres(int** tab, int* temp,int taille,int nbrligne);
int verifierVoisins(int* tab,int taille);
void melangerTab(int** grille, int taille);
void creer_grille(int taille);
void P3();
