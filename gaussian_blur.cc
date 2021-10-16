#include "gaussian_blur.h"

Gaussian_Blur::Gaussian_Blur(){
    std::vector<std::vector<float>> kernalPrototype = {{1,4,6,4,1},{4,16,24,16,4},{6,24,36,24,6},{4,16,24,16,4},{1,4,6,4,1}};
    colonel = Kernal(kernalPrototype);
    return;
}

void Gaussian_Blur::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    Image *output = filtered.at(0);
    Image *input = original.at(0);
    *output = *input;//set input to correct width/height
    int divisor=256;
    for(int y=0; y<input->GetHeight(); y++){
        for(int x=0; x<input->GetWidth(); x++){
            unsigned char* newPixel= new unsigned char[4];
            newPixel[0]=0;
            newPixel[1]=0;
            newPixel[2]=0;
            int red=0;
            int green=0;
            int blue=0;
            int count=0;
            int size = colonel.getSize();
            for(int i = 0;i<size;i++){
                for(int j = 0;j<size;j++){
                    unsigned char* pixel = input->GetPixel(x+(i-floor(size/2)),y+(j-floor(size/2)));
                    red+= pixel[0]*colonel.get(i,j);
                    green+= pixel[1]*colonel.get(i,j);
                    blue+=pixel[2]*colonel.get(i,j);
                    // count+=1;
                }
            }
            red/=divisor;
            green/=divisor;
            blue/=divisor;
            
            newPixel[0] = red;
            newPixel[1] = green;
            newPixel[2] = blue;
            newPixel[3]=255;


            output->SetPixel(x,y,newPixel);
            delete[] newPixel;
        }
    }
    return;
}
