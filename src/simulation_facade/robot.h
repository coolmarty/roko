/**
 * @file robot.h
 *
 */

 #ifndef ROBOT_H_
 #define ROBOT_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"

/**
 * @brief Robot class, used to keep track of any and all Robot entities
 *
 *
 */
class Robot:public Entity{
public:
  /**
   * @brief constructor for robot
   *
   */
  Robot(){return;}


  ~Robot(){
    for (int i = 0; i < cameras.size(); i++) {
        delete cameras[i];
    }
  }

  /**
   * @brief update function for robot (doesn't do anything right now)
   *
   */
   void Update(float dt){return;}

};


#endif
