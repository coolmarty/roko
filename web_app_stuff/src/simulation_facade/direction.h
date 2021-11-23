#ifndef DIRECTION_H_
#define DIRECTION_H_


class Direction{
public:
	Direction();

	Direction(float horizontal, float vertical);

	Direction(Direction old);

	~Direction();

	float GetHorizontalAngle();
	float GetVerticalAngle();

	void SetHorizontalAngle(float newAngle);
	void SetVerticalAngle(float newAngle);

private:
	float horizontalAngle, verticalAngle;
}

#endif