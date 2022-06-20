#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"
#define TAILLE_MAX 100

int **construire_tab(FILE *fichier)
{

    int nb_lig = 0, nb_col = 0, i, j, val = 0;
    int **tab = NULL;
    char chaine[TAILLE_MAX] = "";

    if (fichier != NULL)
    {
        fgets(chaine, TAILLE_MAX, fichier);
        fgets(chaine, TAILLE_MAX, fichier);

        fscanf(fichier, "%d", &nb_col);
        fscanf(fichier, "%d", &nb_lig);
        fscanf(fichier, "%d", &val);

        tab = malloc(nb_lig * sizeof(int *));
        for (i = 0; i < nb_lig; i++)
        {
            tab[i] = malloc(nb_col * sizeof(int));
            for (j = 0; j < nb_col; j++)
            {
                fscanf(fichier, "%d", &val);
                tab[i][j] = val;
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur d'ouverture du fichier");
    }
    return tab;
}

int **construire_tab_bin(FILE *fichier)
{

    int nb_lig = 0, nb_col = 0, i, j, val = 0, nb = 0, aide;
    char valChar = 'C';
    int **tab = NULL;
    char chaine[TAILLE_MAX] = "";

    if (fichier != NULL)
    {
        fgets(chaine, TAILLE_MAX, fichier);
        fgets(chaine, TAILLE_MAX, fichier);

        fscanf(fichier, "%d", &nb_col);
        fscanf(fichier, "%d", &nb_lig);

        tab = malloc(nb_lig * sizeof(int *));
        for (i = 0; i < nb_lig; i++)
        {
            aide = i;
            tab[i] = malloc(nb_col * sizeof(int));
            for (j = 0; j < nb_col; j++)
            {
                fscanf(fichier, "%c", &valChar);
                if (valChar == '1')
                {
                    tab[i][j] = 1;
                }

                else if (valChar == '0')
                {
                    tab[i][j] = 0;
                }
                else
                {
                    if (valChar == '\n')
                    {
                        j = j - 1;
                        i = aide;
                    }
                }
            }
        }
        fclose(fichier);
    }
    else
    {
        printf("Erreur d'ouverture du fichier");
    }
    return tab;
}

int *dimImg(FILE *fichier)
{
    char chaine[TAILLE_MAX] = "";
    int nb_lig = 5, nb_col = 3;
    int *tab = NULL;
    tab = malloc(2 * sizeof(int *));
    if (fichier != NULL)
    {
        fgets(chaine, TAILLE_MAX, fichier);
        fgets(chaine, TAILLE_MAX, fichier);

        fscanf(fichier, "%d", &nb_col);
        fscanf(fichier, "%d", &nb_lig);
        tab[0] = nb_lig;
        tab[1] = nb_col;

        fclose(fichier);
    }
    else
    {
        printf("Erreur d'ouverture du fichier");
    }
    return tab;
}

int *histogramme(int **image, int nb_lig, int nb_col)
{
    // int h[256] = {0},i,j;
    int *h = NULL;
    h = malloc(256 * sizeof(int *));
    memset(h, 0, sizeof(int) * 256);
    for (int i = 0; i < nb_lig; i++)
    {
        for (int j = 0; j < nb_col; j++)
        {
            int a = image[i][j];
            h[a]++;
        }
    }
    /*for(int i=0;i<=255;i++)
    {
        printf("Pixel %d : %d occurences \n",i,h[i]);
    }*/
    return h;
}

int mean_img(int **image, int nblig, int nbcol)
{
    int sum = 0;
    float mean;

    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            sum = sum + image[i][j];
        }
    }
    mean = sum / (nblig * nbcol);
    return mean;
}

int **luminance(int **image, int nblig, int nbcol)
{
    int **imageLum = NULL;
    imageLum = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageLum[i] = malloc(nbcol * sizeof(int));
    }

    int mean = mean_img(image, nblig, nbcol);
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            imageLum[i][j] = min(255, (image[i][j] + mean));
        }
    }
    return imageLum;
}

