/*! \mainpage Canny Edge Detection for iteration one
 *
 * \section intro_sec Introduction
 *
 * Robot Drone search program by
 *
 * Emily Iverson
 *
 * Matthew Altamann
 *
 * Dheva Subramaniam
 *
 * Julia Schechter
 *
 *
 *
 *
 * \section how_to_make How to compile/run
 *
 * Simply type make from the provided Makefile and you will generate:
 *
 * web-app and test-app in the build folder
 *
 * To run the program simply type
 *
 * ./build/web-app <any port number> web
 *
 * \section class_overview Class Overview
 *
 * ##Simulation
 *
 * ###Simulation Facade
 *
 * The facade the web app interacts with, simulates a drone searching for a robot
 *
 * it holds a vector of entities and calls their update function to simulate them moving
 *
 * ###Entity
 *
 * A base class for all entities in our simulation, holds data about position direction, and time
 *
 * all have an update function that simulates how they'll change in a small time step
 *
 * ###EntityFactory
 *
 * A base class for all EntityFactories
 *
 * Creats an entity of a corresponding type
 *
 * Uses the abstract composite factory pattern
 *
 *
 * ##Web App
 *
 * ###WebApp
 *
 * The main class for communicating with our web app and sending/recieving JSON messages
 *
 *
 * ##Image processing
 *
 * ###ImageProcessing
 *
 * The image processing facade our camera interacts with
 *
 * blobs detecs to try and find robot using a variety of filters
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
 *
 * ###Filter
 *
 *The Filter class is our abstract class for all filters, it has one method, Apply, that applies the filter to an image
 *
 * ###SimpleFilter
 *
 *The simple filter class has 2 methods, Apply which iterates through an image and calls ApplyAtPixel For every pixel in the image
 *
 * ###Convolution
 *
 *The convolution class has the virtual method Apply to apply a convolutional filter, as well as a protected variable for the Kernal
 *
 * ###Kernal
 *
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
