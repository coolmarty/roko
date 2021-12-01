#include "dronefactory.h"

DroneFactory::DroneFactory(){
  return;
}

Entity *DroneFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "drone") {
      Entity *ourDrone = new Drone();
      return ourDrone;
  }
  return NULL;
}
