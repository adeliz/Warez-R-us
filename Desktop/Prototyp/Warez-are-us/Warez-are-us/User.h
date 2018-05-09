#ifndef USER_H
#define USER_H

#include "Person.h"

class User :
	public Person
{
private:

	string username;
	string password;
	bool adminRights;

public:
	User(string name = "", int SSN = 0, string gender = "", string username = "", string password = "", bool adminRights = 0);
	virtual ~User();

	string getUserName()const;
	bool getAdmin()const;
	bool changePassword(string newPassword);
	bool checkPassword(string currentPassword);
	void setAdminRights();
	void removeAdminRights();

};
#endif