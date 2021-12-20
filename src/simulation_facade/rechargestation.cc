#include "rechargestation.h"




RechargeStation::RechargeStation(Point3 pos){
  busy = false;
  this->SetPosition(pos);
  this->SetVelocity(Vector3());
  this->SetAcceleration(Vector3());
  for(int i = 0; i < 20; i++){ //we have 20 full charges
    powercells.AddBattery(*(new Battery()));
  }
}

RechargeStation::RechargeStation(Point3 pos, CompositeBattery compbatt){
  busy = false;
  powercells = compbatt;
  this->SetPosition(pos);
  this->SetVelocity(Vector3());
  this->SetAcceleration(Vector3());
}

RechargeStation::~RechargeStation(){
  for (int i = 0; i < cameras.size(); i++) {
      delete cameras[i];
  }
}

void RechargeStation::Recharge(Battery* battery){
  busy = true;
   std::cout << ("Recharging...") << std::endl;
  float chargetaken = 0.0;
  while (battery->GetBatteryLife() < 100.0 && powercells.GetFirstBatteryLife() > 0.0){
    battery->SetBatteryLife(battery->GetBatteryLife() + 0.1);
    chargetaken += 0.1;
 //   usleep(100);
  std::cout << "We're at:"  << battery->GetBatteryLife() << std::endl;
  }
  if(battery->GetBatteryLife() >= 100.0){
    powercells.SetFirstBattery(powercells.GetFirstBatteryLife() - chargetaken);
        std::cout << "Recharging complete." << std::endl;
        return;
  }
  else{ //this ensures that if the drone drained the first powercell, it will pop the first battery and start charging off the next.
    //chargetaken -= powercells.GetFirstBatteryLife();
    powercells.RemoveBattery();
   // powercells.SetFirstBattery(powercells.GetFirstBatteryLife() - chargetaken);
    chargetaken = 0.0;
    while (battery->GetBatteryLife() < 100.0){ //this for loop doesn't need the second condition because if it took even 0.1 charge off the first battery, it can't drain the next battery.
      battery->SetBatteryLife(battery->GetBatteryLife() + 0.1);
      chargetaken += 0.1;
      std::cout << "We're at:"  << battery->GetBatteryLife() << std::endl;
   //   usleep(100);
    }
    powercells.SetFirstBattery(powercells.GetFirstBatteryLife() - chargetaken);
    std::cout << "Recharging complete." << std::endl;
  }
  return;
  busy = false;
} //note: this iteration does not have a case in which all batteries are drained. I hope we found the robot within the first 21 charges.


bool RechargeStation::IsBusy(){
  return busy;
}

void RechargeStation::Update(float dt){

}
