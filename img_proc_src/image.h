/**
 * @file image.h
 *
 */
#ifndef IMAGE_H_
#define IMAGE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <iostream>
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for images, allows for copying, saving, and getting/setting pixels
 *
 *
 */
class Image{
public:
    /**
     * @brief default constructor for creating an image;
     *
     * @return an Image with width 0 and height 0;
     */
    Image();

    /**
     * @brief a constructor for creating an image;
     *
     * @return an Image with a certain width and height;
     */
    Image(int width,int height);

    /**
     * @brief a constructor for creating an image;
     *
     * @return an Image read in from a file fname;
     */
    Image(std::string fname);

    /**
     * @brief a copy constructor for creating an image;
     *
     * @return an Image identical to the one passed in;
     */
    Image(const Image& image);

    /**
     * @brief destructor for an image;
     *
     * @return none;
     */
    ~Image();

    /**
     * @brief Saves the image to the file fname;
     *
     * @return none;
     */
    void SaveAs(std::string fname);

    /**
     * @brief equals operator for setting an image;
     *
     * @return none;
     */
    void operator=(Image image);

    /**
     * @brief getter for the width of an image;
     *
     * @return the width of an image as an int;
     */
    int GetHeight();

    /**
     * @brief getter for the height of the image;
     *
     * @return the height of an image as an int;
     */
    int GetWidth();

    /**
     * @brief a function for getting the number of components of an image;
     *
     * @return the number of components as an int;
     */
    int GetComponentNumber();

    /**
     * @brief a getter for the pixel located at (x,y);
     *
     * @return the length 4 unsigned char array of that pixel;
     */
    unsigned char* GetPixel(int x, int y);

    /**
     * @brief setter for pixel at(x,y) to be set with the unsigned char array colors;
     *
     * @return none;
     */
    void SetPixel(int x, int y, unsigned char* colors);


    float getDistance(int x,int y);

    std::vector<float> getDirection(int x,int y);


private:
    unsigned char* image;
    int width;
    int height;
    int components;

    float magnitudeVector(std::vector<float> vec);






};

#endif
