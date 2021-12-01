#include "hospitalfactory.h"

HospitalFactory::HospitalFactory(){
  return
}

Entity HospitalFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "hospital") {
      Entity ourHospital = Robot();
      ourHospital.id = entityData["entityId"].get<double>();
      ourHospital.speed = entityData["speed"].get<double>();

      // Get the position as an array
      picojson::array position = entityData["position"].get<picojson::array>();
      ourHospital.pos[0] = position[0].get<double>();
      ourHospital.pos[1] = position[1].get<double>();
      ourHospital.pos[2] = position[1].get<double>();

      // Get the direction as an array
      picojson::array dir = entityData["direction"].get<picojson::array>();
      ourHospital.dir[0] = dir[0].get<double>();
      ourHospital.dir[1] = dir[1].get<double>();
      ourHospital.dir[2] = dir[1].get<double>();

      return ourHospital;
  }
  return NULL;
}
