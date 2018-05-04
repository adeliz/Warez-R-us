#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item
{

private:

	string name;
	string description;
	string brand;
	int weight;
	int price;

public:
	Item(string name = "", string description = "", string brand = "", int weight = 0, int price = 0);
	~Item();

	string getName()const;
    string getDescription()const;
	string getBrand()const;
	int getWeight()const;
	int getPrice()const;

};

#endif // !ITEM_H