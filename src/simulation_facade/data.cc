#include "data.h"

Data::Data(){
	filename = "basilisk-data-collection.csv";
	std::ofstream fileOUT(filename, std::ofstream::out);
	fileOUT << "Time" << ", " << 
			"Position X" << ", " << 
			"Position Y" << ", " << 
			"Position Z" << ", " << 
			"Velocity X" << ", " << 
			"Velocity Y" << ", " << 
			"Velocity Z" << ", " << 
			"Acceleration X" << ", " << 
			"Acceleration Y" << ", " << 
			"Acceleration Z" << ", " << 
			"Direction X" << ", " << 
			"Direction Y" << ", " << 
			"Direction Z" << ", " << 
			"Destination X" << ", " << 
			"Destination Y" << ", " << 
			"Destination Z" << ", " << 
			"robotFound X" << ", " << 
			"robotFound Y" << ", " << 
			"robotFound Z" << std::endl;
	fileOUT.close();
}

Data::Data(std::string newFilename){
	filename = newFilename;
	std::ofstream fileOUT(filename, std::ofstream::out);
	fileOUT << "Time" << ", " << 
			"Position X" << ", " << 
			"Position Y" << ", " << 
			"Position Z" << ", " << 
			"Velocity X" << ", " << 
			"Velocity Y" << ", " << 
			"Velocity Z" << ", " << 
			"Acceleration X" << ", " << 
			"Acceleration Y" << ", " << 
			"Acceleration Z" << ", " << 
			"Direction X" << ", " << 
			"Direction Y" << ", " << 
			"Direction Z" << ", " << 
			"Destination X" << ", " << 
			"Destination Y" << ", " << 
			"Destination Z" << ", " << 
			"robotFound X" << ", " << 
			"robotFound Y" << ", " << 
			"robotFound Z" << std::endl;
	fileOUT.close();
}

void Data::addData(Point3 position,
  				   Vector3 velocity,
				   Vector3 acceleration,
				   Vector3 direction,
				   float time,
				   Point3 robotFound,
				   Point3 travelDestination){
	std::ofstream fileOUT(filename, std::ofstream::app);
	fileOUT << time << ", " << 
			position.GetX() << ", " << 
			position.GetY() << ", " << 
			position.GetZ() << ", " << 
			velocity.GetX() << ", " << 
			velocity.GetY() << ", " << 
			velocity.GetZ() << ", " << 
			acceleration.GetX() << ", " << 
			acceleration.GetY() << ", " << 
			acceleration.GetZ() << ", " << 
			direction.GetX() << ", " << 
			direction.GetY() << ", " << 
			direction.GetZ() << ", " << 
			travelDestination.GetX() << ", " << 
			travelDestination.GetY() << ", " << 
			travelDestination.GetZ() << ", " << 
			robotFound.GetX() << ", " << 
			robotFound.GetY() << ", " << 
			robotFound.GetZ() << std::endl;
	fileOUT.close();
}