#include "blobdetect.h"
#include <math.h>
#include <memory>

using namespace std;

BlobDetect::BlobDetect(){
  return;
}

bool BlobDetect::check(std::vector<Image*> original, std::vector<Image*> filtered){
  unique_ptr<Filter> canny=unique_ptr<Filter>(new CannyEdgeFilter());
  unique_ptr<Filter> color=unique_ptr<Filter>(new ColorThresholdFilter());

  color->Apply(original,filtered);//color now in filtered
  Image color_image = *filtered.at(0);
  canny->Apply(filtered,original);//canny edge of color in original
  Image *canny_image = original.at(0);//canny

  int color_counter=0;
  int canny_counter=0;

  unsigned char* color_pixel;
  unsigned char* canny_pixel;
  for(int y =0;y<color_image.GetHeight();y++){
    for(int x =0;x<color_image.GetWidth();x++){
      color_pixel=color_image.GetPixel(x,y);
      canny_pixel=canny_image->GetPixel(x,y);
      if(isWhite(color_pixel)){
        color_counter++;
      }
      if(isWhite(canny_pixel)){
        canny_counter++;
      }
    }
  }
  cout<<"canny counter: "<<canny_counter<<endl<<"color counter: "<<color_counter<<endl;
  float threshold = .9;
  // cout<<canny_counter*threshold<<endl;
  return (canny_counter*threshold)<color_counter;
}

float BlobDetect::getDistance(std::vector<Image*> original, std::vector<Image*> filtered){
  unique_ptr<Filter> canny=unique_ptr<Filter>(new CannyEdgeFilter());
  unique_ptr<Filter> color=unique_ptr<Filter>(new ColorThresholdFilter());

  Image direction_im = *filtered.at(1);

  color->Apply(original,filtered);//color now in filtered
  Image color_image = *filtered.at(0);

  unsigned char* color_pixel;
  for(int y =0;y<color_image.GetHeight();y++){
    for(int x =0;x<color_image.GetWidth();x++){
      color_pixel=color_image.GetPixel(x,y);
      if(isWhite(color_pixel)){
        return direction_im.getDistance(x,y);
      }
    }
  }
  return -1;
}

std::vector<float> BlobDetect::getDirection(std::vector<Image*> original, std::vector<Image*> filtered){
  unique_ptr<Filter> canny=unique_ptr<Filter>(new CannyEdgeFilter());
  unique_ptr<Filter> color=unique_ptr<Filter>(new ColorThresholdFilter());

  Image direction_im = *filtered.at(1);

  color->Apply(original,filtered);//color now in filtered
  Image color_image = *filtered.at(0);

  unsigned char* color_pixel;
  for(int y =0;y<color_image.GetHeight();y++){
    for(int x =0;x<color_image.GetWidth();x++){
      color_pixel=color_image.GetPixel(x,y);
      if(isWhite(color_pixel)){
        return direction_im.getDirection(x,y);
      }
    }
  }
  vector<float> error={-1,-1,-1};
  return error;
}

bool BlobDetect::isWhite(unsigned char* pixel){
  return pixel[0]==255 && pixel[1]==255 && pixel[2]==255;
}
