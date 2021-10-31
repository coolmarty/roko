#include "gaussian_blur.h"

Gaussian_Blur::Gaussian_Blur(){
    std::vector<std::vector<float>> kernalPrototype = {{1,4,6,4,1},{4,16,24,16,4},{6,24,36,24,6},{4,16,24,16,4},{1,4,6,4,1}};//kernal
    colonel = Kernal(kernalPrototype);//set colonel
    return;
}

void Gaussian_Blur::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
    Image *output = filtered.at(0);//set output pointer
    Image *input = original.at(0);//set input pointer

    *output = *input;//set input to correct width/height

    int divisor=256;

    for(int y=0; y<input->GetHeight(); y++){
        for(int x=0; x<input->GetWidth(); x++){
            unsigned char* newPixel= new unsigned char[4];//pixel to modify

            newPixel[0]=0;
            newPixel[1]=0;
            newPixel[2]=0;

            //rgb values
            int red=0;
            int green=0;
            int blue=0;

            int size = colonel.getSize();//get the size of the kernal

            for(int i = 0;i<size;i++){
                for(int j = 0;j<size;j++){//iterate through kernal
                    unsigned char* pixel = input->GetPixel(x+(i-floor(size/2)),y+(j-floor(size/2)));//get pixel at kernal

                    //add to rgb value
                    red+= pixel[0]*colonel.get(i,j);
                    green+= pixel[1]*colonel.get(i,j);
                    blue+=pixel[2]*colonel.get(i,j);

                }
            }
            //divide by 256 to get color
            red/=divisor;
            green/=divisor;
            blue/=divisor;

            //set color
            newPixel[0] = red;
            newPixel[1] = green;
            newPixel[2] = blue;
            newPixel[3]=255;


            output->SetPixel(x,y,newPixel);//set pixel into output image

            delete[] newPixel;//dont cause a mem leak
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> fb4696a4e708f875b8c79119e1c8884180b7cf18
