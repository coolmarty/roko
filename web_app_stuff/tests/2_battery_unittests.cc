#include "gtest/gtest.h"
#include "battery.h"
#include "compositebattery.h"

class BatteryTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
};
class CompositeBatteryTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
};

TEST_F(BatteryTest, BatteryTest) {
  //test initial battery
  Battery batt = Battery();
  EXPECT_EQ(batt.GetBatteryLife(),100.0);

  batt.SetBatteryLife(22);
  EXPECT_EQ(batt.GetBatteryLife(),22);
  Battery setInitial = Battery(34.25);
  EXPECT_EQ(setInitial.GetBatteryLife(),34.25);
}

TEST_F(CompositeBatteryTest, CompositeBatteryTest) {
  //test initial battery
  Battery batt = Battery();
  CompositeBattery cbatt = CompositeBattery(batt);
  cbatt.AddBattery(Battery(45));
  cbatt.AddBattery(Battery(77));

  EXPECT_EQ(cbatt.GetTotalBatteryLife(),222);
  EXPECT_EQ(cbatt.GetFirstBatteryLife(),100);
  cbatt.RemoveBattery();
  EXPECT_EQ(cbatt.GetFirstBatteryLife(),45);
  EXPECT_EQ(cbatt.GetTotalBatteryLife(),122);
  cbatt.SetFirstBattery(35);
  EXPECT_EQ(cbatt.GetTotalBatteryLife(),112);
  EXPECT_EQ(cbatt.GetFirstBatteryLife(),35);
}
