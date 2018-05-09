#include "TruckManager.h"



TruckManager::TruckManager()
{
	this->nrOfTrucks = 0;
	this->cap = 10;
	this->trucks = new Truck[cap];
}

TruckManager::~TruckManager()
{
//	delete[] this->trucks;
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
	if (this->nrOfTrucks >= cap)
	{
		this->cap += 2;
		Truck* temp = new Truck[this->cap];
		for (int i = 0; i < nrOfTrucks; i++)
		{
			temp[i] = trucks[i];
		}
		delete[] trucks;
		trucks = temp;
	}
	this->trucks[nrOfTrucks++] = newTruck;
	return true;
}

bool TruckManager::addTruck(string id, string destination, int velocity, int locationX, int locationY, int cap, int temp)
{
	if (this->nrOfTrucks >= cap)
	{
		this->cap += 2;
		Truck* temp = new Truck[this->cap];
		for (int i = 0; i < nrOfTrucks; i++)
		{
			temp[i] = trucks[i];
		}
		delete[] trucks;
		trucks = temp;
	}
	this->trucks[nrOfTrucks++] = Truck(id, destination, velocity, locationX, locationY, cap, temp);
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

void TruckManager::update(bool admin, int action)
{
	string id = "";
	string destination = "";
	int velocity = 0;
	int locationX = 0;
	int locationY = 0;
	int cap = 0;
	int temperature = 0;

	int choice = -1;
	if(action == 1)
	{
		while(choice != 0)
		{
			cout << "Which truck?" << endl;
			for(int i = 0; i < nrOfTrucks; i++)
			{
				cout << i << ": Truck " << i+1 << endl;
			}
			cout << "0: Exit" << endl;
			cin >> choice;
			cin.ignore();
			if(choice != 0)
			{
				trucks[choice].update();
			}
		}
	}
	else if (action == 2)
	{
		while (choice != 0)
		{
			cout << "Enter the trucks information" << endl;
			cout << "Id? " << endl;
			cin.ignore();
			getline(cin, id);
			cout << "Destination? " << endl;
			getline(cin, id);
			cout << "Velocity?" << endl;
			cin >> velocity;
			cin.ignore();
			cout << "LocationX?" << endl;
			cin >> locationX;
			cin.ignore();
			cout << "locationY" << endl;
			cin >> locationY;
			cin.ignore();
			cout << "Cap?" << endl;
			cin >> cap;
			cin.ignore();
			cout << "Temperature?" << endl;
			cin >> temperature;
			cin.ignore();
			this->addTruck(id, destination, velocity, locationX, locationY, cap, temperature);
			choice = 0;
		}
	}

}
