#include "matrix3.h"
#include <math.h>
#include <iostream>

Matrix3::Matrix3() {
	for (int i = 0; i < 9; i++) {
		arr[i] = 0;
	}
}
Matrix3::Matrix3(float newArr[9]) {
	for (int i = 0; i < 9; i++) {
		arr[i] = newArr[i];
	}	
}

Matrix3::Matrix3(float angle, char axis) {
	if (axis == 'x') {
		arr = {1, 0, 0, 0, cos(angle), -sin(angle), 0, sin(angle), cos(angle)};
	} else if (axis == 'y') {
		arr = {cos(angle), 0, sin(angle), 0, 1, 0, -sin(angle), 0, cos(angle)};
	} else if (axis == 'z') {
		arr = {cos(angle), -sin(angle), 0, sin(angle), cos(angle), 0, 0, 0, 1};
	} else {
		arr = {0, 0, 0, 0, 0, 0, 0, 0, 0};
		std::cout << "wrong letter; init to zero" << std::endl;
	}
}

float Matrix3::GetIJ(int i, int j) const {
	return arr[i*3 + j];
}

void Matrix3::SetIJ(int i, int j, float newVal) {
	arr[i*3 + j] = newVal;
}

Vector3 Matrix3::operator*(Vector3& oth) {
	return Vector3((oth.GetX() * arr[0] + oth.GetY() * arr[1] + oth.GetZ() * arr[2]),
					(oth.GetX() * arr[3] + oth.GetY() * arr[4] + oth.GetZ() * arr[5]),
					(oth.GetX() * arr[6] + oth.GetY() * arr[7] + oth.GetZ() * arr[8]))
	;
}

Matrix3 Matrix3::operator*(const Matrix3& oth) {
	float retArr[] = {
		((arr[0] * oth.arr[0]) + (arr[1] * oth.arr[3]) + (arr[2] * oth.arr[6])), ((arr[0] * oth.arr[1]) + (arr[1] * oth.arr[4]) + (arr[2] * oth.arr[7])), ((arr[0] * oth.arr[2]) + (arr[1] * oth.arr[5]) + (arr[2] * oth.arr[8])),
				
		((arr[3] * oth.arr[0]) + (arr[4] * oth.arr[3]) + (arr[5] * oth.arr[6])), ((arr[3] * oth.arr[1]) + (arr[4] * oth.arr[4]) + (arr[5] * oth.arr[7])), ((arr[3] * oth.arr[2]) + (arr[4] * oth.arr[5]) + (arr[5] * oth.arr[8])),
				
		((arr[6] * oth.arr[0]) + (arr[7] * oth.arr[3]) + (arr[8] * oth.arr[6])), ((arr[6] * oth.arr[1]) + (arr[7] * oth.arr[4]) + (arr[8] * oth.arr[7])), ((arr[6] * oth.arr[2]) + (arr[7] * oth.arr[5]) + (arr[8] * oth.arr[8]))
		};
	return Matrix3(retArr);
}