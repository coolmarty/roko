#include "entity.h"
Point3 Entity::GetPosition(){return position;}

Vector3 Entity::GetVelocity(){return velocity;}

Vector3 Entity::GetAcceleration(){return acceleration;}

Vector3 Entity::GetDirection(){return direction;}

float Entity::GetTime(){return time;}

int Entity::GetId(){return id;}

float Entity::GetSpeed(){return speed;}

void Entity::SetPosition(Point3 p){position=p;}

void Entity::SetPosition(float x, float y, float z){position=Point3(x,y,z);}

void Entity::SetVelocity(Vector3 v){velocity=v;}

void Entity::SetVelocity(float x, float y, float z){velocity=Vector3(x,y,z);}

void Entity::SetAcceleration(Vector3 a){acceleration=a;}

void Entity::SetAcceleration(float x, float y, float z){acceleration=Vector3(x,y,z);}

void Entity::SetDirection(Vector3 d){direction=d;}

void Entity::SetDirection(float x, float y, float z){direction=Vector3(x,y,z);}

void Entity::SetTime(float t){time=t;}

void Entity::SetId(int new_id){id=new_id;}

void Entity::SetSpeed(float s){speed=s;}

void Entity::addCamera(Camera * camera){
	cameras.push_back(camera);
}
