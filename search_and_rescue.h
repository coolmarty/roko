#ifndef _SEARCH_AND_RESCUE_H
#define _SEARCH_AND_RESCUE_H

#include "drone.h"
#include "point3.h"

class SearchAndRescue {
public:
	void Search();
	void Rescue(const Point3 dest&);
	
private:
	Drone roko;
};

#endif