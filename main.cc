#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <memory>
#include "image.h"
#include "filter.h"
#include "simple_filter.h"
#include "greyscale_filter.h"
#include "invert.h"

using namespace std;

int main(int argc, const char* argv[]) {
    // Get input file, filter type, and output file from command line
    // argc = # of arguments
    // argv = an array of arguments
    std::string inputFile(argv[1]);
    std::string filterType(argv[2]);
    std::string outputFile(argv[3]);

    // Create available filters (unique_ptr handles dynamic memory)
    std::map<std::string, unique_ptr<Filter>> filters;
    filters["greyscale"] = unique_ptr<Filter>(new GreyScaleFilter());
    filters["invert"] = unique_ptr<Filter>(new InvertFilter());

    // Create input and output vectors
    Image input(inputFile);
    Image output;
    std::vector<Image*> inputs;
    std::vector<Image*> outputs;
    inputs.push_back(&input);
    outputs.push_back(&output);

    // Apply filter based on filter type
    for(int i =0;i<200;i++){
        filters[filterType]->Apply(inputs, outputs);
        filters[filterType]->Apply(outputs,inputs);
    }

    // Save output image
    output.SaveAs(outputFile);
}
