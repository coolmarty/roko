#ifndef MANUAL_MOVEMENT_H_
#define MANUAL_MOVEMENT_H_
 #include "vector3.h"

class ManualMovement {
public:
	ManualMovement();
	// Inherited MovePath ??
	void AlterVelocity(Vector3& dir, Vector3& vel);
	void ChangeKeys(int* arr);
	

private:
	int keys[4];
	Vector3 move_dir = Vector3(0, 1, 0);
};

#endif
