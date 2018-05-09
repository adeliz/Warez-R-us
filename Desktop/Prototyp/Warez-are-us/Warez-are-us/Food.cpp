#include "Food.h"



Food::Food(string name, string description, string brand, int weight,  int price, string type, int size)
	:Item(name, description, brand, "Food", weight, price)
{
	this->type = type;
	this->size = size;
}

//Food::Food(const Food & other)
//	:Item(other)
//{
//	this->type = other.type;
//	this->size = other.size;
//}

Food::~Food()
{
}

string Food::getType()
{
	return this->type;
}

int Food::getSize()
{
	return this->size;
}

void Food::setType(string info)
{
	this->type = info;
}

void Food::setSize(int info)
{
	this->size = info;
}

string Food::toStringSpecific() const
{
	return this->toString() + "\nType: " + this->type + "\nSize: " + to_string(this->size);
}
