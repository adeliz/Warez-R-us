#ifndef Shelf_h
#define Shelf_h

#include "Food.h"
#include "Misc.h"
#include "Tools.h"
#include "Clothes.h"
#include "Furniture.h"

using namespace std;

class Shelf
{
private:
	int cap;
	int nrOfElements;
	Item* *storage;
	string shelfId;
public:
	Shelf(int cap = 10, string shelfId = "");
	virtual ~Shelf();

	int getNrOf();
	int getCap();

	bool addFood(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, string type = "", int size = 0);
	bool addTool(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, string type = "");
	bool addMisc(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, string type = "");
	bool addFurniture(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, string type = "", string material = "", int height = 0, int width = 0, int lenght = 0);
	bool addClothes(string name = "", string description = "", string brand = "", int weight = 0, int price = 0, int size = 0, string material = "");

	string getSubClass(int pos);

	Food* getFoodAt(int pos);
	Tools* getToolAt(int pos);
	Misc* getMiscAt(int pos);
	Furniture* getFurnitureAt(int pos);
	Clothes* getClothesAt(int pos);

	bool removeAt(int pos);

	string getAll();

	void update(bool admin, int action);
};

#endif