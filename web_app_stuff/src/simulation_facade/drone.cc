#include "drone.h"

Drone::Drone(){
	position = Point3();
	direction = Direction();
	velocity = Vector3();
	// acceleration = Acceleration(0,9.8,0);
	time = 0;
}

Drone::Drone(Point3 newPosition, Direction newDirection, Vector3 newVelocity, /*Vector3 newAcceleration*/, float newTime){
	position = newPosition;
	direction = newDirection;
	velocity = newVelocity;
	// acceleration = newAcceleration;
	time = newTime;
}

Drone::Drone(Drone old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
	// acceleration = old.acceleration;
	time = old.time;
}

// Drone::~Drone(){
// 	delete position;
// 	delete direction;
// 	delete velocity;
// 	delete acceleration;
// 	delete time;
// }

// Point3 Drone::GetPosition(){
// 	return position;
// }
// Direction Drone::GetDirection(){
// 	return direction;
// }
// Vector3 Drone::GetVelocity(){
// 	return velocity;
// }
// Vector3 Drone::GetAcceleration(){
// 	return acceleration;
// }
// float Drone::GetTime(){
// 	return time;
// }

// void Drone::SetPosition(Point3 newPosition){
// 	position = newPosition;
// }
// void Drone::SetDirection(Direction newDirection){
// 	direction = newDirection;
// }
// void Drone::SetVelocity(Vector3 newVelocity){
// 	velocity = newVelocity;
// }
// void Drone::SetAcceleration(Vector3 newAcceleration){
// 	acceleration = newAcceleration;
// }
// void Drone::SetTime(float newTime){
// 	time = newTime;
// }

void Drone::Move(){
	MovePath(Point3 *position, Direction *direction, Vector3 *velocity, /*Vector3 *acceleration*/, float *dt);
}

void Drone::Update(float dt){
	
}