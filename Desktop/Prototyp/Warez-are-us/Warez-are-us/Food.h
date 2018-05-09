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
	Food(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, string type = "", int size = 0);
	virtual ~Food();

	string getType();
	int getSize();

	void setType(string info);
	void setSize(int info);

	string toStringSpecific()const;
};

#endif
