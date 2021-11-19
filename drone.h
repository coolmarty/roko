#ifndef DRONE_H_
#define DRONE_H_

#include "movement_strategy.h"


class Drone : public Entity{
public:
	Drone();

	Drone(Point3 newPosition, Direction newDirection, Vector3 newVelocity);

	Drone(Drone old);

	~Drone();

	Point3 GetPosition();
	Direction GetDirection();
	float GetVelocity();

	void SetPosition(Point3 newPosition);
	void SetDirection(Direction newDirection);
	void SetVelocity(Vector3 newVelocity);

	void Move();

private:
	Point3 position;
	Direction direction;
	Vector3 velocity;
}

#endif