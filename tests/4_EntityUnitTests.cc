#include "gtest/gtest.h"
#include "robot.h"
#include "hospital.h"
#include "rechargestation.h"
#include "drone.h"

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone=Drone();
};

class RobotTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Robot robot=Robot();
};

class HospitalTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Hospital hospital=Hospital();
};

class RechargeStationTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  RechargeStation charger=RechargeStation(Point3(0,0,0));
};

TEST_F(DroneTest, CreateDefaultDrone) {
  drone = Drone();

  Point3 expectedPos = Point3(0,0,0);
  Point3 actualPos = drone.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedDir = Vector3(0,0,0);
  Vector3 actualDir = drone.GetDirection();
  EXPECT_EQ(actualDir.GetX(),expectedDir.GetX());
  EXPECT_EQ(actualDir.GetY(),expectedDir.GetY());
  EXPECT_EQ(actualDir.GetZ(),expectedDir.GetZ());

  Vector3 expectedVelo=Vector3(0,0,0);
  Vector3 actualVelo=drone.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

/*
  Vector3 expectedaccel=Vector3(0,9.8,0);
  Vector3 actualAccel=drone.GetAcceleration();
  EXPECT_EQ(actualAccel.GetX(),expectedaccel.GetX());
  EXPECT_EQ(actualAccel.GetY(),expectedaccel.GetY());
  EXPECT_EQ(actualAccel.GetZ(),expectedaccel.GetZ());
*/
  EXPECT_EQ(drone.GetTime(),0);
}


TEST_F(RobotTest, CreateDefaultRobot) {
  robot = Robot();

  Point3 expectedPos = Point3(0,0,0);
  Point3 actualPos = robot.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedDir = Vector3(0,0,0);
  Vector3 actualDir = robot.GetDirection();
  EXPECT_EQ(actualDir.GetX(),expectedDir.GetX());
  EXPECT_EQ(actualDir.GetY(),expectedDir.GetY());
  EXPECT_EQ(actualDir.GetZ(),expectedDir.GetZ());

  Vector3 expectedVelo=Vector3(0,0,0);
  Vector3 actualVelo=robot.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedaccel=Vector3(0,0,0);
  Vector3 actualAccel=robot.GetAcceleration();
  EXPECT_EQ(actualAccel.GetX(),expectedaccel.GetX());
  EXPECT_EQ(actualAccel.GetY(),expectedaccel.GetY());
  EXPECT_EQ(actualAccel.GetZ(),expectedaccel.GetZ());

  EXPECT_EQ(robot.GetTime(),0);
}

TEST_F(HospitalTest, CreateDefaultHospital) {
  hospital = Hospital();

  Point3 expectedPos = Point3(0,0,0);
  Point3 actualPos = hospital.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedDir = Vector3(0,0,0);
  Vector3 actualDir = hospital.GetDirection();
  EXPECT_EQ(actualDir.GetX(),expectedDir.GetX());
  EXPECT_EQ(actualDir.GetY(),expectedDir.GetY());
  EXPECT_EQ(actualDir.GetZ(),expectedDir.GetZ());

  Vector3 expectedVelo=Vector3(0,0,0);
  Vector3 actualVelo=hospital.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedaccel=Vector3(0,0,0);
  Vector3 actualAccel=hospital.GetAcceleration();
  EXPECT_EQ(actualAccel.GetX(),expectedaccel.GetX());
  EXPECT_EQ(actualAccel.GetY(),expectedaccel.GetY());
  EXPECT_EQ(actualAccel.GetZ(),expectedaccel.GetZ());

  EXPECT_EQ(hospital.GetTime(),0);
}


TEST_F(RechargeStationTest, CreateStation) {
  Point3 expectedPos = Point3(0,0,0);
  charger = RechargeStation(expectedPos);


  Point3 actualPos = charger.GetPosition();
  EXPECT_EQ(actualPos.GetX(),expectedPos.GetX());
  EXPECT_EQ(actualPos.GetY(),expectedPos.GetY());
  EXPECT_EQ(actualPos.GetZ(),expectedPos.GetZ());

  Vector3 expectedDir = Vector3(0,0,0);
  Vector3 actualDir = charger.GetDirection();
  EXPECT_EQ(actualDir.GetX(),expectedDir.GetX());
  EXPECT_EQ(actualDir.GetY(),expectedDir.GetY());
  EXPECT_EQ(actualDir.GetZ(),expectedDir.GetZ());

  Vector3 expectedVelo=Vector3(0,0,0);
  Vector3 actualVelo=charger.GetVelocity();
  EXPECT_EQ(actualVelo.GetX(),expectedVelo.GetX());
  EXPECT_EQ(actualVelo.GetY(),expectedVelo.GetY());
  EXPECT_EQ(actualVelo.GetZ(),expectedVelo.GetZ());

  Vector3 expectedaccel=Vector3(0,0,0);
  Vector3 actualAccel=charger.GetAcceleration();
  EXPECT_EQ(actualAccel.GetX(),expectedaccel.GetX());
  EXPECT_EQ(actualAccel.GetY(),expectedaccel.GetY());
  EXPECT_EQ(actualAccel.GetZ(),expectedaccel.GetZ());

  EXPECT_EQ(charger.GetTime(),0);
}
