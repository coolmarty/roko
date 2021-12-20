/**
 * @file movement_strategy.h
 *
 */
#ifndef MOVEMENT_STRATEGY_H_
#define MOVEMENT_STRATEGY_H_

#include "point3.h"
#include "vector3.h"
/**
 * @brief The class for handling movement strategies
 *
 */
class MovementStrategy{
public:
	/**
	 * @brief Abstract class allowing for the use of beeline and patrol's movement strategies
	 *
	 */
	virtual void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity) = 0;
};

#endif