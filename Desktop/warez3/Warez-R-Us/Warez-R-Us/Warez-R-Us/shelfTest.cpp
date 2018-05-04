#include "Shelf.h"
#include <iostream>

int main()
{
	Shelf *shelf = new Shelf(10, "aaaa");

	Item temp = Food("apple", "An apple", "normal", 2, 10, "green", 1);

	Item temp2 = Clothes("shirt", "a shirt", "Normal", 2, 50, 2, "Cotton");

	Misc temp3 = Misc("void", "A void", "abnormal",0, 100, "None");

	shelf->addItem(temp);
	shelf->addItem(temp2);
	shelf->addItem(temp3);

	cout << shelf->getAt(2).getBrand() << endl;
	system("PAUSE");

	return 0;
}