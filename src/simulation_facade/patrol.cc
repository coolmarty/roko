#include "patrol.h"
#include <cmath>
#include <iostream>

PatrolMovement::PatrolMovement(Point3 newNode){
	node = newNode;
}

void PatrolMovement::SetNode(Point3 nodey) {
	node = nodey;
}

void PatrolMovement::MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity){	
	const Point3 rechargeLocation = Point3(50, 0, 20);
	//-1450, 1550
	//-900, 900
	if(position->GetZ() < -1450 || position->GetZ() > 1550){
		node = rechargeLocation;
	}
	if(position->GetX() < -900 || position->GetX() > 900){
		node = rechargeLocation;
	}
	BeelineMovement(node).MovePath(position, direction, velocity);
	//obj.MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity);
	
	// BeelineMovement(GetNode(travelNode, initialPosition)); // go to saved position, 0 at start
	// for(int i = 0; i < nodesPerRefuel; i++){
	// 	BeelineMovement(GetNode(travelNode + i, initialPosition)); // travel to the position of the next node
	// 	travelNode++;
	// }
	// BeelineMovement(GetNode(0, initialPosition));
}