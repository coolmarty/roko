#ifndef GREYSCALEFILTER_H_
#define GREYSCALEFILTER_H_

#include "simple_filter.h"

class GreyScaleFilter : public SimpleFilter {
public:
    GreyScaleFilter();

    unsigned char* applyAtPixel(unsigned char* pixel);

    float GetLuminance(float red,float green,float blue);
};

#endif
