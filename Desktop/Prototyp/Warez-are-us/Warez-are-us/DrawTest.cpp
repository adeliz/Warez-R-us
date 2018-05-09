#include <SFML/Graphics.hpp>
#include "Shelf.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

	Shelf storage = Shelf(10, "aaa");

	storage.addFood("Apple", "An apple", "norMAL", 3, 10, "Green", 3);
	storage.addFood("Apple", "An apple", "FAncy", 3, 100, "Red", 3);
	storage.addFood("Orange", "An orange", "FAncy", 3, 150, "Sweet", 3);
	storage.addClothes("Shirt", "A Shirt", "FAncy", 1, 1000, 3, "Cotton");

	storage.addFood("Apple", "An apple", "norMAL", 3, 10, "Green", 3);
	storage.addFood("Apple", "An apple", "FAncy", 3, 100, "Red", 3);
	storage.addFood("Orange", "An orange", "FAncy", 3, 150, "Sweet", 3);
	storage.addClothes("Shirt", "A Shirt", "FAncy", 1, 1000, 3, "Cotton");

	storage.addFood("Apple", "An apple", "norMAL", 3, 10, "Green", 3);
	storage.addFood("Apple", "An apple", "FAncy", 3, 100, "Red", 3);
	storage.addFood("Orange", "An orange", "FAncy", 3, 150, "Sweet", 3);
	storage.addClothes("Shirt", "A Shirt", "FAncy", 1, 1000, 3, "Cotton");

	storage.addFood("Orange", "An orange", "FAncy", 3, 150, "Sweet", 3);
	storage.addClothes("Shirt", "A Shirt", "FAncy", 1, 1000, 3, "Cotton");

	cout << storage.getNrOf() << endl;;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//window.draw(storage);
		storage.draw(window, sf::BlendAlpha);
		window.display();
	}

	return 0;
}