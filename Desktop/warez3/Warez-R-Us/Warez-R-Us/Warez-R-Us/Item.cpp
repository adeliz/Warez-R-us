#include "Item.h"



Item::Item(string name, string description, string brand, string subClass, int weight, int price)
{

	this->name = name;
	this->description = description;
	this->brand = brand;
	this->subClass = subClass;
	this->weight = weight;
	this->price = price;
}

Item::Item(const Item & other)
{
	this->name = other.name;
	this->description = other.description;
	this->brand = other.brand;
	this->weight = other.weight;
	this->price = other.price;
}

Item::~Item()
{
}

string Item::getName() const
{
	return this->name;
}

string Item::getDescription() const
{
	return this->description;
}

string Item::getBrand() const
{
	return this->brand;
}

string Item::getSubClass() const
{
	return this->subClass;
}

int Item::getWeight() const
{
	return this->weight;
}

int Item::getPrice() const
{
	return this->price;
}

string Item::toString() const
{
	return "Name: " + this->name + "\nDescription: " + this->description +
		"\nBrand: " + this->brand + "\nWeight: " + to_string(this->weight) +
		"\nPrice: " + to_string(this->price);
}

