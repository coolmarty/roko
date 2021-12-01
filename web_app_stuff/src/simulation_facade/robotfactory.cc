#include "robotfactory.h"

RobotFactory::RobotFactory(){
  return;
}

Entity *RobotFactory::create(picojson::object& entityData){
  if (entityData["name"].get<std::string>() == "robot") {
      Entity *ourBot = new Robot();



      return ourBot;
  }
  return NULL;
}
