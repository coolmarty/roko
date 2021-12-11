/**
 * @file patrol.h
 *
 */
#ifndef PATROL_H_
#define PATROL_H_

#include "beeline.h"
/**
 * @brief The main class for the patrol movement strategy
 *
 */
class PatrolMovement : public MovementStrategy{
public:
	/**
	 * @brief Constructor for patrol, takes in the node and direction for drone to move to
	 *
	 */
	PatrolMovement(Point3 newNode);

	/**
	 * @brief Calls to the movement strategy's abstract method
	 *
	 */
	void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity);

	/**
	 * @brief Sets the node held by the class
	 *
	 */
	void SetNode(Point3 nodey);
private:

	Point3 node;
};

#endif