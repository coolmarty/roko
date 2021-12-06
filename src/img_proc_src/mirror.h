/**
 * @file mirror.h
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
 * @brief The MirrorFilter class is used to apply a filter to make an input file to look as if it were mirrored
 * 
*/
class MirrorFilter : public Filter {
public:
/**
* @brief Applies the filter.
*
* @return void. Places result in the output vector.
*/
	void Apply(std::vector<Image*> input, std::vector<Image*> output);
};

#endif