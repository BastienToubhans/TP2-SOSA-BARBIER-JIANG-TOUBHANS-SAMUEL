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

int Image::getPixel(int i, int j){
    return this->image[i][j];
}

void Image::ajouterLigne(vector<int> ligne){
    this->image.push_back(ligne);
}

Image Image::operator -(Image Im2){
    Image ImRes;
    vector<int> aux;
    int j,i;
    for(i=0;i<this->image.size();i++)
    {
        for(j=0;j<this->image[0].size();j++)
        {
            int k=this->image[i][j]-Im2.getPixel(i,j);
            if(k<0)
                k=0;
            aux.push_back(k);
        }
        if(j)
            ImRes.ajouterLigne(aux);
        aux.clear();
    }
    return ImRes;
}

Image Image::histograme(){
    Image ImRes;
    int freq[256],max;
    vector<int> aux;
    for(int i=0;i<256;i++)
        freq[i]=0;
    for(int i=0;i<this->image.size();i++)
    {
        for(int j=0;j<this->image[0].size();j++)
        {
            freq[this->image[i][j]]++;
        }
    }
    
    //Trouver le plus grand
    max=0;
    for(int i=0;i<256;i++)
    {
        if(freq[i]>max)
            max=freq[i];
    }
    
    //Faire histograme
    for(int i=0;i<max;i++)
    {
        for(int j=0;j<freq[i];j++)
        {
            aux.push_back(255);
        }
        for(int j=freq[i];j<max;j++)
        {
            aux.push_back(0);
        }
        ImRes.ajouterLigne(aux);
        aux.clear();
    }
    
    //Pivoter histograme
    ImRes.pivoterImage();
    return ImRes;
}

void Image::pivoterImage(){
    vector<vector<int> > aux;
    vector<int> auxLigne;
    for(int j=this->image[0].size()-1;j>=0 ;j--)
    {
        for(int i=0;i<this->image.size();i++)
        {
            auxLigne.push_back(this->image[i][j]);
        }
        aux.push_back(auxLigne);
        auxLigne.clear();
    }
    this->image=aux;
}