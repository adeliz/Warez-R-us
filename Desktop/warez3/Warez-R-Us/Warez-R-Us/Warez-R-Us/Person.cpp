#include "Person.h"

Person::Person(string name, int SSN, string gender)
{

	this->name = name;
	this->SSN = SSN;
	this->gender = gender;

}

Person::~Person()
{
}

string Person::getName() const
{
	return this->name;
}

int Person::getSSN() const
{
	return this->SSN;
}

string Person::getGender() const
{
	return this->gender;
}
