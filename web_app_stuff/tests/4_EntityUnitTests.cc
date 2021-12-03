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
  Drone drone;
};

class RobotTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Robot robot;
};

class HospitalTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Hospital hospital;
};

class RechargeStationTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  RechargeStation charger=RechargeStation(Point3(0,0,0));
};
