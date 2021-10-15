/**
 * @file filter.h
 *
 */
#ifndef FILTER_H_
#define FILTER_H_

#include <vector>
#include "image.h"


/**
 * @brief The main class for filters, purely virtual
 *
 *
 */
class Filter {
public:
    virtual void Apply(std::vector<Image*> original, std::vector<Image*> filtered)=0;
};


#endif
