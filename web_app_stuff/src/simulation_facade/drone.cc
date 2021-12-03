#include "drone.h"

Drone::Drone(){
	position = Point3();
	direction = Vector3();
	velocity = Vector3();
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