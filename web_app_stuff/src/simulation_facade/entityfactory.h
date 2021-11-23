#include "entity.h"
#include <string>

#ifndef _ENTITYFACTORY_H_
#define _ENTITYFACTORY_H_

class EntityFactory{
public:
  virtual Entity create(picojson::object& entityData)=0;

};


#endif
