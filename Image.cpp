#include "Image.h"

Image::Image() {
}

Image::Image(const Image& orig) {
}

Image::~Image() {
}

void Image::loaderPGM(char* filename)
{
    ifstream myFile(filename, ios::in);
    if (myFile)
    {
        int largeur, hauteur, valeur;
        string info;
        int maxGris;
        vector <int> ligne;
        myFile >> info >>info; //on passe sur les infos P2 #
        myFile >> largeur >> hauteur;
        myFile >> maxGris;
        
        for (int i=0;i< hauteur; i++)
        {
            for (int j =0; j< largeur ; j++)
            {
                myFile >> valeur;
                ligne.push_back(valeur);
            }
            image.push_back(ligne);
            ligne.clear();
        }
        myFile.close();
    }
    else
    {
        cerr <<"Ouverture fichier impossible"<<endl;
    }
}

void Image::writerPGM(char* filename) {
    ofstream myfile;
    int largeur = image[0].size();
    int hauteur = image.size();
    int compteur = 0;
    int valeur_actuelle;
    
    if (hauteur == 0 && largeur == 0) {
        cerr << "Il n'y a pas d'image a ecrire";
    } 
    else {
        myfile.open(filename, ios::out);
        myfile << "P2\n";
        myfile << "#\n";
        myfile << largeur << " " << hauteur << "\n";
        myfile << "255\n";


        for (int i = 0; i < hauteur; i++) {
            for (int j = 0; j < largeur; j++) {
                valeur_actuelle = image[i][j];

                if (valeur_actuelle < 10) {
                    compteur++;
                } else if (valeur_actuelle < 100) {
                    compteur += 2;
                } else {
                    compteur += 3;
                }

                if (compteur >= 70) {
                    myfile << "\n";
                    myfile << valeur_actuelle<< " ";

                    if (valeur_actuelle < 10) {
                        compteur = 2;
                    } else if (valeur_actuelle < 100) {
                        compteur = 3;
                    } else {
                        compteur = 4;
                    }
                } else {
                    myfile << valeur_actuelle << " ";
                    compteur++; //prise en compte de l'espace
                }
                //myfile << valeur_actuelle << " ";
            }//myfile << "\n";
        }
        
        myfile.close();
    }
}

