#ifndef DOUBLETHRESHOLDFILTER_H_
#define DOUBLETHRESHOLDFILTER_H_

#include "simple_filter.h"

class DoubleThresholdFilter : public SimpleFilter {
public:
    DoubleThresholdFilter();

    unsigned char* applyAtPixel(unsigned char* pixel);

    float threshold1;
    float threshold2;
};

#endif
