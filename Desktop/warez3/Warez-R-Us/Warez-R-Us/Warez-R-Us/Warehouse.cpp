#include "Warehouse.h"



Warehouse::Warehouse(){
	if (!this->backgroundTexture.loadFromFile("Texture/background.jpg")) {
		// error message
	}
	this->background.setTexture(this->backgroundTexture);
}


Warehouse::~Warehouse()
{
}

void Warehouse::draw(sf::RenderTarget & target){
	target.draw(this->background);
}

