/**
 * @file beeline.h
 *
 */
#ifndef BEELINE_H_
#define BEELINE_H_

#include "movement_strategy.h"
/**
 * @brief The class for handling the beeline movement strategy
 *
 */
class BeelineMovement : public MovementStrategy{
public:
	/**
	 * @brief Constructor, applies the destination for the entity to beeline to
	 *
	 */
	BeelineMovement(Point3 dest);

	/**
	 * @brief Execute the movement strategy
	 *
	 */
	void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity);

private:
	Point3 destination;
};

#endif