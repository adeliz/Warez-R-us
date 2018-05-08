#ifndef MISC_H
#define MISC_H

#include "Item.h"

class Misc :
	public Item
{
private:
	string type;

public:
	Misc(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, string type = "");
	virtual ~Misc();

	string getType();

	void setType(string info);

	string toStringSpecific()const;
};



#endif
