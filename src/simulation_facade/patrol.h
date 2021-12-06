#ifndef PATROL_H_
#define PATROL_H_

#include "beeline.h"

class PatrolMovement : public MovementStrategy{
public:
	PatrolMovement(int newNode);

	void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity);

	Point3 GetNode(int node);
	void SetNode(int node);

	int node;
private:

};

#endif