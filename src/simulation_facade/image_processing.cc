#include "img_proc_src/cannyedge.h"
#include "img_proc_src/blobdetect.h"
#include "image_processing.h"

bool ImageProcessing::BlobCheck(std::string fname) {
	Image in_img = Image(fname);
	Image out_img = Image(in_img.GetWidth(), in_img.GetHeight());
	std::vector<Image *> input;
	std::vector<Image *> output;
	input.push_back(&in_img);
	output.push_back(&out_img);

	BlobDetect filter;
	return filter.check(input, output);
}

float ImageProcessing::BlobGetDistance(std::string color_name, std::string depth_name) {
	Image color_img = Image(color_name);
	Image depth_img = Image(depth_name);
	std::vector<Image*> color_vec;
	std::vector<Image*> depth_vec;
	color_vec.push_back(&color_img);
	depth_vec.push_back(&depth_img);

	BlobDetect filter;
	return filter.getDistance(color_vec, depth_vec);
}

std::vector<float> ImageProcessing::BlobGetDirection(std::string color_name, std::string depth_name) {
	Image color_img = Image(color_name);
	Image depth_img = Image(depth_name);
	std::vector<Image*> color_vec;
	std::vector<Image*> depth_vec;
	color_vec.push_back(&color_img);
	depth_vec.push_back(&depth_img);

	BlobDetect filter;
	return filter.getDirection(color_vec, depth_vec);
}
