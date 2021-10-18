#include "greyscale_filter.h"

#include <math.h>


GreyScaleFilter::GreyScaleFilter(){
    return;
}


unsigned char* GreyScaleFilter::applyAtPixel(unsigned char* pixel){
        unsigned char* newPixel= new unsigned char[4];
        float luminance = floor(GreyScaleFilter::GetLuminance(pixel[0],pixel[1],pixel[2]));
        newPixel[0]=luminance;
        newPixel[1]=luminance;
        newPixel[2]=luminance;
        newPixel[3]=pixel[3];
        return newPixel;

}

float GreyScaleFilter::GetLuminance(float red,float green,float blue){
     return 0.2126*red + 0.7152*green + 0.0722*blue;
}
