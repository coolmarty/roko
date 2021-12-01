#ifndef VECTOR3_H_
#define VECTOR3_H_


class Vector3{
public:
	Vector3();

	Vector3(float a, float b, float c);

	Vector3(const Vector3& old);

	float GetX();
	float GetY();
	float GetZ();

	void SetX(float newx);
	void SetY(float newy);
	void SetZ(float newz);

private:
	float x, y, z;
};

#endif
