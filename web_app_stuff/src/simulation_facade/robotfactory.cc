#include "robotfactory.h"

RobotFactory::RobotFactory(){
  return;
}

Entity *RobotFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "robot") {
      Entity *ourBot = new Drone();

      ourBot->SetId(entityData["entityId"].get<double>());


      picojson::array position = entityData["position"].get<picojson::array>();
      ourBot->SetPosition(position[0].get<double>(), position[1].get<double>(), position[2].get<double>());

      picojson::array direction = entityData["direction"].get<picojson::array>();
      ourBot->SetPosition(direction[0].get<double>(), direction[1].get<double>(), direction[2].get<double>());

      return ourBot;
  }
  return NULL;
}
