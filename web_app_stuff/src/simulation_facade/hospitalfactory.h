/**
 * @file hospitalfactory.h
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entityfactory.h"
#include "hospital.h"

#ifndef ROBOTFACTORY_H_
#define ROBOTFACTORY_H_

/**
 * @brief The main class used to generate hospitals objects in our simulation
 *
 * inherits from Entity Factory
 */
class RobotFactory::public EntityFactory{
public:
  /**
   * @brief constructor for HospitalFactory
   */
  HospitalFactory();

  /**
   * @brief The function used to generate a Robot
   *
   * Takes in a picojson object containing all the data about an entity
   *
   * @return a Robot Entity
   */
  Entity create(picojson::object& entityData);
};


#endif
