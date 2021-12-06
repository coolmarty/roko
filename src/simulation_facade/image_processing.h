/**
 * @file image_processing.h
*/


#ifndef _IMAGE_PROCESSING_H
#define _IMAGE_PROCESSING_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "img_proc_src/image.h"

/**
 * @brief Facade into the image processing functionality of the Drone
 */
class ImageProcessing {
public:
	/**
	 * @brief Uses image processor to determine whether the robot was detected in an RGB image via blob detect
	 */
	bool BlobCheck(std::string fname);

	/**
	 * @brief Uses image processor to determine the distance away from the drone the robot is given a depth image. Typically run after BloblCheck returns true.
	 */
	float BlobGetDistance(std::string color_name, std::string depth_name);

	/**
	 * @brief Gets the direction of the robot relative to the front of the drone
	 */
	std::vector<float> BlobGetDirection(std::string color_name, std::string depth_name);
};

#endif
