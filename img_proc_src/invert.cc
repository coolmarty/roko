#include "invert.h"

InvertFilter::InvertFilter(){
    return;
}


unsigned char* InvertFilter::applyAtPixel(unsigned char* pixel){
        unsigned char* newPixel= new unsigned char[4];
        newPixel[0]= 255 - pixel[0];
        newPixel[1]= 255 - pixel[1];
        newPixel[2]= 255 - pixel[2];
        newPixel[3]= pixel[3];
        return newPixel;

}

