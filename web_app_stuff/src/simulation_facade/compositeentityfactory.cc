#include "compositeentityfactory.h"
CompositeEntityFactory::CompositeEntityFactory(){
  factories.push_back(new DroneFactory());
  factories.push_back(new RobotFactory());
  factories.push_back(new HospitalFactory());
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
