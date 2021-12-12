#ifndef MANUAL_MOVEMENT_H_
#define MANUAL_MOVEMENT_H_
#include "vector3.h"
#include "matrix3.h"

class ManualMovement {
public:
	ManualMovement();
	// Inherited MovePath ??
	void AlterVelocity(Vector3& dir, Vector3& vel);
	void ChangeKeys(int* arr);
	

private:
	int keys[4];
	
	Matrix3 xPosRot;
	Matrix3 yPosRot;
	Matrix3 zPosRot;
	Matrix3 xNegRot;
	Matrix3 yNegRot;
	Matrix3 zNegRot;
	
	Matrix3 toWorld;
};

#endif
