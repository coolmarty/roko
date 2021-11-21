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
#include "mirror.h"
#include "colorthreshold.h"
#include "cannyedge.h"
#include "blobdetect.h"


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
    filters["double_threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(150, 100));
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSuppression());
	  filters["mirror"] = unique_ptr<Filter>(new MirrorFilter());
    filters["color-thresh"]=unique_ptr<Filter>(new ColorThresholdFilter());
    filters["canny-edge-detect"] = unique_ptr<Filter>(new CannyEdgeFilter());


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
    if(filterType.compare("blob")==0){ // uses system() to run the filters in order, creating images leading up to the final canny edge detection. Once the canny edge detection image is complete, it deletes the images used in its creation
      unique_ptr<BlobDetect> blobby = unique_ptr<BlobDetect>(new BlobDetect());
      if(blobby->check(inputs,outputs)){
        cout<<"ROBOT FOUND!!!"<<endl;
      }

      return 1;
    }

    filters[filterType]->Apply(inputs, outputs);

    // Save output image
    if(filterType.compare("sobel")==0){
    	output2.SaveAs(outputFile2);
    }


    output.SaveAs(outputFile);
}
