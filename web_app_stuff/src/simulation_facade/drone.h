#ifndef DRONE_H_
#define DRONE_H_

#include "entity.h"


class Drone : public Entity{
public:
	Drone();

	Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, Vector3 newAcceleration, float newTime);

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
};

#endif
