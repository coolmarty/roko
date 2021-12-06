/**
 * @file point3.h
 *
 */
 #ifndef POINT3_H_
#define POINT3_H_

/**
 * @brief The main class for keeping track entity's of xyz positions
 *
 */
class Point3{
public:
	/**
	 * @brief Default constructor, sets x,y,z to 0
	 *
	 */
	Point3();

	/**
	 * @brief overloaded constructer to set xyz automatically
	 *
	 */
	Point3(float a, float b, float c);

	/**
	 * @brief copy constructor
	 *
	 */
	Point3(const Point3& old);

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
	
	bool operator==(const Point3& other);

	bool operator!=(const Point3& p){
		return !(p.x == this->x && p.y == this->y && this->z == p.z);
	}





private:
	float x, y, z;
};

#endif
