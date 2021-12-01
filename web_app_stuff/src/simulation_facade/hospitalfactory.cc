#include "hospitalfactory.h"

HospitalFactory::HospitalFactory(){
  return;
}

Entity *HospitalFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "hospital") {
      Entity *ourHospital = new Hospital();

      return ourHospital;
  }
  return NULL;
}
