#include "Item.h"



Item::Item(string name, string description, string brand, int weight, int price)
{

	this->name = name;
	this->description = description;
	this->brand = brand;
	this->weight = weight;
	this->price = price;
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

int Item::getWeight() const
{
	return this->weight;
}

int Item::getPrice() const
{
	return this->price;
}

