#include "StorageUnit.h"

StorageUnit::StorageUnit(int cap, int temperature)
{
	this->cap = cap;
	this->nrOfElements = 0;
	this->temperature = temperature;
	this->storage = new Item*[cap];
}

StorageUnit::~StorageUnit()
{
	for (int i = 0; i < nrOfElements; i++)
	{
		delete storage[i];
	}
	delete[] storage;
}

string StorageUnit::getTemp()
{
	return to_string(this->temperature);
}

void StorageUnit::changeTemp(int temp)
{
	this-> temperature = temp;
}

int StorageUnit::getNrOf()
{
	return this->nrOfElements;
}

bool StorageUnit::addFood(string name, string description, string brand, int weight, int price, string type, int size)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Food(name, description, brand, weight, price, type, size);
		return true;
	}

	return false;
}

bool StorageUnit::addTool(string name, string description, string brand, int weight, int price, string type)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Tools(name, description, brand, weight, price, type);
		return true;
	}

	return false;
}

bool StorageUnit::addMisc(string name, string description, string brand, int weight, int price, string type)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Misc(name, description, brand, weight, price, type);
		return true;
	}

	return false;
}

bool StorageUnit::addFurniture(string name, string description, string brand, int weight, int price, string type, string material, int height, int width, int lenght)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Furniture(name, description, brand, weight, price, type, material, height, width, lenght);
		return true;
	}

	return false;
}

bool StorageUnit::addClothes(string name, string description, string brand, int weight, int price, int size, string material)
{
	if (nrOfElements < cap)
	{
		this->storage[nrOfElements++] = new Clothes(name, description, brand, weight, price, size, material);
		return true;
	}

	return false;
}

//#########################################################

string StorageUnit::getSubClass(int pos)
{
	return storage[pos]->getSubClass();
}


//#########################################################
Food* StorageUnit::getFoodAt(int pos)
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

Tools * StorageUnit::getToolAt(int pos)
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

Misc * StorageUnit::getMiscAt(int pos)
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

Furniture * StorageUnit::getFurnitureAt(int pos)
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

Clothes* StorageUnit::getClothesAt(int pos)
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

bool StorageUnit::removeAt(int pos)
{
	if (pos <= nrOfElements)
	{
		if (pos != nrOfElements)
		{
			delete storage[pos];
			storage[pos] = storage[--nrOfElements];
			storage[nrOfElements] = nullptr;
		}
		else
		{
			cout << "Check4" << endl;
			delete storage[nrOfElements--];
		}
		return true;
	}
	return false;
}

string StorageUnit::getAll()
{
	string returnString = "";

	for (int i = 0; i < this->nrOfElements; i++)
	{
		if (storage[i]->getSubClass() == "Food")
		{
			returnString += this->getFoodAt(i)->toStringSpecific() + "\n" + "\n";
		}
		else if (storage[i]->getSubClass() == "Misc")
		{
			returnString += this->getMiscAt(i)->toStringSpecific() + "\n" + "\n";
		}
		else if (storage[i]->getSubClass() == "Furniture")
		{
			returnString += this->getFurnitureAt(i)->toStringSpecific() + "\n" + "\n";
		}
		else if (storage[i]->getSubClass() == "Tools")
		{
			returnString += this->getToolAt(i)->toStringSpecific() + "\n" + "\n";
		}
		else if (storage[i]->getSubClass() == "Clothes")
		{
			returnString += this->getClothesAt(i)->toStringSpecific() + "\n" + "\n";
		}
	}
	return returnString;
}