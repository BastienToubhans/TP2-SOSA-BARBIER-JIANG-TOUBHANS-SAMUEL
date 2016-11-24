/* 
 * File:   Image.h
 * Author: user
 *
 * Created on 24 novembre 2016, 09:48
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <vector>
#include <iostream>
#include <cstdlib>
#include <fstream> //pour la lecture ecriture
using namespace std;

/* JJ Loader PGM 
 Jose Writer PGM
 TT Histogramme
 JJ Seuillage
 Jose Differernce
 TT Agrandissement/Reduction */

class Image {
public:
    Image();
    Image(const Image& orig);
    virtual ~Image();
    
    //Methodes
    void loaderPGM(char* fichier);
    void writerPGM(char* filename);//ecrire le nom du fichier avec l'extension .PGM
    void resizePGM(int newHauteur, int newLargeur);
    void pivoterImage();//Pivoter au sens trigo
    int getPixel(int i, int j);
    void ajouterLigne(vector<int> ligne);
    Image operator-(Image Im2);//La difference entre deux Images
    Image histograme();
    
private:
    vector<vector<int> > image;
};

#endif	/* IMAGE_H */
