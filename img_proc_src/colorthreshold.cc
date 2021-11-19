#include "colorthreshold.h"
#include <math.h>

ColorThresholdFilter::ColorThresholdFilter(){
  this->color[0] = 234;
  this->color[1] = 117;
  this->color[2] = 17;
  this->color[3] = 255;
  return;
}

// ColorThresholdFilter::ColorThresholdFilter(unsigned char color[4]){
//   this->color = color;
//
// }


unsigned char* ColorThresholdFilter::applyAtPixel(unsigned char* pixel){
  unsigned char* newPixel= new unsigned char[4];

  int distance_threshold = 90;
  double distance = distanceTo(pixel);

  if(distance<distance_threshold){
    newPixel[0]=255;
    newPixel[1]=255;
    newPixel[2]=255;
  }
  else{
    newPixel[0]=0;
    newPixel[1]=0;
    newPixel[2]=0;
  }
  newPixel[3]=255;
  return newPixel;
}

double ColorThresholdFilter::distanceTo(unsigned char* pixel){
  return sqrt(pow(pixel[0]-color[0],2)+pow(pixel[1]-color[1],2)+pow(pixel[2]-color[2],2));
}
