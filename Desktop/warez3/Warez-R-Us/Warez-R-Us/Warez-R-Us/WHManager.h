#ifndef WHManager_H
#define WHManager_H

#include "Warehouse.h"
#include "Usermanager.h"

class WHManager
{
private:
	int nrOfWareHouses;
	int cap;
	Warehouse* houses;
	Usermanager users;

public:
	WHManager();
	virtual ~WHManager();

	bool addUser(string name, int SSN, string gender, string username, string password, bool adminRights);
	bool addWareHouse(int nrOfShelfs);

	bool removeWareHouse(int pos);
	bool SelectWarehouse(int warehouse, bool admin);

	void update(bool admin);
	bool login();
};

#endif // !WHManager_H