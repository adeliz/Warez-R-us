#ifndef Truck_h
#define Truck_h

#include <string>
#include "StorageUnit.h"

class Truck

{
private:
	string id;
	string destination;
	int velocity;
	int locationX;
	int locationY;
	StorageUnit* storage;

public:
	Truck(string id = "", string destination = "", int velocity = 0, int locationX = 0, int locationY = 0, int cap = 10, int temperature = 20);
	virtual ~Truck();

	string getDestination()const;
	string getID();
	string getLocation();
	int getVelocity();
	StorageUnit* GetStorage();

	void changeDestination(string destination);
	void changeLocationX(int pos);
	void changeLocationY(int pos);
};

#endif