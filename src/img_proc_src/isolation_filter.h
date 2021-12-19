/**
 * @file isolation_filter.h
 *
 *
 */

#ifndef ISO_H_
#define ISO_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of IsolationFilter.
 *
 *  Derived class of Filter, splits an image into 3 images of its channels
 */
class IsolationFilter : public Filter {
public:
     /**
  * @brief Generation of a IsolationFilter
  *
  */
    IsolationFilter();

   // ColorThresholdFilter(unsigned char color[4]);
     /**
  * @brief Application of a ColorThresholdFilter
  *
  */
    void Apply(std::vector<Image*> input, std::vector<Image*> output);

};

#endif
