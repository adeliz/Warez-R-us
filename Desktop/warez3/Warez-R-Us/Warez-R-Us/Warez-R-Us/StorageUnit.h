#ifndef StorageUnit_h
#define StorageUnit_h

#include "Food.h"
#include "Misc.h"
#include "Tools.h"
#include "Clothes.h"
#include "Furniture.h"
#include <string>

using namespace std;

class StorageUnit
{
private:
	int cap;
	int nrOfElements;
	Item* *storage;
	int temperature;

	sf::Texture texture;
	sf::Sprite* spriteList;

	sf::Font font;
	sf::Text* textList;

	void load();

public:
	StorageUnit(int cap = 0, int temperature = 0);
	virtual ~StorageUnit();

	string getTemp();
	void changeTemp(int temp);

	int getNrOf();

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

	void draw(sf::RenderTarget& target, sf::RenderStates stats) const;

};

#endif