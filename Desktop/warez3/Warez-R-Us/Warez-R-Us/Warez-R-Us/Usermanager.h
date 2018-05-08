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
	bool removeUser(User newUser);
	bool grantAdminRights(User thisUser, string passwrod);
	bool removeAdminRights(User thisUser);
};

#endif