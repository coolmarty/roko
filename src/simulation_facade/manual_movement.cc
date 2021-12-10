#include "manual_movement.h"
#include <iostream>

ManualMovement::ManualMovement() {
	keys[0] = 0;
	keys[1] = 0;
	keys[2] = 0;
	keys[3] = 0;
}

void ManualMovement::ChangeKeys(int* arr) {
	for (int i = 0; i < 4; i++) {
		keys[i] = arr[i];
	}
}

void ManualMovement::AlterVelocity(Vector3& dir, Vector3& vel) {
	//Vector3 dir = roko.GetDirection();
	float speed = vel.Magnitude();
	if (move_dir.Dot(vel) <= 0) {
		speed = -speed;
	} 
	// float angle = 0;
	
	// Pitch

	if (keys[0] == 1) {
		if (dir.GetY() > -1) {
			dir.SetY(dir.GetY() - 0.1);
			move_dir.SetY(move.d); // NOTE TO SELF: START FIXING HERER, facing direction seems ok for now, need to implement the movement itself though
			move_dir.SetZ();
		}
	} else if (keys[0] == -1) {
		if (dir.GetY() < 1) {
			dir.SetY(dir.GetY() + 0.1);
		}
	} else {
		if (dir.GetY() < 0.01 && dir.GetY() > -0.01) {
			dir.SetY(0);
		} else if (dir.GetY() > 0) {
			dir.SetY(dir.GetY() - 0.1);
		} else if (dir.GetY() < 0) {
			dir.SetY(dir.GetY() + 0.1);
		}
	}

/*	
	// Yaw
	if (keys[1] == 1) {
		dir.SetY(dir.GetY() + 0.01);
	} else if (keys[1] == -1) {
		dir.SetY(dir.GetY() - 0.01);
	}
*/	
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
	//roko.SetDirection(dir.Normalize());
	//dir.SetY(1 - dir.GetY());
	//roko.SetVelocity(dir.Normalize() * speed);

	// std::cout << speed << std::endl;
	// std::cout << vel.GetX() << " " << vel.GetY() << " " << vel.GetZ() << std::endl;
	// std::cout << dir.GetX() << std::endl;
	
	if (dir.Magnitude() == 0) {
		dir.SetX(0);
		dir.SetY(0);
		dir.SetZ(1);
	}
	
	Vector3 temp = move_dir.Normalize();
	// std::cout << dir.GetX() << " " << dir.GetY() << " " << dir.GetZ() << std::endl;
	// std::cout << keys[0] << " " << keys[1] << " " << keys[2] << std::endl;
	
	vel.SetX(temp.GetX() * speed);
	vel.SetY(temp.GetY() * speed);
	vel.SetZ(temp.GetZ() * speed);

}