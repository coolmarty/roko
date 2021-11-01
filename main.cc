#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <cstring>
#include <memory>
#include "image.h"
#include "filter.h"
#include "simple_filter.h"
#include "convolution.h"
#include "greyscale_filter.h"
#include "gaussian_blur.h"
#include "sobel_filter.h"
#include "non_max_suppression.h"
#include "doublethreshold.h"
#include "hysteresis_filter.h"
#include "invert.h"


using namespace std;

int main(int argc, const char* argv[]) {

    
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    std::string arg2(argv[2]);
    std::string arg3(argv[3]);
    std::string inputFile(argv[1]);
    std::string inputFile2;
    std::string filterType;
    std::string outputFile;
    std::string outputFile2;
    if(arg3.compare("non_max_suppression")==0){
    	inputFile2 = argv[2];
    	filterType = argv[3];
    	outputFile = argv[4];
    }
    else if(arg2.compare("sobel")==0){
    	filterType = argv[2];
    	outputFile = argv[3];
    	outputFile2 = argv[4];
    }
    else{
    	filterType = argv[2];
    	outputFile = argv[3];
    }

    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian"] = unique_ptr<Filter>(new Gaussian_Blur());
    filters["invert"] = unique_ptr<Filter>(new InvertFilter());
    filters["hysteresis"] = unique_ptr<Filter>(new HysteresisFilter());
    filters["double_threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(200, 100));
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSuppression());


    // Create input and output vectors
    Image input(inputFile);
    Image input2;
    Image output;
    Image output2;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);

    if(filterType.compare("sobel")==0){
    	outputs.push_back(&output2);	
    }
    if(filterType.compare("non_max_suppression")==0){
    	input2=(Image(inputFile2));
    	inputs.push_back(&input2);
    	output=(Image(inputFile2));
    }

    // Apply filter based on filter type

    // using canny-edge-detect runs a full canny edge detection filter
    if(filterType.compare("canny-edge-detect")==0){ // uses system() to run the filters in order, creating images leading up to the final canny edge detection. Once the canny edge detection image is complete, it deletes the images used in its creation
    	std::string openingLine = "./image_processor " + inputFile + " greyscale greyscaleimage.png";
    	std::string closingLine = "./image_processor dtimage.png hysteresis " + outputFile;
    	int openLen = openingLine.length();
    	int closeLen = closingLine.length();
    	char openCommand[openLen + 1];
    	char closeCommand[closeLen + 1];
    	strcpy(openCommand, openingLine.c_str());
    	strcpy(closeCommand, closingLine.c_str());
    	system(openCommand);
    	system("./image_processor greyscaleimage.png gaussian gaussianimage.png");
    	system("./image_processor gaussianimage.png sobel sobelimageintensity.png sobelimagedirection.png");
    	system("./image_processor sobelimageintensity.png sobelimagedirection.png non_max_suppression nonmaximage.png");
    	system("./image_processor nonmaximage.png double_threshold dtimage.png");
    	system(closeCommand);
    	system("rm greyscaleimage.png gaussianimage.png sobelimagedirection.png sobelimageintensity.png nonmaximage.png dtimage.png");
    	return 1;
    }

    filters[filterType]->Apply(inputs, outputs);

    // Save output image
    if(filterType.compare("sobel")==0){
    	output2.SaveAs(outputFile2);
    }


    output.SaveAs(outputFile);
}
