#include "Clothes.h"

Clothes::Clothes(string name, string description, string brand, int weight, int price, int size, string material)
	: Item(name, description, brand, "Clothes", weight, price)
{
	this->size = size;
	this->material = material;
}

Clothes::~Clothes()
{
}

int Clothes::getSize() const
{
	return this->size;
}

string Clothes::getMaterial() const
{
	return this->material;
}

void Clothes::setSize(int info)
{
	this->size = info;
}

void Clothes::setMaterial(string info)
{
	this->material = info;
}

string Clothes::toStringSpecific() const
{
	return this->toString() + "\nSize: " + to_string(this->size) + "\nMaterial: " + material;
}
