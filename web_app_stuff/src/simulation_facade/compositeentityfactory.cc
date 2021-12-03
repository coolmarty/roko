#include "compositeentityfactory.h"
CompositeEntityFactory::CompositeEntityFactory(){
  factories.push_back(new DroneFactory());
  factories.push_back(new RobotFactory());
  factories.push_back(new HospitalFactory());
}

CompositeEntityFactory::~CompositeEntityFactory(){
  EntityFactory *f;
  for(int i=0;i<factories.size();i++){
    f=factories[0];//get first selement
    factories.erase(factories.begin());//erase first element
    delete f;//delete memory we malloc'd (or new'd I guess)
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
