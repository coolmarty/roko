#include "gtest/gtest.h"
#include "drone.h"

/*

Similar to the position and velocity tests, these tests check the fundamental connection
between velocity and acceleration. Unlike the previous test, these two relationships are
between two Vector3s, rather than a Point3 and a Vector3.

*/

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone = Drone();
};

TEST_F(DroneTest, XNegAccelerationTest) {
  drone = Drone();

  drone.SetAcceleration(-1000, 0, 0);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  Vector3 expectedVel = Vector3(-1000,0,0);
  Vector3 actualVel = drone.GetVelocity();
  EXPECT_EQ(actualVel.GetX(),expectedVel.GetX());
  EXPECT_EQ(actualVel.GetY(),expectedVel.GetY());
  EXPECT_EQ(actualVel.GetZ(),expectedVel.GetZ());

  Vector3 expectedVelo = Vector3(-1000,0,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, XPosAccelerationTest) {
  drone = Drone();

  drone.SetAcceleration(1000, 0, 0);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  Vector3 expectedVel = Vector3(1000,0,0);
  Vector3 actualVel = drone.GetVelocity();
  EXPECT_EQ(actualVel.GetX(),expectedVel.GetX());
  EXPECT_EQ(actualVel.GetY(),expectedVel.GetY());
  EXPECT_EQ(actualVel.GetZ(),expectedVel.GetZ());

  Vector3 expectedVelo = Vector3(1000,0,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, YNegAccelerationTest) {
  drone = Drone();

  drone.SetAcceleration(0, -1000, 0);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  Vector3 expectedVel = Vector3(0,-1000,0);
  Vector3 actualVel = drone.GetVelocity();
  EXPECT_EQ(actualVel.GetX(),expectedVel.GetX());
  EXPECT_EQ(actualVel.GetY(),expectedVel.GetY());
  EXPECT_EQ(actualVel.GetZ(),expectedVel.GetZ());

  Vector3 expectedVelo = Vector3(0,-1000,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, YPosAccelerationTest) {
  drone = Drone();

  drone.SetAcceleration(0, 1000, 0);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  Vector3 expectedVel = Vector3(0,1000,0);
  Vector3 actualVel = drone.GetVelocity();
  EXPECT_EQ(actualVel.GetX(),expectedVel.GetX());
  EXPECT_EQ(actualVel.GetY(),expectedVel.GetY());
  EXPECT_EQ(actualVel.GetZ(),expectedVel.GetZ());

  Vector3 expectedVelo = Vector3(0,1000,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, ZNegAccelerationTest) {
  drone = Drone();

  drone.SetAcceleration(0, 0, -1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  Vector3 expectedVel = Vector3(0,0,-1000);
  Vector3 actualVel = drone.GetVelocity();
  EXPECT_EQ(actualVel.GetX(),expectedVel.GetX());
  EXPECT_EQ(actualVel.GetY(),expectedVel.GetY());
  EXPECT_EQ(actualVel.GetZ(),expectedVel.GetZ());

  Vector3 expectedVelo = Vector3(0,0,-1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, ZPosAccelerationTest) {
  drone = Drone();

  drone.SetAcceleration(0, 0, 1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  Vector3 expectedVel = Vector3(0,0,1000);
  Vector3 actualVel = drone.GetVelocity();
  EXPECT_EQ(actualVel.GetX(),expectedVel.GetX());
  EXPECT_EQ(actualVel.GetY(),expectedVel.GetY());
  EXPECT_EQ(actualVel.GetZ(),expectedVel.GetZ());

  Vector3 expectedVelo = Vector3(0,0,1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}
