
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
	void Search(Point3* position, Vector3* direction, Vector3* velocity);

	/**
	 * @brief Enter done into rescue mode by setting movement pattern to beeline
	 */
	void Rescue(Point3* position, Vector3* direction, Vector3* velocity, const Point3& dest);
	
	void SetTNode(int node);
	void SetCNode(int node);
	
	int GetTravel();
	int GetCurrent();	

private:
	int travelNode;
	int currentNode;
	Point3 rechargeLocation;
	bool found;
};

#endif
