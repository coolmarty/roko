/**
 * @file drone.h
 *
 */

#ifndef DRONE_H_
#define DRONE_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "entity.h"
#include "battery.h"
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/

/**
 * @brief The main class used for drones
 *
 * inherits from Entity
 */
class Drone : public Entity{
public:
	/**
	 * @brief The default constructer for Drones
	 *
	 * @return a drone object
	 */
	Drone();

	/**
	 * @brief an overloaded constructer for Drones
	 *
	 * @return a drone object
	 */
	Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, Vector3 newAcceleration, float newTime);

	/**
	 * @brief copy constructor for drone
	 *
	 * @return a drone object
	 */
	Drone(const Drone& old);

	// ~Drone();

	// Point3 GetPosition();
	// Direction GetDirection();
	// Vector3 GetVelocity();
	// Vector3 GetAcceleration();
	// float GetTime();

	// void SetPosition(Point3 newPosition);
	// void SetDirection(Direction newDirection);
	// void SetVelocity(Vector3 newVelocity);
	// void SetAcceleration(Vector3 newAcceleration);
	// void SetTime(float newTime);

	void Move();
	void TakePicture();

	void Update(float dt);
        Battery battery;
};

#endif
