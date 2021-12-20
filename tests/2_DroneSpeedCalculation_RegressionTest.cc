#include "gtest/gtest.h"
#include "drone.h"
#include <cmath>
#include <iostream>

/*

Drone's speed should be able to accurately match the distance traveled in a second

*/

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone = Drone();
};

TEST_F(DroneTest, SpeedPythagorasTest) {
  drone = Drone();

  drone.SetVelocity(5, 5, 5);

  float speed = sqrt(pow(5,2) +
					           pow(5,2) +
					           pow(5,2));

  float expectedSpeed = speed;
  float actualSpeed = sqrt(pow(drone.GetVelocity().GetX(),2) +
					                 pow(drone.GetVelocity().GetY(),2) +
					                 pow(drone.GetVelocity().GetZ(),2));
  EXPECT_EQ(actualSpeed,expectedSpeed);
}

TEST_F(DroneTest, SpeedPythagorasUpdateTest) {
  drone = Drone();
  drone.SetPosition(0, 0, 0);

  drone.SRF(Point3(5, 5, 5));

  float speed = sqrt(pow(5,2) +
					           pow(5,2) +
					           pow(5,2));

  drone.Update(1);

  float distanceTraveled = sqrt(pow(drone.GetPosition().GetX(),2) +
					                      pow(drone.GetPosition().GetY(),2) +
					                      pow(drone.GetPosition().GetZ(),2));

  EXPECT_EQ(distanceTraveled,speed);
}
