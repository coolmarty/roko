/*! \mainpage Canny Edge Detection for iteration one
 *
 * \section intro_sec Introduction
 *
 * Canny Edge detection program by
 *
 * Emily Iverson
 *
 * Matthew Altamann
 *
 * Julia Schechter
 *
 * Gabriel Subra
 *
 *
 * \section how_to_make How to compile/run
 *
 * Simply type make from the provided Makefile and you will generate:
 *
 * image_processor
 *
 * To run the program simply type
 *
 * ./image_processor {input file path} {filter to apply} {output file path}
 *
 * \section class_overview Class Overview
 *
 * Image
 * -----
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
 *
 *Filter
 *-------
 *
 *The Filter class is our abstract class for all filters, it has one method, Apply, that applies the filter to an image
 *
 *SimpleFilter
 *------------
 *
 *The simple filter class has 2 methods, Apply which iterates through an image and calls ApplyAtPixel For every pixel in the image
 *
 *Convolution
 *------
 *
 *The convolution class has the virtual method Apply to apply a convolutional filter, as well as a protected variable for the Kernal
 *
 *Kernal
 *------
 *The kernal class is for getting values from a kernel
 *
 *(unintentional misspelling, found too late)
 *
 * \section extending How to extend the system
 *
 *To add a new filter simply make it inherit from convolution or simple filter
 *
 *if its a simple filter the entire apply function must be made, if its only a simple filter only the apply at pixel method must be implemented
 *
 *
 */
