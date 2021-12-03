#ifndef POINT3_H_
#define POINT3_H_


class Point3{
public:
	Point3();

	Point3(float a, float b, float c);

	Point3(const Point3 &old);

	~Point3();

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