#include "gtest/gtest.h"
#include "drone.h"

/*

Drone's time should increment by dt after Update()

*/

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone = Drone();
};

TEST_F(DroneTest, DroneTimeTest) {
  drone = Drone();

  drone.Update(0.01);

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  float expectedTime = 0.01;
  float actualTime = drone.GetTime();
  EXPECT_EQ(actualTime,expectedTime);
}
