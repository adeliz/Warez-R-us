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
	Clothes(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, int size = 0, string material = "");
	virtual ~Clothes();

	int getSize()const;
	string getMaterial()const;
	string toStringSpecific()const;

};

#endif