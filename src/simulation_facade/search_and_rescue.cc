#include "search_and_rescue.h"
#include <iostream>

SearchAndRescue::SearchAndRescue() : found(false), node(Point3(-1000, 0, -1000)), rechargeLocation(Point3(50, 0, 20)), pathToRecharge(false), turn(0) { }

SearchAndRescue::~SearchAndRescue() {
}

void SearchAndRescue::NextNode(Point3* position, Point3* savedNode, int* currentDirection){
	//Point3 edgePoints[4] = {Point3(-900,0,1550), Point3(900,0,1550), Point3(900, 0, -1450), Point3(-00, 0, -1450)};
	//if((position->GetZ() < -1450/22 || position->GetZ() > 1550/22 || position->GetX() < -900/9 || position->GetX() > 900/9)){
	std::cout << "Turn is " << turn << "\n";
	//}
	if(turn % 16 >= 0 && turn % 16 <= 3){
		savedNode->SetZ(savedNode->GetZ() + 500);
	}
	else if(turn % 16 >= 4 && turn % 16 <= 7){
		savedNode->SetX(savedNode->GetX() + 500);
	}
	else if(turn % 16 >= 8 && turn % 16 <= 11){
		savedNode->SetZ(savedNode->GetZ() - 500);
	}
	else if(turn % 16 >= 12 && turn % 16 <= 15){
		savedNode->SetX(savedNode->GetX() - 500);
	}
	turn++;
	node.SetZ(savedNode->GetZ());
	node.SetX(savedNode->GetX());
}

void SearchAndRescue::Search(Point3* position, Vector3* direction, Vector3* velocity, Point3* travelDestination, Point3* savedDestination, int* travelDirection) {
	/*MovementStrategy *initialize_pattern = new SearchPattern();

	roko.SetMovementPattern(initialize_pattern);
	roko.movement_pattern->MovePath(Point3 *pos); */
	
	if (*position == rechargeLocation || (position->GetX() <= rechargeLocation.GetX()+0.05 && position->GetX() >= rechargeLocation.GetX()-0.05 && position->GetZ() <= rechargeLocation.GetZ()+0.05 && position->GetZ() >= rechargeLocation.GetZ()-0.05) && pathToRecharge ) {
		std::cout << "Line 34 of search_and_rescue.cc entered\n";
		NextNode(position, savedDestination, travelDirection);
		travelDestination->SetX(savedDestination->GetX());
		travelDestination->SetY(savedDestination->GetY());
		travelDestination->SetZ(savedDestination->GetZ());
		pathToRecharge = false;
		std::cout << "savedDestination is X: " << savedDestination->GetX() << "   Z: " << savedDestination->GetZ() << "\n";
	}
	else if (*position == node || (position->GetZ() < -1450/22 || position->GetZ() > 1550/22 || position->GetX() < -900/9 || position->GetX() > 900/9) && pathToRecharge == false){
		travelDestination->SetX(rechargeLocation.GetX());
		travelDestination->SetY(rechargeLocation.GetY());
		travelDestination->SetZ(rechargeLocation.GetZ());
		pathToRecharge = true;
		std::cout << "Returning to recharge station\n";
	}
	// std::cout << "X: " << position->GetX() << "  Z: " << position->GetZ() << "  pathToRecharge: " << pathToRecharge << "\n";
	
	PatrolMovement(*travelDestination).MovePath(position, direction, velocity);
}

void SearchAndRescue::Rescue(Point3* position, Vector3* direction, Vector3* velocity, const Point3& dest) {
	/* MovementStrategy *goto_entity = new Beeline(dest);

	roko.SetMovementPattern(goto_entity);
	roko.movement_pattern->MovePath(Point3 &pos); */

	BeelineMovement(dest).MovePath(position, direction, velocity);
}

