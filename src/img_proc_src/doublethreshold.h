/**
 * @file doublethreshold.h
 *
 * 
 */
 
#ifndef DOUBLETHRESHOLDFILTER_H_
#define DOUBLETHRESHOLDFILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_filter.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of DoubleThresholdFilter.
 *
 *  Derived class of SimpleFilter, invoked to create and apply a double threshold filter to an Image.
 */
class DoubleThresholdFilter : public SimpleFilter {
public:
     /**
  * @brief Generation of a DoubleThresholdFilter with no parameters
  *
  */
    DoubleThresholdFilter();
/**
  * @brief Generation of a DoubleThresholdFilter with two parameters, the two thresholds to be used in the image calculation.
  *
  */
    DoubleThresholdFilter(float t1, float t2);
     /**
  * @brief Application of a DoubleThresholdFilter at a specific pixel in the image.
  *
  */
    unsigned char* applyAtPixel(unsigned char* pixel);
     /**
  * @brief Returns the Luminance of a specific pixel with a simple equation in order to determine what threshold it falls in
  */   
    float GetLuminance(float red,float green,float blue);
     /**
  * @brief The two thresholds that define the look of the output image.
  */
    float threshold1;
    float threshold2;
};

#endif