int **inverse(int **image, int nblig, int nbcol)
{
    int **imageInv = NULL;
    imageInv = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageInv[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            imageInv[i][j] = 255 - image[i][j];
        }
    }

    return imageInv;
}

int **NOT(int **image, int nblig, int nbcol)
{
    int **imageInv = NULL;
    imageInv = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageInv[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            if (image[i][j] == 1)
                imageInv[i][j] = 255;
            else if (image[i][j] == 0)
                imageInv[i][j] = 0;
        }
    }

    return imageInv;
}

int min(int a, int b)
{
    int res = 0;
    if (a <= b)
    {
        res = a;
    }
    else
    {
        res = b;
    }
    return res;
}

int max(int a, int b)
{
    int res = 0;
    if (a <= b)
    {
        res = b;
    }
    else
    {
        res = a;
    }
    return res;
}

void makefile(int **matrice, int nblig, int nbcol)
{
    FILE *fichier = NULL;
    fichier = fopen("imageTrans.txt", "w");
    int tailleMax = 255;
    if (fichier != NULL)
    {
        fputs("P2\n", fichier);
        fputs("#Make by Bleriot Tchamba\n", fichier);
        fprintf(fichier, "%d %d \n", nbcol, nblig);
        fprintf(fichier, "%d \n", tailleMax);

        for (int i = 0; i < nblig; i++)
        {
            for (int j = 0; j < nbcol; j++)
            {
                fprintf(fichier, "%d \n", matrice[i][j]);
            }
        }

        fclose(fichier);
    }
    else
    {
        printf("Erreur d'ouverture du fichier");
    }
}

void makefile2(int **matrice, int *dim1, int *dim2)
{
    int nblig = min(dim1[0], dim2[0]);
    int nbcol = min(dim1[1], dim2[1]);
    FILE *fichier = NULL;
    fichier = fopen("imageTrans.txt", "w");
    int tailleMax = 255;
    if (fichier != NULL)
    {
        fputs("P2\n", fichier);
        fputs("#Make by Bleriot Tchamba\n", fichier);
        fprintf(fichier, "%d %d \n", nbcol, nblig);
        fprintf(fichier, "%d \n", tailleMax);

        for (int i = 0; i < nblig; i++)
        {
            for (int j = 0; j < nbcol; j++)
            {
                fprintf(fichier, "%d \n", matrice[i][j]);
            }
        }

        fclose(fichier);
    }
    else
    {
        printf("Erreur d'ouverture du fichier");
    }
}

int min_img(int **matrice, int nblig, int nbcol)
{
    int min = matrice[0][0];
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            if (matrice[i][j] <= min)
            {
                min = matrice[i][j];
            }
        }
    }
    return min;
}

int max_img(int **matrice, int nblig, int nbcol)
{
    int max = matrice[0][0];
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            if (matrice[i][j] >= max)
            {
                max = matrice[i][j];
            }
        }
    }
    return max;
}

int **transfLineaire(int **image, int nblig, int nbcol)
{
    int LUT[256] = {0};
    for (int i = 0; i <= 255; i++)
    {
        LUT[i] = 255 * (i - min_img(image, nblig, nbcol)) / (max_img(image, nblig, nbcol) - min_img(image, nblig, nbcol));
    }

    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            imageT[i][j] = LUT[image[i][j]];
        }
    }
    return imageT;
}

