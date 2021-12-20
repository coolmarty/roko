#include "beeline.h"
#include <cmath>
#include <iostream>

BeelineMovement::BeelineMovement(Point3 dest){
	destination = dest;
}



void BeelineMovement::MovePath(Point3 *position, Vector3 *direction, Vector3 *velocity){
	// Vector from destination to position
	Vector3 distanceVector = Vector3(destination.GetX() - position->GetX(), 
									 destination.GetY() - position->GetY(),
									 destination.GetZ() - position->GetZ());

	// calculates the length of the distance
	float distanceLength = sqrt(pow(distanceVector.GetX(),2) + 
								pow(distanceVector.GetY(),2) + 
								pow(distanceVector.GetZ(),2));

	// normalizes the distance vector
	Vector3 normalizedVector = Vector3(distanceVector.GetX()/distanceLength,
									   distanceVector.GetY()/distanceLength,
									   distanceVector.GetZ()/distanceLength);

	// sets change in direction
	direction->SetX(normalizedVector.GetX());
	direction->SetY(normalizedVector.GetY());
	direction->SetZ(normalizedVector.GetZ());

	// finds speed of velocity variable from the object
	float speed = sqrt(pow(velocity->GetX(),2) + 
					   pow(velocity->GetY(),2) + 
					   pow(velocity->GetZ(),2));

	// ensures speed is non-zero and positive
	if(speed < 0){
		speed = abs(speed);
	}else if(speed == 0){
		speed = 3;
	}

	// sets velocity to the normalized vector multiplied by speed
	velocity->SetX(normalizedVector.GetX() * speed);
	velocity->SetY(normalizedVector.GetY() * speed);
	velocity->SetZ(normalizedVector.GetZ() * speed);
}