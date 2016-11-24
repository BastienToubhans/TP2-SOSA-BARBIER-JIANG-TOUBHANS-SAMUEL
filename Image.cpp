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

Image::~Image() {
}

