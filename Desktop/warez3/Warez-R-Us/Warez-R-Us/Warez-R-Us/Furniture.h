#ifndef FURNITURE_H
#define FURNITURE_H

#include "Item.h"

class Furniture :
	public Item
{
private:
	string type;
	string material;
	int height;
	int width;
	int lenght;

public:
	Furniture(string name, string description, string brand, int weight, int price, string type, string material, int height, int width, int lenght);
	virtual ~Furniture();

	string getType()const;
	string getMaterial()const;
	int getHeight()const;
	int getWidth()const;
	int getLenght()const;

};

#endif