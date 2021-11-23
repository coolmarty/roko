#include "hysteresis_filter.h"

HysteresisFilter::HysteresisFilter(){
    std::vector<std::vector<float>> kernalPrototype = {{1,1,1},{1,1,1},{1,1,1}};
    colonel = Kernal(kernalPrototype);
    return;
}

void HysteresisFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    Image *output = filtered.at(0);
    Image *input = original.at(0);
    *output = *input;//set input to correct width/height
    const unsigned char blackPixel[4] = {0,0,0,255};
    const unsigned char strongPixel[4] = {255,255,255,255};
    for(int y=0; y<input->GetHeight(); y++){
        for(int x=0; x<input->GetWidth(); x++){
            unsigned char* newPixel = new unsigned char[4];
            newPixel[0] = 0;
            newPixel[1] = 0;
            newPixel[2] = 0;
            newPixel[3] = 255;
            if(input->GetPixel(x,y)[0] == 0){ // sets black pixels to black
                newPixel[0] = 0;
                newPixel[1] = 0;
                newPixel[2] = 0;
                newPixel[3] = 255;
            }
            else if(input->GetPixel(x,y)[0] == 255){ // sets strong pixels to white
                newPixel[0] = 255;
                newPixel[1] = 255;
                newPixel[2] = 255;
                newPixel[3] = 255;
            }
            else{ // determines if a weak pixel is surrounded by any strongs 
                int size = colonel.getSize();
                int neighboringStrong = 0; // 0 if no strong pixel found, 1 if found
                for(int i = -1; i < size-1; i++){ // double nested for loop checking for surrounding strong pixels
                    for(int j = -1; j < size-1; j++){
                        if(input->GetPixel(x+i,y+j)[0] == 255){
                            neighboringStrong = 1;
                        }
                    }
                }
                if(neighboringStrong == 1){
                    newPixel[0] = 255;
                    newPixel[1] = 255;
                    newPixel[2] = 255;
                    newPixel[3] = 255;
                }
            }
            output->SetPixel(x,y,newPixel);
            delete[] newPixel;
        }
    }
    return;
}