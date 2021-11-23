#include "beeline.h"
#include <cmath>

BeelineMovement::BeelineMovement(Point3 *dest){
	destination = dest;
}


void BeelineMovement::MovePath(Point3 *position, Direction *direction, Vector3 *velocity, Vector3 *acceleration, float *dt){
	// Vector from destination to position
	Vector3 distanceVector = new Vector3(position.GetX() - destination.GetX(), 
										position.GetY() - destination.GetY(),
										position.GetZ() - destination.GetZ());

	// calculates the length of the distance
	float distanceLength = sqrt(pow(distanceVector.GetX(),2) + 
								pow(distanceVector.GetY(),2) + 
								pow(distanceVector.GetZ(),2));

	// normalizes the distance vector
	Vector3 normalizedVector = new Vector(distanceVector.GetX()/distanceLength,
										  distanceVector.GetY()/distanceLength,
										  distanceVector.GetZ()/distanceLength);

	// calculates change in angles to face destination
	float angleChangeHorizontal = atan(distance.GetZ()/distance.GetX());
	float angleChangeVertical = atan(distance.GetY()/distance.GetX());

	// sets change in angles
	direction.SetHorizontalAngle(direction.GetHorizontalAngle() + angleChangeHorizontal);
	direction.SetVerticalAngle(direction.GetVerticalAngle() + angleChangeVertical);

	// finds speed of velocity variable from the object
	float speed = sqrt(pow(velocity.GetX(),2) + 
					   pow(velocity.GetY(),2) + 
					   pow(velocity.GetZ(),2));

	// ensures speed is non-zero and positive
	if(speed <= 0){
		speed = abs(speed);
	}

	// updates position according to velocity
	position.SetX(position.GetX() + velocity.GetX());
	position.SetY(position.GetY() + velocity.GetY());
	position.SetZ(position.GetZ() + velocity.GetZ());

	// // sets velocity to the normalized vector multiplied by speed
	// velocity.SetX(normalizedVector.GetX() * speed);
	// velocity.SetY(normalizedVector.GetY() * speed);
	// velocity.SetZ(normalizedVector.GetZ() * speed);

	// // time step is velocity times dt. dt has yet to be implemented properly, it's a placeholder for now
	// Vector3 timeStep = new Vector(velocity.GetX() * dt,
	// 							  velocity.GetY() * dt,
	// 							  velocity.GetZ() * dt);

	// // changes position by the time step to move it gradually forward to its destination
	// position.SetX(position.GetX() + timeStep.GetX());
	// position.SetY(position.GetY() + timeStep.GetY());
	// position.SetZ(position.GetZ() + timeStep.GetZ());

}