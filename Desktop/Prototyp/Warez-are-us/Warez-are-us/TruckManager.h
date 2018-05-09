#ifndef TruckManager_h
#define TruckManager_h

#include "Truck.h"
#include <vector>

class TruckManager
{
private:
	int nrOfTrucks;
	int cap;
	Truck* trucks;

public:
	TruckManager();
	virtual ~TruckManager();
	int getNrOfTrucks();

	string list();
	bool addTruck(Truck newTruck);
	bool addTruck(string id, string destination, int velocity, int locationX, int locationY, int cap, int temp);
	bool removeTruck(Truck newTruck);
	Truck getTruckAt(int pos);

	//Truck* trackTruck(Truck );

	void update(bool admin, int action);
};

#endif