/**
 * @file greyscale_filter.h
 *
 */
#ifndef GREYSCALEFILTER_H_
#define GREYSCALEFILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "simple_filter.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief greyscale filter class, applies the greyscale filter to an image
 *
 *
 */
class GreyScaleFilter : public SimpleFilter {
public:
    /**
     * @brief constructor for creating a GreyScaleFilter
     *
     * @return a GreyScaleFilter object
     */
    GreyScaleFilter();

    /**
     * @brief apply convolutional filter based on image(s) from input vector, store them in output vector
     *
     * @return a length 4 unsigned char array of values
     */
    unsigned char* applyAtPixel(unsigned char* pixel);


    /**
     * @brief get the luminance of a pixel
     *
     * @return a float representing the luminance of an image
     */
    float GetLuminance(float red,float green,float blue);
};

#endif
