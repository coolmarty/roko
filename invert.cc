#ifndef DOUBLETHRESHOLDFILTER_H_
#define DOUBLETHRESHOLDFILTER_H_

#include "simple_filter.h"


class InvertFilter : public SimpleFilter {
public:
    InvertFilter();

    unsigned char* applyAtPixel(unsigned char* pixel);
};

#endif
