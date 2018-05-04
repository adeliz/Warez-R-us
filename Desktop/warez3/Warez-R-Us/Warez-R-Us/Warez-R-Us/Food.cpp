#include "Food.h"



Food::Food(string name, string description, string brand, int weight,  int price, string type, int size)
	:Item(name, description, brand, weight, price)
{
	this->type = type;
	this->size = size;
}

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
