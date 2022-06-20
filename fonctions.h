#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **construire_tab(FILE *fichier);
int **construire_tab_bin(FILE *fichier);
int *dimImg(FILE *fichier);
int *histogramme(int **image, int nb_lig, int nb_col);
int mean_img(int **image, int nblig, int nbcol);
int **luminance(int **image, int nblig, int nbcol);
int **inverse(int **image, int nblig, int nbcol);
int **NOT(int **image, int nblig, int nbcol);
int **transfLineaire(int **image, int nblig, int nbcol);
int **transfLineaireSat(int **image, int nblig, int nbcol);
int **egalisation(int **image, int *hist, int nblig, int nbcol);
int **addition(int **image1, int **image2, int *dim1, int *dim2);
int **soustraction(int **image1, int **image2, int *dim1, int *dim2);
int **multiplication(int **image, int nblig, int nbcol);
int **And_logique(int **image1, int **image2, int *dim1, int *dim2);
int **OR_XOR_logique(int **image1, int **image2, int *dim1, int *dim2, char info);
int **zoomm(int **image, int nblig, int nbcol, int zoom);
int min(int a, int b);
int max(int a, int b);
void makefile(int **matrice, int nblig, int nbcol);
void makefile2(int **matrice, int *dim1, int *dim2);
int min_img(int **matrice, int nblig, int nbcol);
int max_img(int **matrice, int nblig, int nbcol);
int est_binaire(int **matrice , int nblig, int nbcol);
int **convolution(int **image, int nblig, int nbcol); 
int **contour_prewitt_sobel_isotropic(int **image, int nblig, int nbcol, int info);
int **filtreMedian(int **image, int nblig, int nbcol);
int mediane(int *tab, int taille);

#endif // FONCTIONS_H_INCLUDED
