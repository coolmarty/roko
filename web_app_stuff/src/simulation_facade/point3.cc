#include "point3.h"

Point3::Point3(){
	x = 0;
	y = 0;
	z = 0;
}

Point3::Point3(float a, float b, float c){
	x = a;
	y = b;
	z = c;
}

Point3::Point3(Point3 old){
	x = old.x;
	y = old.y;
	z = old.z;
}

Point3::~Point3(){
	delete x, y, z;
}

float Point3::GetX(){
	return x;
}
float Point3::GetY(){
	return y;
}
float Point3::GetZ(){
	return z;
}

void Point3::SetX(float newx){
	x = newx;
}
void Point3::SetY(float newy){
	y = newy;
}
void Point3::SetZ(float newz){
	z = newz;
}