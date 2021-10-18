#ifndef SOBELFILTER_H_
#define SOBELFILTER_H_

#include "convolution.h"
#include <math.h>

class SobelFilter : public Convolution {
public:
    SobelFilter();

    void Apply(std::vector<Image*> input, std::vector<Image*> output);
};

#endif
