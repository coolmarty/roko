/**
 * @file hysteresis_filter.h
 *
 */


#ifndef HYSTERESIS_FILTER_H_
#define HYSTERESIS_FILTER_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "convolution.h"
#include <math.h>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Hysteresis Filter class, allows for the creation of hysteresis filters
 *
 */
class HysteresisFilter : public Convolution {
public:
    /**
     * @brief constructor, sets colonel to a 3x3
     *
     */
    HysteresisFilter();

    /**
     * @brief method to apply hysteresis to an image
     *
     */
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
};


#endif