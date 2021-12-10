#ifndef MANUAL_MOVEMENT_H_
#define MANUAL_MOVEMENT_H_
 #include "vector3.h"

class ManualMovement {
public:
	ManualMovement();
	// Inherited MovePath ??
	void AlterVelocity(Vector3& dir, Vector3& vel);
	void ChangeKeys(char* arr);
	


	char keys[4];
};

#endif
