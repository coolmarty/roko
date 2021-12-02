#include "patrol.h"
#include <cmath>

PatrolMovement::PatrolMovement(float newUnitDistance, int* newTravelNode, int newNodesPerRefuel){
	unitDistance = newUnitDistance;
	travelNode = newTravelNode;
	nodesPerRefuel = newNodesPerRefuel;
}

Point3 PatrolMovement::GetNode(int node, Point3 position){
	Point3 moveTo = position;
	int directionDetermine = 0; // down = 0; right = 1; up = 2; left = 3
	int straightCount = 1; //length of straight lines per 2 turns
	int i = 0;
	while(i < node/2){
		for(int turns = 0; turns < 2; turns++){ // 2 turns before straight increments
			for(int i = 0; i < straightCount){ // moves in a straight line this many times
				if(directionDetermine % 0){ 
					moveTo.SetZ(moveTo.GetZ() - unitDistance); //down
				}
				else if(directionDetermine % 1){ 
					moveTo.SetX(moveTo.GetX() + unitDistance); //right
				}
				else if(directionDetermine % 2){ 
					moveTo.SetZ(moveTo.GetZ() + unitDistance); //up
				}
				else{ 
					moveTo.SetX(moveTo.GetX() - unitDistance); //left
				}
			}
			directionDetermine++;
		}
		straightCount++;
	}
	return moveTo;
}

void PatrolMovement::MovePath(Point3 *position, Direction *direction, Vector3 *velocity, /*Vector3 *acceleration*/, float *dt){
	Point3 initialPosition = position;
	BeelineMovement(GetNode(travelNode, initialPosition)); // go to saved position, 0 at start
	for(int i = 0; i < nodesPerRefuel; i++){
		BeelineMovement(GetNode(travelNode + i, initialPosition)); // travel to the position of the next node
		travelNode++;
	}
	BeelineMovement(GetNode(0, initialPosition));
}