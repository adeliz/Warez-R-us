#include "Shelf.h"
#include <iostream>

int main()
{
	Shelf *shelf = new Shelf(10, "aaaa");

	Food temp = Food("apple", "An apple", "normal", 2, 10, "green", 1);
	
	Food temp2 = Food("orange", "An orange", "Fancy", 2, 100, "Sweet", 0);

	shelf->addItem(temp);
	shelf->addItem(temp2);

	system("PAUSE");

	return 0;
}