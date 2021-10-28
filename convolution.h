/**
 * @file convolution.h
 *
 */


#ifndef _CONVOLUTION_H
#define _CONVOLUTION_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "kernal.h"
#include "image.h"
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for convolutional filters, purely virtual
 *
 *
 */
class Convolution : public Filter {
protected:
    Kernal colonel;

public:
    /**
     * @brief apply convolutional filter based on image(s) from input vector, store them in output vector
     *
     * @return none
     */
     virtual void Apply(std::vector<Image*> input, std::vector<Image*> output) = 0;
};

#endif
