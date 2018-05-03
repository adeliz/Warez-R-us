#ifndef WAREHOUSE_H
#define WAREHOUSE_H
#include"SFML\Graphics.hpp"


class Warehouse{
private:
	sf::Sprite background;
	sf::Texture backgroundTexture;

public:
	Warehouse();
	~Warehouse();
	void draw(sf::RenderTarget& target);
};

#endif // !WAREHOUSE_H