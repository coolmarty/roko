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
#include "search_and_rescue.h"
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
	 * @brief Manual Movement
	 *
	 * 
	 */
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
	Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime, Point3 newDestination, Point3 newSavedDestination, int newDestDirection);

	/**
	 * @brief copy constructor for drone
	 *
	 * @return a drone object
	 */
	Drone(const Drone &old);

	/**
	 * @brief destructor for drone
	 *
	 * 
	 */
	~Drone();

	/**
	 * @brief calls to MovePath, defunct due to SearchAndRescue
	 *
	 */
	void Move();

	/**
	 * @brief Takes a picture using camera
	 *
	 */
	void TakePicture();

	/**
	 * @brief Updates in line with the simulation
	 *
	 */
	void Update(float dt);

    Battery battery;

private:
	Point3 robotFound;
	SearchAndRescue movementAccessor;
	Point3 travelDestination; // the point which the Drone will move to
	Point3 savedDestination;
	int travelDirection; // the direction the Drone's destination will change
	bool manual;
};

#endif
