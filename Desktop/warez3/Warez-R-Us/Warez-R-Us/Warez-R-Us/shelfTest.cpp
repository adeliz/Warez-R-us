#include "Shelf.h"
#include <iostream>

int main()
{
	Shelf shelf = Shelf(10, "aaaa");

	Item temp = Food("apple", "An apple", 2, "normal", 10, "green", 1);

	Item temp2 = Clothes("shirt", "a shirt", "Normal", 2, 50, 2, "Cotton");

	Misc temp3 = Misc("void", "A void", "abnormal",0, 100, "None");

	shelf.addItem(temp);
	shelf.addItem(temp2);
	shelf.addItem(temp3);

	cout << shelf.getAt(0).getDescription() << endl;


	return 0;
}