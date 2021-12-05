#ifndef MANUAL_MOVEMENT_H_
#define MANUAL_MOVEMENT_H_
 #include "drone.h"

class ManualMovement {
public:
	ManualMovement();
	// Inherited MovePath ??
	void AlterVelocity(Drone& roko);
	

private:
	char keys[4];
};

#endif
