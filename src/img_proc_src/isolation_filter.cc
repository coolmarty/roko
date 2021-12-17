#include "isolation_filter.h"

IsolationFilter::IsolationFilter(){
  return;
}
void IsolationFilter::Apply(std::vector<Image *> original, std::vector<Image *>filtered){
  Image *red = filtered.at(0);
  Image *green = filtered.at(1);
  Image *blue = filtered.at(2);
  Image *input = original.at(0);
  *red = *input;//set input to correct width/height
  *green = *input;//set input to correct width/height
  *blue = *input;//set input to correct width/height

  int height = input->GetHeight();
	int width = input->GetWidth();

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
      unsigned char* pixel = input->GetPixel(x,y);
      unsigned char* newRedPixel = new unsigned char[4];
      unsigned char* newGreenPixel = new unsigned char[4];
      unsigned char* newBluePixel = new unsigned char[4];

      newRedPixel[0]=pixel[0];
      newRedPixel[1]=0;
      newRedPixel[2]=0;
      newRedPixel[3]=pixel[3];

      newGreenPixel[0]=0;
      newGreenPixel[1]=pixel[1];
      newGreenPixel[2]=0;
      newGreenPixel[3]=pixel[3];

      newBluePixel[0]=0;
      newBluePixel[1]=0;
      newBluePixel[2]=pixel[2];
      newBluePixel[3]=pixel[3];
      red->SetPixel(x,y,newRedPixel);
      green->SetPixel(x,y,newGreenPixel);
      blue->SetPixel(x,y,newBluePixel);
      delete[] newRedPixel;
      delete[] newGreenPixel;
      delete[] newBluePixel;
    }
  }
}
