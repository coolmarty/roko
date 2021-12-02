#ifndef DRONE_H_
#define DRONE_H_

#include "movement_strategy.h"
#include "entity.h"


class Drone : public Entity{
public:
	Drone();

	Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime);

	Drone(Drone old);

	void Move();
	Point3 TakePicture();

	void Update(float dt);

private:
	Point3 position;
	Vector3 direction;
	Vector3 velocity;
	float time;
	Point3 robotFound;
}

#endif