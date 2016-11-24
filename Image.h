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
TT Writer PGM
Jose Histogramme
JJ Seuillage
Jose Differernce
TT Agrandissement/Reduction */

class Image {
protected:
    vector<vector<int> > image;
public:
    Image();
    Image(const Image& orig);
    
    virtual ~Image();
    
    //Methodes
    void loadImage(char* fichier);
    void writerPGM(char* filename);
    void pivoterImage();//Pivoter au sens trigo
    int getPixel(int i, int j);
    void ajouterLigne(vector<int> ligne);
    Image operator-(Image Im2);//La difference entre deux Images
    Image histograme();

};

#endif	/* IMAGE_H */

