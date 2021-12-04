#include "battery.h"

float batteryLife;

Battery::Battery(){
  this->batteryLife = 100.0;
  return;
}

Battery::Battery(float batteryLife){
  this->batteryLife = batteryLife;
  return;
}

float Battery::GetBatteryLife(){
  return this->batteryLife;
}

void Battery::SetBatteryLife(float newBatteryLife){
  this->batteryLife = newBatteryLife;
  return;
}
