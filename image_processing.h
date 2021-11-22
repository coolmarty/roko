#ifndef _IMAGE_PROCESSING_H
#define _IMAGE_PROCESSING_H

#include "drone.h"
#include "img_proc_src/image.h"

class ImageProcessing {
public:
	//void CannyEdge(Image *in_img);
	bool BlobCheck(Image *in_img);
	float BlobGetDistance(Image *in_img);
	std::vector<float> BlobGetDirection(Image *in_img);
};

#endif
