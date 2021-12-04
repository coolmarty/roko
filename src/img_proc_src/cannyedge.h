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
 * @brief The main class of CannyEdgeFilter.
 *
 *  Derived class of Filter, invoked to create and apply cenny edge detection to an Image.
 */
class CannyEdgeFilter : public Filter {
public:
     /**
  * @brief Generation of a CannyEdgeFilter
  */
    CannyEdgeFilter();
    /**
  * @brief Application of a CannyEdgeFilter, applies to whole image
  *
  */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};

#endif
