#include "compositeentityfactory.h"
CompositeEntityFactory::CompositeEntityFactory(){
  factories.push_back(new DroneFactory());
  factories.push_back(new RobotFactory());
  factories.push_back(new HospitalFactory());
  factories.push_back(new RechargeStationFactory());
}

CompositeEntityFactory::~CompositeEntityFactory(){
  std::cout<<"deleting myself"<<std::endl;
  EntityFactory *f;
  for(int i=0;i<factories.size();i++){
    delete factories[i];
  }
}

Entity *CompositeEntityFactory::create(picojson::object& entityData, ICameraController& cameraController){
  Entity *ent;
  for(int i=0;i<factories.size();i++){
    ent = factories[i]->create(entityData,cameraController);
    if(ent){
      return ent;
    }
  }
  return NULL;
}

Entity *CompositeEntityFactory::create(picojson::object& entityData){
  Entity *ent;
  for(int i=0;i<factories.size();i++){
    ent = factories[i]->create(entityData);
    if(ent){
      return ent;
    }
  }
  return NULL;

}
