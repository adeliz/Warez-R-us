#ifndef TOOLS_H
#define TOOLS_H

#include "Item.h"

class Tools :
	public Item
{

private:
	string type;


public:
	Tools(string name, string description, string brand, int weight, int price, string type);
	virtual ~Tools();

	string getType()const;






};



#endif
