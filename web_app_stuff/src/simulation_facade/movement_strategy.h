#ifndef MOVEMENT_STRATEGY_H_
#define MOVEMENT_STRATEGY_H_

#include "point3.h"
#include "direction.h"
#include "vector3.h"

class MovementStrategy{
public:
	virtual void MovePath(Point3 *position, Direction *direction, Vector3 *velocity, /*Vector3 *acceleration*/, float *dt) = 0;
}

#endif