int **transfLineaireSat(int **image, int nblig, int nbcol)
{
    float Smin, Smax;
    float val;
    int test = 1;

    printf("Entrer la valeur minimale (Smin) : ");
    scanf("%f", &Smin);
    while (test == 1)
    {
        printf("Entrer la valeur maximale (Smax) : ");
        scanf("%f", &Smax);
        if (Smax > Smin)
        {
            test = 0;
        }
        else
        {
            test = 1;
            printf(" Smax doit etre supérieur à Smin !!!");
        }
    }

    int LUT[256] = {0};
    for (int i = 0; i <= 255; i++)
    {
        val = 255 * (i - Smin) / (Smax - Smin);
        if (val < 0)
        {
            LUT[i] = 0;
        }
        else if (val > 255)
        {
            LUT[i] = 255;
        }
        else
        {
            LUT[i] = val;
        }
    }

    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            imageT[i][j] = LUT[image[i][j]];
        }
    }
    return imageT;
}

int **egalisation(int **image, int *hist, int nblig, int nbcol)
{
    float tailleImg = nblig * nbcol;

    // Creation du tableau de l'histogramme normalisé
    float *histNorm = malloc(256 * sizeof(float *));

    // Normalisation de l'histogramme
    for (int i = 0; i < 256; i++)
    {
        histNorm[i] = hist[i] / tailleImg;
    }

    // Densité de probabilité normalisée
    for (int i = 1; i < 256; i++)
    {
        histNorm[i] = histNorm[i - 1] + histNorm[i];
    }

    // Transformation des niveaux de gris de l'image
    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            imageT[i][j] = (histNorm[image[i][j]] * 255);
        }
    }
    return imageT;
}

int **addition(int **image1, int **image2, int *dim1, int *dim2)
{
    int nblig = 0, nbcol = 0;
    nblig = min(dim1[0], dim2[0]);
    nbcol = min(dim1[1], dim2[1]);
    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            imageT[i][j] = min((image1[i][j] + image2[i][j]), 255);
        }
    }
    return imageT;
}

int **soustraction(int **image1, int **image2, int *dim1, int *dim2)
{
    int nblig = 0, nbcol = 0;
    nblig = min(dim1[0], dim2[0]);
    nbcol = min(dim1[1], dim2[1]);
    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            imageT[i][j] = max((image1[i][j] - image2[i][j]), 0);
        }
    }
    return imageT;
}

int **multiplication(int **image, int nblig, int nbcol)
{

    int **imageT = NULL;
    float facteur;
    printf("Entrer le facteur de multiplication : ");
    scanf("%f", &facteur);
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            imageT[i][j] = min(facteur * image[i][j], 255);
        }
    }
    return imageT;
}

int **And_logique(int **image1, int **image2, int *dim1, int *dim2)
{
    // image1 est une image en niveau de gris
    // image2 est une image binaire dans laquelle "1=noir" et "0= blanc"

    int nblig = 0, nbcol = 0;
    nblig = min(dim1[0], dim2[0]);
    nbcol = min(dim1[1], dim2[1]);

    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    int rep = est_binaire(image1, dim1[0], dim1[1]);
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        memset(imageT[i], 500, sizeof(int) * nbcol);
        for (int j = 0; j < nbcol; j++)
        {
            if (rep == 1)
            {
                if ((image1[i][j] == 1 && image2[i][j] == 0) || (image1[i][j] == 0 && image2[i][j] == 1) || (image1[i][j] == 0 && image2[i][j] == 0))
                    imageT[i][j] = 255;
                else if (image1[i][j] == 1 && image2[i][j] == 1)
                    imageT[i][j] = 0;
            }
            else
            {
                if (image2[i][j] == 1)
                    imageT[i][j] = 0;
                else if (image2[i][j] == 0)
                    imageT[i][j] = image1[i][j];
            }
        }
    }
    return imageT;
}

