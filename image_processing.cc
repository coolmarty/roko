#include "img_proc_src/cannyedge.h"
#include "img_proc_src/blobdetect.h"
#include "image_processing.h"

/* void ImageProcessing::CannyEdge(Image *in_img) {
	std::vector<Image *> input;
	std::vector<Image *> output;
	input.push_back(in_img);
	
	CannyEdgeFilter filter;
	filter.Apply(input, output);
	return output
} */

bool ImageProcessing::BlobCheck(Image *in_img) {
	std::vector<Image *> input;
	std::vector<Image *> output;
	input.push_back(in_img);
	
	BlobDetect filter;
	return filter.check(input, output);
}

float ImageProcessing::BlobGetDistance(Image *in_img) {
	std::vector<Image *> input;
	std::vector<Image *> output;
	input.push_back(in_img);
	
	BlobDetect filter;
	return filter.getDistance(input, output);
}

std::vector<float> ImageProcessing::BlobGetDirection(Image *in_img) {
	std::vector<Image *> input;
	std::vector<Image *> output;
	input.push_back(in_img);
	
	BlobDetect filter;
	return filter.getDirection(input, output);
}