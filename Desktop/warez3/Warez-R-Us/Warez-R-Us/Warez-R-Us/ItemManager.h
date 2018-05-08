#ifndef ItemManager_h
#define ItemManager_h

#include "Food.h"
#include "Misc.h"
#include "Tools.h"
#include "Clothes.h"
#include "Furniture.h"
#include <string>

class ItemManager
{
private:
	int nrOfElements;
	int cap;
	string* storage;
	int* amounts;

public:
	ItemManager();
	virtual ~ItemManager();

	bool addItem(string info);
	void decreaseAmount(int pos);
	void increaseAmount(int pos);
	int SearchForItem(string info);


};

#endif