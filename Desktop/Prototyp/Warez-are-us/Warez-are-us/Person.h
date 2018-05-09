#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person 
{

private:
	string name;
	int SSN;
	string gender;

public:

	Person(string name = "", int SSN = 0, string gender = "");
	~Person();

	string getName()const;
	int getSSN()const;
	string getGender()const;

};








#endif