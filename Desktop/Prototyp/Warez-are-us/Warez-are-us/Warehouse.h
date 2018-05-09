#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include "TruckManager.h"
#include "Shelf.h"

class Warehouse{
private:
	int nrOfShelfs;
	int cap;
	Shelf* shelfs;
	int loadingZones;
	TruckManager trucks;

public:
	Warehouse(int nrOfShelfs = 10);
	~Warehouse();

	int getNrOfShelfs();
	int getNrOfLoadingZones();

	void update(bool admin);
};

#endif // !WAREHOUSE_H