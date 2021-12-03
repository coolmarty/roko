#include "dronefactory.h"


DroneFactory::DroneFactory(){
  return;
}

Entity *DroneFactory::create(picojson::object& entityData, ICameraController& cameraController){
  if (entityData["name"].get<std::string>() == "drone") {
    Entity *ourDrone = new Drone();

    ourDrone->SetId(entityData["entityId"].get<double>());


    picojson::array position = entityData["position"].get<picojson::array>();
    ourDrone->SetPosition(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

    picojson::array direction = entityData["direction"].get<picojson::array>();
    ourDrone->SetDirection(direction[0].get<double>(), direction[1].get<double>(), direction[2].get<double>());

    ourDrone->SetSpeed(entityData["speed"].get<double>());

    picojson::array cameras = entityData["cameras"].get<picojson::array>();
    for (int i = 0; i < cameras.size(); i++) {
        Camera* camera = new Camera(cameras[i].get<double>(), &cameraController);
        ourDrone->addCamera(camera);
    }

    return ourDrone;
  }
  return NULL;
}

Entity *DroneFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "drone") {
    Entity *ourDrone = new Drone();

    ourDrone->SetId(entityData["entityId"].get<double>());


    picojson::array position = entityData["position"].get<picojson::array>();
    ourDrone->SetPosition(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

    picojson::array direction = entityData["direction"].get<picojson::array>();
    ourDrone->SetDirection(direction[0].get<double>(), direction[1].get<double>(), direction[2].get<double>());

    ourDrone->SetSpeed(entityData["speed"].get<double>());

    return ourDrone;
  }
  return NULL;
}
