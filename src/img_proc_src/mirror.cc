#include "mirror.h"

void MirrorFilter::Apply(std::vector<Image*> input, std::vector<Image*> output) {
	Image* inputImg = input.at(0);
	Image* outputImg = output.at(0);
	
	*outputImg = *inputImg;
	
	int height = inputImg->GetHeight();
	int width = inputImg->GetWidth();
	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			outputImg->SetPixel(x, y, inputImg->GetPixel(width - x, y));
		}
	}
}