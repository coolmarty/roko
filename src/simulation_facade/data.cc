#include "data.h"

Data::Data(){
	filename = "basilisk-data-collection";
}

Data::Data(std::string newFilename){
	filename = newFilename;
}

void Data::openFile(){
	// file.open(filename+".csv");
}

void Data::closeFile(){
	// file.close();
}

void Data::addData(Point3 position,
  				   Vector3 velocity,
				   Vector3 acceleration,
				   Vector3 direction,
				   float time,
				   Point3 robotFound,
				   Point3 travelDestination,
				   int travelDirection){
	// file << time << ", " << 
	// 		position.GetX() << ", " << 
	// 		position.GetY() << ", " << 
	// 		position.GetZ() << ", " << 
	// 		velocity.GetX() << ", " << 
	// 		velocity.GetY() << ", " << 
	// 		velocity.GetZ() << ", " << 
	// 		acceleration.GetX() << ", " << 
	// 		acceleration.GetY() << ", " << 
	// 		acceleration.GetZ() << ", " << 
	// 		direction.GetX() << ", " << 
	// 		direction.GetY() << ", " << 
	// 		direction.GetZ() << ", " << 
	// 		travelNode << ", " << 
	// 		currentNode << ", " << 
	// 		robotFound.GetX() << ", " << 
	// 		robotFound.GetY() << ", " << 
	// 		robotFound.GetZ() << "\n";
}