#ifndef DATA_H_
#define DATA_H_

#include <cstring>
#include <string>
#include <iostream>
#include "vector3.h"
#include "point3.h"

class Data{
public:
	Data();

	Data(std::string newFilename);

	void openFile();

	void closeFile();

	void addData(Point3 position,
  				 Vector3 velocity,
				 Vector3 acceleration,
				 Vector3 direction,
				 float time,
				 Point3 robotFound,
				 int travelNode,
				 int currentNode);

private:
	std::string filename;
	// ofstream file;
};

#endif
