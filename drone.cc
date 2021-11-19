#include "drone.h"

Drone::Drone(){
	position = Point3();
	direction = Direction();
	velocity = Vector3;
}

Drone::Drone(Point3 newPosition, Direction newDirection, Vector3 newVelocity){
	position = newPosition;
	direction = newDirection;
	velocity = newVelocity;
}

Drone::Drone(Drone old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
}

Drone::~Drone(){
	delete position;
	delete direction;
	delete velocity;
}

Point3 Drone::GetPosition(){
	return position;
}
Direction Drone::GetDirection(){
	return direction;
}
float Drone::GetVelocity(){
	return velocity;
}

void Drone::SetPosition(Point3 newPosition){
	position = newPosition;
}
void Drone::SetDirection(Direction newDirection){
	direction = newDirection;
}
void Drone::SetVelocity(Vector3 newVelocity){
	velocity = newVelocity;
}

void Drone::Move(){

}