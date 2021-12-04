/**
 * @file colorthreshold.h
 *
 *
 */

#ifndef COLORTHRESHOLD_H_
#define COLORTHRESHOLD_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_filter.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of ColorThresholdFilter.
 *
 *  Derived class of SimpleFilter, invoked to create and apply a color threshold filter to an Image.
 */
class ColorThresholdFilter : public SimpleFilter {
public:
     /**
  * @brief Generation of a ColorThresholdFilter with no parameters (defaults to orange)
  *
  */
    ColorThresholdFilter();

    /**
 * @brief Generation of a ColorThresholdFilter with the color wanted
 *
 */
   // ColorThresholdFilter(unsigned char color[4]);
     /**
  * @brief Application of a ColorThresholdFilter at a specific pixel in the image.
  *
  */
    unsigned char* applyAtPixel(unsigned char* pixel);

private:
    double distanceTo(unsigned char* pixel);

     /**
  * @brief The color we want
  */
    unsigned char color[4];
};

#endif
