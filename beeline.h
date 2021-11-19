#ifndef BEELINE_H_
#define BEELINE_H_

#include "point3.h"
#include "direction.h"
#include "vector3.h"

class BeelineMovement : public MovementStrategy{
public:
	BeelineMovement(Point3 *dest);

	void MovePath(Point3 *position, Direction *direction, Vector3 *velocity);

private:
	Point3 destination;
}

#endif