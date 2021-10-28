#ifndef _CONVOLUTION_H
#define _CONVOLUTION_H

#include <vector>
#include "kernal.h"
#include "image.h"
#include "filter.h"


class Convolution : public Filter {
protected:
Kernal colonel;

public:
virtual void Apply(std::vector<Image*> input, std::vector<Image*> output) = 0;
};

#endif