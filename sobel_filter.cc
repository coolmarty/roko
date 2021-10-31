#include "sobel_filter.h"

SobelFilter::SobelFilter(){
    std::vector<std::vector<float>> kernalPrototype = {{-1,0,1},{-2,0,2},{-1,0,1}};//x kernal
    colonel = Kernal(kernalPrototype);//set colonel to x kernal
}

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
int max(int a,int b){ //returns the maximum of 2 numbers
    if(a>b){
        return a;
    }
    return b;
}

void SobelFilter::Apply(std::vector<Image*> input, std::vector<Image*> output){

    Image *intensity = output.at(0);//intensity image
    Image *direction =output.at(1);//direction image

    Image *in = input.at(0);//input image

    *intensity = *in;//sit width and height to input image
    *direction = *in;//sit width and height to input image

    std::vector<std::vector<float>> kernalPrototype = {{1,2,1},{0,0,0},{-1,-2,-1}};//y kernal
    Kernal Kernal_y = Kernal(kernalPrototype);//set y kernal


    for(int y=0; y<in->GetHeight(); y++){
        for(int x=0; x<in->GetWidth(); x++){//iterate through image
            int lum_x=0;//luminance of the x pixel
            int lum_y=0;//luminance of the y pixel

            int size = colonel.getSize();//kernal size

            for(int i = 0;i<size;i++){
                for(int j = 0;j<size;j++){//iterate through the kernals

                    unsigned char* pixel = in->GetPixel(x+(i-floor(size/2)),y+(j-floor(size/2)));//get pixel

                    lum_x += pixel[0]*colonel.get(i,j);//get x luminance

                    lum_y += pixel[0]*Kernal_y.get(i,j);//get y luminance
                }
            }

            unsigned char* newPixel_i= new unsigned char[4];//new pixel for intensity image

            int intensityLevel = min(floor(sqrt(lum_x*lum_x+lum_y*lum_y)),255);//get intensity level

            //set the pixel
            newPixel_i[0] = intensityLevel;
            newPixel_i[1] = intensityLevel;
            newPixel_i[2] = intensityLevel;
            newPixel_i[3] = 255;


            intensity->SetPixel(x,y,newPixel_i);//put pixel in image

            delete[] newPixel_i;//delete so no mem leaks

            unsigned char* newPixel_d= new unsigned char[4];//new pixel for direction matrix

            if(atan2(lum_y,lum_x)==0){//set 0 direction to 0;
                newPixel_d[0]=0;
                newPixel_d[1]=0;
                newPixel_d[2]=0;
            }
            else{
                float directionLevel = atan2(lum_y,lum_x)+M_PI;//make sure directionLevel is positive
                directionLevel*=20;//multiply so more directions for non max suppression

                //set pixel for direction level
                newPixel_d[0] = directionLevel;
                newPixel_d[1] = directionLevel;
                newPixel_d[2] = directionLevel;
            }

            newPixel_d[3] = 255;

            direction->SetPixel(x,y,newPixel_d);//put pixel in direction image

            delete[] newPixel_d;//delete so no mem leaks
        }
    }
<<<<<<< HEAD
}
=======
}
>>>>>>> fb4696a4e708f875b8c79119e1c8884180b7cf18
