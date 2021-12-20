#include "gtest/gtest.h"
#include "drone.h"

/*

This combines the previous two DronePosVel and DroneVelAcc tests into a regression test
to confirm the operation across the three parameters of our physics. This will test how
the physics of Drone should operate across any version, due to the fundamental physics
of entity. Along with testing the connections between the two Vector3 and Point3 variables,
this will also test a combination of positive and negative movement directions across
all three dimensions. The acceleration checked is 1000, a drastic amount to ensure it functions
even with extreme accelerations.

*/

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone = Drone();
};

TEST_F(DroneTest, XNegYNegZNegComplexTest) {
  drone = Drone();

  drone.SetAcceleration(-1000, -1000, -1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(-1000, -1000, -1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(-1000, -1000, -1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(-1000, -1000, -1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}

TEST_F(DroneTest, XPosYNegZNegComplexTest) {
  drone = Drone();

  drone.SetAcceleration(1000, -1000, -1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(1000, -1000, -1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(1000, -1000, -1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(1000, -1000, -1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}

TEST_F(DroneTest, XNegYPosZNegComplexTest) {
  drone = Drone();

  drone.SetAcceleration(-1000, 1000, -1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(-1000, 1000, -1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(-1000, 1000, -1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(-1000, 1000, -1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}

TEST_F(DroneTest, XNegYNegZPosComplexTest) {
  drone = Drone();

  drone.SetAcceleration(-1000, -1000, 1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(-1000, -1000, 1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(-1000, -1000, 1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(-1000, -1000, 1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}

TEST_F(DroneTest, XPosYPosZNegComplexTest) {
  drone = Drone();

  drone.SetAcceleration(1000, 1000, -1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(1000, 1000, -1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(1000, 1000, -1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(1000, 1000, -1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}

TEST_F(DroneTest, XPosYNegZPosComplexTest) {
  drone = Drone();

  drone.SetAcceleration(1000, -1000, 1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(1000, -1000, 1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(1000, -1000, 1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(1000, -1000, 1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}

TEST_F(DroneTest, XNegYPosZPosComplexTest) {
  drone = Drone();

  drone.SetAcceleration(-1000, 1000, 1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(-1000, 1000, 1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(-1000, 1000, 1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(-1000, 1000, 1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}

TEST_F(DroneTest, XPosYPosZPosComplexTest) {
  drone = Drone();

  drone.SetAcceleration(1000, 1000, 1000);

  drone.SetVelocity(drone.GetAcceleration().GetX() + drone.GetVelocity().GetX(),
                    drone.GetAcceleration().GetY() + drone.GetVelocity().GetY(),
                    drone.GetAcceleration().GetZ() + drone.GetVelocity().GetZ());

  drone.SetPosition(drone.GetVelocity().GetX() + drone.GetPosition().GetX(),
                    drone.GetVelocity().GetY() + drone.GetPosition().GetY(),
                    drone.GetVelocity().GetZ() + drone.GetPosition().GetZ());

  Point3 expectedPos = Point3(1000, 1000, 1000);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedVelo = Vector3(1000, 1000, 1000);
  Vector3 actualVelo = drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedAccl = Vector3(1000, 1000, 1000);
  Vector3 actualAccl = drone.GetAcceleration();
  EXPECT_EQ(actualAccl.GetX(),expectedAccl.GetX());
  EXPECT_EQ(actualAccl.GetY(),expectedAccl.GetY());
  EXPECT_EQ(actualAccl.GetZ(),expectedAccl.GetZ());
}
