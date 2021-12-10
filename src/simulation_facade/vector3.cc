#include "vector3.h"
#include <math.h>
#include <iostream>

Vector3::Vector3(){
	x = 0;
	y = 0;
	z = 0;
}

float Vector3::Magnitude() {
	return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

Vector3 Vector3::Normalize() {
	float mag = this->Magnitude();
	std::cout << mag << std::endl;
	return Vector3(x / mag, y / mag, z / mag);
}

Vector3::Vector3(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

Vector3::Vector3(const Vector3& old){
	x = old.x;
	y = old.y;
	z = old.z;
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

Vector3 Vector3::operator*(float scalar) {
	return Vector3(x * scalar, y * scalar, z * scalar);
}