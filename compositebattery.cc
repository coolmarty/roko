#include "compositebattery.h"

 
CompositeBattery::CompositeBattery(Battery batt){
  batteries.push_back(batt);
  return;
}
void CompositeBattery::AddBattery(Battery batt){
  batteries.push_back(batt);
  return;
}
void CompositeBattery::RemoveBattery(){
  batteries.pop_back();
  return;
}
float CompositeBattery::GetFirstBatteryLife(){
  return batteries.front().GetBatteryLife();
}
float CompositeBattery::GetTotalBatteryLife(){
  float total = 0.0;
  for (int i = 0; i < batteries.size(); i++){
    std::cout << "Battery: " << i << " Percentage: " << batteries[i].GetBatteryLife() << std::endl;
    total += batteries[i].GetBatteryLife();
  }
  std::cout << "Total charge: " << total << std::endl;
  return total;
}
  
void CompositeBattery::SetFirstBattery(float NBL){
  batteries.front().SetBatteryLife(NBL);
  return;
}

