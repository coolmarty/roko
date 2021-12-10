/**
 * @file vector3.h
 *
 */
 #ifndef VECTOR3_H_
#define VECTOR3_H_

/**
 * @brief The main class for keeping track entity's of xyz vectors
 *
 */
class Vector3{
public:
	/**
	 * @brief Default constructor, sets x,y,z to 0
	 *
	 */
	Vector3();

	/**
	 * @brief overloaded constructer to set xyz automatically
	 *
	 */
	Vector3(float a, float b, float c);

	/**
	 * @brief copy constructor
	 *
	 */
	Vector3(const Vector3& old);

	/**
	 * @brief The getter for x
	 *
	 */
	float GetX();

	/**
	 * @brief The getter for y
	 *
	 */
	float GetY();

	/**
	 * @brief The getter for z
	 *
	 */
	float GetZ();

	/**
	 * @brief The setter for x
	 *
	 */
	void SetX(float newx);

	/**
	 * @brief The setter for y
	 *
	 */
	void SetY(float newy);

	/**
	 * @brief The setter for z
	 *
	 */
	void SetZ(float newz);
	
	float Magnitude();

	float Dot(const Vector3& other);

	Vector3 Normalize();

	Vector3 operator*(float scalar);

private:
	float x, y, z;
};

#endif
