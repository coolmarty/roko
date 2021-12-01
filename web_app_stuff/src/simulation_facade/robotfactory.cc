#include "robotfactory.h"

RobotFactory::RobotFactory(){
  return
}

Entity RobotFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "robot") {
      Entity ourBot = Robot();
      ourBot.id = entityData["entityId"].get<double>();
      ourBot.speed = entityData["speed"].get<double>();

      // Get the position as an array
      picojson::array position = entityData["position"].get<picojson::array>();
      ourBot.pos[0] = position[0].get<double>();
      ourBot.pos[1] = position[1].get<double>();
      ourBot.pos[2] = position[1].get<double>();

      // Get the direction as an array
      picojson::array dir = entityData["direction"].get<picojson::array>();
      ourBot.dir[0] = dir[0].get<double>();
      ourBot.dir[1] = dir[1].get<double>();
      ourBot.dir[2] = dir[1].get<double>();

      return ourDrone;
  }
  return NULL;
}
