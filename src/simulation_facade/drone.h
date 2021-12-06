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
#include "movement_strategy.h"
#include "data.h"
#include "beeline.h"
#include "patrol.h"
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

	void SetJoystick(double x, double y, double z, double a) {
		Vector3 dir = Vector3(x,y,z);
		this->SetDirection(dir);
	}
	float lastPictureTime = 0.0;
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
	Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime, int newTravelNode, int newCurrentNode);

	/**
	 * @brief copy constructor for drone
	 *
	 * @return a drone object
	 */
	Drone(const Drone &old);

	~Drone();

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

private:
	Point3 robotFound;
	int travelNode; // keeps track of the drone's target location along the edge of the map, increments when it's at a recharge station
	int currentNode; // for the drone's patrol, where it's currently moving to

};

#endif
