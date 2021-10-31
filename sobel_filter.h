<<<<<<< HEAD
=======

>>>>>>> fb4696a4e708f875b8c79119e1c8884180b7cf18
/**
 * @file sobel_filter.h
 *
 */

#ifndef SOBELFILTER_H_
#define SOBELFILTER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "convolution.h"
#include <math.h>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Sobel Filter class, allows for the creation of Sobel filters
 *
 */
class SobelFilter : public Convolution {
public:
    /**
     * @brief constructor, sets colonel to the Sobel x identity matrix
     *
     */
    SobelFilter();

    /**
     * @brief method to apply a sobel filter to an image, note: takes in 2 output images
     *
     */
    void Apply(std::vector<Image*> input, std::vector<Image*> output);
};

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> fb4696a4e708f875b8c79119e1c8884180b7cf18
