#include "Truck.h"


Truck::Truck(string id, string destination, int velocity, int locationX, int locationY, int cap, int temperature)
{
	this->id = id;
	this->destination = destination;
	this->velocity = velocity;
	this->locationX = locationX;
	this->locationY = locationY;
	this->storage = new StorageUnit(cap, temperature);
}

Truck::~Truck()
{

}

string Truck::getDestination() const
{
	return this->destination;
}

string Truck::getID()
{
	return this->id;
}

string Truck::getLocation()
{
	return "Location X: " + to_string(this->locationX) + "\nLocation Y: " + to_string(this->locationY);
}

void Truck::changeDestination(string destination)
{
	this->destination = destination;
}

void Truck::changeLocationX(int pos)
{
	this->locationX = pos;
}

void Truck::changeLocationY(int pos)
{
	this->locationY = pos;
}

int Truck::getVelocity()
{
	return this->velocity;
}

StorageUnit* Truck::getStorage()
{
	return this->storage;
}
