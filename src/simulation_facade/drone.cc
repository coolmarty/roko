#include "drone.h"

Drone::Drone(){
	position = Point3();
	direction = Vector3(0, 0, 1);
	velocity = Vector3();
	time = 0;
	robotFound = Point3(-1,-1,-1);
/*
	travelNode = 0;
	currentNode = 0;
*/
	movementAccessor = SearchAndRescue();
	manual = false;
	manualMove = ManualMovement();
	battery = *(new Battery());
}

Drone::~Drone(){
    for (int i = 0; i < cameras.size(); i++) {
            delete cameras[i];
    }
}

Drone::Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, float newTime, int newTravelNode, int newCurrentNode){
	position = newPosition;
	direction = Vector3(0,0,1);//newDirection;
	velocity = newVelocity;
	time = newTime;
	robotFound = Point3(-1,-1,-1);
	travelNode = newTravelNode;
	currentNode = newCurrentNode;
	battery = *(new Battery());
}

Drone::Drone(const Drone& old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
	time = old.time;
	robotFound = old.robotFound;
	travelNode = old.travelNode;
	currentNode = old.currentNode;
	battery = old.battery;
}

void Drone::TakePicture(){
}

void Drone::Move(){
	//MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity, float *dt);
}

void Drone::SetKeys(char* arr) {
	this->manualMove.ChangeKeys(arr);
}

void Drone::Update(float dt){
	
	Point3 noRobot = Point3(-1, -1, -1);

	Data storage = Data();
	storage.addData(position, velocity, acceleration, direction, time, robotFound, travelNode, currentNode);
	
	if (false) {
		if (robotFound == noRobot) {
			movementAccessor.Search(&position, &direction, &velocity);
		} else {
			movementAccessor.Rescue(&position, &direction, &velocity, robotFound);
		}
		
		if (manualMove.keys[1] == 1) {
			std::cout << "registered" << std::endl;
		}
		// std::cout << manualMove.keys[0] << std::endl;
	} else {
		//std::cout << velocity.GetX() << " " << velocity.GetY() << " " << velocity.GetZ() << std::endl;
		 manualMove.AlterVelocity(direction, velocity);
	}

/*
	if(position == rechargeLocation){
		travelNode++;
		currentNode = travelNode;
	}

	if(robotFound != noRobot){
	// BeelineMovement(robotFound);

	}
	else{
	PatrolMovement(currentNode);
	}
*/



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
/*
	velocity.SetX(0);
	velocity.SetY(0);
	velocity.SetZ(0);
*/
	time += dt;
}
