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
	bool removeTruck(Truck newTruck);
	Truck getTruckAt(int pos);

	//Truck* trackTruck(Truck );

};

#endif