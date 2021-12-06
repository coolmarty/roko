/**
 * @file compositeentityfactory.h
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entityfactory.h"
#include "dronefactory.h"
#include "robotfactory.h"
#include "hospitalfactory.h"
#include "rechargestationfactory.h"

#ifndef _COMPENTFACT_H_
#define _COMPENTFACT_H_

/**
 * @brief The main class used to generate any entity objects in our simulation
 *
 * inherits from Entity Factory
 */
class CompositeEntityFactory:public EntityFactory{
public:
  /**
   * @brief constructor for CompositeEntityFactory, adds all factories to a vector
   */
  CompositeEntityFactory();

  /**
   * @brief destructor for CompositeEntityFactory, since all factories are new'd
   */
  ~CompositeEntityFactory();

  /**
   * @brief The function used to generate any entity
   *
   * Takes in a picojson object containing all the data about an entity
   *
   * @return an Entity
   */
  Entity *create(picojson::object& entityData, ICameraController& cameraController);

  Entity *create(picojson::object& entityData);
private:
  std::vector<EntityFactory *> factories;
};


#endif
