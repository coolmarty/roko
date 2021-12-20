#include "gtest/gtest.h"
#include "drone.h"

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone = Drone();
};

TEST_F(DroneTest, XNegLimitTest) {
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

TEST_F(DroneTest, XPosLimitTest) {
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

TEST_F(DroneTest, YNegLimitTest) {
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

TEST_F(DroneTest, YPosLimitTest) {
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

TEST_F(DroneTest, ZNegLimitTest) {
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

TEST_F(DroneTest, ZPosLimitTest) {
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
