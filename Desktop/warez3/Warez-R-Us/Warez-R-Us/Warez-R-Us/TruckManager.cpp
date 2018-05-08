#include "TruckManager.h"



TruckManager::TruckManager()
{
	this->nrOfTrucks = 0;
	this->cap = 10;
	this->trucks = new Truck[cap];
}


TruckManager::~TruckManager()
{
}

int TruckManager::getNrOfTrucks()
{
	return this->nrOfTrucks;
}

string TruckManager::list()
{
	string returnString = "";
	for(int i = 0; i < this->nrOfTrucks; i++)
	{
		returnString += trucks[i].getID() + "\n";
	}
	return returnString;
}

bool TruckManager::addTruck(Truck newTruck)
{
	if(this->nrOfTrucks >= cap)
	{
		this->cap += 2;
		Truck* temp = new Truck[this->cap];
		for(int i = 0; i < nrOfTrucks; i++)
		{
			temp[i] = trucks[i];
		}
		delete trucks;
		trucks = temp;
	}
	this->trucks[nrOfTrucks++] = newTruck;
	return true;
}

bool TruckManager::removeTruck(Truck Truck)
{
	bool found = false;
	for(int i = 0; i < nrOfTrucks && found == false; i++)
	{
		if(this->trucks[i].getID() == Truck.getID())
		{
			if(i != nrOfTrucks)
			{
				trucks[i] = trucks[nrOfTrucks];
				trucks[nrOfTrucks--];
			}
		}
	}
	return false;
}

Truck TruckManager::getTruckAt(int pos)
{
	return trucks[pos];
}
