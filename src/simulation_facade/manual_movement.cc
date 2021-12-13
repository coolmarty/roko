#include "manual_movement.h"
#include <iostream>
#include <math.h>

std::ostream& operator<<(std::ostream& os, const Matrix3& cur) {
	os << "[[";
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			os << " " << cur.GetIJ(i, j) << ",";
		}
		os << std::endl << "  ";
	}
	os << " " << cur.GetIJ(2, 0) << ", " << cur.GetIJ(2, 1) << ", " << cur.GetIJ(2, 2) << " ]]" << std::endl;
	return os;
}

ManualMovement::ManualMovement() {
	keys[0] = 0;
	keys[1] = 0;
	keys[2] = 0;
	keys[3] = 0;
	
	float xPosAr[9] = {1, 0, 0, 0, cos(0.05), -sin(0.05), 0, sin(0.05), cos(0.05)};
	float yPosAr[9] = {cos(0.05), 0, sin(0.05), 0, 1, 0, -sin(0.05), 0, cos(0.05)};
	float zPosAr[9] = {cos(0.05), -sin(0.05), 0, sin(0.05), cos(0.05), 0, 0, 0, 1};
	
	float xNegAr[9] = {1, 0, 0, 0, cos(-0.05), -sin(-0.05), 0, sin(-0.05), cos(-0.05)};
	float yNegAr[9] = {cos(-0.05), 0, sin(-0.05), 0, 1, 0, -sin(-0.05), 0, cos(-0.05)};
	float zNegAr[9] = {cos(-0.05), -sin(-0.05), 0, sin(-0.05), cos(-0.05), 0, 0, 0, 1};
	
	float identity[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	toWorld = Matrix3(identity);
	
	ang = 0;
	flag = false;
	
	xPosRot = Matrix3(xPosAr); // Pitch?
	yPosRot = Matrix3(yPosAr); // Yaw?
	zPosRot = Matrix3(zPosAr);
	xNegRot = Matrix3(xNegAr);
	yNegRot = Matrix3(yNegAr);
	zNegRot = Matrix3(zNegAr);
}

void ManualMovement::ChangeKeys(int* arr) {
	for (int i = 0; i < 4; i++) {
		keys[i] = arr[i];
	}
}

void ManualMovement::AlterVelocity(Vector3& dir, Vector3& vel) {
	if (dir.Magnitude() == 0) {
		dir.SetX(0);
		dir.SetY(0);
		dir.SetZ(1);
	}
	
	
	//Vector3 dir = roko.GetDirection();
	float speed = vel.Magnitude();
	Vector3 move_dir;
	if (flag) {
		speed = -speed;
	}
	//std::cout << move_dir.GetX() << " " << move_dir.GetY() << " " << move_dir.GetZ() << std::endl;
	// Pitch
	if (keys[0] == 1) {
		if (dir.GetY() > -0.97) {
			dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
			dir = xPosRot * dir;
			dir = Matrix3(ang, 'y') * dir;
		} else {
			dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
			dir = Matrix3(-atan(dir.GetZ() / dir.GetY())-0.001, 'x') * dir;
			dir = Matrix3(ang, 'y') * dir;
		}
	} else if (keys[0] == -1) {
		if (dir.GetY() < 0.97) {
			dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
			dir = xNegRot * dir;
			dir = Matrix3(ang, 'y') * dir;
			//ang = 0;
		} else {
			dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
			dir = Matrix3(-atan(dir.GetZ() / dir.GetY())-0.001, 'x') * dir;
			dir = Matrix3(ang, 'y') * dir;
		}
	} else {
		if (dir.GetY() < 0.05 && dir.GetY() > -0.05) {
			dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
			dir = Matrix3(atan(dir.GetY() / dir.GetZ()), 'x') * dir;
			dir = Matrix3(ang, 'y') * dir;
		} else if (dir.GetY() > 0.05) {
			dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
			dir = xPosRot * dir;
			dir = Matrix3(ang, 'y') * dir;
		} else if (dir.GetY() < -0.05) {
			dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
			dir = xNegRot * dir;
			dir = Matrix3(ang, 'y') * dir;
		}		
	}

	
	// Yaw

	if (keys[1] == 1) {
		dir = yNegRot * dir;
		ang -= 0.05;
		if (ang < -2 * M_PI) {
			ang += 2 * M_PI;
		}
	} else if (keys[1] == -1) {
		dir = yPosRot * dir;
		ang += 0.05;
		if (ang >= 2 * M_PI) {
			ang -= 2 * M_PI;
		}
	}
	

	// Thrust/Elevation
	if (keys[2] == 1) {
		if (speed < 4) {
			speed += 0.1;
		}
	} else if (keys[2] == -1) {
		if (speed > -4) {
			speed -= 0.1;
		}
	} else {
		if (speed > 0) {
			speed -= 0.1;
		} else if (speed < 0) {
			speed += 0.1;
		}
	}
	
	if (speed > 0) {
		flag = false;
	} else if (speed < 0) {
		flag = true;
	}
	
	// Roll
/*
	if (keys[3] == 1) {
		if (angle >= 360) {
			angle = 0;
		}
		angle += 10;
	} else if (keys[3] == -1) {
		if (speed <= -360) {
			angle = 0;
		}
		angle -= 10;
	}
*/	
	
	
/*
	Vector3 testa = Vector3(3,4,5);
	float arr[9] = {1, 0, 0, 0, cos(20), -sin(20), 0, sin(20), cos(20)};
	Matrix3 testy = Matrix3(arr);
	Vector3 testb = testy * testa;
	std::cout << testb.GetX() << " " << testb.GetY() << " " << testb.GetZ() << std::endl;
*/	
	
	
	
	/*
	dir = dir.Normalize();
	move_dir = move_dir.Normalize();
	vel = move_dir * speed;
	*/
	
	//Vector3 move_dir = (Matrix3((2 * M_PI) - ang, 'y') * dir);
	move_dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
	move_dir = Matrix3(-(M_PI / 2), 'x') * move_dir;
	move_dir = Matrix3(ang, 'y') * move_dir;
	
	dir = Matrix3((M_PI * 2) - ang, 'y') * dir;
	dir = Matrix3(-(M_PI / 2), 'x') * dir;
	dir = Matrix3(ang, 'y') * dir;
	
	//move_dir = (Matrix3(ang, 'y') * move_dir);
	//std::cout << move_dir.GetX() << " " << move_dir.GetY() << " " << move_dir.GetZ() << std::endl;
	//std::cout << speed << std::endl;
	vel.SetX(move_dir.GetX() * speed);
	vel.SetY(move_dir.GetY() * speed);
	vel.SetZ(move_dir.GetZ() * speed);

}