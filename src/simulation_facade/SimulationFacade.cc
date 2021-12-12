#include "SimulationFacade.h"

SimulationFacade::SimulationFacade(){
  return;
}

void SimulationFacade::CreateEntity(picojson::object& entityData, ICameraController& cameraController){
  Entity *entity = entityFactory.create(entityData,cameraController);
  if(entity){
    entities.push_back(entity);
  }
  return;
}
void SimulationFacade::Update(double dt, const std::map<std::string,int>& keyStatus){
  int keyArr[4] = {0, 0, 0, 0};
  
  if (keyStatus.find("ArrowRight") != keyStatus.end() && keyStatus.find("ArrowRight")->second == 1) { // Yaw
	keyArr[1] = 1;
  } else if (keyStatus.find("ArrowLeft") != keyStatus.end() && keyStatus.find("ArrowLeft")->second == 1) {
	keyArr[1] = -1;
  } else {
	keyArr[1] = 0;
  }
  if (keyStatus.find("ArrowUp") != keyStatus.end() && keyStatus.find("ArrowUp")->second == 1) { // Thrust/Elevation
	keyArr[2] = 1;
  } else if (keyStatus.find("ArrowDown") != keyStatus.end() && keyStatus.find("ArrowDown")->second == 1) {
	keyArr[2] = -1;
  } else {
	keyArr[2] = 0;
  }
  if (keyStatus.find("w") != keyStatus.end() && keyStatus.find("w")->second == 1) { // Pitch
	keyArr[0] = 1;
  } else if (keyStatus.find("s") != keyStatus.end() && keyStatus.find("s")->second == 1) {
	keyArr[0] = -1;  
  } else {
	keyArr[0] = 0;  
  }
  /*
  if (keyStatus.find("a") != keyStatus.end() && keyStatus.find("ArrowRight") == 1) {
	//
  } else if (keyStatus.find("d") != keyStatus.end() && keyStatus.find("ArrowRight") == 1) {
	  
  } else {
	
  }
  */
  for(int i=0;i<entities.size();i++){
    entities[i]->Update(dt);
	entities[i]->SetKeys(keyArr);
  }
}

void SimulationFacade::FinishUpdate(picojson::object& returnValue){
  for(int i=0;i<entities.size();i++){
    Entity *e=entities[i];
    picojson::object entity;
    entity["entityId"] = picojson::value((double)e->GetId());

    // Save the position as an array
    Point3 entityPosition=e->GetPosition();
    picojson::array pos;
    pos.push_back(picojson::value(entityPosition.GetX()));
    pos.push_back(picojson::value(entityPosition.GetY()));
    pos.push_back(picojson::value(entityPosition.GetZ()));
    entity["pos"] = picojson::value(pos);

    // Save the direction as an array
    Vector3 entityDirection=e->GetDirection();
    picojson::array dir;
    dir.push_back(picojson::value(entityDirection.GetX()));
    dir.push_back(picojson::value(entityDirection.GetY()));
    dir.push_back(picojson::value(entityDirection.GetZ()));
    entity["dir"] = picojson::value(dir);

    // Send the compile picojson data to the UI in the returnValue variable
    returnValue["entity"+std::to_string(e->GetId())] = picojson::value(entity);
  }
}
