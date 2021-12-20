/**
 * @file hospital.h
 *
 */
#ifndef SIMFACADE_H_
#define SIMFACADE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "picojson.h"
#include "camera_controller.h"
#include "entity.h"
#include "compositeentityfactory.h"
#include <vector>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief our main class for running a simulation of a drone rescuing a robot
 *
 *
 */
class SimulationFacade {
public:
  /**
   * @brief constructor, sets up our simulation
   *
   *
   */
  SimulationFacade();

  /**
   * @brief creates entities and adds them to its entity vector;
   *
   * calls the abstract composite entity factory
   */
  void CreateEntity(picojson::object& entityData, ICameraController& cameraController);

  /**
   * @brief calls the update method for each entity in its vector
   *
   *
   */
  void Update(double dt, const std::map<std::string,int>& keyStatus);

  /**
   * @brief creates a json object with updated data for all entities to send to the server
   *
   */
  void FinishUpdate(picojson::object& returnValue);
private:
  std::vector<Entity *> entities;
  CompositeEntityFactory entityFactory=CompositeEntityFactory();
};

#endif
