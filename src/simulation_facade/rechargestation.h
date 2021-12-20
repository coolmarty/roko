/**
 * @file rechargestation.h
 *
 */
#ifndef RECHARGESTATION_H_
#define RECHARGESTATION_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "compositebattery.h"
#include <unistd.h>
#include "point3.h"
#include "vector3.h"

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
class Drone;

/**
 * @brief The main class of RechargeStation
 *
 *  Derived class of Entity, invoked to create a recharge station (a composite battery of 10  for drones.
 */
 
class RechargeStation : public Entity{
  public:

/**
* @brief Boolean value of whether a drone is currently at the station, initialized to FALSE.
*
*/
    bool busy;

/**
* @brief The RechargeStation's source of power - a CompositeBattery to be drained by the drone.
*
*/
    CompositeBattery powercells;
/*
* @brief Generation of a RechargeStation with nothing passed in. This will create a RechargeStation with ten fully charged batteries in its inventory.
*
*/
    RechargeStation(Point3 pos);
/**
* @brief Generation of a RechargeStation with a CompositeBattery passed in.
*
*/
    RechargeStation(Point3 pos, CompositeBattery compbatt);

    ~RechargeStation();
/**
* @brief Function to recharge a drone object passed in as a parameter, will drain power cells of the Recharge Station. If the power cell gets drained, it will discard it and take charge off the next one in line.
*
*/
    void Recharge(Drone* drone);
/**
* @brief Returns the busy boolean so two drones don't to refill at once.
*
*/
    bool IsBusy();

    void Update(float dt);
};

#endif
