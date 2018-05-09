#ifndef TOOLS_H
#define TOOLS_H

#include "Item.h"

class Tools:
	public Item
{

private:
	string type;


public:
	Tools(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, string type = "");
	virtual ~Tools();

	string getType()const;

	void setType(string info);
	string toStringSpecific()const;

};

#endif