int **OR_XOR_logique(int **image1, int **image2, int *dim1, int *dim2, char info)
{
    // image1 est une image en niveau de gris
    // image2 est une image binaire dans laquelle "1=noir" et "0= blanc"

    int nblig = 0, nbcol = 0;
    nblig = min(dim1[0], dim2[0]);
    nbcol = min(dim1[1], dim2[1]);

    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    int rep = est_binaire(image1, dim1[0], dim1[1]);
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
        for (int j = 0; j < nbcol; j++)
        {
            if (rep == 1 && info == 'O')
            {
                if ((image1[i][j] == 1 && image2[i][j] == 0) || (image1[i][j] == 0 && image2[i][j] == 1) || (image1[i][j] == 1 && image2[i][j] == 1))
                    imageT[i][j] = 0;
                else if (image1[i][j] == 0 && image2[i][j] == 0)
                    imageT[i][j] = 255;
            }
            else if (rep == 1 && info == 'X')
            {
                if ((image1[i][j] == 1 && image2[i][j] == 0) || (image1[i][j] == 0 && image2[i][j] == 1))
                    imageT[i][j] = 0;
                else if ((image1[i][j] == 0 && image2[i][j] == 0) || (image1[i][j] == 1 && image2[i][j] == 1))
                    imageT[i][j] = 255;
            }
            else
            {
                if (image2[i][j] == 1)
                    imageT[i][j] = image1[i][j];
                else if (image2[i][j] == 0)
                    imageT[i][j] = 255;
            }
        }
    }
    return imageT;
}

int est_binaire(int **matrice, int nblig, int nbcol)
{
    int res = 1;
    for (int i = 0; i < nblig; i++)
    {
        for (int j = 0; j < nbcol; j++)
        {
            if (matrice[i][j] != 0 && matrice[i][j] != 1)
            {
                res = 0;
            }
        }
    }
    return res;
}

int **zoomm(int **image, int nblig, int nbcol, int zoom)
{

    int nblig_f = nblig * zoom;
    int nbcol_f = nbcol * zoom;
    int **imageT = NULL;

    imageT = malloc(nblig_f * sizeof(int *));
    for (int i = 0; i < nblig_f; i++)
    {
        imageT[i] = malloc(nbcol_f * sizeof(int));
        for (int j = 0; j < nbcol_f; j++)
        {
            imageT[i][j] = image[i / zoom][j / zoom];
        }
    }
    return imageT;
}

int **convolution(int **image, int nblig, int nbcol)
{
    // Construction du filtre
    int val, nbLigFil, nbColFil;
    printf("Entrer le nombre de lignes de votre filtre : ");
    scanf("%d", &nbLigFil);
    printf("Entrer le nombre de colonnes de votre filtre : ");
    scanf("%d", &nbColFil);
    int filtre[nbLigFil][nbColFil], info = 0;

    printf("Type de filtre à appliquer : 1 pour moyenneur, 2 pour gaussien et 3 pour autre :");
    scanf("%d", &info);
    if (info == 1)
    {
        for (int i = 0; i < nbLigFil; i++)
        {
            for (int j = 0; j < nbColFil; j++)
            {
                filtre[i][j] = 1;
            }
        }
    }
    else if (info == 2 || info == 3)
    {
        printf("Entrer les valeurs du filtre\n");
        for (int i = 0; i < nbLigFil; i++)
        {
            printf("Entrer les valeurs de la ligne %d séparées un espace : ", i + 1);
            for (int j = 0; j < nbColFil; j++)
            {
                scanf("%d", &val);
                filtre[i][j] = val;
            }
        }
    }

    // Creation du tableau qui sera retourné
    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
    }

    int tmp, lig_trans, col_trans, sum = 0, fl = 0, fc = 0, tl = 0, tc = 0, sumf = 0;

    // Creation d'une matrice intermédiaire
    tmp = nbLigFil / 2;
    lig_trans = nblig + (tmp * 2);
    col_trans = nbcol + (tmp * 2);

    int tab_trans[lig_trans][col_trans];
    for (int i = 0; i < lig_trans; i++)
    {
        for (int j = 0; j < col_trans; j++)
        {
            if (i < tmp || i >= tmp + nblig || j < tmp || j >= tmp + nbcol)
            {
                tab_trans[i][j] = 300;
            }
            else
            {
                tab_trans[i][j] = image[i - tmp][j - tmp];
            }
        }
    }

    // Convolution proprement dite
    for (int i = tmp; i < tmp + nblig; i++)
    {
        for (int j = tmp; j < tmp + nbcol; j++)
        {
            int k = i - tmp;
            int l = j - tmp;
            sum = 0;
            sumf = 0;
            fl = 0;
            fc = 0;

            for (int li = k; li < k + nbLigFil; li++)
            {
                for (int co = l; co < l + nbLigFil; co++)
                {
                    if (tab_trans[li][co] != 300)
                    {
                        sum = sum + (tab_trans[li][co] * filtre[fl][fc]);
                        sumf = sumf + filtre[fl][fc];
                    }

                    fc = fc + 1;
                }
                fl = fl + 1;
                fc = 0;
            }

            imageT[tl][tc] = sum / sumf;
            tc = tc + 1;
        }
        tl = tl + 1;
        tc = 0;
    }

    return imageT;
}


