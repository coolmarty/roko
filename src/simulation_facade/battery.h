/**
 * @file battery.h
 *
 */

#ifndef BATTERY_H_
#define BATTERY_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <iostream>
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class of Battery.
 *
 * A drone will hold a battery with a capacity between 0.0 and 100.0 inclusive.
 */
class Battery{
  private:
/**
 * @brief The Battery's private battery life, usually initialized to 100.0.
 *
 *  
 */
    float batteryLife;
    
  public:

/**
 * @brief Initialize a Battery object with no parameters, setting its battery life to 100.0.
 *
 *  
 */
    Battery();
/**
 * @brief Initialize a Battery with a battery life equal to the float value passed in as parameter.
 *
 *  
 */
    Battery(float batteryLife);
/**
 * @brief Returns the battery life of the Battery.
 *
 *  
 */
    float GetBatteryLife();
/**
 * @brief Modifies a Battery's batterylife to the float value passed in as parameter.
 *
 *  
 */
    void SetBatteryLife(float newBatteryLife); 
};
#endif
