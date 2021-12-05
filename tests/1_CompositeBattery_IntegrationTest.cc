#include "gtest/gtest.h"
#include "battery.h"
#include "compositebattery.h"

class CompositeBatteryIntegrationTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
};

TEST_F(CompositeBatteryIntegrationTest, MessAroundAbunch) {
  //test initial battery
  Battery batt = Battery();
  CompositeBattery cbatt = CompositeBattery(batt);
  for(int i=0;i<99;i++){
    batt=Battery();
    cbatt.AddBattery(batt);
  }
  EXPECT_EQ(cbatt.GetTotalBatteryLife(),10000);
  for(int i=0;i<100;i++){
    for(int j =0;j<1000;j++){
      cbatt.SetFirstBattery(cbatt.GetFirstBatteryLife()-.1);
      
    }
    cbatt.RemoveBattery();
  }
  EXPECT_EQ(cbatt.GetTotalBatteryLife(),0);

}
