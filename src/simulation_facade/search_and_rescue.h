
/**
 * @file search_and_rescue.h
 *
*/

#ifndef _SEARCH_AND_RESCUE_H
#define _SEARCH_AND_RESCUE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "patrol.h"
#include "beeline.h"
#include "point3.h"
#include "vector3.h"
/**
 * @brief Facade into the search and rescue functionality of the Drone
 *
 * Drone will use this facde to switch behaviors between searching and rescue phases
 */
class SearchAndRescue {
public:
	SearchAndRescue();
	
	~SearchAndRescue();

	/**
	 * @brief Enter done into search mode by setting movement pattern to patrol
	 */
	void Search(Point3* position, Vector3* direction, Vector3* velocity, Point3* travelDestination, Point3* savedDestination, int* travelDirection);

	/**
	 * @brief Enter done into rescue mode by setting movement pattern to beeline
	 */
	void Rescue(Point3* position, Vector3* direction, Vector3* velocity, const Point3& dest);

	/**
	 * @brief Determines the node traveled to in order to facilitate Patrol
	 */
	void NextNode(Point3* position, Point3* savedNode, int* currentDirection);

private:
	Point3 node;
	Point3 rechargeLocation;
	bool found;
	bool pathToRecharge;
	int turn;
};

#endif
