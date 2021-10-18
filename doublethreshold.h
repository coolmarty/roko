#ifndef DOUBLETHRESHOLDFILTER_H_
#define DOUBLETHRESHOLDFILTER_H_

#include "simple_filter.h"

class DoubleThresholdFilter : public SimpleFilter {
public:
    DoubleThresholdFilter();
    
    DoubleThresholdFilter(float t1, float t2);

    unsigned char* applyAtPixel(unsigned char* pixel);
   
    float GetLuminance(float red,float green,float blue);

    float threshold1;
    float threshold2;
};

#endif
