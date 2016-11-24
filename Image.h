/* 
 * File:   Image.h
 * Author: user
 *
 * Created on 24 novembre 2016, 09:48
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

/* JJ Loader PGM 
TT Writer PGM
Jose Histogramme
JJ Seuillage
Jose Differernce
TT Agrandissement/Reduction */

class Image {
public:
    Image();
    Image(const Image& orig);
    virtual ~Image();
    void writerPGM(string filename);
    
private:
    vector<vector<int> > image;
};

#endif	/* IMAGE_H */

