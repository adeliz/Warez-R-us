#ifndef MISC_H
#define MISC_H

#include "Item.h"

class Misc :
	public Item
{
private:
	string type;

public:
	Misc(string name, string description, string brand, int weight, int price, string type);
	virtual ~Misc();

	string getType();

};



#endif
