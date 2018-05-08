#ifndef USERMANAGER_H
#define USERMANAGER_H	

#include"User.h"
#include<string>
#include <vector>

using namespace std;

class Usermanager
{
private:
	int nrOfUsers;
	int cap;
	User* users;

public:
	Usermanager();
	virtual ~Usermanager();
	int getNrOfUsers();

	string list();
	bool addUser(User newUser);
	bool addUser(string name, int SSN, string gender, string username, string password, bool adminRights);
	bool removeUser(User newUser);
	bool grantAdminRights(User thisUser, string passwrod);
	bool removeAdminRights(User thisUser);

	User getUser(int pos);

	int findUser(string userName);
};

#endif