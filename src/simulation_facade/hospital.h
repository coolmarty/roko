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

class Hospital:public Entity{
public:
  Hospital(){return;}

  ~Hospital(){
    for (int i = 0; i < cameras.size(); i++) {
        delete cameras[i];
    }
  }

  void Update(float dt){return;}

};


#endif
