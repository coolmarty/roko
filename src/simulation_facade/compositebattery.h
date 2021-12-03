/**
 * @file compositebattery.h
 *
 */
 
/*******************************************************************************
 * Includes
 ******************************************************************************/
#ifndef COMPOSITE_BATTERY_H_
#define COMPOSITE_BATTERY_H_
#include <vector>
#include "battery.h"
/**
 * @brief The main class of CompositeBattery
 *
 *  Derived class of Battery, invoked to create a composite battery containing a Battery vector.
 */
class CompositeBattery : public Battery{
  public:
/**
 * @brief The battery vector of the composite battery.
 *
 * 
 */
  std::vector<Battery> batteries;
/**
* @brief Generation of a CompositeBattery with no parameters.
*
*/
  CompositeBattery();
/**
* @brief Generation of a CompositeBattery with a Battery passed in.
*
*/
  CompositeBattery(Battery batt);
/**
* @brief Add a Battery to the composite battery, passed in as a parameter.
*
*/
  void AddBattery(Battery batt);
/**
* @brief Remove the first battery from the composite battery.
*
*/
  void RemoveBattery();
/**
* @brief Returns the battery life of the first battery in the vector.
*
*/
  float GetFirstBatteryLife();
/**
* @brief Returns the sum of each battery life in the  vector.
*
*/
  float GetTotalBatteryLife();
/**
* @brief Changes the life of the first battery to the float passed in as parameter.
*
*/
  void SetFirstBattery(float NBL);
  
    
};
#endif
