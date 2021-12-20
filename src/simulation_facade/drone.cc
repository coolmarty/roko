#include "drone.h"

Drone::Drone(){
	position = Point3();
	direction = Vector3(0, 0, 1);
	velocity = Vector3(5,5,5);
	time = 0;
	robotFound = Point3(-1,-1,-1);
	travelDestination = Point3(-1000, 80, -1000); //initial travelDestination is the southwest corner
	savedDestination = Point3(-1000, 80, -1000);
	travelDirection = 0;
  	battery = (Battery());
  	movementAccessor = SearchAndRescue();
	manual = false;
	manualMove = ManualMovement();
	storage = Data();
	battery = *(new Battery(100));
	rs = new RechargeStation(Point3(50,0,20));
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
	storage = Data();
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

void Drone::SRF(Point3 r){
  robotFound = r;
}
void Drone::TakePicture(){
}

void Drone::SetKeys(int* arr) {
	if (arr[4] == 1 && swap_cooldown == 0) {
		if (manual) {
			manual = false;
			velocity.SetX(0);
			velocity.SetY(0);
			velocity.SetZ(0);
		} else {
			manual = true;
			velocity = Vector3(0,0,0);
			direction = Vector3(0,0,1);
			manualMove.SetAng(0);
		}
		swap_cooldown = 10;
	}
	if (swap_cooldown > 0) { swap_cooldown -= 1; }

	this->manualMove.ChangeKeys(arr);
}

void Drone::Update(float dt){
	std::cout << "BAttery Life: " << battery.GetBatteryLife() <<std::endl;
	Point3 noRobot = Point3(-1, -1, -1);

	Point3 rechargeLocation = Point3(50, 0, 20);




	// takes picture (duh)
	// GetCamera(0)->TakePicture();

	// BELOW ADDS DATA TO THE basilisk-data-collection.csv FILE BUT PREVENTS THE SIMULATION FROM RUNNING FAST
	// IF WE WISH TO RUN THE SIMULATION SLOWLY IN ORDER TO UPDATE DATA, UNCOMMENT THAT LINE
	// storage.addData(position, velocity, acceleration, direction, time, robotFound, travelDestination);
	
	if (!manual) {
		if (robotFound == noRobot) {
			movementAccessor.Search(&position, &direction, &velocity, &travelDestination, &savedDestination, &travelDirection);
		} else {
			movementAccessor.Rescue(&position, &direction, &velocity, robotFound);
		}
	} else {
		manualMove.AlterVelocity(direction, velocity);
	}
	if(position == rechargeLocation || (position.GetX() <= rechargeLocation.GetX()+0.05 && position.GetX() >= rechargeLocation.GetX()-0.05 && position.GetZ() <= rechargeLocation.GetZ()+0.05 && position.GetZ() >= rechargeLocation.GetZ()-0.05)){
	    rs->Recharge(&battery);
	}	  
	
	

	// time step is velocity times dt. dt has yet to be implemented properly, it's a placeholder for now
	Vector3 timeStep = Vector3(velocity.GetX() * dt,
							   velocity.GetY() * dt,
							   velocity.GetZ() * dt);

	// changes position by the time step to move it gradually forward to its destination
	position.SetX(position.GetX() + timeStep.GetX());
	position.SetY(position.GetY() + timeStep.GetY());
	position.SetZ(position.GetZ() + timeStep.GetZ());

	battery.SetBatteryLife(battery.GetBatteryLife() - dt);

	time += dt;
}
