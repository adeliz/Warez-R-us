#include "Warehouse.h"


Warehouse::Warehouse(int nrOfShelfs)
{
	this->nrOfShelfs = nrOfShelfs;
	this->cap = 10;
	this->shelfs = new Shelf[cap];
	this->trucks = TruckManager();
}

Warehouse::~Warehouse()
{
}



int Warehouse::getNrOfShelfs()
{
	return this->nrOfShelfs;
}

int Warehouse::getNrOfLoadingZones()
{
	return this->loadingZones;
}

void Warehouse::update(bool admin)
{
	int choice = 6;
	while(choice != 0)
	{
		cout << "What do you want to do?" << endl;
		cout << "1: Add an item to a Shelf" << endl;
		cout << "2: See a map of the Warehouse" << endl;
		cout << "3. Add a truck" << endl;
		cout << "4: Look at trucks" << endl;
		cout << "5: Interact with truck" << endl;
		cout << "6: Interact with Shelf" << endl;
		cout << "7: Chat     (Does not work, no one to send to)" << endl;
		cout << "0: Exit" << endl;
		cin >> choice;
		cin.ignore();
		if(choice == 1)
		{
			if(admin == true)
			{
				cout << "Which shelf" << endl;
				for (int i = 0; i < nrOfShelfs; i++)
				{
					cout << i + 1 << ": Shelf " << i + 1;
				}
				cout << "0: Exit" << endl;
				cin >> choice;
				cin.ignore();
				if (choice != 0 && choice <= nrOfShelfs)
				{
					shelfs[choice].update(admin, 1);
				}
			}

		}

		else if (choice == 2) 
		{
			for(int i = 0; i < nrOfShelfs; i++)
			{
				cout << "Shelf: " << i << endl;
				cout << shelfs[i].getAll() << endl << endl;
			}
		}
		else if (choice == 3) 
		{
			if (admin == true)
			{
				trucks.update(admin, 2);
			}
		}
		else if (choice == 4) 
		{
			for(int i = 0; i < trucks.getNrOfTrucks(); i++)
			{
				cout << "Truck: " << i << endl;
				trucks.getTruckAt(i).toString();
			}
		}
		else if (choice == 5) 
		{
			trucks.update(admin, 1);
		}
		else if (choice == 6) 
		{
			cout << "Which shelf" << endl;
			for(int i = 0; i < nrOfShelfs; i++)
			{
				cout << i+1 << ": Shelf " << i + 1;
			}
			cout << "0: Exit" << endl;
			cin >> choice;
			cin.ignore();
			if(choice != 0 && choice <= nrOfShelfs)
			{
				shelfs[choice].update(admin, 2);
			}
		}
		else if (choice == 7) 
		{
			cout << "Under development" << endl;
		}
	}

}
