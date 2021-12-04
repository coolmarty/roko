/**
 * @file kernal.h
 *
 */
#ifndef KERNAL_H_
#define KERNAL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include <iostream>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief a class for creating kernals to be used with convolutional filters;
 *
 *
 */
class Kernal {
public:
    /**
     * @brief constructor for a Kernal that takes in a 2D vector;
     *
     * @return a Kernal object with that 2D vector;
     */
    Kernal(std::vector<std::vector<float>> k);

    /**
     * @brief default constructor for a Kernal;
     *
     * @return a Kernal with a size of 0;
     */
    Kernal();

    /**
     * @brief destructor for a kernal;
     *
     * @return none;
     */
    ~Kernal();

    /**
     * @brief getter for the size of a kernal;
     *
     * @return the size represented as an int;
     */
    int getSize();

    /**
     * @brief a getter for the value located at Kernal[y][x];
     *
     * @return the value at (x,y) as a float;
     */
    float get(int x, int y);

private:
    std::vector<std::vector<float>> kernal;

    int size;
};


#endif
