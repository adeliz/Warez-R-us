#include "Tools.h"

Tools::Tools(string name, string description, string brand, int weight, int price, string type)
	: Item(name, description, brand, weight, price)
{
	this->type = type;
}

Tools::~Tools()
{
}

string Tools::getType() const
{
	return this->type;
}
