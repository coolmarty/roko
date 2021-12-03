#include "hospitalfactory.h"

HospitalFactory::HospitalFactory(){
  return;
}

Entity *HospitalFactory::create(picojson::object& entityData, ICameraController& cameraController){
  if (entityData["name"].get<std::string>() == "hospital") {
      Entity *ourHospital = new Hospital();

      ourHospital->SetId(entityData["entityId"].get<double>());


      picojson::array position = entityData["position"].get<picojson::array>();
      ourHospital->SetPosition(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

      picojson::array direction = entityData["direction"].get<picojson::array>();
      ourHospital->SetDirection(direction[0].get<double>(), direction[1].get<double>(), direction[2].get<double>());

      picojson::array cameras = entityData["cameras"].get<picojson::array>();
      for (int i = 0; i < cameras.size(); i++) {
          Camera* camera = new Camera(cameras[i].get<double>(), &cameraController);
          ourHospital->addCamera(camera);
      }

      return ourHospital;
  }
  return NULL;
}

Entity *HospitalFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "hospital") {
      Entity *ourHospital = new Hospital();

      ourHospital->SetId(entityData["entityId"].get<double>());


      picojson::array position = entityData["position"].get<picojson::array>();
      ourHospital->SetPosition(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

      picojson::array direction = entityData["direction"].get<picojson::array>();
      ourHospital->SetDirection(direction[0].get<double>(), direction[1].get<double>(), direction[2].get<double>());

      return ourHospital;
  }
  return NULL;
}
