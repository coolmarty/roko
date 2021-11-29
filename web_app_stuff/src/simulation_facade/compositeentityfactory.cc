#include "compositeentityfactory.h"
CompositeEntityFactory::CompositeEntityFactory(){
  factories.push_back(DroneFactory());
}

Entity CompositeEntityFactory::create(picojson::object& entityData){
  Entity ent;
  for(int i=0;i<factories.length;i++){
    ent = factories[i].create(entityData);
    if(ent){
      return ent;
    }
  }
  return NULL;

}
