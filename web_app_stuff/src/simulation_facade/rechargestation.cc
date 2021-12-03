/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "rechargestation.h"




RechargeStation::RechargeStation(Point3 pos){
  busy = false;
  for(int i = 0; i < 4000; i++){
    powercells.AddBattery(*(new Battery()));
  }
  this->SetPosition(pos);
  this->SetVelocity(Vector3());
  this->SetAcceleration(Vector3());
}

RechargeStation::RechargeStation(Point3 pos, CompositeBattery compbatt){
  busy = false;
  powercells = compbatt;
  this->SetPosition(pos);
  this->SetVelocity(Vector3());
  this->SetAcceleration(Vector3());
}

void RechargeStation::Recharge(Drone drone){
  busy = true;
   std::cout << ("Recharging...") << std::endl;
  float chargetaken = 0.0;
  while (drone.battery.GetBatteryLife() != 100.0 && powercells.GetFirstBatteryLife() > 0.0){
    drone.battery.SetBatteryLife(drone.battery.GetBatteryLife() + 0.1);
    chargetaken += 0.1;
    usleep(100);
  std::cout << "We're at:"  << drone.battery.GetBatteryLife() << std::endl;
  }
  if(drone.battery.GetBatteryLife() == 100.0){
    powercells.SetFirstBattery(powercells.GetFirstBatteryLife() - chargetaken);
        std::cout << "Recharging complete." << std::endl;
  }
  else{ //this ensures that if the drone drained the first powercell, it will pop the first battery and start charging off the next.
    //chargetaken -= powercells.GetFirstBatteryLife();
    powercells.RemoveBattery();
   // powercells.SetFirstBattery(powercells.GetFirstBatteryLife() - chargetaken);
    chargetaken = 0.0;
    while (drone.battery.GetBatteryLife() != 100.0){ //this for loop doesn't need the second condition because if it took even 0.1 charge off the first battery, it can't drain the next battery.
      drone.battery.SetBatteryLife(drone.battery.GetBatteryLife() + 0.1);
      chargetaken += 0.1;
      usleep(100);
    }
    powercells.SetFirstBattery(powercells.GetFirstBatteryLife() - chargetaken);
    std::cout << "Recharging complete." << std::endl;
  }
  return;
} //note: this iteration does not have a case in which all batteries are drained. I hope we found the robot within the first 21 charges.

void RechargeStation::Update(float dt){

}
