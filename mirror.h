/**
 * @file non_max_suppression.h
 *
 *
*/

#ifndef MIRROR_H_
#define MIRROR_H_

/*******************************************************************************
 * Includes
******************************************************************************/
#include <vector>
#include "image.h"
#include "filter.h" // Inherits from Filter class

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The NonMaxSuppression class used to apply a non-max suppression filter given a photo's intensity and direction
 * each of which must be stored as images of the same size. Works best when used following a sobel filter.
*/
class MirrorFilter : public Filter {
public:
/**
* @brief Applies the filter. Intensity must be at index 0 and direction must be at index 1. Must be memory already allocated at the output.
*
* @return void. Places result in the output vector.
*/
	void Apply(std::vector<Image*> input, std::vector<Image*> output);
};

#endif