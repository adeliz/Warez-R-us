#include "Furniture.h"

Furniture::Furniture(string name, string description, string brand, int weight, int price, string type, string material, int height, int width, int lenght)
	:Item(name, description, brand, weight, price)
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
