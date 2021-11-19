#ifndef BATTERY_H_
#define BATTERY_H_
#include <iostream>
class Battery{
  private:
    float batteryLife;
    
  public:
    Battery();
    Battery(float batteryLife);
    float GetBatteryLife();
    void SetBatteryLife(float newBatteryLife); 
};
#endif
