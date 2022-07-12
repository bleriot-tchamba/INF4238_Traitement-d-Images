                       TP INFO 4238: TRAITEMENT D'IMAGES ET VISION PAR ORDINATEUR                                          

Le projet est contenu dans un dossier.

Dans ce dossier, se trouvent 4 dossiers et 2 fichiers.

Les différents dossiers sont: 

-- Executable : dossier contenant l'executable du projet (main)

-- Sources : dossier contenant les fichiers sources "fonctions.c", "fonctions.h" et "main.c"

-- images : dossier contenant les différentes images sur lesquelles ont été testés les différents algorithmes

-- imagesRes : dossier contenant les differentes images obtenues apres application de certains algorithmes

En plus de ces 4 dossiers, il y'a aussi un fichier "ReadMe.txt" et un fichier "Makefile" qui genère l'executable. Mais vous n'avez pas besoin d'utiliser le "Makefile" car l'executable a deja été généré. 

Au cas où cet executable pose des problèmes, allez dans le dossier Executable et supprimez l'executable "main";  Placez vous dans le dossier principal et tapez la commande "make". 

Pour executer un algorithme, la syntaxe est la suivante:

./Executable/main NomAlgo images/nomImgEntree.pgm imagesRes/nomImgSortie

*** "main" ici est le nom de l'executale

*** "NomAlgo" représente le nom de l'algorithme que vous voulez exécuter sur l'immage

*** "nomImgEntree.pgm" fait reférence au nom de votre image en entrée au format pgm. s'il s'agit d'un algorithme utilisant une image binaire (constituée de 0 et 1), votre image doit etre sous format .pbm 

*** "nomImgSortie" fait reférence au nom de l'image que vous voulez obtenir en sortie. 

Dans la suite,je vous montre avec précision les différentes commandes à taper en fonction de l'algorithme que vous voulez executer:

