#ifndef SIMPLEFILTER_H_
#define SIMPLEFILTER_H_

#include "filter.h"

class SimpleFilter : public Filter {
public:
    void Apply(std::vector<Image*> original, std::vector<Image*> filtered);
protected:
    virtual unsigned char* applyAtPixel(unsigned char* pixel)=0;
};

#endif
