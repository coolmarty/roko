#ifndef PATROL_H_
#define PATROL_H_

#include "beeline.h"

class PatrolMovement : public MovementStrategy{
public:
	PatrolMovement(int* newNode);

	void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity, float *dt);

private:

	Point3 GetNode(int node);

	int node;
};

#endif