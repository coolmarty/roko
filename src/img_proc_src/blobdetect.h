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
 * @brief The main class of BlobDetect.
 *
 *  main purpose is to find robot in an image and give its location
 */
class BlobDetect {
public:
     /**
  * @brief Generation of a BlobDetect
  *
  */
    BlobDetect();

    /**
  * @brief Application of a BlobDetect, returns true if we think there is a robot in the image
  *
  */
    bool check(std::vector<Image*> original, std::vector<Image*> filtered);

    /**
  * @brief get the distance of the robot in an image
  *
  */
    float getDistance(std::vector<Image*> original, std::vector<Image*> filtered);

    /**
  * @brief get the direction of the robot in an image
  *
  */
    std::vector<float> getDirection(std::vector<Image*> original, std::vector<Image*> filtered);

  private:
    bool isWhite(unsigned char* pixel);
};

#endif
