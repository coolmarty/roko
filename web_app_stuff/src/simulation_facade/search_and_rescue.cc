#include "search_and_rescue.h"

void SearchAndRescue::Search(Drone& roko) {
	MovementStrategy *initialize_pattern = new SearchPattern();

	roko.SetMovementPattern(initialize_pattern);
	roko.movement_pattern->MovePath(Point3 *pos);
}

void SearchAndRescue::Rescue(Drone roko&, const Point3 &dest) {
	MovementStrategy *goto_entity = new Beeline(dest);

	roko.SetMovementPattern(goto_entity);
	roko.movement_pattern->MovePath(Point3 &pos);
}
