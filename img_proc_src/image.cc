#include "image.h"
#include <iostream>
#include <string>


// Needed for reading images
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Needed for writing images
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
Image::Image(){
    width=0;
    height=0;
}
Image::Image(const Image& image){
    this->width = image.width;
    this->height = image.height;
    this->components=image.components;
    this->image=new unsigned char[width*height*components];
    for(int i=0;i<width*height*components;i++){
        this->image[i]=image.image[i];
    }
}
Image::Image(int width, int height){
    this->width = width;
    this->height=height;
    components=4;
    image = new unsigned char[width*height*components];
}
Image::Image(std::string fname){
    unsigned char *loadedImage = stbi_load(fname.c_str(), &width, &height, &components, STBI_rgb_alpha);
    components=4;
    image = new unsigned char[width*height*components];

  	std::copy(loadedImage, loadedImage + width*height*components, image); // copy allows us to copy one byte array to another
    stbi_image_free(loadedImage);
}

void Image::operator=(Image image){
    this->width = image.width;
    this->height = image.height;
    this->components=image.components;
    this->image=new unsigned char[width*height*components];
    for(int i=0;i<width*height*components;i++){
        this->image[i]=image.image[i];
    }

}

Image::~Image(){
    delete[] image;
}

void Image::SaveAs(std::string fname){
    stbi_write_png(fname.c_str(), width, height, components, image, width*4);
}

int Image::GetHeight(){
    return height;
}
int Image::GetWidth(){
    return width;
}
int Image::GetComponentNumber(){
    return components;
}

unsigned char* Image::GetPixel(int x, int y){
    if(x<0){
        x=0;
    }
    else if(x>=width){
        x=width-1;
    }
    if(y<0){
        y=0;
    }
    else if(y>=height){
        y=height-1;
    }
    return &image[(y*width + x)*4];
}

void Image::SetPixel(int x, int y, unsigned char* colors){
    unsigned char* pixel = &image[(y*width + x)*4];
    pixel[0] = colors[0];
    pixel[1] = colors[1];
    pixel[2] = colors[2];
    pixel[3] = colors[3];
}

float Image::getDistance(int x,int y){
    unsigned char* pixel = &image[(y*width + x)*4];
    return (1.0-(pixel[0]/255))*50.0;
}

std::vector<float> Image::getDirection(int x,int y){
    unsigned char* pixel = &image[(y*width + x)*4];
    std::vector<float> direction;
    direction.push_back(((pixel[1]/255.0)-.5)*2.0);
    direction.push_back(((pixel[2]/255.0)-.5)*2.0);
    direction.push_back(((pixel[3]/255.0)-.5)*2.0);
    return direction;
}
