#include "dronefactory.h"

DroneFactory::DroneFactory(){
  return
}

Entity DroneFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "drone") {
      Entity ourDrone = Drone();
      ourDrone.id = entityData["entityId"].get<double>();
      ourDrone.speed = entityData["speed"].get<double>();

      // Get the position as an array
      picojson::array position = entityData["position"].get<picojson::array>();
      ourDrone.pos[0] = position[0].get<double>();
      ourDrone.pos[1] = position[1].get<double>();
      ourDrone.pos[2] = position[1].get<double>();

      // Get the direction as an array
      picojson::array dir = entityData["direction"].get<picojson::array>();
      ourDrone.dir[0] = dir[0].get<double>();
      ourDrone.dir[1] = dir[1].get<double>();
      ourDrone.dir[2] = dir[1].get<double>();

      // Create cameras for the entity.
      picojson::array cameras = entityData["cameras"].get<picojson::array>();
      for (int i = 0; i < cameras.size(); i++) {
          WriteYourOwnCameraClass* camera = new WriteYourOwnCameraClass(cameras[i].get<double>(), &cameraController);
          ourDrone.cameras.push_back(camera);
      }
      return ourDrone;
  }
  return NULL;
}
