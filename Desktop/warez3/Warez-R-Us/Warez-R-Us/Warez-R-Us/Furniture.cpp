#include "Furniture.h"

Furniture::Furniture(string name, string description, string brand, int weight, int price, string type, string material, int height, int width, int lenght)
	:Item(name, description, brand, "Furniture", weight, price)
{
	this->type = type;
	this->material = material;
	this->height = height;
	this->width = width;
	this->lenght = lenght;
}

Furniture::~Furniture()
{
}

string Furniture::getType() const
{
	return this->type;
}

string Furniture::getMaterial() const
{
	return this->material;
}

int Furniture::getHeight() const
{
	return this->height;
}

int Furniture::getWidth() const
{
	return this->width;
}

int Furniture::getLenght() const
{
	return this->lenght;
}

string Furniture::toStringSpecific() const
{
	return this->toString() + "\nType: " + this->type + "\nMaterial: " + this->material + "\nHeight: "
	+ to_string(this->height) + "\nWidth" + to_string(this->width) + "\nLenght" + to_string(this->lenght);
}
