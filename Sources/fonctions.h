#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//Pour l'affichage de l'histogramme
struct Tuple3
{
    int **image;
    int nblig;
    int nbcol;
};
typedef struct Tuple3 Tuple3;



int **construire_tab(FILE *fichier); //dej
int **construire_tab_bin(FILE *fichier); //dej
int *dimImg(FILE *fichier); //dej
int mean_img(int **image, int nblig, int nbcol); //dej
int *histogramme(int **image, int nb_lig, int nb_col); //dej
Tuple3 affichageHistogramme(int **image, int nblig, int nbcol);
int **luminance(int **image, int nblig, int nbcol); //dej
int **inverse(int **image, int nblig, int nbcol); //dej
int **NOT(int **image, int nblig, int nbcol); //dej
int **transfLineaire(int **image, int nblig, int nbcol); //dej
int **transfLineaireSat(int **image, int nblig, int nbcol); //dej
int **egalisation(int **image, int *hist, int nblig, int nbcol); //dej
int **addition(int **image1, int **image2, int *dim1, int *dim2); //dej
int **soustraction(int **image1, int **image2, int *dim1, int *dim2); //dej
int **multiplication(int **image, int nblig, int nbcol); //dej
int **And_logique(int **image1, int **image2, int *dim1, int *dim2); //dej
int **OR_XOR_logique(int **image1, int **image2, int *dim1, int *dim2, char info); //dej
int **zoomm(int **image, int nblig, int nbcol, int zoom);//dej
int min(int a, int b); //dej
int max(int a, int b); //dej
void makefile(int **matrice, int nblig, int nbcol, int argc, char **argv); //dej
void makefile2(int **matrice, int *dim1, int *dim2,int argc, char **argv); //dej
int min_img(int **matrice, int nblig, int nbcol);//dej
int max_img(int **matrice, int nblig, int nbcol);//dej
int est_binaire(int **matrice , int nblig, int nbcol);//dej
int **convolution(int **image, int nblig, int nbcol); //dej
int **filtreMoyenneurGaussien(int **image, int nblig, int nbcol, char info);
int **filtreMedian(int **image, int nblig, int nbcol);//dej
int **contour_prewitt_sobel(int **image, int nblig, int nbcol, int info);//dej
Tuple3 hough_transform(int **image,int *dim);
int **test();
int **robert(int **image, int nblig, int nbcol, int info);
int mediane(int *tab, int taille);//dej
int Otsu(int **image, int nblig, int nbcol);//dej
int **binarisation(int **image, int nblig, int nbcol);//dej
int **binarisationOtsu(int **image, int nblig, int nbcol);//dej
int findCluster(float *tabCentre, int k, int pixel );//dej
int valeurAbso(int nbre);//dej
int **kMeans(int **image, int nblig, int nbcol);//dej


#endif // FONCTIONS_H_INCLUDED
