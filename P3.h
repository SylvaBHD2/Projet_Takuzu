//
// Created by lucas on 06/04/2022.
//

#ifndef PROJET_TAKUZU_P3_H
#define PROJET_TAKUZU_P3_H
#define T_4 4
#endif //PROJET_TAKUZU_P3_H

int random(int module);
int puissance(int chiffre,int exposant);
void transforme_binaire(int * tab, int numero, int taille);
int sommeTab(int *Tab,int taille);
void inverserLigne(int *tab,int *result,int taille);
int comparerLignes(int* tab, int* tab2, int taille);
int verifPres(int** tab, int* temp,int taille,int nbrligne);
int verifierVoisinsLigne(int* tab, int taille);
void melangerTab(int** grille, int taille);
int** creer_grille(int taille,int silence);
void P3(int choix,int silence);
