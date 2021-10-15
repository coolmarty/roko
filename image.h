#ifndef IMAGE_H_
#define IMAGE_H_
#include <string>
#include <iostream>

/**
 * @brief The main class for images, allows for copying, saving, and getting/setting pixels
 *
 *
 */
class Image{
public:
    Image();
    Image(int width,int height);
    Image(std::string fname);
    Image(const Image& image);

    ~Image();

    void SaveAs(std::string fname);

    void operator=(Image image);

    int GetHeight();
    int GetWidth();
    int GetComponentNumber();

    unsigned char* GetPixel(int x, int y);

    void SetPixel(int x, int y, unsigned char* colors);
private:
    unsigned char* image;
    int width;
    int height;
    int components;






};

#endif
