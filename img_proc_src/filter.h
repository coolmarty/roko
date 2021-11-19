/**
 * @file filter.h
 *
 */
#ifndef FILTER_H_
#define FILTER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "image.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for filters, purely virtual
 *
 *
 */
class Filter {
public:
    /**
     * @brief apply convolutional filter based on image(s) from input vector, store them in output vector
     *
     * @return none
     */
    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered)=0;
};


#endif
