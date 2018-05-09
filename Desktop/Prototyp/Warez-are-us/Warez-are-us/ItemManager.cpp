#include "ItemManager.h"


ItemManager::ItemManager()
{
	this->nrOfElements = 0;
	this->cap = 10;
	this->storage = new string[cap];
}


ItemManager::~ItemManager()
{
	delete[] storage;
	delete[] amounts;
}

bool ItemManager::addItem(string info)
{
	int found = 0;
	found = this->SearchForItem(info);
	if(found != -1)
	{
		if (this->nrOfElements >= cap)
		{
			this->cap += 2;
			string* temp = new string[this->cap];
			int* temp2 = new int[cap];
			for (int i = 0; i < nrOfElements; i++)
			{
				temp[i] = storage[i];
				temp2[i] = amounts[i];
			}
			delete[] amounts;
			delete[] storage;
			storage = temp;
			amounts = temp2;
		}
		this->storage[nrOfElements] = info;
		this->amounts[nrOfElements++] = 1;
		return true;
	}
	this->increaseAmount(found);
	return false;
}

void ItemManager::decreaseAmount(int pos)
{
	this->amounts[pos]--;
}

void ItemManager::increaseAmount(int pos)
{
	this->amounts[pos]++;
}

int ItemManager::SearchForItem(string info)
{
	for(int i = 0; i < nrOfElements; i++)
	{
		if(storage[i] == info)
		{
			return 1;
		}
	}
	return -1;
}

