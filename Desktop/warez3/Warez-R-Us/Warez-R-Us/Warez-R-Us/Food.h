#ifndef Food_h
#define Food_h

#include "Item.h"
class Food :
	public Item
{
private:
	string type;
	int size;

public:
	Food(string name, string description, int weight, string brand, int price, string type, int size);
	virtual ~Food();

	string getType();
	int getSize();
};

#endif