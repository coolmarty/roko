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
	 * @brief Constructor for patrol, takes in the node for drone to move to
	 *
	 */
	PatrolMovement(int newNode);

	/**
	 * @brief Calls to the movement strategy's abstract method
	 *
	 */
	void MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity);

	/**
	 * @brief Gets the node held by the class
	 *
	 */
	Point3 GetNode(int node);
	/**
	 * @brief Sets the node held by the class
	 *
	 */
	void SetNode(int node);

	int node = -1;
private:

	int node;
};

#endif