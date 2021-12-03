<<<<<<< HEAD
#ifndef DRONE_H_
#define DRONE_H_

#include "movement_strategy.h"
#include "entity.h"


class Drone : public Entity{
public:
	Drone();

	Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime, int newTravelNode, int newCurrentNode);

	Drone(const Drone &old);

	void Move();
	Point3 TakePicture();

	void Update(float dt);

private:
	// Point3 position;
	// Vector3 direction;
	// Vector3 velocity;
	// float time;
	Point3 robotFound;
	int travelNode; // keeps track of the drone's target location along the edge of the map, increments when it's at a recharge station
	int currentNode; // for the drone's patrol, where it's currently moving to
};

#endif
=======
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
>>>>>>> dev