int **contour_prewitt_sobel_isotropic(int **image, int nblig, int nbcol, int info)
{
    int filtre[3][3]; 
    // Construction du filtre
    if( info== 1)
    {
        filtre[0][0] = -1; filtre[0][1] = -1; filtre[0][2] = -1;
        filtre[1][0] = 0; filtre[1][1] = 0; filtre[1][2] = 0;
        filtre[2][0] = 1; filtre[2][1] = 1; filtre[2][2] = 1;
    }
    else if(info == 2)
    {
       filtre[0][0] = -1; filtre[0][1] = 0; filtre[0][2] = 1;
       filtre[1][0] = -1; filtre[1][1] = 0; filtre[1][2] = 1;
       filtre[2][0] = -1; filtre[2][1] = 0; filtre[2][2] = 1; 
    }
    else if(info == 3)
    {
       filtre[0][0] = -1; filtre[0][1] = -2; filtre[0][2] = -1;
       filtre[1][0] = 0; filtre[1][1] = 0; filtre[1][2] = 0;
       filtre[2][0] = 1; filtre[2][1] = 2; filtre[2][2] = 1; 
    }
    else if(info == 4)
    {
       filtre[0][0] = -1; filtre[0][1] = 0; filtre[0][2] = 1;
       filtre[1][0] = -2; filtre[1][1] = 0; filtre[1][2] = 2;
       filtre[2][0] = -1; filtre[2][1] = 0; filtre[2][2] = 1; 
    }
    
    // Creation du tableau qui sera retourné
    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
    }

    int tmp, lig_trans, col_trans, sum = 0, fl = 0, fc = 0, tl = 0, tc = 0, sumf = 0;

    // Creation d'une matrice intermédiaire
    tmp = 3/2;
    lig_trans = nblig + (tmp * 2);
    col_trans = nbcol + (tmp * 2);

    int tab_trans[lig_trans][col_trans];
    for (int i = 0; i < lig_trans; i++)
    {
        for (int j = 0; j < col_trans; j++)
        {
            if (i < tmp || i >= tmp + nblig || j < tmp || j >= tmp + nbcol)
            {
                tab_trans[i][j] = 300;
            }
            else
            {
                tab_trans[i][j] = image[i - tmp][j - tmp];
            }
        }
    }

    // Convolution proprement dite
    for (int i = tmp; i < tmp + nblig; i++)
    {
        for (int j = tmp; j < tmp + nbcol; j++)
        {
            int k = i - tmp;
            int l = j - tmp;
            sum = 0;
            sumf = 0;
            fl = 0;
            fc = 0;

            for (int li = k; li < k + 3; li++)
            {
                for (int co = l; co < l + 3; co++)
                {
                    if (tab_trans[li][co] != 300)
                    {
                        sum = sum + (tab_trans[li][co] * filtre[fl][fc]);
                        sumf = sumf + filtre[fl][fc];
                    }

                    fc = fc + 1;
                }
                fl = fl + 1;
                fc = 0;
            }
            if(sum<0)
            {
                imageT[tl][tc] = sum * -1;
                tc = tc + 1;
            }
            else if(sum>255)
            {
                imageT[tl][tc] = 255;
                tc = tc + 1;
            }
            else
            {
                imageT[tl][tc] = sum ;
                tc = tc + 1;
            }
            
        }
        tl = tl + 1;
        tc = 0;
    }

    return imageT;
}


