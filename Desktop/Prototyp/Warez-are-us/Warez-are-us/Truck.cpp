#include "Truck.h"


Truck::Truck(string id, string destination, int velocity, int locationX, int locationY, int cap, int temperature)
{
	this->id = id;
	this->destination = destination;
	this->velocity = velocity;
	this->locationX = locationX;
	this->locationY = locationY;
	this->storage = new StorageUnit(cap, temperature);
}

Truck::~Truck()
{

}

string Truck::getDestination() const
{
	return this->destination;
}

string Truck::getID()
{
	return this->id;
}

string Truck::getLocation()
{
	return "Location X: " + to_string(this->locationX) + "\nLocation Y: " + to_string(this->locationY);
}

void Truck::changeDestination(string destination)
{
	this->destination = destination;
}

void Truck::changeLocationX(int pos)
{
	this->locationX = pos;
}

void Truck::changeLocationY(int pos)
{
	this->locationY = pos;
}

string Truck::toString()
{
	return "Id: " + this->id + "\nDestination: " + this->destination + "\nVelocity: " + to_string(this->velocity)
		+ "\nLocation: " + this->getLocation() + "\nTemperatur: "+ this->getStorage()->getTemp();
}

void Truck::update()
{
	int choice = -1;
	int temp = 0;
	string temp2 = "";
	int temp3 = 0;

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

	while (choice != 0)
	{
		cout << "What do you want to do?" << endl;
		cout << "1: View Truck info" << endl;
		cout << "2: Change temperature " << endl;
		cout << "3: Change destination" << endl;
		cout << "4: Change velocity" << endl;
		cout << "5: View Cargo" << endl;
		cout << "6: Change cargo data" << endl;
		cout << "7: Add Item" << endl;
		cout << "0: Exit" << endl;
		cin >> choice;
		cin.ignore();
		if(choice != 0)
		{
			if (choice == 1)
			{
				cout << "Truck" << endl;
				cout << this->toString();
			}

			else if (choice == 2) 
			{
				cout << "Insert new temperature" << endl;
				cin >> temp;
				cin.clear();
				storage->changeTemp(temp);
			}
			else if (choice == 3) 
			{
				cout << "Enter new destination" << endl;
				cin >> temp2;
				cin.clear();
				this->destination = temp2;
			}
			else if (choice == 4) 
			{
				cout << "Insert new velocity" << endl;
				cin >> temp;
				cin.clear();
				this->velocity = temp;
			}
			else if (choice == 5) 
			{
				cout << "Truck Storage" << endl;
				cout << storage->getAll() << endl;
			}
			else if (choice == 6) 
			{
				cout << "What Item you wish to change?" << endl;
				for(int i = 0; i < storage->getNrOf(); i++)
				{
					if (storage->getSubClass(i) == "Food")
					{
						cout << i+1 << ": "<< storage->getFoodAt(i)->getName() << endl << endl;
					}
					else if (storage->getSubClass(i) == "Misc")
					{
						cout << i + 1 << ": " << storage->getMiscAt(i)->getName() << endl << endl;
					}
					else if (storage->getSubClass(i) == "Furniture")
					{
						cout << i + 1 << ": " << storage->getFurnitureAt(i)->getName() << endl << endl;
					}
					else if (storage->getSubClass(i) == "Tools")
					{
						cout << i + 1 << ": " << storage->getToolAt(i)->getName() << endl << endl;
					}
					else if (storage->getSubClass(i) == "Clothes")
					{
						cout << i + 1 << ": " << storage->getClothesAt(i)->getName() << endl << endl;
					}
				}
				cout << "0: Exit" << endl;
				cin >> choice;
				cin.clear();
				if(choice != 0)
				{
					while(choice != 0)
					{
						cout << "What do you want to change?" << endl;
						cout << "1: Name" << endl;
						cout << "2: Description" << endl;
						cout << "3: brand" << endl;
						cout << "4: Weight" << endl;
						cout << "5: price" << endl;
						if (storage->getSubClass(choice) == "Food")
						{
							cout << "6: Type" << endl;
							cout << "7: Size" << endl;
							cout << "0: Exit" << endl;
							cin >> temp;
							cin.clear();
							if(temp != 0)
							{
								if(temp == 1)
								{
									cout << "What is the new name?" << endl;
									getline(cin, temp2);
									storage->getFoodAt(choice)->setName(temp2);
								}
								else if (temp == 2) 
								{
									cout << "What is the new description?" << endl;
									getline(cin, temp2);
									storage->getFoodAt(choice)->setDescription(temp2);
								}
								else if (temp == 3) 
								{
									cout << "What is the new brand?" << endl;
									getline(cin, temp2);
									storage->getFoodAt(choice)->setBrand(temp2);
								}
								else if (temp == 4)
								{
									cout << "What is the new weight?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFoodAt(choice)->setWeight(temp3);
								}
								else if (temp == 5) 
								{
									cout << "What is the new price?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFoodAt(choice)->setPrice(temp3);
								}
								else if (temp == 6)
								{
									cout << "What is the new type?" << endl;
									getline(cin, temp2);
									storage->getFoodAt(choice)->setType(temp2);
								}
								else if (temp == 7) 
								{
									cout << "What is the new Size? (int)" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFoodAt(choice)->setSize(temp3);
								}
								
							}
						}
						else if (storage->getSubClass(choice) == "Misc")
						{
							cout << "6: Type" << endl;
							cout << "0: Exit" << endl;
							cin >> temp;
							cin.clear();
							if (temp != 0)
							{
								if (temp == 1)
								{
									cout << "What is the new name?" << endl;
									getline(cin, temp2);
									storage->getMiscAt(choice)->setName(temp2);
								}
								else if (temp == 2)
								{
									cout << "What is the new description?" << endl;
									getline(cin, temp2);
									storage->getMiscAt(choice)->setDescription(temp2);
								}
								else if (temp == 3)
								{
									cout << "What is the new brand?" << endl;
									getline(cin, temp2);
									storage->getMiscAt(choice)->setBrand(temp2);
								}
								else if (temp == 4)
								{
									cout << "What is the new weight?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getMiscAt(choice)->setWeight(temp3);
								}
								else if (temp == 5)
								{
									cout << "What is the new price?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getMiscAt(choice)->setPrice(temp3);
								}
								else if (temp == 6)
								{
									cout << "What is the new type?" << endl;
									getline(cin, temp2);
									storage->getMiscAt(choice)->setType(temp2);
								}

							}
						}
						else if (storage->getSubClass(choice) == "Furniture")
						{
							cout << "6: Type" << endl;
							cout << "7: Material" << endl;
							cout << "8: Height" << endl;
							cout << "9: Width" << endl;
							cout << "10: Lenght" << endl;
							cout << "0: Exit" << endl;
							cin >> temp;
							cin.clear();
							if (temp != 0)
							{
								if (temp == 1)
								{
									cout << "What is the new name?" << endl;
									getline(cin, temp2);
									storage->getFurnitureAt(choice)->setName(temp2);
								}
								else if (temp == 2)
								{
									cout << "What is the new description?" << endl;
									getline(cin, temp2);
									storage->getFurnitureAt(choice)->setDescription(temp2);
								}
								else if (temp == 3)
								{
									cout << "What is the new brand?" << endl;
									getline(cin, temp2);
									storage->getFurnitureAt(choice)->setBrand(temp2);
								}
								else if (temp == 4)
								{
									cout << "What is the new weight?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFurnitureAt(choice)->setWeight(temp3);
								}
								else if (temp == 5)
								{
									cout << "What is the new price?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFurnitureAt(choice)->setPrice(temp3);
								}
								else if (temp == 6)
								{
									cout << "What is the new type?" << endl;
									getline(cin, temp2);
									storage->getFurnitureAt(choice)->setType(temp2);
								}
								else if (temp == 7)
								{
									cout << "What is the new Material?" << endl;
									getline(cin, temp2);
									storage->getFurnitureAt(choice)->setMaterial(temp2);
								}
								else if (temp == 8)
								{
									cout << "What is the new Height?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFurnitureAt(choice)->setHeight(temp3);
								}
								else if (temp == 9)
								{
									cout << "What is the new Width?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFurnitureAt(choice)->setWidth(temp3);
								}
								else if (temp == 10)
								{
									cout << "What is the new Lenght?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getFurnitureAt(choice)->setlenght(temp3);
								}

							}
						}
						else if (storage->getSubClass(choice) == "Tools")
						{
							cout << "6: Type" << endl;
							cout << "0: Exit" << endl;
							cin >> temp;
							cin.clear();
							if (temp != 0)
							{
								if (temp == 1)
								{
									cout << "What is the new name?" << endl;
									getline(cin, temp2);
									storage->getToolAt(choice)->setName(temp2);
								}
								else if (temp == 2)
								{
									cout << "What is the new description?" << endl;
									getline(cin, temp2);
									storage->getToolAt(choice)->setDescription(temp2);
								}
								else if (temp == 3)
								{
									cout << "What is the new brand?" << endl;
									getline(cin, temp2);
									storage->getToolAt(choice)->setBrand(temp2);
								}
								else if (temp == 4)
								{
									cout << "What is the new weight?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getToolAt(choice)->setWeight(temp3);
								}
								else if (temp == 5)
								{
									cout << "What is the new price?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getToolAt(choice)->setPrice(temp3);
								}
								else if (temp == 6)
								{
									cout << "What is the new type?" << endl;
									getline(cin, temp2);
									storage->getToolAt(choice)->setType(temp2);
								}

							}
						}
						else if (storage->getSubClass(choice) == "Clothes")
						{
							cout << "6: Material" << endl;
							cout << "7: Size" << endl;
							cout << "0: Exit" << endl;
							cin >> temp;
							cin.clear();
							if (temp != 0)
							{
								if (temp == 1)
								{
									cout << "What is the new name?" << endl;
									getline(cin, temp2);
									storage->getClothesAt(choice)->setName(temp2);
								}
								else if (temp == 2)
								{
									cout << "What is the new description?" << endl;
									getline(cin, temp2);
									storage->getClothesAt(choice)->setDescription(temp2);
								}
								else if (temp == 3)
								{
									cout << "What is the new brand?" << endl;
									getline(cin, temp2);
									storage->getClothesAt(choice)->setBrand(temp2);
								}
								else if (temp == 4)
								{
									cout << "What is the new weight?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getClothesAt(choice)->setWeight(temp3);
								}
								else if (temp == 5)
								{
									cout << "What is the new price?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getClothesAt(choice)->setPrice(temp3);
								}
								else if (temp == 6)
								{
									cout << "What is the new Material?" << endl;
									getline(cin, temp2);
									storage->getClothesAt(choice)->setMaterial(temp2);
								}
								else if (temp == 7)
								{
									cout << "What is the new Size?" << endl;
									cin >> temp3;
									cin.clear();
									storage->getClothesAt(choice)->setSize(temp3);
								}
							}
						}
					}
					choice = -1;
				}
			}
			else if (choice == 7)
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
					cin.ignore();
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
							cin.ignore();
							cout << "Price?" << endl;
							cin >> price;
							cin.ignore();
							cout << "Type?" << endl;
							getline(cin, type);
							cout << "Size?" << endl;
							cin >> size;
							cin.ignore();
							this->storage->addFood(name, description, brand, weight, price, type, size);
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
							cin.ignore();
							cout << "Price?" << endl;
							cin >> price;
							cin.ignore();
							cout << "Type?" << endl;
							getline(cin, type);
							cout << "Material?" << endl;
							getline(cin, material);
							cout << "Height?" << endl;
							cin >> heigth;
							cin.ignore();
							cout << "Width?" << endl;
							cin >> widthe;
							cin.ignore();
							cout << "Lenght?" << endl;
							cin >> lenght;
							cin.ignore();
							this->storage->addFurniture(name, description, brand, weight, price, type, material, heigth, widthe, lenght);
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
							cin.ignore();
							cout << "Price?" << endl;
							cin >> price;
							cin.ignore();
							cout << "Material?" << endl;
							getline(cin, material);
							cout << "Size?" << endl;
							cin >> size;
							cin.ignore();
							this->storage->addClothes(name, description, brand, weight, price, size, material);
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
							cin.ignore();
							cout << "Price?" << endl;
							cin >> price;
							cin.ignore();
							cout << "Type?" << endl;
							getline(cin, type);
							this->storage->addMisc(name, description, brand, weight, price, type);
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
							cin.ignore();
							cout << "Price?" << endl;
							cin >> price;
							cin.ignore();
							cout << "Type?" << endl;
							getline(cin, type);
							this->storage->addMisc(name, description, brand, weight, price, type);
						}
					}
				}
			}
			choice = -1;
		}

	}
}

int Truck::getVelocity()
{
	return this->velocity;
}

StorageUnit* Truck::getStorage()
{
	return this->storage;
}
