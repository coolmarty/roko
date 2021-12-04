
/**
 * @file search_and_rescue.h
 *
*/

#ifndef _SEARCH_AND_RESCUE_H
#define _SEARCH_AND_RESCUE_H

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "drone.h"

/**
 * @brief Facade into the search and rescue functionality of the Drone
 *
 * Drone will use this facde to switch behaviors between searching and rescue phases
 */
class SearchAndRescue {
public:
	/**
	 * @brief Enter done into search mode by setting movement pattern to patrol
	 */
	void Search(Drone& roko);

	/**
	 * @brief Enter done into rescue mode by setting movement pattern to beeline
	 */
	void Rescue(Drone& roko, const Point3& dest);
};

#endif
