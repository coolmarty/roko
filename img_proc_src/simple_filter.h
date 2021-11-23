/**
 * @file kernal.h
 *
 */
#ifndef SIMPLEFILTER_H_
#define SIMPLEFILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief a class for creating simple filters;
 *
 *
 */
class SimpleFilter : public Filter {
public:
    /**
     * @brief method to apply filter to an image, loops through image and calls applyAtPixel for every pixel;
     *
     * @return nothing;
     */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
protected:
    /**
     * @brief virtual method, subclasses implement this method differently;
     *
     * @return a length 4 character array;
     */
    virtual unsigned char* applyAtPixel(unsigned char* pixel)=0;
};

#endif
