#ifndef POINT3_H_
#define POINT3_H_

#include <cstring>
#include <fstring>
#include <iostream>

class Data{
public:
	Data();

	Data(string newFilename);

	void openFile();

	void closeFile();

	void addData(Point3 position,
  				 Vector3 velocity,
				 Vector3 acceleration,
				 Vector3 direction,
				 float time=0,
				 Point3 robotFound,
				 int travelNode,
				 int currentNode);

private:
	string filename;
	ofstream file;
};

#endif
