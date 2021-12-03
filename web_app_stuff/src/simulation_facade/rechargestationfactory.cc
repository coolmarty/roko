#include "rechargestationfactory.h"

RechargeStationFactory::RechargeStationFactory(){
  return;
}

Entity *RechargeStationFactory::create(picojson::object& entityData, ICameraController& cameraController){
  if (entityData["name"].get<std::string>() == "recharge station") {


      picojson::array position = entityData["position"].get<picojson::array>();
      Point3 p = Point3(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

      Entity *ourCharger = new RechargeStation(p);

      ourCharger->SetId(entityData["entityId"].get<double>());




      picojson::array direction = entityData["direction"].get<picojson::array>();
      ourCharger->SetDirection(direction[0].get<double>(), direction[1].get<double>(), direction[2].get<double>());

      picojson::array cameras = entityData["cameras"].get<picojson::array>();
      for (int i = 0; i < cameras.size(); i++) {
          Camera* camera = new Camera(cameras[i].get<double>(), &cameraController);
          ourCharger->addCamera(camera);
      }

      return ourCharger;
  }
  return NULL;
}

Entity *RechargeStationFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "recharge station") {


      picojson::array position = entityData["position"].get<picojson::array>();
      Point3 p = Point3(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

      Entity *ourCharger = new RechargeStation(p);

      ourCharger->SetId(entityData["entityId"].get<double>());




      picojson::array direction = entityData["direction"].get<picojson::array>();
      ourCharger->SetDirection(direction[0].get<double>(), direction[1].get<double>(), direction[2].get<double>());



      return ourCharger;
  }
  return NULL;
}