Pour le faire, j'utilise quelques images se trouvant dans le dosiier images.


 1-- Histogramme:
 tapez la commande :  ./Executable/main histogramme images/circuit.pgm  
 
 2-- augmenter la lumninance d'une image :  
 tapez la commande :  ./Executable/main luminance images/cam.pgm imagesRes/camLum
 
 3-- Transformation linéaire simple :
 tapez la commande :  ./Executable/main transfLineaireSimple images/villeobscure.pgm imagesRes/villeClaire
 
 4-- Transformation linéaire avec saturation :
 tapez la commande :  ./Executable/main transfLineaireSat images/port.pgm imagesRes/portClaire
 
 5-- Egalisation d'histrogramme :
 tapez la commande :   ./Executable/main egalisation images/filletteEgal.pgm imagesRes/fiEgal
 
 6-- Addition de deux images en niveaux de gris (pgm)
 tapez la commande :   ./Executable/main addition images/bonhomeBlouson.pgm images/filletteEgal.pgm imagesRes/Iadd
 
 7-- Soustraction de deux images en niveaux de gris (pgm)
 tapez la commande :   ./Executable/main soustraction images/empreinte.pgm images/bonhomeBlouson.pgm imagesRes/Isous
 
 8-- Multiplication d'une image par un facteur
 tapez la commande :   ./Executable/main multiplication images/imageMult1.pgm imagesRes/Imult
 
 9-- Inverse d'une image en niveaux de gris (pgm)
 tapez la commande :   ./Executable/main inverse images/cam.pgm imagesRes/Iinv
 
 10-- And_logique entre une image en niveaux de gris et une image binaire (pbm)
 tapez la commande :   ./Executable/main andGrisBin images/tour.pgm images/petitcoinOu.pbm imagesRes/andGrisBin
 
 11-- And_logique entre deux images binaires
 tapez la commande :   ./Executable/main andBinBin images/imagebin.pbm images/imagebin2.pbm imagesRes/andBinBin
 
 12-- OR_logique entre une image en niveaux de gris et une image binaire (pbm)
 tapez la commande :   ./Executable/main orGrisBin images/tour.pgm images/petitcoinOu.pbm imagesRes/orGrisBin
 
 13-- OR_logique entre deux images binaires
 tapez la commande :   ./Executable/main orBinBin images/imagebin.pbm images/imagebin2.pbm imagesRes/orBinBin
 
 14-- XOR_logique entre deux images binaires
 tapez la commande : ./Executable/main xorBinBin images/imagebin.pbm images/imagebin2.pbm imagesRes/xorBinBin
 
 15-- NOT d'une image bianire
 tapez la commande :  ./Executable/main notBin images/imagebin.pbm imagesRes/notBin
 
 16-- Zoom d'une image en niveaux de gris
 tapez la commande :  ./Executable/main zoom images/cam.pgm imagesRes/Izoom
  
 17-- Filtre Médian
 tapez la commande :  ./Executable/main filtreMedian images/circuit.pgm imagesRes/circuitMed
 
 18-- Filtre Moyenneur :
 tapez la commande :   ./Executable/main filtreMoyenneur images/circuit.pgm imagesRes/circuitMoy
 
 19--Filtre Gaussien :
 tapez la commande :    ./Executable/main filtreGaussien images/boulanger.pgm imagesRes/boulanGauss
 
 20--Convolution :
 tapez la commande :    ./Executable/main convolution images/circuit.pgm imagesRes/circuitConv
 
 21--Détection des contours avec prewit
 tapez la commande :    ./Executable/main prewitt images/cam.pgm imagesRes/prewittCam
 
 22-- Détection des contours avec prewiit + binarisation
 tapez la commande :    ./Executable/main prewittSeuil images/cam.pgm imagesRes/prewittSeuilCam
 
 23-- Détection des contours avec sobel
 tapez la commande :     ./Executable/main sobel images/cam.pgm imagesRes/sobelCam
 
 24--Détection des contours avec sobel + binarisation
 tapez la commande :     ./Executable/main sobelSeuil images/cam.pgm imagesRes/sobelSeuilCam
 
 25-- Détection des contours avec robert sans binarisation
 tapez la commande :     ./Executable/main robert images/cam.pgm imagesRes/robertCam
 
 26-- Filtre de robert avec binarisation (il faut mettre un petit seuil pour avoir une bonne image)
 tapez la commande :    ./Executable/main robertSeuil images/cam.pgm imagesRes/robertSeuilCam
 
 27-- Détection des contours avec le laplacien4 sans binarisation
 tapez la commande :    ./Executable/main laplacien4 images/cam.pgm imagesRes/lapla4Reg
 
 28-- Détection des contours avec le laplacien8 sans binarisation
 tapez la commande :    ./Executable/main laplacien8 images/cam.pgm imagesRes/lapla8Reg
 
 29--Seuil fourni par l'algotihme d'Otsu
 tapez la commande : ./Executable/main otsu images/empreinte.pgm
 
 30-- Binarisation d'une image en utilisant le seuil fourni par l'algorithme d'Otsu
 tapez la commande : ./Executable/main binarisationOtsu images/empreinte.pgm imagesRes/IbinariseOtsu
 
 31-- Binarisation d'une image en utilisant un seuil fourni par l'utilisateur
 tapez la commande :   ./Executable/main binarisation images/empreinte.pgm imagesRes/Ibinarise
 
 32-- Segmentation d'une image à l'aide de Kmeans
 tapez la commande :   ./Executable/main segmentationKMeans images/fruits.pgm imagesRes/IKmeans
 
 33-- Transformée de Hough
 tapez la commande :    ./Executable/main hough_transform images/cam.pgm imagesRes/HougTrans
 
 Après chacunes de ces commandes, recuperer l'image resultante dans le dossier imagesRes.
 
 -----------------------------------------------------------FIN-----------------------------------------------------
