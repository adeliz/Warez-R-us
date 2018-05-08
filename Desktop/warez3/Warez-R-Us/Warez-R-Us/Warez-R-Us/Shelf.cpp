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

int Shelf::getCap()
{
	return this->cap;
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

void Shelf::update(bool admin, int action)
{
	int choice = - 1;
	
	int temp = 0;
	string temp2 = "";

	string name = "";
	string description = "";
	string brand = "";
	int weight = 0;
	int price = 0;

	string type = "";
	string material = "";
	int size = 0;
	int heigth = 0;
	int widthe = 0;
	int lenght = 0;


	if(action == 1)
	{
		while (choice != 0)
		{
			cout << "What kind Of Item do you wanna add?" << endl;
			cout << "1: Food" << endl;
			cout << "2: Furniture" << endl;
			cout << "3: Clothes" << endl;
			cout << "4: Misc" << endl;
			cout << "5: Tools" << endl;
			cout << "0: Exit" << endl;
			cin >> choice;
			if (choice != 0)
			{
				if (choice == 1)
				{
					cout << "Enter the Food Items information" << endl;
					cout << "name? " << endl;
					getline(cin, name);
					cout << "Description? " << endl;
					getline(cin, description);
					cout << "Brand?" << endl;
					getline(cin, brand);
					cout << "Weight?" << endl;
					cin >> weight;
					cout << "Price?" << endl;
					cin >> price;
					cout << "Type?" << endl;
					getline(cin, type);
					cout << "Size?" << endl;
					cin >> size;
					this->addFood(name, description, brand, weight, price, type, size);
				}
				else if (choice == 2)
				{
					cout << "Enter the Furniture Items information" << endl;
					cout << "name? " << endl;
					getline(cin, name);
					cout << "Description? " << endl;
					getline(cin, description);
					cout << "Brand?" << endl;
					getline(cin, brand);
					cout << "Weight?" << endl;
					cin >> weight;
					cout << "Price?" << endl;
					cin >> price;
					cout << "Type?" << endl;
					getline(cin, type);
					cout << "Material?" << endl;
					getline(cin, material);
					cout << "Height?" << endl;
					cin >> heigth;
					cout << "Width?" << endl;
					cin >> widthe;
					cout << "Lenght?" << endl;
					cin >> lenght;
					this->addFurniture(name, description, brand, weight, price, type, material, heigth, widthe, lenght);
				}
				else if (choice == 3)
				{
					cout << "Enter the Clothes Items information" << endl;
					cout << "name? " << endl;
					getline(cin, name);
					cout << "Description? " << endl;
					getline(cin, description);
					cout << "Brand?" << endl;
					getline(cin, brand);
					cout << "Weight?" << endl;
					cin >> weight;
					cout << "Price?" << endl;
					cin >> price;
					cout << "Material?" << endl;
					getline(cin, material);
					cout << "Size?" << endl;
					cin >> size;
					this->addClothes(name, description, brand, weight, price, size, material);
				}
				else if (choice == 4)
				{
					cout << "Enter the Misc Items information" << endl;
					cout << "name? " << endl;
					getline(cin, name);
					cout << "Description? " << endl;
					getline(cin, description);
					cout << "Brand?" << endl;
					getline(cin, brand);
					cout << "Weight?" << endl;
					cin >> weight;
					cout << "Price?" << endl;
					cin >> price;
					cout << "Type?" << endl;
					getline(cin, type);
					this->addMisc(name, description, brand, weight, price, type);
				}
				else if (choice == 5)
				{
					cout << "Enter the Tool Items information" << endl;
					cout << "name? " << endl;
					getline(cin, name);
					cout << "Description? " << endl;
					getline(cin, description);
					cout << "Brand?" << endl;
					getline(cin, brand);
					cout << "Weight?" << endl;
					cin >> weight;
					cout << "Price?" << endl;
					cin >> price;
					cout << "Type?" << endl;
					getline(cin, type);
					this->addMisc(name, description, brand, weight, price, type);
				}
			}
		}
	}

	else if(action == 2)
	{
		int choice = -1;
		int temp = 0;
		string temp2 = "";
		int temp3 = 0;
		while (choice != 0)
		{
			cout << "What do you want to do?" << endl;
			cout << "1: View Shelf info" << endl;
			cout << "2: Change cargo data" << endl;
			cout << "0: Exit" << endl;
			cin >> choice;
			cin.ignore();
			if (choice != 0)
			{
				if (choice == 1)
				{
					cout << "Shelf" << endl;
					cout << this->getAll();
				}

				else if (choice == 2)
				{
					cout << "What Item you wish to change?" << endl;
					for (int i = 0; i < this->getNrOf(); i++)
					{
						if (this->getSubClass(i) == "Food")
						{
							cout << i + 1 << ": " << this->getFoodAt(i)->getName() << endl << endl;
						}
						else if (this->getSubClass(i) == "Misc")
						{
							cout << i + 1 << ": " << this->getMiscAt(i)->getName() << endl << endl;
						}
						else if (this->getSubClass(i) == "Furniture")
						{
							cout << i + 1 << ": " << this->getFurnitureAt(i)->getName() << endl << endl;
						}
						else if (this->getSubClass(i) == "Tools")
						{
							cout << i + 1 << ": " << this->getToolAt(i)->getName() << endl << endl;
						}
						else if (this->getSubClass(i) == "Clothes")
						{
							cout << i + 1 << ": " << this->getClothesAt(i)->getName() << endl << endl;
						}
					}
					cout << "0: Exit" << endl;
					cin >> choice;
					cin.ignore();
					if (choice != 0)
					{
						while (choice != 0)
						{
							cout << "What do you want to change?" << endl;
							cout << "1: Name" << endl;
							cout << "2: Description" << endl;
							cout << "3: brand" << endl;
							cout << "4: Weight" << endl;
							cout << "5: price" << endl;
							if (this->getSubClass(choice) == "Food")
							{
								cout << "6: Type" << endl;
								cout << "7: Size" << endl;
								cout << "0: Exit" << endl;
								cin >> temp;
								if (temp != 0)
								{
									if (temp == 1)
									{
										cout << "What is the new name?" << endl;
										getline(cin, temp2);
										this->getFoodAt(choice)->setName(temp2);
									}
									else if (temp == 2)
									{
										cout << "What is the new description?" << endl;
										getline(cin, temp2);
										this->getFoodAt(choice)->setDescription(temp2);
									}
									else if (temp == 3)
									{
										cout << "What is the new brand?" << endl;
										getline(cin, temp2);
										this->getFoodAt(choice)->setBrand(temp2);
									}
									else if (temp == 4)
									{
										cout << "What is the new weight?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFoodAt(choice)->setWeight(temp3);
									}
									else if (temp == 5)
									{
										cout << "What is the new price?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFoodAt(choice)->setPrice(temp3);
									}
									else if (temp == 6)
									{
										cout << "What is the new type?" << endl;
										getline(cin, temp2);
										this->getFoodAt(choice)->setType(temp2);
									}
									else if (temp == 7)
									{
										cout << "What is the new Size? (int)" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFoodAt(choice)->setSize(temp3);
									}

								}
							}
							else if (this->getSubClass(choice) == "Misc")
							{
								cout << "6: Type" << endl;
								cout << "0: Exit" << endl;
								cin >> temp;
								cin.ignore();
								if (temp != 0)
								{
									if (temp == 1)
									{
										cout << "What is the new name?" << endl;
										getline(cin, temp2);
										this->getMiscAt(choice)->setName(temp2);
									}
									else if (temp == 2)
									{
										cout << "What is the new description?" << endl;
										getline(cin, temp2);
										this->getMiscAt(choice)->setDescription(temp2);
									}
									else if (temp == 3)
									{
										cout << "What is the new brand?" << endl;
										getline(cin, temp2);
										this->getMiscAt(choice)->setBrand(temp2);
									}
									else if (temp == 4)
									{
										cout << "What is the new weight?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getMiscAt(choice)->setWeight(temp3);
									}
									else if (temp == 5)
									{
										cout << "What is the new price?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getMiscAt(choice)->setPrice(temp3);
									}
									else if (temp == 6)
									{
										cout << "What is the new type?" << endl;
										getline(cin, temp2);
										this->getMiscAt(choice)->setType(temp2);
									}

								}
							}
							else if (this->getSubClass(choice) == "Furniture")
							{
								cout << "6: Type" << endl;
								cout << "7: Material" << endl;
								cout << "8: Height" << endl;
								cout << "9: Width" << endl;
								cout << "10: Lenght" << endl;
								cout << "0: Exit" << endl;
								cin >> temp;
								cin.ignore();
								if (temp != 0)
								{
									if (temp == 1)
									{
										cout << "What is the new name?" << endl;
										getline(cin, temp2);
										this->getFurnitureAt(choice)->setName(temp2);
									}
									else if (temp == 2)
									{
										cout << "What is the new description?" << endl;
										getline(cin, temp2);
										this->getFurnitureAt(choice)->setDescription(temp2);
									}
									else if (temp == 3)
									{
										cout << "What is the new brand?" << endl;
										getline(cin, temp2);
										this->getFurnitureAt(choice)->setBrand(temp2);
									}
									else if (temp == 4)
									{
										cout << "What is the new weight?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFurnitureAt(choice)->setWeight(temp3);
									}
									else if (temp == 5)
									{
										cout << "What is the new price?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFurnitureAt(choice)->setPrice(temp3);
									}
									else if (temp == 6)
									{
										cout << "What is the new type?" << endl;
										getline(cin, temp2);
										this->getFurnitureAt(choice)->setType(temp2);
									}
									else if (temp == 7)
									{
										cout << "What is the new Material?" << endl;
										getline(cin, temp2);
										this->getFurnitureAt(choice)->setMaterial(temp2);
									}
									else if (temp == 8)
									{
										cout << "What is the new Height?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFurnitureAt(choice)->setHeight(temp3);
									}
									else if (temp == 9)
									{
										cout << "What is the new Width?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFurnitureAt(choice)->setWidth(temp3);
									}
									else if (temp == 10)
									{
										cout << "What is the new Lenght?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getFurnitureAt(choice)->setlenght(temp3);
									}

								}
							}
							else if (this->getSubClass(choice) == "Tools")
							{
								cout << "6: Type" << endl;
								cout << "0: Exit" << endl;
								cin >> temp;
								cin.ignore();
								if (temp != 0)
								{
									if (temp == 1)
									{
										cout << "What is the new name?" << endl;
										getline(cin, temp2);
										this->getToolAt(choice)->setName(temp2);
									}
									else if (temp == 2)
									{
										cout << "What is the new description?" << endl;
										getline(cin, temp2);
										this->getToolAt(choice)->setDescription(temp2);
									}
									else if (temp == 3)
									{
										cout << "What is the new brand?" << endl;
										getline(cin, temp2);
										this->getToolAt(choice)->setBrand(temp2);
									}
									else if (temp == 4)
									{
										cout << "What is the new weight?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getToolAt(choice)->setWeight(temp3);
									}
									else if (temp == 5)
									{
										cout << "What is the new price?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getToolAt(choice)->setPrice(temp3);
									}
									else if (temp == 6)
									{
										cout << "What is the new type?" << endl;
										getline(cin, temp2);
										this->getToolAt(choice)->setType(temp2);
									}

								}
							}
							else if (this->getSubClass(choice) == "Clothes")
							{
								cout << "6: Material" << endl;
								cout << "7: Size" << endl;
								cout << "0: Exit" << endl;
								cin >> temp;
								cin.ignore();
								if (temp != 0)
								{
									if (temp == 1)
									{
										cout << "What is the new name?" << endl;
										getline(cin, temp2);
										this->getClothesAt(choice)->setName(temp2);
									}
									else if (temp == 2)
									{
										cout << "What is the new description?" << endl;
										getline(cin, temp2);
										this->getClothesAt(choice)->setDescription(temp2);
									}
									else if (temp == 3)
									{
										cout << "What is the new brand?" << endl;
										getline(cin, temp2);
										this->getClothesAt(choice)->setBrand(temp2);
									}
									else if (temp == 4)
									{
										cout << "What is the new weight?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getClothesAt(choice)->setWeight(temp3);
									}
									else if (temp == 5)
									{
										cout << "What is the new price?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getClothesAt(choice)->setPrice(temp3);
									}
									else if (temp == 6)
									{
										cout << "What is the new Material?" << endl;
										getline(cin, temp2);
										this->getClothesAt(choice)->setMaterial(temp2);
									}
									else if (temp == 7)
									{
										cout << "What is the new Size?" << endl;
										cin >> temp3;
										cin.ignore();
										this->getClothesAt(choice)->setSize(temp3);
									}
								}
							}
						}
						choice = -1;
					}
				}
				choice = -1;
			}

		}
	}
}
