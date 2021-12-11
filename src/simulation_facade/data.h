/**
 * @file data.h
 *
 */
#ifndef DATA_H_
#define DATA_H_

#include <cstring>
#include <string>
#include <iostream>
#include "vector3.h"
#include "point3.h"
/**
 * @brief The main class for data collection
 *
 */
class Data{
public:
	/**
	 * @brief Default constructor, initializes filename to basilisk-data-collection
	 *
	 */
	Data();

	/**
	 * @brief Constructor, allows user to pick a file name
	 *
	 */
	Data(std::string newFilename);

	/**
	 * @brief Opens the file
	 *
	 */
	void openFile();

	/**
	 * @brief Closes the file
	 *
	 */
	void closeFile();

	/**
	 * @brief Adds a line of data to the file
	 *
	 */
	void addData(Point3 position,
  				 Vector3 velocity,
				 Vector3 acceleration,
				 Vector3 direction,
				 float time,
				 Point3 robotFound,
				 Point3 travelDestination,
				 int travelDirection);

private:
	std::string filename;
	// ofstream file;
};

#endif
