/* 
 * File:   main.cpp
 * Author: user
 *
 * Created on 24 novembre 2016, 09:47
 */

#include <cstdlib>
#include "Image.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Image img;
    img.loaderPGM("lena.pgm");
    img.writerPGM("newLena.pgm");
    return 0;
}

// 
