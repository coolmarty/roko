#include "entity.h"
Point3 Entity::GetPosition(){return position;}

Vector3 Entity::GetVelocity(){return velocity;}

Vector3 Entity::GetAcceleration(){return acceleration;}

Vector3 Entity::GetDirection(){return direction;}

float Entity::GetTime(){return time;}

void Entity::SetPosition(Point3 p){position=p;}

void Entity::SetVelocity(Vector3 v){velocity=v;}

void Entity::SetAcceleration(Vector3 a){acceleration=a;}

void Entity::SetDirection(Vector3 d){direction=d;}

void Entity::SetTime(float t){time=t;}
