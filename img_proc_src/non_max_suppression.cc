#ifndef NON_MAX_SUPPRESSION_CC_
#define NON_MAX_SUPPRESSION_CC_

#include "non_max_suppression.h"

void NonMaxSuppression::Apply(std::vector<Image*> input, std::vector<Image*> output) {
	const float pi = 3.1415926;
	
	Image* intensity = input.at(0);
	Image* direction = input.at(1);
	
	Image* out = output.at(0);
	unsigned char out_pix[4];
	
	unsigned char intensity_pix;
	unsigned char direction_pix;
	
	unsigned char adj_1;
	unsigned char adj_2;
	
	float angle;
	
	int height = intensity->GetHeight();
	int width = intensity->GetWidth();
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			intensity_pix = intensity->GetPixel(x, y)[0];
			direction_pix = direction->GetPixel(x, y)[0];
			
			if (direction_pix != 0) {
				angle = static_cast<float>(direction_pix) / static_cast<float>(20) - pi;
			} else {
				angle = 0;
			}
			
			if ((angle < (pi / 8.)) || ((angle < 9. * pi / 8.) && (angle > 7. * pi / 8.)) || (angle > (15. * pi / 8.))) { // Direction 0 or pi
				if (x + 1 == width) {
					adj_1 = -1;
				} else {
					adj_1 = intensity->GetPixel(x+1, y)[0];
				}
				
				if (x - 1 < 0) {
					adj_2 = -1;
				} else {
					adj_2 = intensity->GetPixel(x-1, y)[0];
				}
			} else if ((angle < 3. * pi / 8.) || ((angle < 11. * pi / 8.) && (angle > 9. * pi / 8.))) { // Direction pi/4 or 5pi/4
				if (x + 1 == width || y - 1  <0) {
					adj_1 = -1;
				} else {
					adj_1 = intensity->GetPixel(x+1, y-1)[0];
				}
				
				if (x - 1 < 0 || y + 1 == height) {
					adj_2 = -1;
				} else {
					adj_2 = intensity->GetPixel(x-1, y+1)[0];
				}
			} else if ((angle < 5. * pi / 8.) || ((angle < 13. * pi / 8.) && (angle > 11. * pi / 8.))) { // Direction pi/2 or 3pi/2
				if (y + 1 == height) {
					adj_1 = -1;
				} else {
					adj_1 = intensity->GetPixel(x, y+1)[0];
				}
				
				if (y - 1 < 0) {
					adj_2 = -1;
				} else {
					adj_2 = intensity->GetPixel(x, y-1)[0];
				}
			} else { // Direction 3pi/4 or 7pi/4
				if (x - 1 < 0 || y - 1 < 0) {
					adj_1 = -1;
				} else {
					adj_1 = intensity->GetPixel(x-1, y-1)[0];
				}
				
				if (x + 1 == width || y + 1 == height) {
					adj_2 = -1;
				} else {
					adj_2 = intensity->GetPixel(x+1, y+1)[0];
				}
			}
			
			if ((adj_1 > intensity_pix) || (adj_2 > intensity_pix)) {
				for (int i = 0; i < 3; i++) {
					out_pix[i] = 0;
				}
				out_pix[3] = 255;
			} else {
				for (int i = 0; i < 4; i++) {
					out_pix[i] = intensity->GetPixel(x, y)[i];
				}
			}
			
			out->SetPixel(x, y, out_pix);
		}
	}
}

#endif