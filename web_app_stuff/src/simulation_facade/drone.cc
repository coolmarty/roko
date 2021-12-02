#include "drone.h"

Drone::Drone(){
	position = Point3();
	direction = Direction();
	velocity = Vector3();
	time = 0;
	robotFound = Point3(-1,-1,-1);
}

Drone::Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime){
	position = newPosition;
	direction = newDirection;
	velocity = newVelocity;
	time = newTime;
	robotFound = Point3(-1,-1,-1);
}

Drone::Drone(Drone old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
	time = old.time;
}

void Drone::Move(){
	MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity, float *dt);
}

void Drone::Update(float dt){
	const Point3 noRobot = Point3(-1, -1, -1);
	if(robotFound != noRobot){
		BeelineMovement(robotFound);
	}

	// time step is velocity times dt. dt has yet to be implemented properly, it's a placeholder for now
	Vector3 timeStep = new Vector(velocity.GetX() * dt,
								  velocity.GetY() * dt,
								  velocity.GetZ() * dt);

	// changes position by the time step to move it gradually forward to its destination
	position.SetX(position.GetX() + timeStep.GetX());
	position.SetY(position.GetY() + timeStep.GetY());
	position.SetZ(position.GetZ() + timeStep.GetZ());
}