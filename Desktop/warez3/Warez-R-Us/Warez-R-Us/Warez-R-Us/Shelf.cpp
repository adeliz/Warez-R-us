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
	for(int i = 0; i < nrOfElements; i++)
	{
		delete storage[i];
	}
	delete[] storage;
}

int Shelf::getNrOf()
{
	return this->nrOfElements;
}

bool Shelf::addFood(string name, string description, string brand, int weight, int price, string type, int size)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Food(name, description, brand, weight, price, type, size);
		return true;
	}

	return false;
}

bool Shelf::addTool(string name, string description, string brand, int weight, int price, string type)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Tools(name, description, brand, weight, price, type);
		return true;
	}

	return false;
}

bool Shelf::addMisc(string name, string description, string brand, int weight, int price, string type)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Misc(name, description, brand, weight, price, type);
		return true;
	}

	return false;
}

bool Shelf::addFurniture(string name, string description, string brand, int weight, int price, string type, string material, int height, int width, int lenght)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Furniture(name, description, brand, weight, price, type, material, height, width, lenght);
		return true;
	}

	return false;
}

bool Shelf::addClothes(string name, string description, string brand, int weight, int price, int size, string material)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Clothes(name, description, brand, weight, price, size, material);
		return true;
	}

	return false;
}

//#########################################################

string Shelf::getSubClass(int pos)
{
	return storage[pos]->getSubClass();
}


//#########################################################
Food* Shelf::getFoodAt(int pos)
{
	Food* foodptr = nullptr;
	Food* temp = new Food();
	foodptr = dynamic_cast<Food *> (storage[pos]);
	if (foodptr != nullptr)
	{
		return foodptr;
	}
	return temp;
}

Tools * Shelf::getToolAt(int pos)
{
	Tools* toolptr = nullptr;
	Tools* temp = new Tools();
	toolptr = dynamic_cast<Tools *> (storage[pos]);
	if (toolptr != nullptr)
	{
		return toolptr;
	}
	return temp;
}

Misc * Shelf::getMiscAt(int pos)
{
	Misc* miscptr = nullptr;
	Misc* temp = new Misc();
	miscptr = dynamic_cast<Misc *> (storage[pos]);
	if (miscptr != nullptr)
	{
		return miscptr;
	}
	return temp;
}

Furniture * Shelf::getFurnitureAt(int pos)
{
	Furniture* furnitureptr = nullptr;
	Furniture* temp = new Furniture();
	furnitureptr = dynamic_cast<Furniture *> (storage[pos]);
	if (furnitureptr != nullptr)
	{
		return furnitureptr;
	}
	return temp;
}

Clothes* Shelf::getClothesAt(int pos)
{
	Clothes* clothesptr = nullptr;
	Clothes* temp = new Clothes();
	clothesptr = dynamic_cast<Clothes *> (storage[pos]);
	if (clothesptr != nullptr)
	{
		return clothesptr;
	}
	return temp;
}

bool Shelf::removeAt(int pos)
{
	if(pos <= nrOfElements)
	{
		if(pos != nrOfElements)
		{
			this->storage[pos] = nullptr;
			this->storage[pos] = storage[nrOfElements];
		}
		else
		{

		}
		return true;
	}
	return false;
}

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


string Shelf::getAll()
{
	string returnString = "";

	for (int i = 0; i < this->getNrOf(); i++)
	{
		if (storage[i]->getSubClass() == "Food")
		{
			returnString += this->getFoodAt(i)->toString() + "\n" +"\n"; 
		}
		else if (storage[i]->getSubClass() == "Misc")
		{
			returnString += this->getMiscAt(i)->toString() + "\n" + "\n";
		}
		else if (storage[i]->getSubClass() == "Furniture")
		{
			returnString += this->getFurnitureAt(i)->toString() + "\n" + "\n";
		}
		else if (storage[i]->getSubClass() == "Tools")
		{
			returnString += this->getToolAt(i)->toString() + "\n" + "\n";
		}
		else if (storage[i]->getSubClass() == "Clothes")
		{
			returnString += this->getClothesAt(i)->toString() + "\n" + "\n";
		}
	}
	return returnString;
}


