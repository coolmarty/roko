#include "cannyedge.h"
#include <math.h>
#include <memory>

using namespace std;

CannyEdgeFilter::CannyEdgeFilter(){
  return;
}

void CannyEdgeFilter::Apply(std::vector<Image*> original, std::vector<Image*> filtered){
  unique_ptr<Filter> grey=unique_ptr<Filter>(new GreyScaleFilter());
  unique_ptr<Filter> blur = unique_ptr<Filter>(new Gaussian_Blur());
  unique_ptr<Filter> sobel = unique_ptr<Filter>(new SobelFilter());
  unique_ptr<Filter> nonMax = unique_ptr<Filter>(new NonMaxSuppression());
  unique_ptr<Filter> doubleThresh = unique_ptr<Filter>(new DoubleThresholdFilter(200, 100));
  unique_ptr<Filter> hysteresis = unique_ptr<Filter>(new HysteresisFilter());

  Image extra;
  grey->Apply(original,filtered);//greyscale now in filtered
  blur->Apply(filtered,original);//grey blur in original

  filtered.push_back(&extra);

  sobel->Apply(original,filtered);//2 in filtered
  nonMax->Apply(filtered,original);//1 in original
  doubleThresh->Apply(original,filtered);
  hysteresis->Apply(filtered,original);
  grey->Apply(original,filtered);//greyscale now in filtered

}
