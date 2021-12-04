/**
 * @file rechargestationfactory.h
 *
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entityfactory.h"
#include "rechargestation.h"

#ifndef RECHARGEFACTORY_H_
#define RECHARGEFACTORY_H_

/**
 * @brief The main class used to generate charge stations objects in our simulation
 *
 * inherits from Entity Factory
 */
class RechargeStationFactory:public EntityFactory{
public:
  /**
   * @brief constructor for RechargeStationFactory
   */
  RechargeStationFactory();

  /**
   * @brief The function used to generate a recharge station
   *
   * Takes in a picojson object containing all the data about an entity
   *
   * @return a Recharge Station Entity
   */
  Entity *create(picojson::object& entityData, ICameraController& cameraController);

  /**
   * @brief The function used to generate a recharge station debug only
   *
   * Takes in a picojson object containing all the data about an entity
   *
   * @return a Recharge Station Entity
   */
  Entity *create(picojson::object& entityData);
};


#endif
