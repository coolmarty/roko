#include "manual_movement.h"
#include <iostream>

ManualMovement::ManualMovement() {
	keys[0] = 0;
	keys[1] = 0;
	keys[2] = 0;
	keys[3] = 0;
}

void ManualMovement::ChangeKeys(char* arr) {
	for (int i = 0; i < 4; i++) {
		keys[i] = arr[i];
	}
}

void ManualMovement::AlterVelocity(Vector3& dir, Vector3& vel) {
	//Vector3 dir = roko.GetDirection();
	float speed = vel.Magnitude();
	float angle = 0;
	
	// Pitch
	if (keys[0] == 1) {
		if (dir.GetZ() > -1) {
			dir.SetZ(dir.GetZ() - 0.01);
		}
	} else if (keys[0] == -1) {
		if (dir.GetZ() < 1) {
			dir.SetZ(dir.GetZ() + 0.01);
		}
	} else {
		if (dir.GetZ() > 0) {
			dir.SetZ(dir.GetZ() - 0.01);
		} else if (dir.GetZ() < 0) {
			dir.SetZ(dir.GetZ() + 0.01);
		}
	}
/*	
	// Yaw
	if (keys[1] == 1) {
		dir.SetY(dir.GetY() + 0.01);
	} else if (keys[1] == -1) {
		dir.SetY(dir.GetY() - 0.01);
	}
	
	// Thrust/Elevation
	if (keys[2] == 1) {
		if (speed < 4) {
			speed += 0.01;
		}
	} else if (keys[2] == -1) {
		if (speed > -4) {
			speed -= 0.01;
		}
	} else {
		if (speed <= 0) {
			speed += 0.01;
		} else if (speed >= 0) {
			speed -= 0.01;
		}
	}
	
	// Roll
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
	
	//roko.SetDirection(dir.Normalize());
	//dir.SetY(1 - dir.GetY());
	//roko.SetVelocity(dir.Normalize() * speed);
*/
	// std::cout << speed << std::endl;
	// std::cout << vel.GetX() << " " << vel.GetY() << " " << vel.GetZ() << std::endl;
	// std::cout << dir.GetX() << std::endl;
	
	Vector3 temp = dir.Normalize();
	std::cout << temp.GetX() << " " << temp.GetY() << " " << temp.GetZ() << std::endl;
	
	// vel.SetX(temp.GetX() * speed);
	// vel.SetY(temp.GetY() * speed);
	// vel.SetZ(temp.GetZ() * speed);

}