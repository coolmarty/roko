#include "gtest/gtest.h"
#include "battery.h"
#include "camera.h"
#include "compositebattery.h"
#include "drone.h"
#include "dronefactory.h"
#include "entity.h"
#include "entityfactory.h"
#include "hospital.h"
#include "hospitalfactory.h"
#include "image_processing.h"
#include "point3.h"
#include "robot.h"
#include "robotfactory.h"
#include "SimulationFacade.h"
#include "vector3.h"

class SearchAndRescueFacadeTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
};

TEST_F(SearchAndRescueFacadeTest, SearchTest) {
 // SearchAndRescue* SAR = new SearchAndRescue();
  Drone d = Drone();
  d.Update(0.1); //there is a SAR object in each drone, so 
  const Point3 origin = Point3();
  ASSERT_EQ((d.GetPosition() != origin), true);
 // delete SAR;
}

TEST_F(SearchAndRescueFacadeTest, RescueTest){
  Drone d = Drone();
  Point3 p = Point3(8,0,23);
  d.SRF(p);
  for(int i = 0; i < 1000; i++){
    d.Update(0.1);
  }
  bool closeEnough = (d.GetPosition() == p || (d.GetPosition().GetX() <= p.GetX()+0.5 && d.GetPosition().GetX() >= p.GetX()-0.5 && d.GetPosition().GetZ() <= p.GetZ()+0.5 && d.GetPosition().GetZ() >= p.GetZ()-0.5));
  EXPECT_EQ(closeEnough,true);
}

