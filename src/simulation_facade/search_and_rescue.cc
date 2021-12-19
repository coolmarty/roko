#include "search_and_rescue.h"
#include <iostream>

SearchAndRescue::SearchAndRescue() : found(false), node(Point3(-1000, 80, -1000)), rechargeLocation(Point3(50, 0, 20)), pathToRecharge(false), turn(0) { }

SearchAndRescue::~SearchAndRescue() {
}

void SearchAndRescue::NextNode(Point3* position, Point3* savedNode, int* currentDirection){
	int rotations = 16; // the number of times the drone will travel around the map before looping. Preferrably divisible by 4
	if(turn % rotations >= 0 && turn % 16 <= (rotations/4)-1){
		savedNode->SetZ(savedNode->GetZ() + 2000/(rotations/4));
	}
	else if(turn % rotations >= (rotations/4) && turn % 16 <= 2*(rotations/4)-1){
		savedNode->SetX(savedNode->GetX() + 2000/(rotations/4));
	}
	else if(turn % rotations >= 2*(rotations/4) && turn % 16 <= 3*(rotations/4)-1){
		savedNode->SetZ(savedNode->GetZ() - 2000/(rotations/4));
	}
	else if(turn % rotations >= 3*(rotations/4) && turn % 16 <= rotations-1){
		savedNode->SetX(savedNode->GetX() - 2000/(rotations/4));
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
		NextNode(position, savedDestination, travelDirection);
		travelDestination->SetX(savedDestination->GetX());
		travelDestination->SetY(savedDestination->GetY());
		travelDestination->SetZ(savedDestination->GetZ());
		pathToRecharge = false;
	}
	else if (*position == node || (position->GetZ() < -1450/22 || position->GetZ() > 1550/22 || position->GetX() < -900/9 || position->GetX() > 900/9) && pathToRecharge == false){
		travelDestination->SetX(rechargeLocation.GetX());
		travelDestination->SetY(rechargeLocation.GetY());
		travelDestination->SetZ(rechargeLocation.GetZ());
		pathToRecharge = true;
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

