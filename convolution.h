#ifndef _CONVOLUTION_H
#define _CONVOLUTION_H

#include <vector>
#include "kernal.h"
#include "image.h"


class Convolution : public Filter {
private:
Kernal colonel;

public:
virtual void Apply(std::vector<Image*> input, std::vector<Image*> output) = 0;
}