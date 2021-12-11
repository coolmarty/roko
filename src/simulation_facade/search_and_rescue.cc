#include "search_and_rescue.h"

SearchAndRescue::SearchAndRescue() : found(false), node(Point3(-1450, 0, -900)), savedNode(Point3(-900, 0, -1450)), nodeDirection(0), rechargeLocation(Point3(50, 0, 20)) { }

SearchAndRescue::~SearchAndRescue() {
}

void SearchAndRescue::NextNode(Point3* position){
	Point3 edgePoints[4] = {Point3(-900,0,1550), Point3(900,0,1550), Point3(900, 0, -1450), Point3(-00, 0, -1450)};
	if(*position == edgePoints[nodeDirection % 4]){
		nodeDirection++;
	}
	if(nodeDirection % 4 == 0){
		savedNode.SetZ(node.GetZ() + 10);
	}
	else if(nodeDirection % 4 == 1){
		savedNode.SetX(node.GetX() + 10);
	}
	else if(nodeDirection % 4 == 2){
		savedNode.SetZ(node.GetZ() - 10);
	}
	else if(nodeDirection % 4 == 3){
		savedNode.SetX(node.GetX() - 10);
	}
}

void SearchAndRescue::Search(Point3* position, Vector3* direction, Vector3* velocity) {
	/*MovementStrategy *initialize_pattern = new SearchPattern();

	roko.SetMovementPattern(initialize_pattern);
	roko.movement_pattern->MovePath(Point3 *pos); */
	
	if (*position == rechargeLocation) {
		NextNode(position);
		node = savedNode;
	}
	else if (*position == node || position->GetZ() < -1450 || position->GetZ() > 1550 || position->GetX() < -900 || position->GetX() > 900){
		node = rechargeLocation;
	}
	
	PatrolMovement(node).MovePath(position, direction, velocity);
}

void SearchAndRescue::Rescue(Point3* position, Vector3* direction, Vector3* velocity, const Point3& dest) {
	/* MovementStrategy *goto_entity = new Beeline(dest);

	roko.SetMovementPattern(goto_entity);
	roko.movement_pattern->MovePath(Point3 &pos); */

	BeelineMovement(dest).MovePath(position, direction, velocity);
}

