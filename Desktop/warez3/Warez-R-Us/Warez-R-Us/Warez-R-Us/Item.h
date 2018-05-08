#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

using namespace std;

class Item
{

private:
	string name;
	string description;
	string brand;
	string subClass;
	int weight;
	int price;

public:
	Item(string name = "", string description = "", string brand = "", string subClass = "", int weight = 0, int price = 0);
	Item(const Item& other);
	~Item();

	string getName()const;
    string getDescription()const;
	string getBrand()const;
	string getSubClass()const;
	int getWeight()const;
	int getPrice()const;

	void setName(string info);
	void setDescription(string info);
	void setBrand(string info);
	void setWeight(int info);
	void setPrice(int info);

	string toString()const;
	virtual string toStringSpecific()const = 0;
};

#endif // !ITEM_H