/* 
 * File:   Image.h
 * Author: user
 *
 * Created on 24 novembre 2016, 09:48
 */
#include <vector>
#pragma once;
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
private:
    vector<vector<int> > image;
};

#endif	/* IMAGE_H */

