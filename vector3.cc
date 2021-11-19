#include "vector3.h"

Vector3::Vector3(){
	x = 0;
	y = 0;
	z = 0;
}

Vector3::Vector3(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

Vector3::Vector3(Vector3 old){
	x = old.x;
	y = old.y;
	z = old.z;
}

Vector3::~Vector3(){
	delete x, y, z;
}

float Vector3::GetX(){
	return x;
}
float Vector3::GetY(){
	return y;
}
float Vector3::GetZ(){
	return z;
}

void Vector3::SetX(float newx){
	x = newx;
}
void Vector3::SetY(float newy){
	y = newy;
}
void Vector3::SetZ(float newz){
	z = newz;
}