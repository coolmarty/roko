#include "patrol.h"
#include <cmath>
#include <iostream>

PatrolMovement::PatrolMovement(int newNode){
	node = newNode;
}

void PatrolMovement::SetNode(int nodey) {
	node = nodey;
}

Point3 PatrolMovement::GetNode(int node){
	Point3 target = Point3(-1450, 0, -900); // southwest corner of map
	if(node > 96){
		node = 96; // will have gone out of bounds, sets to bottom left
	}
	if(node < -1){
		node = -1; // if node is -1. it goes back to the recharge station
	}
	if(node == -1){
		return Point3(20, 0, 50);
	}
	for(int i = 0; i < node; i++){ // will seek for the node along a rectangular path following the edge of the map
		if(i < 30){
			target.SetX(target.GetX() + 10); // iterates east along southern edge
		}else if(i > 29 && i < 48){
			target.SetZ(target.GetZ() + 10); // iterates north along eastern edge
		}else if(i > 47 && i < 78){
			target.SetX(target.GetX() - 10); // iterates west along northern edge
		}else if(i > 77){
			target.SetZ(target.GetZ() - 10); // iterates south along western edge
		}
	}
	return target;
}

void PatrolMovement::MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity){	
	const Point3 rechargeLocation = Point3(20, 0, 50);
	//-1450, 1550
	//-900, 900
	if(position->GetX() < -1450 || position->GetX() > 1550){
		node = -1;
	}
	if(position->GetZ() < -900 || position->GetZ() > 900){
		node = -1;
	}
	BeelineMovement(GetNode(node)).MovePath(position, direction, velocity);
	//obj.MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity);
	
	// BeelineMovement(GetNode(travelNode, initialPosition)); // go to saved position, 0 at start
	// for(int i = 0; i < nodesPerRefuel; i++){
	// 	BeelineMovement(GetNode(travelNode + i, initialPosition)); // travel to the position of the next node
	// 	travelNode++;
	// }
	// BeelineMovement(GetNode(0, initialPosition));
}