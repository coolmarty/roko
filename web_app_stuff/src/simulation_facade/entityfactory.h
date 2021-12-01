/**
 * @file entityfactory.h
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include <string>
#include <vector>
#include "picojson"

#ifndef _ENTITYFACTORY_H_
#define _ENTITYFACTORY_H_

/**
 * @brief The main class of all EntityFactories
 *
 *  purely abstract class
 */
class EntityFactory{
public:
  /**
   * @brief The function used to generate an entity
   *
   * Takes in a picojson object containing all the data about an entity
   *
   * @return an Entity
   */
  virtual Entity create(picojson::object& entityData)=0;

};


#endif
