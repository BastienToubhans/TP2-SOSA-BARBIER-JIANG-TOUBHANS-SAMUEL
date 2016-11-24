/* 
 * File:   Image.cpp
 * Author: user
 * 
 * Created on 24 novembre 2016, 09:48
 */

#include "Image.h"

Image::Image() {
}

Image::Image(const Image& orig) {
}

Image::~Image() {
}

void Image::writerPGM(string filename) {
    ofstream myfile;
    int largeur = image[0].size();
    int hauteur = image.size();
    int compteur = 0;
    int valeur_actuelle;

    myfile.open(filename + ".PGM", ios::out);
    myfile << "P2\n";
    myfile << "#\n";
    myfile << largeur << " " << hauteur << "\n";
    myfile << "255\n";

    for (int i = 0; i < hauteur; i++) {
        for (int j = 0; j < largeur; j++) {
            valeur_actuelle=image[i][j];
            
            if(valeur_actuelle<10){compteur++;}
            else if(valeur_actuelle<100){compteur+=2;}
            else{compteur+=3;}

            if (compteur >= 70){
                myfile << "\n";
                myfile << valeur_actuelle;
                
                if(valeur_actuelle<10){compteur=1+;}
                else if(valeur_actuelle<100){compteur=2;}
                else{compteur=3;}
            }
            else {
                myfile << valeur_actuelle << " ";
                compteur++;//prise en compte de l'espace
            }
        }
    }
    
    myfile.close();
}
