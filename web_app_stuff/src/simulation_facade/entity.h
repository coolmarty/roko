/**
 * @file entity.h
 *
 */


#ifndef _ENTITY_H_
#define _ENTITY_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "point3.h"
#include "vector3.h"
#include "direction.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The main class for convolutional filters, purely virtual
 *
 *
 */
class Entity  {


public:
    /**
     * @brief Base class for all entities
     *
     * @return none
     */
     virtual void Update(float dt) = 0;

     /**
      * @brief getter for position
      *
      * @return Point3 position
      */
     Point3 GetPosition();

     /**
      * @brief getter for velocity
      *
      * @return Vector3 velocity
      */
     Vector3 GetVelocity();

     /**
      * @brief getter for Accelleration
      *
      * @return Vector3 acceleration
      */
     Vector3 GetAcceleration();

     /**
      * @brief getter for Direction
      *
      * @return Direction direction
      */
     Direction GetDirection();

     /**
      * @brief getter for time
      *
      * @return float time
      */
     float GetTime();

     /**
      * @brief setter for position
      *
      * @return none
      */
     void SetPosition(Point3 p);

     /**
      * @brief setter for velocity
      *
      * @return none
      */
     void SetVelocity(Vector3 v);

     /**
      * @brief setter for acceleration
      *
      * @return none
      */
     void SetAcceleration(Vector3 a);

     /**
      * @brief setter for direction
      *
      * @return none
      */
     void SetDirection(Direction d);

     /**
      * @brief setter for time
      *
      * @return none
      */
     void SetTime(float t){time=t};
protected:
  Point3 position;
  Vector3 velocity;
  Vector3 acceleraton;
  Direction direction;
  float time;

};

#endif
