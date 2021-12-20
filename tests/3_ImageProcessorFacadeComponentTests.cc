#include "gtest/gtest.h"
#include "blobdetect.h"
#include "cannyedge.h"
#include "colorthreshold.h"
#include "convolution.h"
#include "doublethreshold.h"
#include "filter.h"
#include "gaussian_blur.h"
#include "greyscale_filter.h"
#include "hysteresis_filter.h"
#include "image.h"
#include "invert.h"
#include "kernal.h"
#include "mirror.h"
#include "non_max_suppression.h"
#include "simple_filter.h"
#include "sobel_filter.h"
#include "stb_image.h"
#include "stb_image_write.h"
#include "image_processing.h"

class ImageComponentTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
};

TEST_F(ImageComponentTest, BlobCheckTest) {
  ImageProcessing* IP = new ImageProcessing();
  std::cout << "HERE" << std::endl;
 // Image *testimage = new Image("/tests/testimages/robot1.png");
  bool found = IP->BlobCheck("tests/testimages/robot1.png");
  std::cout << "HEREHERE" << std::endl;
  EXPECT_EQ(found,true);
  delete IP;
  //delete testimage;
}

TEST_F(ImageComponentTest, BlobDistanceTest){
  ImageProcessing* IP = new ImageProcessing();
  // Image *testimage2 = new Image("/tests/testimages/robot2.png");
  float distance = IP->BlobGetDistance("tests/testimages/color.jpg", "tests/testimages/depth.jpg");
  EXPECT_GT(distance,0);
  delete IP;
 // delete testimage2;
}

TEST_F(ImageComponentTest, BlobGetDirectionTest){
  ImageProcessing* IP = new ImageProcessing();
//  Image *testimage2 = new Image("/tests/testimages/robot2.png");
  std::vector<float> distance = IP->BlobGetDirection("tests/testimages/color.jpg", "tests/testimages/depth.jpg");
  std::vector<float> error = {-1,-1,-1};
  ASSERT_NE(distance,error);
  delete IP;
 // delete testimage2;
}
