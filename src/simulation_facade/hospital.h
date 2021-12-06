/**
 * @file hospital.h
 *
 */

 #ifndef HOSPITAL_H_
 #define HOSPITAL_H_
/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
/**
 * @brief Hospital class, used to keep track of all Hospital entities
 *
 *
 */
class Hospital:public Entity{
public:
  /**
   * @brief constructor for hospital
   *
   */
  Hospital(){return;}


  ~Hospital(){
    for (int i = 0; i < cameras.size(); i++) {
        delete cameras[i];
    }
  }


  /**
   * @brief update function for hospital (doesn't do anything right now)
   *
   */
  void Update(float dt){return;}

};


#endif
