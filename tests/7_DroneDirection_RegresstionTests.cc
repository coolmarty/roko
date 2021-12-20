#include "gtest/gtest.h"
#include "drone.h"
#include "matrix3.h"

/*

For manual movement, keys change the direction as well as the velocity, so the core responnsibility of these tests is to ensure that the direction is properly manipulated by the rotation matrices and to ensure that that does not change. This will also check if speed correctly reaches 0 after manually moving and then being left alone

*/

class DroneTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
  Drone drone = Drone();
};

TEST_F(DroneTest, DefaultDirection) { // Test that default remains pointing on z axis
  drone = Drone();
  
  Vector3 expectedDirection = Vector3(0,0,1);
  Vector3 actualDirection = drone.GetDirection();
  EXPECT_EQ(actualDirection.GetX(),expectedDirection.GetX());
  EXPECT_EQ(actualDirection.GetY(),expectedDirection.GetY());
  EXPECT_EQ(actualDirection.GetZ(),expectedDirection.GetZ());
}

TEST_F(DroneTest, NegYAxisRotation) { // Turn in negative pitch direction
  drone = Drone();
  
  Vector3 expectedDirection = Vector3(0,0,1);
  Matrix3 rot = Matrix3(-0.5, 'y');
  expectedDirection = rot * expectedDirection;
  
  int arr[5] = {0, 1, 0, 0, 1};
  
  float dt = 0.1;
  drone.SetKeys(arr);
  drone.Update(dt);
  arr[4] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  Vector3 actualDirection = drone.GetDirection();
  Vector3 testDirection = Vector3(actualDirection.GetX() - expectedDirection.GetX(), actualDirection.GetY() - expectedDirection.GetY(), actualDirection.GetZ() - expectedDirection.GetZ());
  bool rangex = testDirection.GetX() < 0.01 && testDirection.GetX() > -0.01;
  bool rangey = testDirection.GetY() < 0.01 && testDirection.GetY() > -0.01;
  bool rangez = testDirection.GetZ() < 0.01 && testDirection.GetZ() > -0.01;
  EXPECT_EQ(rangex,true);
  EXPECT_EQ(rangey,true);
  EXPECT_EQ(rangez,true);
}

TEST_F(DroneTest, PosYAxisRotation) { // Turn in positive pitch direction
  drone = Drone();
  
  Vector3 expectedDirection = Vector3(0,0,1);
  Matrix3 rot = Matrix3(0.5, 'y');
  expectedDirection = rot * expectedDirection;
  
  int arr[5] = {0, -1, 0, 0, 1};
  
  float dt = 0.1;
  drone.SetKeys(arr);
  drone.Update(dt);
  arr[4] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  Vector3 actualDirection = drone.GetDirection();
  Vector3 testDirection = Vector3(actualDirection.GetX() - expectedDirection.GetX(), actualDirection.GetY() - expectedDirection.GetY(), actualDirection.GetZ() - expectedDirection.GetZ());
  bool rangex = testDirection.GetX() < 0.01 && testDirection.GetX() > -0.01;
  bool rangey = testDirection.GetY() < 0.01 && testDirection.GetY() > -0.01;
  bool rangez = testDirection.GetZ() < 0.01 && testDirection.GetZ() > -0.01;
  EXPECT_EQ(rangex,true);
  EXPECT_EQ(rangey,true);
  EXPECT_EQ(rangez,true);
}

TEST_F(DroneTest, PosXAxisRotation) { // Turn in positive yaw direction
  drone = Drone();
  
  Vector3 expectedDirection = Vector3(0,0,1);
  Matrix3 rot = Matrix3(0.5, 'x');
  expectedDirection = rot * expectedDirection;
  
  int arr[5] = {1, 0, 0, 0, 1};
  
  float dt = 0.1;
  drone.SetKeys(arr);
  drone.Update(dt);
  arr[4] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  Vector3 actualDirection = drone.GetDirection();
  Vector3 testDirection = Vector3(actualDirection.GetX() - expectedDirection.GetX(), actualDirection.GetY() - expectedDirection.GetY(), actualDirection.GetZ() - expectedDirection.GetZ());
  bool rangex = testDirection.GetX() < 0.01 && testDirection.GetX() > -0.01;
  bool rangey = testDirection.GetY() < 0.01 && testDirection.GetY() > -0.01;
  bool rangez = testDirection.GetZ() < 0.01 && testDirection.GetZ() > -0.01;
  EXPECT_EQ(rangex,true);
  EXPECT_EQ(rangey,true);
  EXPECT_EQ(rangez,true);
}

TEST_F(DroneTest, NegXAxisRotation) { // Turn in negative yaw direction
  drone = Drone();
  
  Vector3 expectedDirection = Vector3(0,0,1);
  Matrix3 rot = Matrix3(-0.5, 'x');
  expectedDirection = rot * expectedDirection;
  
  int arr[5] = {-1, 0, 0, 0, 1};
  
  float dt = 0.1;
  drone.SetKeys(arr);
  drone.Update(dt);
  arr[4] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  Vector3 actualDirection = drone.GetDirection();
  Vector3 testDirection = Vector3(actualDirection.GetX() - expectedDirection.GetX(), actualDirection.GetY() - expectedDirection.GetY(), actualDirection.GetZ() - expectedDirection.GetZ());
  bool rangex = testDirection.GetX() < 0.01 && testDirection.GetX() > -0.01;
  bool rangey = testDirection.GetY() < 0.01 && testDirection.GetY() > -0.01;
  bool rangez = testDirection.GetZ() < 0.01 && testDirection.GetZ() > -0.01;
  std::cout << actualDirection.GetX() << actualDirection.GetY() << actualDirection.GetZ() << std::endl;
  EXPECT_EQ(rangex,true);
  EXPECT_EQ(rangey,true);
  EXPECT_EQ(rangez,true);
}

TEST_F(DroneTest, PosSpeedToStopTest) { // Apply positive thrust then stop
  drone = Drone();
  
  float expectedSpeed = 0;
  
  int arr[5] = {0, 0, 1, 0, 1};
  
  float dt = 1;
  drone.SetKeys(arr);
  drone.Update(dt);
  arr[4] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  arr[2] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  float actualSpeed = drone.GetVelocity().Magnitude();
  EXPECT_EQ(actualSpeed, expectedSpeed);
  EXPECT_EQ(actualSpeed, expectedSpeed);
  EXPECT_EQ(actualSpeed, expectedSpeed);
}

TEST_F(DroneTest, NegSpeedToStopTest) { // Apply negative thrust then stop
  drone = Drone();
  
  float expectedSpeed = 0;
  
  int arr[5] = {0, 0, -1, 0, 1};
  
  float dt = 1;
  drone.SetKeys(arr);
  drone.Update(dt);
  arr[4] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  arr[2] = 0;
  drone.SetKeys(arr);
  
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  drone.Update(dt);
  
  float actualSpeed = drone.GetVelocity().Magnitude();
  EXPECT_EQ(actualSpeed, expectedSpeed);
  EXPECT_EQ(actualSpeed, expectedSpeed);
  EXPECT_EQ(actualSpeed, expectedSpeed);
}