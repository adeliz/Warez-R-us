#include "Shelf.h"




Shelf::Shelf(int cap, string shelfId)
{
	this->cap = cap;
	this->nrOfElements = 0;
	this->shelfId = shelfId;
	this->storage = new Item*[cap];
}

Shelf::~Shelf()
{
	delete storage;
}

bool Shelf::addItem(Item element)
{
	if(nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Item(element);
		return true;
	}

	return false;
}

Item Shelf::getFoodAt(int pos)
{
	Food* foodptr = nullptr;
	Food temp = Food("", "", "", 0, 0, "", 0);
	foodptr = dynamic_cast<Food *> (storage[pos]);
	if (foodptr != nullptr)
	{
		return *storage[pos];
	}

	return temp;
}

//bool Shelf::removeAt(int pos)
//{
//	if(pos <= nrOfElements)
//	{
//		if(pos != nrOfElements)
//		{
//			this->storage[pos] = nullptr;
//			this->storage[pos] = storage[nrOfElements];
//		}
//		else
//		{
//
//		}
//		return true;
//	}
//	return false;
//}
//
//bool Shelf::removeItem(Item element)
//{
//	for(int i = 0; i < nrOfElements; i++)
//	{
//		Food foodPtr = nullptr;
//		foodPtr = dynamic_cast<Food>(storage[i]);
//		if(foodPtr != nullptr)
//		{
//			
//		}
//
//
//	}
//	return false;
//}



