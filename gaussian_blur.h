/**
 * @file gaussian_blur.h
 *
 */


#ifndef GAUSS_BLUR_H_
#define GAUSS_BLUR_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "convolution.h"
#include <math.h>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Gaussian Blur class, allows for the creation of gaussian blur filters
 *
 */
class Gaussian_Blur : public Convolution {
public:
    /**
     * @brief constructor, sets colonel to the gaussian identity matrix
     *
     */
    Gaussian_Blur();

    /**
     * @brief method to apply gaussian blur to an image
     *
     */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};


<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> fb4696a4e708f875b8c79119e1c8884180b7cf18
