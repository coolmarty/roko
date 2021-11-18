#include "simple_filter.h"

void SimpleFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    Image *output = filtered.at(0);
    Image *input = original.at(0);
    *output = *input;//set input to correct width/height
    for(int y=0; y<input->GetHeight(); y++){
        for(int x=0; x<input->GetWidth(); x++){
            unsigned char* pixel = applyAtPixel(input->GetPixel(x,y));
            output->SetPixel(x,y,pixel);
            delete[] pixel;
        }
    }
}
