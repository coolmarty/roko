#ifndef PATROL_H_
#define PATROL_H_

#include "beeline.h"

class PatrolMovement : public MovementStrategy{
public:
	PatrolMovement(float newUnitDistance, int* newTravelNode, int newNodesPerRefuel);

	void MovePath(Point3 *position, Direction *direction, Vector3 *velocity, /*Vector3 *acceleration*/, float *dt);

private:

	Point3 GetNode(int node);

	float unitDistance;
	int travelNode;
	int nodesPerRefuel;
}

#endif