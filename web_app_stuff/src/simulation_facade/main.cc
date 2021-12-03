#include "drone.h"


int main(){
	Drone basilisk = new Drone(Point3(20, 0, 50), Vector3(0, 0, 0), Vector3(0, 0, 0), 0, 0, 0);
	while(1){
		basilisk.Update(0.01);
		cout << basilist.time << ": " << basilisk.position.GetX() << ", " << basilisk.position.GetY() << ", " << basilisk.position.GetZ() << "\n";
	}
}