#include "search_and_rescue.h"

SearchAndRescue::SearchAndRescue() : found(false), travelNode(0), currentNode(-1), rechargeLocation(Point3(20, 0, 50)) { }

SearchAndRescue::~SearchAndRescue() {
}

void SearchAndRescue::Search(Point3* position, Vector3* direction, Vector3* velocity) {
	/*MovementStrategy *initialize_pattern = new SearchPattern();

	roko.SetMovementPattern(initialize_pattern);
	roko.movement_pattern->MovePath(Point3 *pos); */
	
	if (*position == rechargeLocation) {
		travelNode++;
		currentNode = travelNode;
	}
	
	PatrolMovement(currentNode).MovePath(position, direction, velocity);
}

void SearchAndRescue::Rescue(Point3* position, Vector3* direction, Vector3* velocity, const Point3& dest) {
	/* MovementStrategy *goto_entity = new Beeline(dest);

	roko.SetMovementPattern(goto_entity);
	roko.movement_pattern->MovePath(Point3 &pos); */

	BeelineMovement(dest).MovePath(position, direction, velocity);
}

void SearchAndRescue::SetTNode(int newNode) { travelNode = newNode; }

void SearchAndRescue::SetCNode(int newNode) { currentNode = newNode; }
	
int SearchAndRescue::GetTravel() { return travelNode; }

int SearchAndRescue::GetCurrent() { return currentNode; }