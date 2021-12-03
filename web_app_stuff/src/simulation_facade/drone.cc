#include "drone.h"


Drone::Drone(){
	position = Point3();
	direction = Vector3();
	velocity = Vector3();
	acceleration = Vector3(0,9.8,0);
	time = 0;
	battery = *(new Battery());
}

Drone::Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, Vector3 newAcceleration, float newTime){
	position = newPosition;
	direction = newDirection;
	velocity = newVelocity;
	acceleration = newAcceleration;
	time = newTime;
        battery = *(new Battery());
}

Drone::Drone(const Drone& old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
	acceleration = old.acceleration;
	time = old.time;
	battery = old.battery;
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

}

void Drone::Update(float dt){

}
