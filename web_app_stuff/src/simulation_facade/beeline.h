#ifndef BEELINE_H_
#define BEELINE_H_

#include "movement_strategy.h"

class BeelineMovement : public MovementStrategy{
public:
	BeelineMovement(Point3 dest);

	void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity, float *dt);

private:
	Point3 destination;
};

#endif