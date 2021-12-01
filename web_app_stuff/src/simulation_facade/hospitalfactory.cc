#include "hospitalfactory.h"

HospitalFactory::HospitalFactory(){
  return;
}

Entity *HospitalFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "hospital") {
      Entity *ourHospital = new Hospital();

      ourHospital->SetId(entityData["entityId"].get<double>());


      picojson::array position = entityData["position"].get<picojson::array>();
      ourHospital->SetPosition(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

      return ourHospital;
  }
  return NULL;
}
