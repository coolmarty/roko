#ifndef BEELINE_H_
#define BEELINE_H_

#include "movement_strategy.h"

class BeelineMovement : public MovementStrategy{
public:
	BeelineMovement(Point3 *dest);

	void MovePath(Point3 *position, Direction *direction, Vector3 *velocity, Vector3 *acceleration, float *dt);

private:
	Point3 destination;
}

#endif