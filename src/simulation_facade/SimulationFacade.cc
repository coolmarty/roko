#include "SimulationFacade.h"

SimulationFacade::SimulationFacade(){
  return;
}

void SimulationFacade::CreateEntity(picojson::object& entityData, ICameraController& cameraController){
  Entity *entity = entityFactory.create(entityData,cameraController);
  entities.push_back(entity);
  return;
}
void SimulationFacade::Update(double dt){
  for(int i=0;i<entities.size();i++){
    entities[i]->Update(dt);
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
