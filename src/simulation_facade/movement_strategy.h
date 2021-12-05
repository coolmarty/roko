#ifndef MOVEMENT_STRATEGY_H_
#define MOVEMENT_STRATEGY_H_

#include "point3.h"
#include "vector3.h"

class MovementStrategy{
public:
	virtual void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity) = 0;
};

#endif