/*! \page RokoImageApp Roko's Image processor
 *
 * \section intro_sec Introduction
 *
 * Image processing app by
 *
 * Emily Iverson
 *
 * Matthew Altamann
 *
 * Dheva Subramaniam
 *
 * Julia Schechter
 *
 * \section how_to_make How to compile/run
 *
 * Simply type make from the provided Makefile and you will generate image-app in the build folder
 *
 * To run the program simply type
 *
 * ./build/image-app input filter output (for most filters, non-max-supression and sobel are special cases see below)
 *
 * The list of good filters are:
 *
 * greyscale: converts the image to greyscale
 *
 * gaussian: applies a standard gaussian blur to an image
 *
 * mirror: mirrors the image on the horizontal axis
 *
 * color-threshold: shows the colors close to orange on the new image as white pixels
 *
 * sobel: applies a sobel filter to an image (NOTE: pass in 2 outputs for it after the filter name)
 *
 * hysteresis: applies a hysteresis filter to an image
 *
 * non_max_supression: applies a non max supression algorithm to an image(NOTE: pass in 2 inputs before the filter name if using this filter)
 *
 * invert: inverts an image's colors
 *
 * double_threshold: applies a double threshold filter on an image
 *
 * canny-edge-detect: creates a new image showing the lines found on the original image
 *
 * \section class_overview Class Overview
 *
 * \image html "../resources/image-processor.png"
 *
 * ##Image processing
 *
 * ###Image
 *
 *The image class is the main way we work with image data, it holds a one dimensional
 *unsigned char array of length width*height*components of the image
 *
 *We have getters and setters for individual pixels (4 length unsigned char arrays)
 *
 *There is also a copy constructor/operator= method to allow for copying images
 *
 *As well as methods to save to and load from files
 *
 *An easy way to iterate through an image would be 2 nested for loops, the outer for y of the image, and the inner for the x
 *
 *
 * ###Filter
 *
 *The Filter class is our abstract class for all filters, it has one method, Apply, that applies the filter to an image
 *
 *Filters that inherit directly from this are free to implement whatever filter they want
 *
 * ###SimpleFilter
 *
 * The SimpleFilter class has 2 methods, Apply which iterates through an image and calls ApplyAtPixel For every pixel in the image
 *
 *If inheriting a filter from this class only the ApplyAtPixel method needs to be implemented
 *
 *Filters that inherit directly can only see one pixel at a time
 *
 * ###Convolution
 *
 *The Convolution class has the virtual method Apply to apply a convolutional filter, as well as a protected variable for the Kernal
 *
 *Filters that inherit directly from this have an associated Kernel that uses data from surrouding pixels
 *
 * ###Kernal
 *
 *The Kernal class is for getting values from a kernel
 *
 * \section extending How to extend the system
 *
 * To add a new Filter to the system you must:
 *
 * 1. decide what filter to make
 *
 * 2. make it inherit from SimpleFilter,Convolution, or Filter
 *
 * 3. implementing:
 *    - if inheriting from SimpleFilter just fill out the ApplyAtPixel function, stating what you want the filter to do to every pixel
 *
 *    - otherwise fill out the Apply function by looping through the image, and doing whatever math needs to be done
 *
 * 4. after implementing your filter, add it to the includes of image_processor.cc
 *
 * 5. give it a string to recognize your filter by (ex: radial-blur for a RadialBlur filter)
 *
 * and that's it
 *
 *
 * For instance to isolate the blue channel for a filter you would:
 *
 * 1. decide to make a blue isolation filter
 *
 * 2. make it inherit from SimpleFilter (since it would only have to know about one pixel at a time)
 *
 * 3. set the ApplyAtPixel to return a pixel with only the blue value from the pixel coming in
 *
 * 4. add the #include "blueisolationfilter.h" to image_processor.cc
 *
 * 5. add filters["blue-isolation"] = unique_ptr<Filter>(new BlueIsolationFilter()); to image_processor.cc
 *
 * and now you've added a blue isolation filter to the image-app. Congratualtions!!
 *
 * \section Additional notes
 *
 * the ApplyAtPixel function has to create a new pixel that will be freed in SimpleFilter's apply
 *
 * the Convolution filter has no associated code, we reccomend a 4x nested for loop, 2 for the image, 2 for the Kernal
 *
 * if working with multiple inputs/outputs you wanna add an if else statement to catch if enough args are passed in prolly
 *
 */
