/**
 * @file point3.h
 *
 */

#ifndef MATRIX3_H_
#define MATRIX3_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "vector3.h"
#include <array>

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
 /**
 * @brief Class used for storage and relevant use of matrices, 3x3 square matrices specifically
 *
 * 
 */
class Matrix3 {
private:
	std::array<float, 9> arr;

public:
	/**
	 * @brief Default constructor, sets float array to all 0's
	 *
	 */
	Matrix3();
	
	/**
	 * @brief Constructor, sets array based on input
	 *
	 */
	Matrix3(float newArr[9]);
	
	/**
	 * @brief Creates a rotation matrix about an axis (x, y, or z) of angle radians
	 *
	 */
	Matrix3(float angle, char axis);
	
	/**
	 * @brief Returns the ith column, jth row entry
	 *
	 */
	float GetIJ(int i, int j) const;
	
	/**
	 * @brief Sets the ith column, jth row entry
	 *
	 */
	void SetIJ(int i, int j, float newVal);
	
	
	/**
	 * @brief Allows multiplication with vectors
	 *
	 */
	Vector3 operator*(Vector3& oth);
	
	/**
	 * @brief Allows multiplication with other matrices
	 *
	 */
	Matrix3 operator*(const Matrix3& oth);
};

#endif