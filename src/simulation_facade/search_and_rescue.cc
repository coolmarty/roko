#include "search_and_rescue.h"

SearchAndRescue::SearchAndRescue() : found(false), travelNode(0), currentNode(0), rechargeLocation(Point3(20, 0, 50)) {
	currentStrat = new PatrolMovement(0);
}

SearchAndRescue::~SearchAndRescue() {
	delete currentStrat;
}

void SearchAndRescue::Search(Point3* position, Vector3* direction, Vector3* velocity) {
	/*MovementStrategy *initialize_pattern = new SearchPattern();

	roko.SetMovementPattern(initialize_pattern);
	roko.movement_pattern->MovePath(Point3 *pos); */
	
	if (*position == rechargeLocation) {
		travelNode++;
		currentNode = travelNode;
	}
	
	PatrolMovement* strat = static_cast<PatrolMovement*>(currentStrat); 
	strat->SetNode(currentNode);
	currentStrat->MovePath(position, direction, velocity);
}

void SearchAndRescue::Rescue(Point3* position, Vector3* direction, Vector3* velocity, const Point3& dest) {
	/* MovementStrategy *goto_entity = new Beeline(dest);

	roko.SetMovementPattern(goto_entity);
	roko.movement_pattern->MovePath(Point3 &pos); */
	if (!found) {
		delete currentStrat;
		currentStrat = new BeelineMovement(dest);
		found = true;
	}
	
	currentStrat->MovePath(position, direction, velocity);
}

void SearchAndRescue::SetTNode(int newNode) { travelNode = newNode; }

void SearchAndRescue::SetCNode(int newNode) { currentNode = newNode; }
	
int SearchAndRescue::GetTravel() { return travelNode; }

int SearchAndRescue::GetCurrent() { return currentNode; }