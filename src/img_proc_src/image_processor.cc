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
#include "isolation_filter.h"


using namespace std;

int main(int argc, const char* argv[]) {
    std::vector<std::string> good_filters;
    good_filters.push_back("greyscale");
    good_filters.push_back("gaussian");
    good_filters.push_back("mirror");
    good_filters.push_back("color-threshold");
    good_filters.push_back("sobel");
    good_filters.push_back("hysteresis");
    good_filters.push_back("non_max_supression");
    good_filters.push_back("invert");
    good_filters.push_back("double_threshold");
    good_filters.push_back("canny-edge-detect");
    good_filters.push_back("isolate");
    if(argc<4){
      cout<<"ERROR, please use the format ./build/image-app input <filter> output"<<endl;
      return -1;
    }
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
      if(argc<5){
        cout<<"ERROR, please use the format ./build/image-app input_1 input_2 non_max_suppression output"<<endl;
        return -1;
      }
    	inputFile2 = argv[2];
    	filterType = argv[3];
    	outputFile = argv[4];
    }
    else if(arg2.compare("sobel")==0){
      if(argc<5){
        cout<<"ERROR, please use the format ./build/image-app input sobel output_1 output_2"<<endl;
        return -1;
      }
    	filterType = argv[2];
    	outputFile = argv[3];
    	outputFile2 = argv[4];
    }
    else{
    	filterType = argv[2];
    	outputFile = argv[3];
    }
    int good=0;
    for(int i=0;i<good_filters.size();i++){
      if(filterType.compare(good_filters[i])==0){
        good=1;
      }
    }

    if(!good){
      cout<<"ERROR, please use one of the provided filters:"<<endl;
      for(int i=0;i<good_filters.size();i++){
        cout<<good_filters[i]<<endl;
      }
      return -1;
    }
    cout<<"good filter bud"<<endl;

    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["gaussian"] = unique_ptr<Filter>(new Gaussian_Blur());
    filters["invert"] = unique_ptr<Filter>(new InvertFilter());
    filters["hysteresis"] = unique_ptr<Filter>(new HysteresisFilter());
    filters["double_threshold"] = unique_ptr<Filter>(new DoubleThresholdFilter(200, 100));
    filters["sobel"] = unique_ptr<Filter>(new SobelFilter());
    filters["non_max_suppression"] = unique_ptr<Filter>(new NonMaxSuppression());
	  filters["mirror"] = unique_ptr<Filter>(new MirrorFilter());
    filters["color-threshold"] = unique_ptr<Filter>(new ColorThresholdFilter());
    filters["canny-edge-detect"] = unique_ptr<Filter>(new CannyEdgeFilter());
    filters["isolate"] = unique_ptr<Filter>(new IsolationFilter());

    // Filter *chosen_filter =filters[filterType].release();

    // Create input and output vectors
    Image input(inputFile);
    Image input2;
    Image output;
    Image output2;
    Image output3;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);

    if(filterType.compare("sobel")==0){
    	outputs.push_back(&output2);
    }
    if(filterType.compare("isolate")==0){
    	outputs.push_back(&output2);
      outputs.push_back(&output3);
    }
    if(filterType.compare("non_max_suppression")==0){
    	input2=(Image(inputFile2));
    	inputs.push_back(&input2);
    	output=(Image(inputFile2));
    }

    // Apply filter based on filter type

    filters[filterType]->Apply(inputs, outputs);


    cout<<"applied filter bud"<<endl;

    // Save output image
    if(filterType.compare("sobel")==0){
    	output2.SaveAs(outputFile2);
    }
    if(filterType.compare("isolate")==0){
      output.SaveAs("pics/r.png");
    	output2.SaveAs("pics/g.png");
      output3.SaveAs("pics/b.png");
    }


    output.SaveAs(outputFile);

    cout<<"saved image bud"<<endl;


    return 0;
}
