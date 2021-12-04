/**
 * @file doublethreshold.h
 *
 * 
 */
#ifndef INVERT_H_
#define INVERT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of InvertFilter.
 *
 *  Derived class of SimpleFilter, invoked to create and apply an inversion filter to an Image.
 */
class InvertFilter : public SimpleFilter {
public:
/**
  * @brief Generation of an InvertFilter with no parameters
  *
  */
    InvertFilter();
/**
  * @brief Application of an InvertFilter at a specific pixel in the image.
  *
  */

    unsigned char* applyAtPixel(unsigned char* pixel);
};

#endif
