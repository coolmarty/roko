#ifndef MANUAL_MOVEMENT_H_
#define MANUAL_MOVEMENT_H_
 #include "vector3.h"

class ManualMovement {
public:
	ManualMovement();
	// Inherited MovePath ??
	void AlterVelocity(Vector3& dir, Vector3& vec);
	void ChangeKeys(char* arr);
	

private:
	char keys[4];
};

#endif
