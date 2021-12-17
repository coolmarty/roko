/*! \page Sim Simulation Documentation
*
* \section intro_sec Introduction
*
* Robot Drone search program simulation by
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
* \section class_overview Class Overview
*
* \image html "../resources/full_uml.png"
*
* ##Simulation
*
* ###Simulation Facade
*
* The facade the web app interacts with, simulates a drone searching for a robot
*
* it holds a vector of entities and calls their update function to simulate them moving
*
* ###EntityFactory
*
* our main way to generate entitites, the composite entity factory generates all entitites by iterating through concrete factories
*
* ###Entity
*
* A base class for all entities in our simulation, holds data about position direction, and time
*
* all have an update function that simulates how they'll change in a small time step
*
* ###Drone
*
* our main actor in the simulation, moves around looking for the robot in images it takes, if it finds one it beelines towards it
*
* ###Robot
*
* what we search for in the simulation
*
* ###RechargeStation
*
* Recharges the Drone allowing it to search for the robot for longer
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
* The SimpleFilter class has 2 methods, Apply which iterates through an image and calls ApplyAtPixel For every pixel in the image
*
* ###Convolution
*
*The Convolution class has the virtual method Apply to apply a convolutional filter, as well as a protected variable for the Kernal
*
* ###Kernal
*
*The Kernal class is for getting values from a kernel
*
*(unintentional misspelling, found too late)
*
* \section extending How to extend the system
*
* To add a new Entity just make its class, make a factory for it, and add its factory to the composite factory's vector
*
* To add new behavior to an Entity, simply make a new entity with a unique update function
*
* To add new ways to find the robot just change the Image Processing facade and add in any filters wanted
*
*
*/
