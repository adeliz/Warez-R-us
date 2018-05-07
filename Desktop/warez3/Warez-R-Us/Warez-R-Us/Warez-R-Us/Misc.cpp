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

string Misc::toStringSpecific() const
{
	return this->toString() + "\nType: " + this->type;
}
