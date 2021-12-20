#include "gtest/gtest.h"
#include "drone.h"

/*

Based on the basic ideas on how position and velocity are coorelated, it should always be true that
incrementing a Drone's position by its velocity should be stable and consistent. In order to test
this, we will use very large velocities in order to ensure that position will be what it is supposed
to even with large increments of velocity.

*/

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone = Drone();
};

TEST_F(DroneTest, XNegVelocityTest) {
  drone = Drone();

  drone.SetVelocity(-1000, 0, 0);

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(-1000,0,0);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(-1000,0,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, XPosVelocityTest) {
  drone = Drone();

  drone.SetVelocity(1000, 0, 0);

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(1000,0,0);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(1000,0,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, YNegVelocityTest) {
  drone = Drone();

  drone.SetVelocity(0, -1000, 0);

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(0,-1000,0);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(0,-1000,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, YPosVelocityTest) {
  drone = Drone();

  drone.SetVelocity(0, 1000, 0);

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(0,1000,0);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(0,1000,0);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, ZNegVelocityTest) {
  drone = Drone();

  drone.SetVelocity(0, 0, -1000);

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(0,0,-1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(0,0,-1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}

TEST_F(DroneTest, ZPosVelocityTest) {
  drone = Drone();

  drone.SetVelocity(0, 0, 1000);

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(0,0,1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(0,0,1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());
}
