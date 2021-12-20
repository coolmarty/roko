#include "gtest/gtest.h"
#include "battery.h"
#include "compositebattery.h"
#include "drone.h"
#include "rechargestation.h"

class RechargeStationRegressionTest : public ::testing::Test {
public:
  void SetUp( ) {

  }
protected:
};

TEST_F(RechargeStationRegressionTest, RSInitTest){
  RechargeStation r = RechargeStation(Point3(8,0,23));
  const Point3 rsl = Point3(8,0,23);
  ASSERT_EQ((r.GetPosition() == rsl), true);
//  EXPECT_EQ(r.GetVelocity(),Vector3());
  EXPECT_EQ(r.powercells.GetTotalBatteryLife(),2000.0);
  EXPECT_EQ(r.IsBusy(),false);
}

TEST_F(RechargeStationRegressionTest, RSDrainTest){
  RechargeStation r = RechargeStation(Point3());
  Battery b = Battery(66.6);
  r.Recharge(&b);
  EXPECT_LT(r.powercells.GetFirstBatteryLife(),100.0);
}

TEST_F(RechargeStationRegressionTest, RSBusyTest){
  RechargeStation r = RechargeStation(Point3());
  Drone d = Drone();
  d.battery.SetBatteryLife(0.0);
  r.Recharge(&d.battery);
  EXPECT_EQ(r.IsBusy(),true);
}
