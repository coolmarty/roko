#include "gtest/gtest.h"
#include "battery.h"
#include "compositebattery.h"
#include "drone.h"

class BatteryRegressionTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
};

TEST_F(BatteryRegressionTest, BatteryInitTest){
  Drone d = Drone();
  EXPECT_EQ(d.battery.GetBatteryLife(),100.0);
}

TEST_F(BatteryRegressionTest, BatteryDecreasesCheck){
  Drone d = Drone();
  d.Update(0.1);
  d.Update(0.1);
  d.Update(0.1);
  d.Update(0.1);
  EXPECT_LT(d.battery.GetBatteryLife(),100.0);
}

TEST_F(BatteryRegressionTest, BatterySetCheck){
  Drone d = Drone();
  d.battery.SetBatteryLife(75.0);
  EXPECT_EQ(d.battery.GetBatteryLife(),75.0);
}
