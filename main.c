#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#define TAILLE_MAX 100


int main()
{
    FILE *fichier = NULL;
    FILE *fichier2 = NULL;
    int **image = NULL;
    int **image2 = NULL;
    int **imageLum = NULL;
    int *taillImg = NULL;
    int *taillImg2 = NULL;
    int **imageT = NULL;
    int **imageInv = NULL;
    int **imageTSat = NULL;
    int **imageEgal = NULL;
    int **imageAdd = NULL;
    int **imageSous = NULL;
    int **imageMult = NULL;
    int **image_and_logique = NULL;
    int **image_OU_logique = NULL;
    int **image_NOT = NULL;
    int **image_Interp = NULL;
    int ** imageConv = NULL;
    int ** imageConv2 = NULL;
    int ** add = NULL;
    int *hist = NULL;
    char info = 'X';
    int zoom=2;
    
    
   

    // premiere image : sa matrice
    fichier = fopen("cam.txt", "r");
    image = construire_tab(fichier);

    // premiere image : ses dimensions
    fichier = fopen("cam.txt", "r");
    taillImg = dimImg(fichier);

    // deuxieme image : sa matrice
    fichier2 = fopen("imagebin2.txt", "r");
    image2 = construire_tab_bin(fichier2);
    
    // deuxieme image : ses dimensions
    fichier2 = fopen("imagebin2.txt", "r");
    taillImg2 = dimImg(fichier2);

    // Construction de l'histogramme
    // hist = histogramme(image, taillImg[0], taillImg[1]);

    // imageLum = luminance(image,taillImg[0], taillImg[1] );
    // imageInv = inverse(image,taillImg[0], taillImg[1] );

    // makefile(imageLum,taillImg[0], taillImg[1] );
    // printf("%d", max_img(image,taillImg[0],taillImg[1]));

    // imageT = transfLineaire(image,taillImg[0], taillImg[1] );
    // imageTSat = transfLineaireSat(image,taillImg[0], taillImg[1] );

    // Egalisation de l'histogramme
    // imageEgal = egalisation(image, hist,taillImg[0],taillImg[1]);
    // makefile(imageEgal,taillImg[0], taillImg[1] );

    // Soustraction d'images
    // imageSous = soustraction(image, image2,taillImg[0],taillImg[1]);
    // makefile(imageSous,taillImg[0], taillImg[1] );

    // Multiplication d'image par un facteur
    // imageMult = multiplication(image, taillImg[0],taillImg[1]);
    // makefile(imageMult,taillImg[0], taillImg[1] );

    // Et logique
    //image_OU_logique = OR_XOR_logique(image, image2, taillImg, taillImg2, info);
    //makefile2(image_OU_logique, taillImg, taillImg2);

    //NOT logique
    //image_NOT = NOT(image,taillImg[0], taillImg[1] );
    //makefile(image_NOT, taillImg[0], taillImg[1]);

   
    /*printf("Entrer la taille du zoom (ex: 2,3,4 ou plus) : ");
    scanf("%d",&zoom);
    image_Interp = zoomm(image, taillImg[0], taillImg[1],zoom);
    makefile(image_Interp, taillImg[0]*zoom, taillImg[1]*zoom);*/

    /*imageConv = contour_prewitt(image, taillImg[0],taillImg[1]);
    makefile(imageConv, taillImg[0], taillImg[1]);*/

    imageConv = contour_prewitt_sobel_isotropic(image, taillImg[0],taillImg[1],3);
    imageConv2 = contour_prewitt_sobel_isotropic(image, taillImg[0],taillImg[1],4);
    add = addition(imageConv, imageConv2, taillImg, taillImg);
    makefile2(add, taillImg, taillImg);
    //makefile(imageConv, taillImg[0], taillImg[1]);

    return 0;
}

