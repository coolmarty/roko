#include "drone.h"

Drone::Drone(){
	position = Point3();
	direction = Vector3();
	velocity = Vector3(1, 1, 1);
	time = 0;
	robotFound = Point3(-1,-1,-1);
	travelDestination = Point3(-1000, 80, -1000); //initial travelDestination is the southwest corner
	savedDestination = Point3(-1000, 80, -1000);
	travelDirection = 0;
  	battery = (Battery());
  	movementAccessor = SearchAndRescue();
	manual = false;
	battery = *(new Battery());
}

Drone::~Drone(){
    for (int i = 0; i < cameras.size(); i++) {
            delete cameras[i];
    }
}

Drone::Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime, Point3 newDestination, Point3 newSavedDestination, int newDestDirection){
	position = newPosition;
	direction = newDirection;
	velocity = newVelocity;
	time = newTime;
	robotFound = Point3(-1,-1,-1);
	travelDestination = newDestination;
	savedDestination = newSavedDestination;
	travelDirection = newDestDirection;
	battery = *(new Battery());
}

Drone::Drone(const Drone& old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
	time = old.time;
	robotFound = old.robotFound;
	travelDestination = old.travelDestination;
	travelDirection = old.travelDirection;
	battery = old.battery;
}

void Drone::TakePicture(){
}

void Drone::Move(){
	//MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity, float *dt);
}

void Drone::Update(float dt){
	
	Point3 noRobot = Point3(-1, -1, -1);

	Data storage = Data();
	storage.addData(position, velocity, acceleration, direction, time, robotFound, travelDestination, travelDirection);
	
	if (true) {
		if (robotFound == noRobot) {
			movementAccessor.Search(&position, &direction, &velocity, &travelDestination, &savedDestination, &travelDirection);
		} else {
			movementAccessor.Rescue(&position, &direction, &velocity, robotFound);
		}
	} else {
		// TODO
	}

	// time step is velocity times dt. dt has yet to be implemented properly, it's a placeholder for now
	Vector3 timeStep = Vector3(velocity.GetX() * dt,
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
