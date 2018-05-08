#include "WHManager.h"



WHManager::WHManager()
{
	this->nrOfWareHouses = 0;
	this->cap = 10;
	this->houses = new Warehouse[cap];
	this->users = Usermanager();
}


WHManager::~WHManager()
{
	delete[] houses;
}

bool WHManager::addUser(string name, int SSN, string gender, string username, string password, bool adminRights)
{
	return users.addUser(name, SSN, gender, username, password, adminRights);;
}

bool WHManager::addWareHouse(int nrOfShelfs)
{

	if (this->nrOfWareHouses >= cap)
	{
		this->cap += 2;
		Warehouse* temp = new Warehouse[this->cap];
		for (int i = 0; i < nrOfWareHouses; i++)
		{
			temp[i] = houses[i];
		}
		delete[] houses;
		houses = temp;
	}
	this->houses[nrOfWareHouses++] = Warehouse(nrOfShelfs);
	return true;
}

bool WHManager::removeWareHouse(int pos)
{
	if (pos <= nrOfWareHouses)
	{
		if (pos != nrOfWareHouses)
		{
			houses[pos] = houses[nrOfWareHouses--];
		}
		else
		{
			houses[nrOfWareHouses--];
		}
		return true;
	}
	return false;
}

bool WHManager::SelectWarehouse(int warehouse, bool admin)
{
	if(warehouse <= nrOfWareHouses)
	{
		this->houses[warehouse].update(admin);
		return true;
	}
	return true;
}

void WHManager::update(bool admin)
{
	int choice = 6;
	int temp = 0;
	while (choice != 0)
	{
		cout << "What do you want to do?" << endl;
		cout << "1: Enter warehouse" << endl;
		cout << "2: Add WareHouse" << endl;
		cout << "0: Exit Program" << endl;
		cin >> choice;
		cin.ignore();
		if(choice == 1)
		{
			cout << "Which warehouse?" << endl;
			for(int i = 0; i < nrOfWareHouses; i++)
			{
				cout << i << ": " << "Warehouse " << i+1;
			}
			cout << "0: Exit" << endl;
			cin >> choice;
			cin.ignore();
			if(choice != 0)
			{
				this->SelectWarehouse(choice, admin);
			}
		}
		else if(choice == 2)
		{
			cout << "How many Shelfs?" << endl;
			cin >> temp;
			cin.ignore();
			this->addWareHouse(temp);
		}
	}
}

bool WHManager::login()
{
	string username = "";
	string password = "";

	cout << "Enter your username" << endl;
	getline(cin, username);

	int pos = users.findUser(username);
	if(pos != -1)
	{
		cout << "User found!" << "\nEnter password" << endl;
		getline(cin, password);
		if(users.getUser(pos).checkPassword(password) == true)
		{
			cout << "Password cleared" << "\nUser is logged in!" << endl;
			this->update(users.getUser(pos).getAdmin());
		}

	}


	return false;
}
