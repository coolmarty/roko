#include "direction.h"


Direction::Direction(){
	horizontalAngle = 0;
	verticalAngle = 0;
}

Direction::Direction(float horizontal, float vertical){
	horizontalAngle = horizontal % 360;
	verticalAngle = vertical % 360;
}

Direction::Direction(Direction old){
	horizontalAngle = old.horizontalAngle;
	verticalAngle = old.verticalAngle;
}

Direction::~Direction(){
	delete horizontalAngle, verticalAngle;
}

float Direction::GetHorizontalAngle(){
	return horizontalAngle;
}
float Direction::GetVerticalAngle(){
	return verticalAngle;
}

void Direction::SetHorizontalAngle(float newAngle){
	horizontalAngle = newAngle % 360;
}
void Direction::SetVerticalAngle(float newAngle){
	verticalAngle = newAngle % 360;
}