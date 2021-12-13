#ifndef MATRIX3_H_
#define MATRIX3_H_

#include "vector3.h"
#include <array>

class Matrix3 {
private:
	std::array<float, 9> arr;

public:
	Matrix3();
	Matrix3(float newArr[9]);
	Matrix3(float angle, char axis);
	float GetIJ(int i, int j) const;
	void SetIJ(int i, int j, float newVal);
	
	Vector3 operator*(Vector3& oth);
	Matrix3 operator*(const Matrix3& oth);
};

#endif