int **filtreMedian(int **image, int nblig, int nbcol)
{
    int nbLigFil;
    printf("Entrer le nombre de lignes de votre filtre : ");
    scanf("%d", &nbLigFil);

    int *tabFiltre = NULL;
    int *tabFiltreVrai = NULL; 
    int taille = nbLigFil*nbLigFil;
    tabFiltre = malloc(taille * sizeof(int));
    
    // Creation de la matrice qui sera retournée
    int **imageT = NULL;
    imageT = malloc(nblig * sizeof(int *));
    for (int i = 0; i < nblig; i++)
    {
        imageT[i] = malloc(nbcol * sizeof(int));
    }

    int tmp, lig_trans, col_trans, tl = 0, tc = 0, cpt, cpt2, o, med;

    // Creation d'une matrice intermédiaire
    tmp = nbLigFil / 2;
    lig_trans = nblig + (tmp * 2);
    col_trans = nbcol + (tmp * 2);

    int tab_trans[lig_trans][col_trans];
    for (int i = 0; i < lig_trans; i++)
    {
        for (int j = 0; j < col_trans; j++)
        {
            if (i < tmp || i >= tmp + nblig || j < tmp || j >= tmp + nbcol)
            {
                tab_trans[i][j] = 300;
            }
            else
            {
                tab_trans[i][j] = image[i - tmp][j - tmp];
            }
        }
    }

    // Convolution proprement dite
    for (int i = tmp; i < tmp + nblig; i++)
    {
        for (int j = tmp; j < tmp + nbcol; j++)
        {
            int k = i - tmp;
            int l = j - tmp;
            cpt = 0;
            cpt2 = 0;
            o = 0;

            for (int li = k; li < k + nbLigFil; li++)
            {
                for (int co = l; co < l + nbLigFil; co++)
                {
                    tabFiltre[cpt] = tab_trans[li][co];
                    cpt = cpt+1;
                    if(tab_trans[li][co] != 300)
                    {
                        cpt2 = cpt2 + 1;
                    }
                }
            }
            tabFiltreVrai = malloc(cpt2 * sizeof(int));

            for(int m=0; m<cpt; m++)
            {
                if(tabFiltre[m] != 300)
                {
                    tabFiltreVrai[o] = tabFiltre[m];
                    o = o+1; 
                }
                
            }
            med = mediane(tabFiltreVrai, cpt2);

            imageT[tl][tc] = med;
            tc = tc + 1;
        }
        tl = tl + 1;
        tc = 0;
    }

    return imageT;
}

int mediane(int *tab, int taille)
{
    int nbElements = taille;
    // Copie des valeurs du tableau en entrée dans un autre tableau (tabCopie)
    int *tabCopie = NULL, tmp, med = 300;
    tabCopie = malloc(taille * sizeof(int));
    for (int i = 0; i < taille; i++)
    {
        tabCopie[i] = tab[i];
    }

    // Trie du tableau tabCopie
    while (nbElements != 1)
    {
        for (int i = 0; i < nbElements - 1; i++)
        {
            if (tabCopie[i] > tabCopie[i + 1])
            {
                tmp = tabCopie[i];
                tabCopie[i] = tabCopie[i + 1];
                tabCopie[i + 1] = tmp;
            }
        }
        nbElements = nbElements - 1;
    }
    // Calcul de la médiane
    if (taille % 2 == 0)
    {
        med = (tabCopie[(taille / 2) - 1] + tabCopie[taille / 2]) / 2;
    }
    else if (taille % 2 == 1)
    {
        med = tabCopie[taille / 2];
    }

    return med;
}
