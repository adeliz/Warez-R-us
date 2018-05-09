#include "Misc.h"

Misc::Misc(string name, string description, string brand, int weight, int price, string type)
	:Item(name, description, brand, "Misc", weight, price)
{
	this->type = type;
}

Misc::~Misc()
{
}

string Misc::getType()
{
	return this->type;
}

void Misc::setType(string info)
{
	this->type = info;
}

string Misc::toStringSpecific() const
{
	return this->toString() + "\nType: " + this->type;
}
