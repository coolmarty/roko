#ifndef PATROL_H_
#define PATROL_H_

#include "beeline.h"

class PatrolMovement : public MovementStrategy{
public:
	PatrolMovement(Point3 newInitialPosition; float newUnitDistance, int* newTravelNode, int newNodesPerRefuel);

	void MovePath(Point3 *position, Direction *direction, Vector3 *velocity, float *dt);

private:

	Point3 GetNode(int node);

	Point3 initialPosition;
	float unitDistance;
	int travelNode;
	int nodesPerRefuel;
}

#endif