#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#define TAILLE_MAX 100

//Structure utilisée dans la fonction Kmeans
struct Tuple
{
    int valPixel;
    int centre;
};
typedef struct Tuple Tuple;

int **gestionImgBin(char *nomImg)
{
    FILE *fichier = NULL;
    int **image = NULL;
    int *taillImg = NULL;
    // premiere image : sa matrice
    fichier = fopen(nomImg, "r");
    image = construire_tab_bin(fichier);

    return image;
}

int main(int argc, char **argv)
{
    FILE *fichier = NULL; //Important
    FILE *fichier2 = NULL; //Important
    int **image = NULL; //Important
    int **image2 = NULL; //Important
    
    int *taillImg = NULL; //Important
    int *taillImg2 = NULL; //Important
    int ** add = NULL; //Important
    int *hist = NULL; //Important
    
    // premiere image : sa matrice
    fichier = fopen(argv[2], "r");
    image = construire_tab(fichier);

    // premiere image : ses dimensions
    fichier = fopen(argv[2], "r");
    taillImg = dimImg(fichier);

    if(strcmp(argv[1], "addition") == 0 || strcmp(argv[1], "soustraction") == 0)
    {
       // deuxieme image : sa matrice
        fichier2 = fopen(argv[3], "r");
        image2 = construire_tab(fichier2);
        
        // deuxieme image : ses dimensions
        fichier2 = fopen(argv[3], "r");
        taillImg2 = dimImg(fichier2); 
    }

    if(strcmp(argv[1], "andGrisBin") == 0 || strcmp(argv[1], "andBinBin") == 0 || strcmp(argv[1], "orGrisBin") == 0 || strcmp(argv[1], "orBinBin") == 0 || strcmp(argv[1], "xorBinBin") == 0)
    {
        // deuxieme image : sa matrice
        fichier2 = fopen(argv[3], "r");
        image2 = construire_tab_bin(fichier2);
        
        // deuxieme image : ses dimensions
        fichier2 = fopen(argv[3], "r");
        taillImg2 = dimImg(fichier2);
    }
    
    // ********************************DEBUT****************************************//

    //Affichage des valeurs de l'histogramme
    if(strcmp(argv[1], "histogramme") == 0)
    {
        hist = histogramme(image, taillImg[0], taillImg[1]);
        for(int i=0;i<256;i++)
        {
            printf("Pixel %d : %d occurences\n",i,hist[i]);
        }
    }
    //commande--->  ./main histogramme images/circuit.pgm


    // Construction de l'histogramme
    else if(strcmp(argv[1], "affichHistogramme") == 0)
    {
        Tuple3 t;
        t = affichageHistogramme(image, taillImg[0], taillImg[1]);
        makefile(t.image, t.nblig, t.nbcol, argc, argv);
    }
    //commande--->  ./main affichHistogramme images/circuit.pgm images/histo


    //Augmenter la luminance d'une image
    else if(strcmp(argv[1], "luminance") == 0)
    {
        int **imageLum = NULL;
        imageLum = luminance(image, taillImg[0], taillImg[1]);
        makefile(imageLum, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main luminance images/cam.pgm images/camLum


    //Transformation Lineaire Simple
    else if(strcmp(argv[1], "transfLineaireSimple") == 0)
    {
        int **imageTransL = NULL;
        imageTransL = transfLineaire(image, taillImg[0], taillImg[1]);
        makefile(imageTransL, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main transfLineaireSimple images/filletteEgal.pgm images/camTra


    //Transformation linéaire avec saturation
    else if(strcmp(argv[1], "transfLineaireSat") == 0)
    {
        int **imageTSat = NULL;
        imageTSat = transfLineaireSat(image, taillImg[0], taillImg[1]);
        makefile(imageTSat, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main transfLineaireSat images/filletteEgal.pgm images/camTrasat


    //Egalisation d'histogramme d'une image
    else if(strcmp(argv[1], "egalisation") == 0)
    {
        int **imageEgal = NULL;
        hist = histogramme(image, taillImg[0], taillImg[1]);
        imageEgal = egalisation(image,hist, taillImg[0], taillImg[1]);
        makefile(imageEgal, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main egalisation images/filletteEgal.pgm images/fiEgal


    //Addition de deux images en niveaux de gris (pgm)
    else if(strcmp(argv[1], "addition") == 0)
    {
        int **imageAdd = NULL;
        imageAdd = addition(image, image2, taillImg, taillImg2);
        makefile2(imageAdd, taillImg, taillImg2, argc, argv);
    }
    //commande--->  ./main addition images/bonhomeBlouson.pgm images/bonhomeBlouson.pgm images/Iadd


    //Soustraction de deux images en niveaux de gris (pgm)
    else if(strcmp(argv[1], "soustraction") == 0)
    {
        int **imageSous = NULL;
        imageSous = soustraction(image, image2, taillImg, taillImg2);
        makefile2(imageSous, taillImg, taillImg2, argc, argv);
    }
    //commande--->  ./main soustraction images/empreinte.pgm images/bonhomeBlouson.pgm images/Isous


    //Multiplication d'une image par un facteur
    else if(strcmp(argv[1], "multiplication") == 0)
    {
        int **imageMult = NULL; 
        imageMult = multiplication(image, taillImg[0], taillImg[1]);
        makefile(imageMult, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main multiplication images/imageMult1.pgm images/Imult


    //Inverse d'une image en niveaux de gris (pgm)
    else if(strcmp(argv[1], "inverse") == 0)
    {
        int **imageInv = NULL; 
        imageInv = inverse(image, taillImg[0], taillImg[1]);
        makefile(imageInv, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main inverse images/cam.pgm images/Iinv


    //And_logique entre une image en niveaux de gris et une image binaire (pbm)
    else if(strcmp(argv[1], "andGrisBin") == 0)
    {
        int **imageGrisBin = NULL;
        imageGrisBin = And_logique(image, image2, taillImg, taillImg2);
        makefile2(imageGrisBin, taillImg, taillImg2, argc, argv);
    }
    //commande---> ./main andGrisBin images/tour.pgm images/petitcoinOu.pbm images/andGrisBin


    //And_logique entre deux images binaires
    else if(strcmp(argv[1], "andBinBin") == 0)
    {
        image = gestionImgBin(argv[2]);
        int **imageBinBin = NULL;
        imageBinBin = And_logique(image, image2, taillImg, taillImg2);
        makefile2(imageBinBin, taillImg, taillImg2, argc, argv);
    }
    //commande--->  ./main andBinBin images/imagebin.pbm images/imagebin2.pbm images/andBinBin


    //OR_logique entre une image en niveaux de gris et une image binaire (pbm)
    else if(strcmp(argv[1], "orGrisBin") == 0)
    {
        int **imageGrisBin = NULL; 
        imageGrisBin = OR_XOR_logique(image, image2, taillImg, taillImg2,'A');
        makefile2(imageGrisBin, taillImg, taillImg2, argc, argv);
    }
    //commande--->  ./main orGrisBin images/tour.pgm images/petitcoinOu.pbm images/orGrisBin


    //OR_logique entre deux images binaires
    else if(strcmp(argv[1], "orBinBin") == 0)
    {
        image = gestionImgBin(argv[2]);
        int **imageBinBin = NULL; 
        imageBinBin = OR_XOR_logique(image, image2, taillImg, taillImg2,'O');
        makefile2(imageBinBin, taillImg, taillImg2, argc, argv);
    }
    //commande--->  ./main orBinBin images/imagebin.pbm images/imagebin2.pbm images/orBinBin


    //XOR_logique entre deux images binaires
    else if(strcmp(argv[1], "xorBinBin") == 0)
    {
        image = gestionImgBin(argv[2]);
        int **imageXorBinBin = NULL; 
        imageXorBinBin = OR_XOR_logique(image, image2, taillImg, taillImg2,'X');
        makefile2(imageXorBinBin, taillImg, taillImg2, argc, argv);
    }
    //commande--->  ./main xorBinBin images/imagebin.pbm images/imagebin2.pbm images/xorBinBin


    //NOT d'une image bianire
    else if(strcmp(argv[1], "notBin") == 0)
    {
        image = gestionImgBin(argv[2]);
        int **imageNotBin = NULL; 
        imageNotBin = NOT(image, taillImg[0], taillImg[1]);
        makefile(imageNotBin, taillImg[0], taillImg[1], argc, argv);
    }
    //commande---> ./main notBin images/imagebin.pbm images/notBin


    //Zoom d'une image en niveaux de gris
    else if(strcmp(argv[1], "zoom") == 0)
    {
        int **imageZoom = NULL;
        int zom;
        printf("Entrer la taille du zoom (ex: 2,3,4 ou plus) : ");
        scanf("%d",&zom);
        imageZoom = zoomm(image, taillImg[0], taillImg[1],zom);
        makefile(imageZoom, taillImg[0]*zom, taillImg[1]*zom, argc, argv);
    }
    //commande---> ./main zoom images/cam.pgm images/Izoom


    //Filtre Median
    else if(strcmp(argv[1], "filtreMedian") == 0)
    {
        int **imageFiltreMedian = NULL;
        imageFiltreMedian = filtreMedian(image, taillImg[0], taillImg[1]);
        makefile(imageFiltreMedian, taillImg[0], taillImg[1], argc, argv);
    }
    //commande---> ./main filtreMedian images/circuit.pgm images/circuitMed


    //Filtre Moyenneur
    else if(strcmp(argv[1], "filtreMoyenneur") == 0)
    {
        int **imageFiltreMoyenneur = NULL;
        imageFiltreMoyenneur = filtreMoyenneurGaussien(image, taillImg[0], taillImg[1], 'M');
        makefile(imageFiltreMoyenneur, taillImg[0], taillImg[1], argc, argv);
        
    }
    //commande--->  ./main filtreMoyenneur images/circuit.pgm images/circuitMoy


    //Filtre Gaussien
    else if(strcmp(argv[1], "filtreGaussien") == 0)
    {
        int **imageFiltreGaussien= NULL;
        imageFiltreGaussien = filtreMoyenneurGaussien(image, taillImg[0], taillImg[1], 'G');
        makefile(imageFiltreGaussien, taillImg[0], taillImg[1], argc, argv);
        
    }


    //Convolution
    else if(strcmp(argv[1], "convolution") == 0)
    {
        int **imageConv= NULL;
        imageConv = convolution(image, taillImg[0], taillImg[1]);
        makefile(imageConv, taillImg[0], taillImg[1], argc, argv);
    }
    //commande---> ./main convolution images/circuit.pgm images/circuitConv


    //Détection des contours avec prewitt
    else if(strcmp(argv[1], "prewitt") == 0)
    {
        int **imageConv= NULL;
        int **imageConv2= NULL;
        imageConv = contour_prewitt_sobel(image, taillImg[0],taillImg[1],1);
        imageConv2 = contour_prewitt_sobel(image, taillImg[0],taillImg[1],2);
        add = addition(imageConv, imageConv2, taillImg, taillImg);
        makefile2(add, taillImg, taillImg, argc, argv);
    }
    //commande---> ./main prewitt images/cam.pgm images/prewittCam


    //Détection des contours avec prewiit + binarisation
    else if(strcmp(argv[1], "prewittSeuil") == 0)
    {
        int **imageConv= NULL;
        int **imageConv2= NULL;
        imageConv = contour_prewitt_sobel(image, taillImg[0],taillImg[1],1);
        imageConv2 = contour_prewitt_sobel(image, taillImg[0],taillImg[1],2);
        add = addition(imageConv, imageConv2, taillImg, taillImg);
        add = binarisation(add, taillImg[0],taillImg[1]);
        makefile2(add, taillImg, taillImg, argc, argv);
    }
    //commande--->  ./main prewittSeuil images/cam.pgm images/prewittSeuilCam


    //Détection des contours avec sobel
    else if(strcmp(argv[1], "sobel") == 0)
    {
        int **imageConv= NULL; 
        int **imageConv2 = NULL;
        imageConv = contour_prewitt_sobel(image, taillImg[0],taillImg[1],3);
        imageConv2 = contour_prewitt_sobel(image, taillImg[0],taillImg[1],4);
        add = addition(imageConv, imageConv2, taillImg, taillImg);
        makefile2(add, taillImg, taillImg, argc, argv);
    }
    //commande--->  ./main sobel images/cam.pgm images/sobelCam


    //Détection des contours avec sobel + binarisation
    else if(strcmp(argv[1], "sobelSeuil") == 0)
    {
        int **imageConv= NULL; 
        int **imageConv2 = NULL;
        imageConv = contour_prewitt_sobel(image, taillImg[0],taillImg[1],3);
        imageConv2 = contour_prewitt_sobel(image, taillImg[0],taillImg[1],4);
        add = addition(imageConv, imageConv2, taillImg, taillImg);
        add = binarisation(add, taillImg[0],taillImg[1]);
        makefile2(add, taillImg, taillImg, argc, argv);
    }
    //commande--->  ./main sobelSeuil images/cam.pgm images/sobelSeuilCam


    //Détection des contours avec robert sans binarisation
    else if(strcmp(argv[1], "robert") == 0)
    {
        int **imageConv= NULL; 
        int **imageConv2 = NULL;
        imageConv = robert(image, taillImg[0],taillImg[1],1);
        imageConv2 = robert(image, taillImg[0],taillImg[1],2);
        add = addition(imageConv, imageConv2, taillImg, taillImg);
        makefile2(add, taillImg, taillImg, argc, argv);
    }
    //commande--->  ./main robert images/cam.pgm images/robertCam

    //Filtre de robert avec binarisation (il faut mettre un petit seuil pour avoir une bonne image)
    else if(strcmp(argv[1], "robertSeuil") == 0)
    {
        int **imageConv= NULL; 
        int **imageConv2 = NULL;
        imageConv = robert(image, taillImg[0],taillImg[1],1);
        imageConv2 = robert(image, taillImg[0],taillImg[1],2);
        add = addition(imageConv, imageConv2, taillImg, taillImg);
        add = binarisation(add, taillImg[0],taillImg[1]);
        makefile2(add, taillImg, taillImg, argc, argv);
    }
    //commande--->  ./main robertSeuil images/cam.pgm images/robertSeuilCam

    
    //Détection des contours avec le laplacien4 sans binarisation
    else if(strcmp(argv[1], "laplacien4") == 0)
    {
        int **imageConv= NULL; 
        imageConv = contour_prewitt_sobel(image, taillImg[0],taillImg[1],5);
        makefile(imageConv, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main laplacien4 images/regulateur.pgm images/lapla4Reg


    //Détection des contours avec le laplacien8 sans binarisation
    else if(strcmp(argv[1], "laplacien8") == 0)
    {
        int **imageConv= NULL; 
        imageConv = contour_prewitt_sobel(image, taillImg[0],taillImg[1],6);
        makefile(imageConv, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main laplacien8 images/regulateur.pgm images/lapla8Reg

    
    //Seuil fourni par l'algotihme d'Otsu
    else if(strcmp(argv[1], "otsu") == 0)
    {
        int seuil = Otsu(image, taillImg[0], taillImg[1]);
        printf("Le seuil donné par l'algorithe d'Otsu est : %d\n", seuil);
    }
    //commande--->  ./main otsu images/empreinte.pgm


    //Binarisation d'une image en utilisant le seuil fourni par l'algorithme d'Otsu
    else if(strcmp(argv[1], "binarisationOtsu") == 0)
    {
        int **imagebinarise= NULL;
        imagebinarise = binarisationOtsu(image, taillImg[0], taillImg[1]);
        makefile(imagebinarise, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main binarisationOtsu images/regulateur.pgm images/IbinariseOtsu


    //Binarisation d'une image en utilisant un seuil fourni par l'utilisateur
    else if(strcmp(argv[1], "binarisation") == 0)
    {
        int **imagebinarise= NULL;
        imagebinarise = binarisation(image, taillImg[0], taillImg[1]);
        makefile(imagebinarise, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main binarisation images/regulateur.pgm images/Ibinarise


    //Segmentation d'une image à l'aide de Kmeans
    else if(strcmp(argv[1], "segmentationKMeans") == 0)
    {
        int **imagekmeans= NULL; 
        imagekmeans = kMeans(image, taillImg[0], taillImg[1]);
        makefile(imagekmeans, taillImg[0], taillImg[1], argc, argv);
    }
    //commande--->  ./main segmentationKMeans images/fruits.pgm images/IKmeans
    
    return 0;
}

