
#ifndef SIMFACADE_H_
#define SIMFACADE_H_

#include "picojson.h"
#include "camera_controller.h"
#include "entity.h"
#include "compositeentityfactory.h"
#include <vector>

class SimulationFacade {
public:
  SimulationFacade();
  void CreateEntity(picojson::object& entityData, ICameraController& cameraController);
  void Update(double dt);
  void FinishUpdate(picojson::object& returnValue);
private:
  std::vector<Entity *> entities;
  CompositeEntityFactory entityFactory=CompositeEntityFactory();
};

#endif
