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