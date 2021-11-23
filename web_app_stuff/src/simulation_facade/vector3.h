#ifndef VECTOR3_H_
#define VECTOR3_H_


class Vector3{
public:
	Vector3();

	Vector3(float a, float b, float c);

	Vector3(Point3 old);

	~Vector3();

	float GetX();
	float GetY();
	float GetZ();

	void SetX(float new);
	void SetY(float new);
	void SetZ(float new);

private:
	float x, y, z;
}

#endif