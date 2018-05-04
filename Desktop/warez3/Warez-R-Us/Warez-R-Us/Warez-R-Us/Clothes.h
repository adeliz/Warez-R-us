#ifndef CLOTHES_H
#define CLOTHES_H

#include "Item.h"


class Clothes :
	public Item
{
private:

	int size;
	string material;


public:
	Clothes(string name, string description, string brand, int weight, int price, int size, string material);
	virtual ~Clothes();

	int getSize()const;
	string getMaterial()const;


};






#endif