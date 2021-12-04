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

class Robot:public Entity{
public:
  Robot(){return;}

  ~Robot(){
    for (int i = 0; i < cameras.size(); i++) {
        delete cameras[i];
    }
  }

  void Update(float dt){return;}

};


#endif
