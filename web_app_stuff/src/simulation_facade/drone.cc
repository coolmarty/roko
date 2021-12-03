#include "drone.h"

<<<<<<< HEAD
=======

>>>>>>> dev
Drone::Drone(){
	position = Point3();
	direction = Vector3();
	velocity = Vector3();
<<<<<<< HEAD
	time = 0;
	robotFound = Point3(-1,-1,-1);
	travelNode = 0;
	currentNode = 0;
}

Drone::Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime, int newTravelNode, int newCurrentNode){
	position = newPosition;
	direction = newDirection;
	velocity = newVelocity;
	time = newTime;
	robotFound = Point3(-1,-1,-1);
	travelNode = newTravelNode;
	currentNode = newCurrentNode;
}

Drone::Drone(Drone old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
	time = old.time;
	robotFound = old.robotFound;
	travelNode = old.travelNode;
	currentNode = old.currentNode;
}

Point3 Drone::TakePicture(){
	return Point3(0, 0, 0);
}

void Drone::Move(){
	MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity, float *dt);
}

void Drone::Update(float dt){
	Point3 noRobot = Point3(-1, -1, -1);
	Point3 rechargeLocation = Point3(20, 0, 50);

	if(position == rechargeLocation){
		travelNode++;
		currentNode = travelNode;
	}

	if(robotFound != noRobot){
		BeelineMovement(robotFound);
	}
	else{
		PatrolMovement(currentNode);
	}

	// time step is velocity times dt. dt has yet to be implemented properly, it's a placeholder for now
	Vector3 timeStep = new Vector(velocity.GetX() * dt,
								  velocity.GetY() * dt,
								  velocity.GetZ() * dt);

	// takes picture (duh)
	TakePicture();

	// changes position by the time step to move it gradually forward to its destination
	position.SetX(position.GetX() + timeStep.GetX());
	position.SetY(position.GetY() + timeStep.GetY());
	position.SetZ(position.GetZ() + timeStep.GetZ());

	time += dt;
}
=======
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
>>>>>>> dev
