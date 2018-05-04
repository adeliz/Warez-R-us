#include "Misc.h"

Misc::Misc(string name, string description, string brand, int weight, int price, string type)
	:Item(name, description, brand, weight, price)
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
