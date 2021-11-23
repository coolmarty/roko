#include "doublethreshold.h"
#include <math.h>

DoubleThresholdFilter::DoubleThresholdFilter(){
    return;
}

DoubleThresholdFilter::DoubleThresholdFilter(float t1, float t2){
  this->threshold1 = t1;
  this->threshold2 = t2;
  
}


unsigned char* DoubleThresholdFilter::applyAtPixel(unsigned char* pixel){
  unsigned char* newPixel= new unsigned char[4];
  float luminance = floor(DoubleThresholdFilter::GetLuminance(pixel[0],pixel[1],pixel[2]));
  if(luminance > threshold1){
    newPixel[0]=255;
    newPixel[1]=255;
    newPixel[2]=255;
    newPixel[3]=255;
  }
  else if(luminance > threshold2 && luminance < threshold1){
    newPixel[0]=25;
    newPixel[1]=25;
    newPixel[2]=25;
    newPixel[3]=255;
  }
  else{
    newPixel[0]=0;
    newPixel[1]=0;
    newPixel[2]=0;
    newPixel[3]=255;
  }
return newPixel;
}

float DoubleThresholdFilter::GetLuminance(float red,float green,float blue){
  return 0.2126*red + 0.7152*green + 0.0722*blue;
}
