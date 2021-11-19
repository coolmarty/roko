/**
 * @file blobdetect.h
 *
 *
 */

#ifndef BLOBDETECT_H_
#define BLOBDETECT_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "filter.h"
#include "cannyedge.h"
#include "colorthreshold.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of DoubleThresholdFilter.
 *
 *  Derived class of SimpleFilter, invoked to create and apply a double threshold filter to an Image.
 */
class BlobDetect {
public:
     /**
  * @brief Generation of a DoubleThresholdFilter with no parameters (defaults to orange)
  *
  */
    BlobDetect();
    /**
  * @brief Application of a DoubleThresholdFilter at a specific pixel in the image.
  *
  */
    bool check(std::vector<Image*> original, std::vector<Image*> filtered);

    float getDistance(std::vector<Image*> original, std::vector<Image*> filtered);

    std::vector<float> getDirection(std::vector<Image*> original, std::vector<Image*> filtered);

  private:
    bool isWhite(unsigned char* pixel);
};

#endif
