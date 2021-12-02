/**
 * @file dronefactory.h
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entityfactory.h"
#include "drone.h"

#ifndef _DRONEFACTORY_H_
#define _DRONEFACTORY_H_

/**
 * @brief The main class used to generate drone objects in our simulation
 *
 * inherits from Entity Factory
 */
class DroneFactory:public EntityFactory{
public:
  /**
   * @brief constructor for DroneFactory
   */
  DroneFactory();

  /**
   * @brief The function used to generate a Drone
   *
   * Takes in a picojson object containing all the data about an entity
   *
   * @return a Drone Entity
   */
  Entity *create(picojson::object& entityData, ICameraController& cameraController);
};


#endif
