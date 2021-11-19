/**
 * @file cannyedge.h
 *
 *
 */

#ifndef CANNYEDGE_H_
#define CANNYEDGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include "simple_filter.h"
#include "convolution.h"
#include "greyscale_filter.h"
#include "gaussian_blur.h"
#include "sobel_filter.h"
#include "non_max_suppression.h"
#include "doublethreshold.h"
#include "hysteresis_filter.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of DoubleThresholdFilter.
 *
 *  Derived class of SimpleFilter, invoked to create and apply a double threshold filter to an Image.
 */
class CannyEdgeFilter : public Filter {
public:
     /**
  * @brief Generation of a DoubleThresholdFilter with no parameters (defaults to orange)
  *
  */
    CannyEdgeFilter();
    /**
  * @brief Application of a DoubleThresholdFilter at a specific pixel in the image.
  *
  */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
