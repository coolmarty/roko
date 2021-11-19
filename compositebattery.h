#ifndef COMPOSITE_BATTERY_H_
#define COMPOSITE_BATTERY_H_
#include <vector>
#include "battery.h"
class CompositeBattery : public Battery{
  public:
  std::vector<Battery> batteries;
  CompositeBattery(Battery batt);
  void AddBattery(Battery batt);
  void RemoveBattery();
  float GetFirstBatteryLife();
  float GetTotalBatteryLife();
  void SetFirstBattery(float NBL);
  
    
};
#endif
