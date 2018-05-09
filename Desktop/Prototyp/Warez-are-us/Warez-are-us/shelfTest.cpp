#include "Shelf.h"
#include <iostream>

int main()
{
	Shelf *shelf = new Shelf(10, "aaaa");

	
	
	shelf->addFood("Apple", "An apple", "normal", 2, 10, "green", 1);//0
	shelf->addFood("Orange", "An orange", "Fancy", 2, 100, "Sweet", 0);//1
	shelf->addClothes("Shirt", "A shirt", "Fancy", 2, 1000, 2, "Cotton");//2
	shelf->addFurniture("Table", "A table", "Ikea", 300, 900, "Cheap", "Wood", 1, 1, 1);//3
	shelf->addMisc("Void", "A void", "", 0, 0, "Abnormal");//4
	shelf->addTool("Hammer", "an Iron hammer", "Norton", 6, 200, "Standard");//5


	Food* testFood;
	Clothes* testClothes;
	Furniture* testFurniture;
	Misc* testMisc;
	Tools* testTools;


	//################################################################# Exempel 1
	//Please don't do this
	testFood = shelf->getFoodAt(1);
	testClothes = shelf->getClothesAt(2);
	testFurniture = shelf->getFurnitureAt(3);
	testMisc = shelf->getMiscAt(4);
	testTools = shelf->getToolAt(5);

	cout << testFood->toStringSpecific() << endl << endl;
	cout << testMisc->toStringSpecific() << endl << endl;
	cout << testFurniture->toStringSpecific() << endl << endl;
	cout << testClothes->toStringSpecific() << endl << endl;
	cout << testTools->toStringSpecific() << endl << endl;

	cout << "##############################################################" << endl;
	system("PAUSE");

	//################################################################# Exempel 2
	//Do this! just copy paste the loop and ifs.

	for(int i = 0; i < shelf->getNrOf(); i++)
	{
		if(shelf->getSubClass(i) == "Food")
		{
			cout << shelf->getFoodAt(i)->toString() << endl << endl;
		}
		else if (shelf->getSubClass(i) == "Misc")
		{
			cout << shelf->getMiscAt(i)->toString() << endl << endl;
		}
		else if (shelf->getSubClass(i) == "Furniture")
		{
			cout << shelf->getFurnitureAt(i)->toString() << endl << endl;
		}
		else if (shelf->getSubClass(i) == "Tools")
		{
			cout << shelf->getToolAt(i)->toString() << endl << endl;
		}
		else if (shelf->getSubClass(i) == "Clothes")
		{
			cout << shelf->getClothesAt(i)->toString() << endl << endl;
		}
	}
	cout << "///////////////////////////////////////////////////////" << endl;
	system("PAUSE");
	//################################################################# Exempel 3
	//Or this. We will probably not use this, BUT it was on the diagram!
	cout << shelf->getAll() << endl;

	cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@" << endl;
	system("PAUSE");
	return 0;
}