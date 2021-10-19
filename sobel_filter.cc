#include "sobel_filter.h"

SobelFilter::SobelFilter(){
    std::vector<std::vector<float>> kernalPrototype = {{-1,0,1},{-2,0,2},{-1,0,1}};
    colonel = Kernal(kernalPrototype);
}

int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    return b;
}

void SobelFilter::Apply(std::vector<Image*> input, std::vector<Image*> output){
    Image *intensity = output.at(0);
    Image *direction =output.at(1);

    Image *in = input.at(0);

    *intensity = *in;
    *direction = *in;

    std::vector<std::vector<float>> kernalPrototype = {{1,2,1},{0,0,0},{-1,-2,-1}};
    Kernal Kernal_y = Kernal(kernalPrototype);


    for(int y=0; y<in->GetHeight(); y++){
        for(int x=0; x<in->GetWidth(); x++){
            int red_x=0;
            int green_x=0;
            int blue_x=0;

            int red_y=0;
            int green_y=0;
            int blue_y=0;

            int size = colonel.getSize();
            for(int i = 0;i<size;i++){
                for(int j = 0;j<size;j++){
                    unsigned char* pixel = in->GetPixel(x+(i-floor(size/2)),y+(j-floor(size/2)));
                    red_x+= pixel[0]*colonel.get(i,j);
                    green_x+= pixel[1]*colonel.get(i,j);
                    blue_x+=pixel[2]*colonel.get(i,j);

                    red_y += pixel[0]*Kernal_y.get(i,j);
                    green_y += pixel[1]*Kernal_y.get(i,j);
                    blue_y += pixel[2]*Kernal_y.get(i,j);
                }
            }


            // std::cout<<red_x<<" "<<green_x<<" "<<blue_x<<std::endl<<red_y<<" "<<green_y<<" "<<blue_y<<std::endl<<std::endl;

            unsigned char* newPixel_i= new unsigned char[4];

            newPixel_i[0] = min(floor(sqrt(red_x*red_x+red_y*red_y)),255);
            newPixel_i[1] = min(floor(sqrt(green_x*green_x+green_y*green_y)),255);
            newPixel_i[2] = min(floor(sqrt(blue_x*blue_x+blue_y*blue_y)),255);
            newPixel_i[3] = 255;

            // std::cout<<min(floor(sqrt(pow(red_x,2)+pow(red_y,2))),255)<<" "<<min(floor(sqrt(pow(green_x,2)+pow(green_y,2))),255)<<" "<<min(floor(sqrt(pow(blue_x,2)+pow(blue_y,2))),255)<<std::endl;

            intensity->SetPixel(x,y,newPixel_i);

            delete[] newPixel_i;

            unsigned char* newPixel_d= new unsigned char[4];



            // std::cout<< floor(atan2(red_y,red_x)*180/3.1415926535)<<" "<< floor(atan2(green_y,green_x)*180/3.1415926535)<<" "<< floor(atan2(blue_y,blue_x)*180/3.1415926535)<<std::endl;

            if(atan2(red_y,red_x)==0){
                newPixel_d[0]=0;
                newPixel_d[1]=0;
                newPixel_d[2]=0;
            }
            else{
                float red = atan2(red_y,red_x)+M_PI;
                // red = abs(red);
                red*=20;
                // std::cout<<red<<std::endl;
                newPixel_d[0] = red;
                newPixel_d[1] = red;
                newPixel_d[2] = red;
            }

            newPixel_d[3] = 255;

            direction->SetPixel(x,y,newPixel_d);

            delete[] newPixel_d;
        }
    }
}
