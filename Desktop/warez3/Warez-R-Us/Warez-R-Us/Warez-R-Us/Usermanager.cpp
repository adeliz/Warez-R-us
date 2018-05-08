#include "Usermanager.h"

Usermanager::Usermanager()
{

	this->nrOfUsers = 0;
	this->cap = 10;
	this->users = new User[cap];
}

Usermanager::~Usermanager()
{
}

int Usermanager::getNrOfUsers()
{
	return this->nrOfUsers;
}

string Usermanager::list()
{
	string returnString = "";
	for (int i = 0; i < this->nrOfUsers; i++)
	{
		returnString += users[i].getUserName() + "\n";
	}
	return returnString;
}

bool Usermanager::addUser(User newUser)
{
	if (this->nrOfUsers >= cap)
	{
		this->cap += 2;
		User* temp = new User[this->cap];
		for (int i = 0; i < nrOfUsers; i++)
		{
			temp[i] = users[i];
		}
		delete users;
		users = temp;
	}
	this->users[nrOfUsers++] = newUser;
	return true;
}

bool Usermanager::removeUser(User newUser)
{
	bool found = false;
	for (int i = 0; i < nrOfUsers && found == false; i++)
	{
		if (this->users[i].getUserName() == newUser.getUserName())
		{
			if (i != nrOfUsers)
			{
				users[i] = users[nrOfUsers];
				users[nrOfUsers--];
			}
		}
	}
	return false;
}

bool Usermanager::grantAdminRights(User thisUser, string password)
{
	for (int i = 0; i < nrOfUsers; i++)
	{
		if (this->users[i].getUserName() == thisUser.getUserName())
		{
			this->users[i].setAdminRights();
			return true;
		}
	}
	return false;
}

bool Usermanager::removeAdminRights(User thisUser)
{
	for (int i = 0; i < nrOfUsers; i++)
	{
		if (this->users[i].getUserName() == thisUser.getUserName())
		{
			this->users[i].removeAdminRights();
			return true;
		}
	}
	return false;
}
