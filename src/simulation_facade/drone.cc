#include "drone.h"


Drone::Drone(){
	position = Point3();
	direction = Vector3();
	velocity = Vector3();
	acceleration = Vector3(0,9.8,0);
	time = 0;
  battery = (Battery());
}

Drone::Drone(Point3 newPosition, Vector3 newDirection, Vector3 newVelocity, Vector3 newAcceleration, float newTime){
	position = newPosition;
	direction = newDirection;
	velocity = newVelocity;
	acceleration = newAcceleration;
	time = newTime;
  battery = Battery();
}

Drone::Drone(const Drone& old){
	position = old.position;
	direction = old.direction;
	velocity = old.velocity;
	acceleration = old.acceleration;
	time = old.time;
	battery = old.battery;
}

Drone::~Drone(){
	for (int i = 0; i < cameras.size(); i++) {
			delete cameras[i];
	}
}

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
		this->SetJoystick(
        0,
        0,
        0,
        0
    );

		Point3 position=this->GetPosition();
		Vector3 direction = this->GetDirection();
		position.SetX(position.GetX()+speed*direction.GetX()*dt);
		position.SetY(position.GetY()+speed*direction.GetY()*dt);
		position.SetZ(position.GetZ()+speed*direction.GetZ()*dt);

		this->SetPosition(position);
		this->SetDirection(direction);

		 // Take a picture every 5 seconds with front camera
		 this->SetTime(this->GetTime()+dt);

		 if (this->GetTime()-lastPictureTime > 5.0) {
			 	 std::cout<<"taking photo"<<std::endl;
				 this->GetCamera(0)->TakePicture();
				 lastPictureTime = this->GetTime();
		 }
}
